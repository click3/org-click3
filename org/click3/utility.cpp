
//�O�����C�u�����[�̌x���͖��������Ă���
#pragma warning(push)
#pragma warning(disable: 4061) // case��`����Ă��Ȃ��񋓎q������܂�
#pragma warning(disable: 4100) // �錾���ꂽ�������g�p���Ă��܂���
#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4180) // �֐��|�C���^�[�ɑ΂��Ė����ȑ����q���g�p���Ă��܂�
#pragma warning(disable: 4189) // �ϐ��ɑ����Q�Ƃ���Ă��܂���
#pragma warning(disable: 4201) // ��W���̊g���@�\�A�����̍\����/���p�̂��g�p���Ă��܂�
#pragma warning(disable: 4263) // ���z�֐����I�[�o�[���C�h���Ă��܂����A�����̌^���Ⴂ�܂�
#pragma warning(disable: 4264) // �����̌^�݈̂Ⴄ�����֐�����`���ꂽ���߁A���z�֐��ɂ̓A�N�Z�X�ł��Ȃ��Ȃ�܂�
#pragma warning(disable: 4266) // ���z�֐��̂��ׂẴI�[�o�[���[�h���I�[�o�[���C�h���Ă��܂���
#pragma warning(disable: 4350) // const�Ȃ��̎Q�Ɠn���̓��e�������󂯎�邱�Ƃ��ł��Ȃ����߁A�ʂ̃R���X�g���N�^���Ă΂�܂�
#pragma warning(disable: 4365) // signed/unsigned���Ⴄ�^�ϊ����s���܂���
#pragma warning(disable: 4512) // ������Z�q�𐶐����邽�߂ɕK�v�ȃR���X�g���N�^���A�N�Z�X�ł��܂���A������Z�q�����܂���ł���
#pragma warning(disable: 4548) // �����ȃJ���}��
#pragma warning(disable: 4555) // ����p�̂Ȃ���
#pragma warning(disable: 4611) // ���ɂ�蓮�삪�قȂ�\���̂���@�\���g�p����Ă��܂�
#pragma warning(disable: 4619) // �����������݂��x���ԍ��͑��݂��܂���
#pragma warning(disable: 4625) // ��{�N���X�̃R�s�[�R���X�g���N�^���A�N�Z�X�s�\�Ȃ̂ŃR�s�[�R���X�g���N�^�����܂���ł���
#pragma warning(disable: 4626) // ��{�N���X�̑�����Z�q���A�N�Z�X�s�\�Ȃ̂ő�����Z�q�����܂���ł���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4668) // ��`����Ă��Ȃ��V���{����#if/#elif�Ŏg�p����܂���
#pragma warning(disable: 4738) // ���������_�̌v�Z���ʂ�32bit�Ɋi�[���Ă��邽�߃p�t�H�[�}���X���ቺ���Ă��܂�
#pragma warning(disable: 4819) // �\���ł��Ȃ��������܂�ł��܂��B
#pragma warning(disable: 4820) // �\���̂̃p�b�e�B���O���������܂���
#pragma warning(disable: 4986) // �ڍוs��
#pragma warning(disable: 4996) // �Z�L�����e�B�[�z�[���ɂȂ肤��W��C�֐����g�p����Ă��܂�

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
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
//�O�����C�u�����[�̌x�����������܂�


#pragma warning(disable: 4061) // case��`����Ă��Ȃ��񋓎q������܂�
#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4350) // const�Ȃ��̎Q�Ɠn���̓��e�������󂯎�邱�Ƃ��ł��Ȃ����߁A�ʂ̃R���X�g���N�^���Ă΂�܂�
#pragma warning(disable: 4503) // ��������4096�����𒴂������ߐ؂�̂Ă��܂�
#pragma warning(disable: 4514) // �g�p����Ă��Ȃ��֐�/���\�b�h���폜����܂���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4710) // �C�����C���֐��Ƃ��đI������܂������C�����C���W�J�ł��܂���ł���

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4100) // �錾���ꂽ�������g�p���Ă��܂���
#pragma warning(disable: 4189) // �ϐ��ɑ����Q�Ƃ���Ă��܂���
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
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
