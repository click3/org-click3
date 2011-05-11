
#ifdef _MT
#ifdef _DLL
#ifdef _DEBUG
#pragma comment(lib, "utility_debug_shared.lib")
#else
#pragma comment(lib, "utility_release_shared.lib")
#endif // _DEBUG
#else
#ifdef _DEBUG
#pragma comment(lib, "utility_debug_static.lib")
#else
#pragma comment(lib, "utility_release_static.lib")
#endif // _DEBUG
#endif // _DLL
#endif // _MT

#pragma comment(lib, "Shlwapi.lib")

#define SPRINTF_IMPL_IMPL(proc, buffer, start, fmt, ...)	::proc(&buffer[start], sizeof(buffer) / sizeof(*buffer) - start, fmt, __VA_ARGS__)
#define STRLEN_IMPL(proc, buffer)					::proc(buffer, sizeof(buffer) / sizeof(*buffer))
#define SPRINTF_IMPL(proc, len_proc, buffer, start, fmt, ...)							\
do {															\
	const unsigned int start_pos = start;									\
	const int length = SPRINTF_IMPL_IMPL(proc, buffer, start_pos, fmt, __VA_ARGS__);			\
	BOOST_ASSERT(length != -1);											\
	BOOST_ASSERT(static_cast<unsigned int>(length) == STRLEN_IMPL(len_proc, buffer) - start_pos);	\
} while(false)
#define SPRINTF(buffer, fmt, ...)				SPRINTF_IMPL(sprintf_s, strnlen, buffer, 0, fmt, __VA_ARGS__)
#define WSPRINTF(buffer, fmt, ...)				SPRINTF_IMPL(swprintf_s, wcsnlen, buffer, 0, fmt, __VA_ARGS__)
#define STRLEN(buffer)					STRLEN_IMPL(strnlen, buffer)
#define WSTRLEN(buffer)					STRLEN_IMPL(wcsnlen, buffer)
#define STRCATF(buffer, fmt, ...)				SPRINTF_IMPL(sprintf_s, strnlen, buffer, STRLEN(buffer), fmt, __VA_ARGS__)
#define WSTRCATF(buffer, fmt, ...)				SPRINTF_IMPL(swprintf_s, wcsnlen, buffer, WSTRLEN(buffer), fmt, __VA_ARGS__)

#define STRCPY_IMPL(proc, buffer, source)			::proc(buffer, sizeof(buffer) / sizeof(*buffer), source)
#define STRCPY(buffer, source)				STRCPY_IMPL(strcpy_s, buffer, source)
#define WSTRCPY(buffer, source)				STRCPY_IMPL(wcscpy_s, buffer, source)

#define STRNCPY_IMPL(proc, buffer, source, length)	::proc(buffer, sizeof(buffer) / sizeof(*buffer), source, length)
#define STRNCPY(buffer, source, length)			STRNCPY_IMPL(strncpy_s, buffer, source, length)
#define WSTRNCPY(buffer, source, length)			STRNCPY_IMPL(wcsncpy_s, buffer, source, length)

#define STRCAT_IMPL(proc, dest, source)			::proc(dest, sizeof(dest) / sizeof(*dest), source)
#define STRCAT(dest, source)				STRCAT_IMPL(strcat_s, dest, source)
#define WSTRCAT(dest, source)				STRCAT_IMPL(wstrcat_s, dest, source)

namespace org { namespace click3 { namespace Utility {

namespace detail {

#undef GetModuleFilename
unsigned int GetModuleFileName(char *buffer, unsigned int size, HMODULE module);
unsigned int GetModuleFileName(wchar_t *buffer, unsigned int size, HMODULE module);

#undef PathRemoveFileSpec
bool PathRemoveFileSpec(char *buffer);
bool PathRemoveFileSpec(wchar_t *buffer);

#undef SetCurrentDirectory
bool SetCurrentDirectory(const char *dir_name);
bool SetCurrentDirectory(const wchar_t *dir_name);

} // detail

template<class CONTAINER>
bool GetModuleFileName(CONTAINER &buffer, HMODULE module = NULL) {
	::SetLastError(ERROR_SUCCESS);
	for(unsigned int size = 256; size < 8192; size *= 2) {
		buffer.resize(size);
		const unsigned int length = detail::GetModuleFileName(&buffer[0], size, module);
		const DWORD error = ::GetLastError();
		if(error == ERROR_SUCCESS && length <= size) {
			if(length < size) {
				buffer.resize(length);
			}
			break;
		} else if(error == ERROR_INSUFFICIENT_BUFFER) {
			continue;
		} else {
			buffer.clear();
			return false;
		}
	}
	return true;
}

template<class CONTAINER>
bool GetAppDir(CONTAINER &str) {
	const bool get_result = GetModuleFileName(str);
	if(!get_result || str.empty()) {
		return false;
	}
	const bool path_remove_result = detail::PathRemoveFileSpec(&str[0]);
	if(!path_remove_result) {
		return false;
	}
	return true;
}

bool SetAppDir(void);

boost::shared_ptr<FILE> MyFOpen(const wchar_t *path, const wchar_t *type);
boost::shared_ptr<FILE> MyFOpen(const char *path, const char *type);
boost::shared_ptr<FILE> MyFOpen(const std::wstring &path, const wchar_t *type);
boost::shared_ptr<FILE> MyFOpen(const std::string &path, const char *type);

boost::shared_ptr<FILE> MyPOpen(const wchar_t *command, const wchar_t *type);
boost::shared_ptr<FILE> MyPOpen(const char *command, const char *type);
boost::shared_ptr<FILE> MyPOpen(const std::wstring &command, const wchar_t *type);
boost::shared_ptr<FILE> MyPOpen(const std::string &command, const char *type);

bool SJISFileRead(std::vector<wchar_t> &result, const std::wstring &path);
bool SJISFileRead(std::vector<wchar_t> &result, const std::string &path);
bool SJISFileRead(std::vector<wchar_t> &result, const wchar_t *path);
bool SJISFileRead(std::vector<wchar_t> &result, const char *path);
bool UTF8FileRead(std::vector<wchar_t> &result, const std::wstring &path);
bool UTF8FileRead(std::vector<wchar_t> &result, const std::string &path);
bool UTF8FileRead(std::vector<wchar_t> &result, const wchar_t *path);
bool UTF8FileRead(std::vector<wchar_t> &result, const char *path);

boost::shared_ptr<const std::string> Str2Ptr(const std::vector<char> &str);
boost::shared_ptr<const std::string> Str2Ptr(const std::string &str);
boost::shared_ptr<const std::string> Str2Ptr(const char* str);
boost::shared_ptr<const std::wstring> Str2Ptr(const std::vector<wchar_t> &str);
boost::shared_ptr<const std::wstring> Str2Ptr(const std::wstring &str);
boost::shared_ptr<const std::wstring> Str2Ptr(const wchar_t* str);


#define MULTI_TO_WIDE_PROCS(name)										\
bool name##ToWChar(std::vector<wchar_t> &result, const char *str);					\
bool name##ToWChar(std::vector<wchar_t> &result, const std::vector<char> &str);			\
bool name##ToWChar(std::vector<wchar_t> &result, const std::string &str);				\
bool name##ToWChar(std::vector<wchar_t> &result, const boost::shared_ptr<std::string> str);

MULTI_TO_WIDE_PROCS(SJIS)
MULTI_TO_WIDE_PROCS(UTF8)

#undef MULTI_TO_WIDE_PROCS


template<class T>
bool FileRead(std::vector<T> &data, const wchar_t *path) {
	BOOST_STATIC_ASSERT(sizeof(T) == 1);
	if(path == NULL || path[0] == '\0') {
		return false;
	}
	boost::shared_ptr<FILE> fp = MyFOpen(path, L"rb");
	if(!fp) {
		return false;
	}
	::fseek(fp.get(), 0, SEEK_END);
	const long size = ::ftell(fp.get());
	if(size < 0) {
		return false;
	}
	::fseek(fp.get(), 0, SEEK_SET);
	data.resize(static_cast<unsigned int>(size));
	const unsigned int read_size = ::fread(&data.front(), 1, data.size(), fp.get());
	if(read_size != data.size()) {
		return false;
	}
	return true;
}

template<class T>
bool FileRead(std::vector<T> &data, const std::wstring &path) {
	return FileRead(data, path.c_str());
}

template<class T>
bool FileRead(std::vector<T> &data, const char *path) {
	BOOST_STATIC_ASSERT(sizeof(T) == 1);
	std::vector<wchar_t> wpath;
	if(path == NULL || path[0] == '\0' || !SJISToWChar(wpath, path) || wpath.empty()) {
		return false;
	}
	return FileRead(data, &wpath.front());
}

template<class T>
bool FileRead(std::vector<T> &data, const std::string &path) {
	return FileRead(data, path.c_str());
}

} // Utility

} // click3

} // org
