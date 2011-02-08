#include "boost/shared_ptr.hpp"
#include "boost/utility.hpp"
#include "boost/optional.hpp"
#include "boost/tuple/tuple.hpp"
#include <map>
#include <string>
#include "org/click3/notification_center.h"
#include <cstdio>

void proc(const char *notify_name, boost::shared_ptr<void> user_data, boost::shared_ptr<void> data) {
	printf("notify_name: %s\n", notify_name);
	printf("user_data: %08x\n", user_data.get());
	if(user_data.get() != NULL) {
		boost::shared_ptr<int> int_ptr = boost::static_pointer_cast<int>(user_data);
		printf(" => %d\n", *int_ptr);
	}
	printf("data: %08x\n", data.get());
	if(data.get() != NULL) {
		boost::shared_ptr<int> int_ptr = boost::static_pointer_cast<int>(data);
		printf(" => %d\n", *int_ptr);
	}
}

void CloseHandle(void *handle) {
	printf("CloseHandle: %08x\n", handle);
	if(handle != NULL) {
		printf(" => %d\n", *(int*)handle);
	}
	delete handle;
}

using namespace org::click3;

int main() {
	boost::shared_ptr<NotificationCenter> center = NotificationCenter::GetDefaultCenter();
	boost::shared_ptr<void> data;
	{
		boost::shared_ptr<int> int_ptr(new int(12345), CloseHandle);
		data = int_ptr;
	}

	char notify_name[256] = "hoge";
	std::string notify_name2("hoge");

	printf("start\n");
	center->SendNotification("hoge", data);
	center->SendNotification(NULL, data);
	center->SendNotification(notify_name, data);
	center->SendNotification(notify_name2.c_str(), data);

	printf("add hoge\n");
	{
		boost::shared_ptr<int> user_data(new int(23456), CloseHandle);
		center->AddObserver("hoge", proc, user_data);
	}
	center->SendNotification("hoge", data);
	center->SendNotification(NULL, data);
	center->SendNotification(notify_name, data);
	center->SendNotification(notify_name2.c_str(), data);

	printf("add NULL\n");
	{
		boost::shared_ptr<int> user_data(new int(34567), CloseHandle);
		center->AddObserver(NULL, proc, user_data);
	}
	center->SendNotification("hoge", data);
	center->SendNotification(NULL, data);
	center->SendNotification(notify_name, data);
	center->SendNotification(notify_name2.c_str(), data);

	printf("remove NULL\n");
	center->RemoveObserver(NULL, proc);
	center->SendNotification("hoge", data);
	center->SendNotification(NULL, data);
	center->SendNotification(notify_name, data);
	center->SendNotification(notify_name2.c_str(), data);

	printf("remove hoge\n");
	center->RemoveObserver("hoge", proc);
	center->SendNotification("hoge", data);
	center->SendNotification(NULL, data);
	center->SendNotification(notify_name, data);
	center->SendNotification(notify_name2.c_str(), data);

	return 0;
}



