
#pragma comment(lib, "notification_center.lib")

namespace org { namespace click3 {

class NotificationCenter : boost::noncopyable {
public:
	NotificationCenter();
	~NotificationCenter();

	static boost::shared_ptr<NotificationCenter> GetDefaultCenter(void);

	typedef void (*observer)(const char *notify_name, void *data);
	void AddObserver(const char *notify_name, observer proc);
	bool RemoveObserver(const char *notify_name, observer proc);
	void SendNotification(const char *notify_name, void *data);
private:
	static boost::shared_ptr<NotificationCenter> default_notification_center;
	std::multimap<boost::optional<std::string>, observer> observers;
};

} // click3

} // org
