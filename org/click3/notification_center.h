
#ifdef _DEBUG
#pragma comment(lib, "notification_center_debug.lib")
#else
#pragma comment(lib, "notification_center.lib")
#endif

namespace org { namespace click3 {

#pragma warning(push)
#pragma warning(disable: 4625)
#pragma warning(disable: 4626)
class NotificationCenter : boost::noncopyable {
public:
	NotificationCenter();
	~NotificationCenter();

	static boost::shared_ptr<NotificationCenter> GetDefaultCenter(void);

	typedef void (*observer)(const char *notify_name, boost::shared_ptr<void> user_data, boost::shared_ptr<void> data);

	void AddObserver(const char *notify_name, observer proc, boost::shared_ptr<void> user_data = boost::shared_ptr<void>());
	bool RemoveObserver(const char *notify_name, observer proc);
	void SendNotification(const char *notify_name, boost::shared_ptr<void> data);
private:
	static boost::shared_ptr<NotificationCenter> default_notification_center;
	std::multimap<boost::optional<std::string>, boost::tuple<observer, boost::shared_ptr<void> > > observers;
};
#pragma warning(pop)

} // click3

} // org
