
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
