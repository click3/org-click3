
//外部ライブラリーの警告は無効化しておく
#pragma warning(push)
#pragma warning(disable: 4061) // case定義されていない列挙子があります
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4180) // 関数ポインターに対して無効な装飾子を使用しています
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4201) // 非標準の拡張機能、無名の構造体/共用体を使用しています
#pragma warning(disable: 4263) // 仮想関数をオーバーライドしていますが、引数の型が違います
#pragma warning(disable: 4264) // 引数の型のみ違う同名関数が定義されたため、仮想関数にはアクセスできなくなります
#pragma warning(disable: 4266) // 仮想関数のすべてのオーバーロードをオーバーライドしていません
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4365) // signed/unsignedが違う型変換が行われました
#pragma warning(disable: 4512) // 代入演算子を生成するために必要なコンストラクタがアクセスできません、代入演算子を作れませんでした
#pragma warning(disable: 4548) // 無効なカンマ式
#pragma warning(disable: 4555) // 副作用のない式
#pragma warning(disable: 4611) // 環境により動作が異なる可能性のある機能が使用されています
#pragma warning(disable: 4619) // 無効化を試みた警告番号は存在しません
#pragma warning(disable: 4625) // 基本クラスのコピーコンストラクタがアクセス不能なのでコピーコンストラクタが作れませんでした
#pragma warning(disable: 4626) // 基本クラスの代入演算子がアクセス不能なので代入演算子が作れませんでした
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4668) // 定義されていないシンボルが#if/#elifで使用されました
#pragma warning(disable: 4738) // 浮動小数点の計算結果を32bitに格納しているためパフォーマンスが低下しています
#pragma warning(disable: 4820) // 構造体のパッティングが発生しました
#pragma warning(disable: 4986) // 詳細不明
#pragma warning(disable: 4996) // セキュリティーホールになりうる標準C関数が使用されています

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
#endif

#include "boost/utility.hpp"
#include "boost/optional.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/tuple/tuple.hpp"

#include <string>
#include <map>

#pragma warning(pop)
//外部ライブラリーの警告無効ここまで



#pragma warning(disable: 4061) // case定義されていない列挙子があります
#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4503) // 装飾名が4096文字を超えたため切り捨てられます
#pragma warning(disable: 4514) // 使用されていない関数/メソッドが削除されました
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4710) // インライン関数として選択されましたがインライン展開できませんでした

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
#endif

#include "notification_center.h"

namespace org { namespace click3 {

namespace {

typedef std::multimap<boost::optional<std::string>, boost::tuple<NotificationCenter::observer, boost::shared_ptr<void> > > observer_map;
typedef std::pair<boost::optional<std::string>, boost::tuple<NotificationCenter::observer, boost::shared_ptr<void> > > map_value;
typedef observer_map::iterator iterator;

boost::optional<std::string> CreateKey(const char *notify_name) {
	if(notify_name == NULL) {
		return boost::none;
	} else {
		return std::string(notify_name);
	}
}

void SendNotificationImpl(iterator it, iterator end_it, const char *notify_name, boost::shared_ptr<void> data) {
	while(it != end_it) {
		NotificationCenter::observer proc;
		boost::shared_ptr<void> user_data;
		boost::tie(proc, user_data) = it->second;
		proc(notify_name, user_data, data);
		++it;
	}
}

bool RemoveObserverImpl(iterator it, iterator end_it, NotificationCenter::observer value, observer_map* observers) {
	boost::optional<iterator> erase_first = boost::none;;
	boost::optional<iterator> erase_end = boost::none;;
	while(it != end_it) {
		if(it->second.get<0>() == value) {
			if(!erase_first) {
				erase_first = it;
			}
			erase_end = it; // ここで+1したいけど出来なかった……
			++(erase_end.get());
		} else if(erase_first) {
			break;
		}
		++it;
	}
	if(erase_first) {
		observers->erase(erase_first.get(), erase_end.get());
		return true;
	}
	return false;
}

} // anonymous

NotificationCenter::NotificationCenter() {
}
NotificationCenter::~NotificationCenter() {
}

//static
boost::shared_ptr<NotificationCenter> NotificationCenter::GetDefaultCenter(void) {
	if(!default_notification_center) {
		default_notification_center.reset(new NotificationCenter());
	}
	return default_notification_center;
}

void NotificationCenter::AddObserver(const char *notify_name, observer proc, boost::shared_ptr<void> user_data) {
	boost::optional<std::string> key = CreateKey(notify_name);
	boost::tuple<observer, boost::shared_ptr<void> > value = boost::make_tuple<observer, boost::shared_ptr<void> >(proc, user_data);
	observers.insert(map_value(key, value));
}

bool NotificationCenter::RemoveObserver(const char *notify_name, observer proc) {
	boost::optional<std::string> key = CreateKey(notify_name);
	std::pair<iterator, iterator> values = observers.equal_range(key);
	return RemoveObserverImpl(values.first, values.second, proc, &observers);
}
void NotificationCenter::SendNotification(const char *notify_name, boost::shared_ptr<void> data) {
	{
		std::pair<iterator, iterator> values = observers.equal_range(boost::none);
		SendNotificationImpl(values.first, values.second, notify_name, data);
	}
	if(notify_name != NULL) {
		boost::optional<std::string> key = CreateKey(notify_name);
		std::pair<iterator, iterator> values = observers.equal_range(key);
		SendNotificationImpl(values.first, values.second, notify_name, data);
	}
}

//static
boost::shared_ptr<NotificationCenter> NotificationCenter::default_notification_center;

} // click3

} // org
