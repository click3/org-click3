
BOOST_STATIC_ASSERT(BOOST_VERSION == 105400);

#ifdef _MT
#ifdef _DLL
#ifdef _DEBUG
#pragma comment(lib, "notification_center_debug_shared.lib")
#else
#pragma comment(lib, "notification_center_release_shared.lib")
#endif // _DEBUG
#else
#ifdef _DEBUG
#pragma comment(lib, "notification_center_debug_static.lib")
#else
#pragma comment(lib, "notification_center_release_static.lib")
#endif // _DEBUG
#endif // _DLL
#endif // _MT

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
	void SendNotification(const char *notify_name, boost::shared_ptr<void> data, bool single_thread = true) const;
private:
	mutable boost::mutex observer_list_mtx;
	std::multimap<boost::optional<std::string>, boost::tuple<observer, boost::shared_ptr<void> > > observer_list;
};
#pragma warning(pop)

} // click3

} // org
