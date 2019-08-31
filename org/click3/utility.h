
BOOST_STATIC_ASSERT(BOOST_VERSION == 107100);

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


#define strmove(s1,s2)	memmove(s1,s2,strlen(s2)+1)
#define snprintf _snprintf


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

#undef GetModuleFileName
unsigned int GetModuleFileName(char *buffer, unsigned int size, HMODULE module);
unsigned int GetModuleFileName(wchar_t *buffer, unsigned int size, HMODULE module);

#undef PathRemoveFileSpec
bool PathRemoveFileSpec(char *buffer);
bool PathRemoveFileSpec(wchar_t *buffer);
bool PathRemoveFileSpec(std::string &buffer);
bool PathRemoveFileSpec(std::wstring &buffer);

#undef SetCurrentDirectory
bool SetCurrentDirectory(const char *dir_name);
bool SetCurrentDirectory(const wchar_t *dir_name);

} // detail


std::string GetModuleFileName(HMODULE module);
template<class CONTAINER> bool GetModuleFileName(CONTAINER &buffer, HMODULE module = NULL) {
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
bool PathRemoveFileSpec(CONTAINER &buffer) {
	if(buffer.empty()) {
		return false;
	}
	if(!PathRemoveFileSpec(&buffer.front())) {
		return false;
	}
	return true;
}

template<class CONTAINER>
bool GetAppDir(CONTAINER &str) {
	const bool get_result = GetModuleFileName(str);
	if(!get_result || str.empty()) {
		return false;
	}
	const bool path_remove_result = detail::PathRemoveFileSpec(str);
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


#define MULTI_TO_WIDE_PROCS(name)								\
bool name##ToWChar(std::vector<wchar_t> &result, const char *str);				\
bool name##ToWChar(std::vector<wchar_t> &result, const std::vector<char> &str);			\
bool name##ToWChar(std::vector<wchar_t> &result, const std::string &str);			\
bool name##ToWChar(std::vector<wchar_t> &result, const boost::shared_ptr<std::string> str);	\
bool name##ToWChar(std::wstring &result, const char *str);					\
bool name##ToWChar(std::wstring &result, const std::vector<char> &str);				\
bool name##ToWChar(std::wstring &result, const std::string &str);				\
bool name##ToWChar(std::wstring &result, const boost::shared_ptr<std::string> str);

MULTI_TO_WIDE_PROCS(SJIS)
MULTI_TO_WIDE_PROCS(UTF8)

#undef MULTI_TO_WIDE_PROCS

#define WIDE_TO_MULTI_PROCS(name)								\
bool WCharTo##name##(std::vector<char> &result, const wchar_t *str);				\
bool WCharTo##name##(std::vector<char> &result, const std::vector<wchar_t> &str);		\
bool WCharTo##name##(std::vector<char> &result, const std::wstring &str);			\
bool WCharTo##name##(std::vector<char> &result, const boost::shared_ptr<std::wstring> str);	\
bool WCharTo##name##(std::string &result, const wchar_t *str);					\
bool WCharTo##name##(std::string &result, const std::vector<wchar_t> &str);			\
bool WCharTo##name##(std::string &result, const std::wstring &str);				\
bool WCharTo##name##(std::string &result, const boost::shared_ptr<std::wstring> str);

WIDE_TO_MULTI_PROCS(SJIS)
WIDE_TO_MULTI_PROCS(UTF8)

#undef WIDE_TO_MULTI_PROCS


typedef boost::shared_ptr<boost::remove_pointer<HANDLE>::type> SHARED_HANDLE;

SHARED_HANDLE ToSharedPtr(HANDLE handle);


template<typename Container>
bool FileRead(Container &result, const boost::filesystem::path &path) {
	if(!boost::filesystem::exists(path) || !boost::filesystem::is_regular_file(path)) {
		return false;
	}
	const unsigned long long int size = boost::filesystem::file_size(path);
	boost::filesystem::ifstream ifs(path);
	if(!ifs.is_open()) {
		return false;
	}
	result.resize(static_cast<unsigned int>(size));
	ifs.read(&*result.begin(), static_cast<long long int>(size));
	if(!ifs.good()) {
		return false;
	}
	return true;
}

} // Utility

} // click3

} // org
