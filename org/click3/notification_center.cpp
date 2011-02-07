#include "boost/utility.hpp"
#include "boost/optional.hpp"
#include "boost/shared_ptr.hpp"

#include <string>
#include <map>

#include "notification_center.h"

namespace org { namespace click3 {

namespace {

typedef std::multimap<boost::optional<std::string>, NotificationCenter::observer> observer_map;
typedef std::pair<boost::optional<std::string> , NotificationCenter::observer> observer_pair;
typedef observer_map::iterator iterator;
typedef observer_map::value_compare value_compare;

boost::optional<std::string> CreateKey(const char *notify_name) {
	if(notify_name == NULL) {
		return boost::none;
	} else {
		return std::string(notify_name);
	}
}

void SendNotificationImpl(iterator it, iterator end_it, const char *notify_name, void *data) {
	while(it != end_it) {
		it->second(notify_name, data);
		++it;
	}
}

bool RemoveObserverImpl(iterator it, iterator end_it, value_compare compare, observer_pair value, observer_map* observers) {
	boost::optional<iterator> erase_first = boost::none;;
	boost::optional<iterator> erase_end = boost::none;;
	while(it != end_it) {
		if(compare(*it, value) == 0) {
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

void NotificationCenter::AddObserver(const char *notify_name, observer proc) {
	boost::optional<std::string> key = CreateKey(notify_name);
	observers.insert(observer_pair(key, proc));
}

bool NotificationCenter::RemoveObserver(const char *notify_name, observer proc) {
	boost::optional<std::string> key = CreateKey(notify_name);
	std::pair<iterator, iterator> values = observers.equal_range(key);
	value_compare compare = observers.value_comp();
	return RemoveObserverImpl(values.first, values.second, compare, observer_pair(key, proc), &observers);
}
void NotificationCenter::SendNotification(const char *notify_name, void *data) {
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
