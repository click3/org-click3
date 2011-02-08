#include "boost/utility.hpp"
#include "boost/optional.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/tuple/tuple.hpp"

#include <string>
#include <map>

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
			erase_end = it; // ‚±‚±‚Å+1‚µ‚½‚¢‚¯‚Ço—ˆ‚È‚©‚Á‚½cc
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
