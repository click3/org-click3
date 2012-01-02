
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

#include <stdio.h>

#include <vector>

#include "boost/version.hpp"
#include "boost/static_assert.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/function.hpp"
#define BOOST_BIND_ENABLE_STDCALL
#include "boost/bind.hpp"
#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"

#include <windows.h>
#include <Shlwapi.h>

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

#include "utility.h"

namespace org { namespace click3 { namespace Utility {

namespace {

bool MyFOpenImpl(FILE ** fp, const wchar_t *fn, const wchar_t *type) {
	if(fp == NULL || fn == NULL || type == NULL || fn[0] == '\0' || type[0] == '\0') {
		return false;
	}
	boost::filesystem::path dir_path(fn);
	dir_path.remove_filename();
	boost::filesystem::create_directories(boost::filesystem::absolute(dir_path));

	const errno_t error = ::_wfopen_s(fp, fn, type);
	if(error != 0) {
		return false;
	}
	return true;
}

void MyFClose(FILE *fp) {
	if(fp == NULL) {
		return;
	}
	::fclose(fp);
}

void MyPClose(FILE *fp) {
	if(fp == NULL) {
		return;
	}
	::_pclose(fp);
}

template<class IN_TYPE, class OUT_TYPE>
bool StringConvert(std::vector<OUT_TYPE> &result, const IN_TYPE *buffer, unsigned int buffer_size, unsigned int code_page, boost::function<int (unsigned int, const IN_TYPE *, int, OUT_TYPE *, int)> convert_function) {
	if(buffer == NULL || buffer_size > INT_MAX || !convert_function) {
		return false;
	}
	if(buffer_size == 0) {
		result.resize(1);
		result[0] = static_cast<OUT_TYPE>('\0');
		return true;
	}
	const int size = convert_function(code_page, buffer, static_cast<int>(buffer_size), NULL, 0);
	if(size <= 0) {
		return false;
	}
	result.resize(static_cast<unsigned int>(size) + 1);
	const int convert_size = convert_function(code_page, buffer, static_cast<int>(buffer_size), &result.front(), static_cast<int>(result.size()));
	if(convert_size != size) {
		return false;
	}
	result[static_cast<unsigned int>(size)] = static_cast<OUT_TYPE>('\0');
	return true;
}

bool CharToWChar(std::vector<wchar_t> &out, const char *buffer, unsigned int buffer_size, unsigned int code_page) {
	const boost::function<int (unsigned int, const char *, int, wchar_t *, int)> convert_function = boost::bind(&::MultiByteToWideChar, _1, MB_ERR_INVALID_CHARS, _2, _3, _4, _5);
	return StringConvert(out, buffer, buffer_size, code_page, convert_function);
}

bool WCharToChar(std::vector<char> &out, const wchar_t *buffer, unsigned int buffer_size, unsigned int code_page) {
	BOOL convert_error = FALSE;
	const boost::function<int (unsigned int, const wchar_t *, int, char *, int)> convert_function = boost::bind(&::WideCharToMultiByte, _1, WC_SEPCHARS, _2, _3, _4, _5, reinterpret_cast<const char *>(NULL), &convert_error);
	const bool result = StringConvert(out, buffer, buffer_size, code_page, convert_function);
	if(!result || convert_error == TRUE) {
		return false;
	}
	return true;
}

template<typename T>
bool CharFileReadAndConvert(std::vector<wchar_t> &result, const T *path, unsigned int code_page) {
	std::vector<char> multi;
	if(!FileRead(multi, path)) {
		return false;
	}
	if(multi.empty()) {
		return true;
	}
	if(!CharToWChar(result, &multi.front(), multi.size(), code_page)) {
		return false;
	}
	return true;
}

void MyCloseHandle(HANDLE handle) {
	if(handle != NULL) {
		::CloseHandle(handle);
	}
}

} // anonymous

namespace detail {

unsigned int GetModuleFileName(char *buffer, unsigned int size, HMODULE module) {
	return GetModuleFileNameA(module, buffer, size);
}
unsigned int GetModuleFileName(wchar_t *buffer, unsigned int size, HMODULE module) {
	return GetModuleFileNameW(module, buffer, size);
}

bool PathRemoveFileSpec(char *buffer) {
	return (::PathRemoveFileSpecA(buffer) != FALSE);
}
bool PathRemoveFileSpec(wchar_t *buffer) {
	return (::PathRemoveFileSpecW(buffer) != FALSE);
}
bool PathRemoveFileSpec(std::string &buffer) {
	if(buffer.empty()) {
		return false;
	}
	if(!PathRemoveFileSpec(&buffer.front())) {
		return false;
	}
	buffer.resize(::strnlen(&buffer.front(), buffer.size()));
	return true;
}

bool PathRemoveFileSpec(std::wstring &buffer) {
	if(buffer.empty()) {
		return false;
	}
	if(!PathRemoveFileSpec(&buffer.front())) {
		return false;
	}
	buffer.resize(::wcsnlen(&buffer.front(), buffer.size()));
	return true;
}

bool SetCurrentDirectory(const char *dir_name) {
	return (::SetCurrentDirectoryA(dir_name) != FALSE);
}
bool SetCurrentDirectory(const wchar_t *dir_name) {
	return (::SetCurrentDirectoryW(dir_name) != FALSE);
}

} // detail

std::string GetModuleFileName(HMODULE module) {
	std::string buffer;
	const bool result = GetModuleFileName(buffer, module);
	BOOST_ASSERT(result);
	return buffer;
}

bool SetAppDir(void) {
	std::wstring dir_name;
	if(!GetAppDir(dir_name) || dir_name.empty()) {
		return false;
	}
	return detail::SetCurrentDirectory(dir_name.c_str());
}

boost::shared_ptr<FILE> MyFOpen(const wchar_t *path, const wchar_t *type) {
	boost::shared_ptr<FILE> result;
	FILE *fp;
	if(MyFOpenImpl(&fp, path, type) && fp != NULL) {
		result.reset(fp, &MyFClose);
	}
	return result;
}
boost::shared_ptr<FILE> MyFOpen(const char *path, const char *type) {
	std::vector<wchar_t> wpath;
	std::vector<wchar_t> wtype;
	boost::shared_ptr<FILE> result;
	if(SJISToWChar(wpath, path) && !wpath.empty() && SJISToWChar(wtype, type) && !wtype.empty()) {
		result = MyFOpen(&wpath.front(), &wtype.front());
	}
	return result;
}
boost::shared_ptr<FILE> MyFOpen(const std::wstring &path, const wchar_t *type) {
	return MyFOpen(path.c_str(), type);
}
boost::shared_ptr<FILE> MyFOpen(const std::string &path, const char *type) {
	return MyFOpen(path.c_str(), type);
}

boost::shared_ptr<FILE> MyPOpen(const wchar_t *command, const wchar_t *type) {
	boost::shared_ptr<FILE> result;
	FILE * const fp = ::_wpopen(command, type);
	if(fp != NULL) {
		result.reset(fp, &MyPClose);
	}
	return result;
}
boost::shared_ptr<FILE> MyPOpen(const char *command, const char *type) {
	std::vector<wchar_t> wcommand;
	std::vector<wchar_t> wtype;
	boost::shared_ptr<FILE> result;
	if(SJISToWChar(wcommand, command) && !wcommand.empty() && SJISToWChar(wtype, type) && !wtype.empty()) {
		result = MyPOpen(&wcommand.front(), &wtype.front());
	}
	return result;
}
boost::shared_ptr<FILE> MyPOpen(const std::wstring &command, const wchar_t *type) {
	return MyPOpen(command.c_str(), type);
}

boost::shared_ptr<FILE> MyPOpen(const std::string &command, const char *type) {
	return MyPOpen(command.c_str(), type);
}


bool SJISFileRead(std::vector<wchar_t> &result, const std::wstring &path) {
	return CharFileReadAndConvert(result, path.c_str(), CP_ACP);
}
bool SJISFileRead(std::vector<wchar_t> &result, const std::string &path) {
	return CharFileReadAndConvert(result, path.c_str(), CP_ACP);
}
bool SJISFileRead(std::vector<wchar_t> &result, const wchar_t *path) {
	return CharFileReadAndConvert(result, path, CP_ACP);
}
bool SJISFileRead(std::vector<wchar_t> &result, const char *path) {
	return CharFileReadAndConvert(result, path, CP_ACP);
}
bool UTF8FileRead(std::vector<wchar_t> &result, const std::wstring &path) {
	return CharFileReadAndConvert(result, path.c_str(), CP_UTF8);
}
bool UTF8FileRead(std::vector<wchar_t> &result, const std::string &path) {
	return CharFileReadAndConvert(result, path.c_str(), CP_UTF8);
}
bool UTF8FileRead(std::vector<wchar_t> &result, const wchar_t *path) {
	return CharFileReadAndConvert(result, path, CP_UTF8);
}
bool UTF8FileRead(std::vector<wchar_t> &result, const char *path) {
	return CharFileReadAndConvert(result, path, CP_UTF8);
}

boost::shared_ptr<const std::string> Str2Ptr(const std::vector<char> &str) {
	return boost::shared_ptr<const std::string>(new std::string(&str.front(), str.size()));
}

boost::shared_ptr<const std::string> Str2Ptr(const std::string &str) {
	return boost::shared_ptr<const std::string>(new std::string(str));
}

boost::shared_ptr<const std::string> Str2Ptr(const char* str) {
	return boost::shared_ptr<const std::string>(new std::string(str));
}

boost::shared_ptr<const std::wstring> Str2Ptr(const std::vector<wchar_t> &str) {
	return boost::shared_ptr<const std::wstring>(new std::wstring(&str.front(), str.size()));
}

boost::shared_ptr<const std::wstring> Str2Ptr(const std::wstring &str) {
	return boost::shared_ptr<const std::wstring>(new std::wstring(str));
}

boost::shared_ptr<const std::wstring> Str2Ptr(const wchar_t* str) {
	return boost::shared_ptr<const std::wstring>(new std::wstring(str));
}

#define MULTI_TO_WIDE_PROCS(name, code_page)							\
bool name##ToWChar(std::vector<wchar_t> &result, const char *str) {				\
	return CharToWChar(result, str, ::strlen(str), code_page);				\
}												\
bool name##ToWChar(std::vector<wchar_t> &result, const std::vector<char> &str) {		\
	return CharToWChar(result, &str.front(), str.size(), code_page);			\
}												\
bool name##ToWChar(std::vector<wchar_t> &result, const std::string &str) {			\
	return CharToWChar(result, str.c_str(), str.size(), code_page);				\
}												\
bool name##ToWChar(std::vector<wchar_t> &result, const boost::shared_ptr<std::string> str) {	\
	return CharToWChar(result, str->c_str(), str->size(), code_page);			\
}

MULTI_TO_WIDE_PROCS(SJIS, CP_ACP)
MULTI_TO_WIDE_PROCS(UTF8, CP_UTF8)

#undef WIDE_TO_MULTI_PROCS

#define WIDE_TO_MULTI_PROCS(name, code_page)							\
bool WCharTo##name##(std::vector<char> &result, const wchar_t *str) {				\
	return WCharToChar(result, str, ::wcslen(str), code_page);				\
}												\
bool WCharTo##name##(std::vector<char> &result, const std::vector<wchar_t> &str) {		\
	return WCharToChar(result, &str.front(), str.size(), code_page);			\
}												\
bool WCharTo##name##(std::vector<char> &result, const std::wstring &str) {			\
	return WCharToChar(result, str.c_str(), str.size(), code_page);				\
}												\
bool WCharTo##name##(std::vector<char> &result, const boost::shared_ptr<std::wstring> str) {	\
	return WCharToChar(result, str->c_str(), str->size(), code_page);			\
}

WIDE_TO_MULTI_PROCS(SJIS, CP_ACP)
WIDE_TO_MULTI_PROCS(UTF8, CP_UTF8)

#undef WIDE_TO_MULTI_PROCS

SHARED_HANDLE ToSharedPtr(HANDLE handle) {
	return SHARED_HANDLE(handle, MyCloseHandle);
}

} // Utility

} // click3

} // org
