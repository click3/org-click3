
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
#pragma warning(disable: 4619) // �����������݂��x���ԍ��͑��݂��܂���
#pragma warning(disable: 4623) // ����̃R���X�g���N�^�[�͈Öقō폜����܂���
#pragma warning(disable: 4625) // ��{�N���X�̃R�s�[�R���X�g���N�^���A�N�Z�X�s�\�Ȃ̂ŃR�s�[�R���X�g���N�^�����܂���ł���
#pragma warning(disable: 4626) // ��{�N���X�̑�����Z�q���A�N�Z�X�s�\�Ȃ̂ő�����Z�q�����܂���ł���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4668) // ��`����Ă��Ȃ��V���{����#if/#elif�Ŏg�p����܂���
#pragma warning(disable: 4710) // �C�����C���֐��ł͂���܂���
#pragma warning(disable: 4738) // ���������_�̌v�Z���ʂ�32bit�Ɋi�[���Ă��邽�߃p�t�H�[�}���X���ቺ���Ă��܂�
#pragma warning(disable: 4774) // sprintf_s�ɕ����񃊃e�����ȊO���n����܂���
#pragma warning(disable: 4819) // �\���ł��Ȃ��������܂�ł��܂��B
#pragma warning(disable: 4820) // �\���̂̃p�b�e�B���O���������܂���
#pragma warning(disable: 4986) // �ڍוs��
#pragma warning(disable: 5025) // move�\�Ȓ�`���폜����Ă��܂�
#pragma warning(disable: 5026) // move constructor���Öقō폜����܂���
#pragma warning(disable: 5027) // move�\�Ȓ�`���폜����Ă��邩public�ł͂���܂���
#pragma warning(disable: 5031) // pragma��push��pop���Ή����Ă��Ȃ��\��������܂�
#pragma warning(disable: 5045) // Spectre�y���􂪑}������܂�

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
#endif

#include <stdio.h>

#include <vector>
#include <numeric>

//wchar_t������̕�����Ƃ��Ďg�p���Ȃ�
//#define UNICODE
//std::min��std::max�ƒ�`���d�����邽��
#define NOMINMAX
#include <windows.h>
#include <tlhelp32.h>

#include "boost/assert.hpp"
#include "boost/static_assert.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

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

#include "dll_hack_lib.h"

#pragma push_macro("MODULEENTRY32")
#undef MODULEENTRY32
#pragma push_macro("Module32First")
#undef Module32First
#pragma push_macro("Module32Next")
#undef Module32Next
#pragma push_macro("PROCESSENTRY32")
#undef PROCESSENTRY32
#pragma push_macro("Process32First")
#undef Process32First
#pragma push_macro("Process32Next")
#undef Process32Next

namespace org { namespace click3 { namespace DllHackLib {

namespace {

FILE *stdout_fp;
FILE *stderr_fp;
FILE *stdin_fp;

} // anonymous

unsigned int GetPageSize(void) {
	SYSTEM_INFO info;
	::GetSystemInfo(&info);
	return info.dwPageSize;
}

void *GetBaseAddr(const void *addr) {
	BOOST_ASSERT(addr != NULL);
	MEMORY_BASIC_INFORMATION mbi;
	::VirtualQuery(addr, &mbi, sizeof(mbi));
	return mbi.BaseAddress;
}

bool ChangeProtect(unsigned int *old_protect, const void *addr, unsigned int new_protect) {
	void * const base_addr = GetBaseAddr(addr);
	const unsigned int page_size = GetPageSize();
	BOOST_STATIC_ASSERT(sizeof(DWORD) == sizeof(unsigned int));
	if(0 == ::VirtualProtect(base_addr, page_size, new_protect, reinterpret_cast<DWORD *>(old_protect))) {
		return false;
	}
	return true;
}

bool ChangeCode(unsigned int addr, const unsigned char *old_code, const unsigned char *new_code, unsigned int size) {
	BOOST_ASSERT(old_code != NULL);
	BOOST_ASSERT(new_code != NULL);
	unsigned char *write_ptr = reinterpret_cast<unsigned char *>(addr);
	unsigned int old_protect;
	if(!ChangeProtect(&old_protect, write_ptr, PAGE_EXECUTE_READWRITE)) {
		return false;
	}
	if(::memcmp(write_ptr, old_code, size) != 0) {
    ChangeProtect(&old_protect, write_ptr, old_protect);
		return false;
	}
	::memcpy(write_ptr, new_code, size);
	unsigned int protect;
	if(!ChangeProtect(&protect, write_ptr, old_protect) || protect != PAGE_EXECUTE_READWRITE) {
		return false;
	}
	return true;
}

bool WriteCode(unsigned char *old_code, unsigned int addr, const unsigned char *new_code, unsigned int size) {
	BOOST_ASSERT(new_code != NULL);
	unsigned char *write_ptr = reinterpret_cast<unsigned char *>(addr);
	unsigned int old_protect;
	if(!ChangeProtect(&old_protect, write_ptr, PAGE_EXECUTE_READWRITE)) {
		return false;
	}
	if(old_code != NULL) {
		::memcpy(old_code, write_ptr, size);
	}
	::memcpy(write_ptr, new_code, size);
	unsigned int protect;
	if(!ChangeProtect(&protect, write_ptr, old_protect) || protect != PAGE_EXECUTE_READWRITE) {
		return false;
	}
	return true;
}

bool SetupConsole() {
	if(FALSE == ::AllocConsole()) {
		return false;
	}
	const errno_t out_error = ::freopen_s(&stdout_fp, "CONOUT$", "w", stdout);
	if(out_error != 0 || stdout_fp == NULL) {
		return false;
	}
	const errno_t in_error = ::freopen_s(&stdin_fp, "CONIN$", "r", stdin);
	if(in_error != 0 || stdin_fp == NULL) {
		return false;
	}
	const errno_t err_error = ::freopen_s(&stderr_fp, "CONOUT$", "w", stderr);
	if(err_error != 0 || stderr_fp == NULL) {
		return false;
	}
	return true;
}



namespace {

template<class entry_class, unsigned int flag, BOOL (WINAPI *first_proc)(HANDLE, entry_class*), BOOL (WINAPI *next_proc)(HANDLE, entry_class*)>
bool CreateEntryList(std::vector<boost::shared_ptr<entry_class> > &entry_list, unsigned int process_id = 0) {
	entry_list.clear();
	HANDLE snapshot = ::CreateToolhelp32Snapshot(flag, process_id);
	if(snapshot == INVALID_HANDLE_VALUE) {
		return false;
	}

	while(true) {
		boost::shared_ptr<entry_class> entry(new entry_class());
		entry->dwSize = sizeof(entry_class);
		if(entry_list.size() == 0) {
			if(FALSE == first_proc(snapshot, entry.get())) {
				break;
			}
		} else {
			if(FALSE == next_proc(snapshot, entry.get())) {
				break;
			}
		}
		entry_list.push_back(entry);
	}
	::CloseHandle(snapshot);
	return true;
}

bool CreateModuleList(std::vector<boost::shared_ptr<MODULEENTRY32> > &entry_list, unsigned int process_id = ::GetCurrentProcessId()) {
	return CreateEntryList<MODULEENTRY32, TH32CS_SNAPMODULE, &::Module32First, &::Module32Next>(entry_list, process_id);
}
bool CreateModuleList(std::vector<boost::shared_ptr<MODULEENTRY32W> > &entry_list, unsigned int process_id = ::GetCurrentProcessId()) {
	return CreateEntryList<MODULEENTRY32W, TH32CS_SNAPMODULE, &::Module32FirstW, &::Module32NextW>(entry_list, process_id);
}
bool CreateProcessList(std::vector<boost::shared_ptr<PROCESSENTRY32> > &entry_list) {
	return CreateEntryList<PROCESSENTRY32, TH32CS_SNAPPROCESS, &::Process32First, &::Process32Next>(entry_list);
}
bool CreateProcessList(std::vector<boost::shared_ptr<PROCESSENTRY32W> > &entry_list) {
	return CreateEntryList<PROCESSENTRY32W, TH32CS_SNAPPROCESS, &::Process32FirstW, &::Process32NextW>(entry_list);
}

struct FindModulePath {
	FindModulePath(const std::wstring &module_path) : module_path(module_path) { }
	std::wstring module_path;
	bool operator()(boost::shared_ptr<MODULEENTRY32W> module) const {
		return module_path == module->szExePath;
	}
};

bool FindProcess(std::vector<boost::shared_ptr<PROCESSENTRY32W> > &result, const wchar_t *exe_name, const boost::filesystem::path &dll_abs_path) {
	std::vector<boost::shared_ptr<PROCESSENTRY32W> > process_list;
	if(!CreateProcessList(process_list)) {
		return false;
	}
	struct FindExeName {
		FindExeName(const std::wstring &exe_name, const std::wstring &module_path) : exe_name(exe_name), module_path(module_path) { }
		std::wstring exe_name;
		std::wstring module_path;
		std::vector<boost::shared_ptr<PROCESSENTRY32W> > operator()(std::vector<boost::shared_ptr<PROCESSENTRY32W> > &list, boost::shared_ptr<PROCESSENTRY32W> value) const {
			if(exe_name == value->szExeFile) {
				while(true) {
					std::vector<boost::shared_ptr<MODULEENTRY32W> > module_list;
					if(!CreateModuleList(module_list, value->th32ProcessID)) { // �f�o�b�O���ȂǁA����ȃv���Z�X�ł���Ύ��s����̂Ŗ�������
						break;
					}
					const std::vector<boost::shared_ptr<MODULEENTRY32W> >::const_iterator it = std::find_if(module_list.begin(), module_list.end(), FindModulePath(module_path));
					if(it == module_list.end()) {
						list.push_back(value);
					}
					break;
				}
			}
			return list;
		}
	};
  std::vector<boost::shared_ptr<PROCESSENTRY32W> > initValue;
  initValue = std::accumulate(process_list.begin(), process_list.end(), initValue, FindExeName(exe_name, dll_abs_path.wstring()));
	result.swap(initValue);
	return true;
}

DWORD (WINAPI *GetLoadLibraryPath(unsigned int process_id))(void *) {
  return reinterpret_cast<DWORD (WINAPI *)(void *)>(GetProcRemoteAddress(process_id, L"kernel32.dll", "LoadLibraryW"));
}

typedef boost::shared_ptr<boost::remove_pointer<HANDLE>::type> SHREAD_HANDLE;
void MyVirtualFreeEx(HANDLE process, void *addr) {
	BOOST_ASSERT(process != NULL);
	DWORD exit_code;
	if(addr != NULL && FALSE != ::GetExitCodeProcess(process, &exit_code) && exit_code == STILL_ACTIVE) {
		const BOOL result = ::VirtualFreeEx(process, addr, 0, MEM_RELEASE);
		BOOST_ASSERT(result != FALSE);
	}
}

bool CreateThreadParam(boost::shared_ptr<void> &result, HANDLE process, const void *data, unsigned int data_size) {
	boost::function<void (void *)> func = boost::bind(&MyVirtualFreeEx, process, _1);
	result.reset(::VirtualAllocEx(process, NULL, data_size, MEM_COMMIT, PAGE_READWRITE), func);
	if(result.get() == NULL) {
		return false;
	}
	if(FALSE == ::WriteProcessMemory(process, result.get(), data, data_size, NULL)) {
		return false;
	}
	return true;
}

bool CreateThreadParam(boost::shared_ptr<void> &result, SHREAD_HANDLE process, const void *data, unsigned int data_size) {
	return CreateThreadParam(result, process.get(), data, data_size);
}

void MyCloseHandle(HANDLE handle) {
	if(handle != NULL) {
		::CloseHandle(handle);
	}
}

} // anonymous

unsigned int GetProcRemoteAddress(unsigned int process_id, const wchar_t * const dll_name, const char * const proc_name) {
	const unsigned int dll_base_addr = reinterpret_cast<unsigned int>(::GetModuleHandleW(dll_name));
	if(dll_base_addr == NULL) {
		return NULL;
	}
	std::vector<boost::shared_ptr<MODULEENTRY32W> > current_module_list;
	if(!CreateModuleList(current_module_list)) {
		return false;
	}
	struct FindModuleAddr {
		FindModuleAddr(unsigned int module_addr) : module_addr(module_addr) { }
		unsigned int module_addr;
		bool operator()(boost::shared_ptr<MODULEENTRY32W> module) {
			return reinterpret_cast<unsigned int>(module->hModule) == module_addr;
		}
	};
	const std::vector<boost::shared_ptr<MODULEENTRY32W> >::const_iterator current_it = std::find_if(current_module_list.begin(), current_module_list.end(), FindModuleAddr(dll_base_addr));
	if(current_it == current_module_list.end()) {
		return NULL;
	}
	std::vector<boost::shared_ptr<MODULEENTRY32W> > target_module_list;
	if(!CreateModuleList(target_module_list, process_id)) {
		return false;
	}
	const std::vector<boost::shared_ptr<MODULEENTRY32W> >::const_iterator target_it = std::find_if(target_module_list.begin(), target_module_list.end(), FindModulePath((*current_it)->szExePath));
	if(target_it == target_module_list.end()) {
		return NULL;
	}
	const unsigned int current_proc_address = reinterpret_cast<unsigned int>(::GetProcAddress(reinterpret_cast<HMODULE>(dll_base_addr), proc_name));
	if(current_proc_address == NULL) {
		return NULL;
	}
	const unsigned int target_base_addr = reinterpret_cast<unsigned int>((*target_it)->hModule);
	const unsigned int result = current_proc_address - dll_base_addr + target_base_addr;
	if(result < target_base_addr || target_base_addr +  (*target_it)->modBaseSize <= result) {
		return NULL;
	}
	return result;
}

bool DllInjection(const wchar_t *exe_name, const boost::filesystem::path &dll_path) {
	const boost::filesystem::path dll_abs_path = boost::filesystem::absolute(dll_path);
	std::vector<boost::shared_ptr<PROCESSENTRY32W> > th_app_list;
	if(!FindProcess(th_app_list, exe_name, dll_abs_path)) {
		return false;
	}
	BOOST_FOREACH(boost::shared_ptr<PROCESSENTRY32W> app, th_app_list) {
		DWORD (WINAPI * const proc_address)(LPVOID) = GetLoadLibraryPath(app->th32ProcessID);
		if(proc_address == NULL) {
			return false;
		}
		const SHREAD_HANDLE process = SHREAD_HANDLE(::OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, FALSE, app->th32ProcessID), &MyCloseHandle);
		if(process.get() == NULL) {
			return false;
		}
		const std::wstring &thread_param_string = dll_abs_path.wstring();
		boost::shared_ptr<void> thread_param;
		if(!CreateThreadParam(thread_param, process, thread_param_string.c_str(), (thread_param_string.size() + 1) * sizeof(wchar_t))) {
			return false;
		}
		const SHREAD_HANDLE thread = SHREAD_HANDLE(::CreateRemoteThread(process.get(), NULL, 0, proc_address, thread_param.get(), 0, NULL), &MyCloseHandle);
		if(thread.get() == NULL) {
			return false;
		}
		if(WAIT_OBJECT_0 != ::WaitForSingleObject(thread.get(), INFINITE)) {
			return false;
		}
	}
  return true;
}

bool DllInjection(const HANDLE process, const boost::filesystem::path &dll_path) {
	const boost::filesystem::path dll_abs_path = boost::filesystem::absolute(dll_path);
	if(process == NULL) {
		return false;
	}
	DWORD (WINAPI * const proc_address)(LPVOID) = GetLoadLibraryPath(GetProcessId(process));
	if(proc_address == NULL) {
		return false;
	}
	const std::wstring &thread_param_string = dll_abs_path.wstring();
	boost::shared_ptr<void> thread_param;
	if(!CreateThreadParam(thread_param, process, thread_param_string.c_str(), (thread_param_string.size() + 1) * sizeof(wchar_t))) {
		return false;
	}
	const SHREAD_HANDLE thread = SHREAD_HANDLE(::CreateRemoteThread(process, NULL, 0, proc_address, thread_param.get(), 0, NULL), &MyCloseHandle);
	if(thread.get() == NULL) {
		return false;
	}
	if(WAIT_OBJECT_0 != ::WaitForSingleObject(thread.get(), INFINITE)) {
		return false;
	}
	return true;
}

} // org

} // click3

} //DllHackLib

#pragma pop_macro("MODULEENTRY32")
#pragma pop_macro("Module32First")
#pragma pop_macro("Module32Next")
#pragma pop_macro("PROCESSENTRY32")
#pragma pop_macro("Process32First")
#pragma pop_macro("Process32Next")
