
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
#pragma warning(disable: 4819) // 表示できない文字を含んでいます。
#pragma warning(disable: 4820) // 構造体のパッティングが発生しました
#pragma warning(disable: 4986) // 詳細不明
#pragma warning(disable: 4996) // セキュリティーホールになりうる標準C関数が使用されています

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
#endif

#include "boost/version.hpp"
#include "boost/static_assert.hpp"
#include "boost/utility.hpp"
#include "boost/optional.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/tuple/tuple.hpp"
#include "boost/thread.hpp"

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
typedef observer_map::const_iterator const_iterator;

boost::optional<std::string> CreateKey(const char *notify_name) {
	if(notify_name == NULL) {
		return boost::none;
	} else {
		return std::string(notify_name);
	}
}

void ThreadProxy(NotificationCenter::observer proc, boost::shared_ptr<std::string> notify_name, boost::shared_ptr<void> user_data, boost::shared_ptr<void> data) {
	const char *notify_name_impl = NULL;
	if(notify_name) {
		notify_name_impl = notify_name->c_str();
	}
	proc(notify_name_impl, user_data, data);
}


void SendNotificationImpl(const_iterator it, const_iterator end_it, boost::shared_ptr<std::string> notify_name, boost::shared_ptr<void> data, bool single_thread) {
	while(it != end_it) {
		NotificationCenter::observer proc;
		boost::shared_ptr<void> user_data;
		boost::tie(proc, user_data) = it->second;
		boost::function<void (void)> bind_proc = boost::bind(&ThreadProxy, proc, notify_name, user_data, data);
		if(single_thread) {
			bind_proc();
		} else {
			boost::thread th(bind_proc);
			th.detach();
		}
		++it;
	}
}

bool RemoveObserverImpl(iterator it, iterator end_it, NotificationCenter::observer value, observer_map* observer_list) {
	boost::optional<iterator> erase_first = boost::none;;
	boost::optional<iterator> erase_end = boost::none;;
	while(it != end_it) {
		if(it->second.get<0>() == value) {
			if(!erase_first) {
				erase_first = it;
			}
			erase_end = it;
			++(erase_end.get());
		} else if(erase_first) {
			break;
		}
		++it;
	}
	if(erase_first) {
		observer_list->erase(erase_first.get(), erase_end.get());
		return true;
	}
	return false;
}

boost::shared_ptr<NotificationCenter> default_notification_center;

} // anonymous

NotificationCenter::NotificationCenter() {
}
NotificationCenter::~NotificationCenter() {
}

//static
boost::shared_ptr<NotificationCenter> NotificationCenter::GetDefaultCenter(void) {
	static boost::mutex mtx;
	boost::mutex::scoped_lock lk(mtx);
	if(!default_notification_center) {
		default_notification_center.reset(new NotificationCenter());
	}
	return default_notification_center;
}

void NotificationCenter::AddObserver(const char *notify_name, observer proc, boost::shared_ptr<void> user_data) {
	boost::optional<std::string> key = CreateKey(notify_name);
	boost::tuple<observer, boost::shared_ptr<void> > value = boost::make_tuple<observer, boost::shared_ptr<void> >(proc, user_data);
	boost::mutex::scoped_lock lk(observer_list_mtx);
	observer_list.insert(map_value(key, value));
}

bool NotificationCenter::RemoveObserver(const char *notify_name, observer proc) {
	boost::optional<std::string> key = CreateKey(notify_name);
	boost::mutex::scoped_lock lk(observer_list_mtx);
	std::pair<iterator, iterator> values = observer_list.equal_range(key);
	return RemoveObserverImpl(values.first, values.second, proc, &observer_list);
}

void NotificationCenter::SendNotification(const char *notify_name_ptr, boost::shared_ptr<void> data, bool single_thread) const {
	boost::mutex::scoped_lock lk(observer_list_mtx);
	boost::shared_ptr<std::string> notify_name;
	if(notify_name_ptr != NULL) {
		notify_name.reset(new std::string(notify_name_ptr));
	}
	{
		std::pair<const_iterator, const_iterator> values = observer_list.equal_range(boost::none);
		SendNotificationImpl(values.first, values.second, notify_name, data, single_thread);
	}
	if(notify_name != NULL) {
		boost::optional<std::string> key = CreateKey(notify_name_ptr);
		std::pair<const_iterator, const_iterator> values = observer_list.equal_range(key);
		SendNotificationImpl(values.first, values.second, notify_name, data, single_thread);
	}
}

} // click3

} // org
