
BOOST_STATIC_ASSERT(BOOST_VERSION == 105400);

#ifdef _MT
#ifdef _DLL
#ifdef _DEBUG
#pragma comment(lib, "image_debug_shared.lib")
#else
#pragma comment(lib, "image_release_shared.lib")
#endif // _DEBUG
#else
#ifdef _DEBUG
#pragma comment(lib, "image_debug_static.lib")
#else
#pragma comment(lib, "image_release_static.lib")
#endif // _DEBUG
#endif // _DLL
#endif // _MT

namespace org { namespace click3 { namespace Image {

typedef boost::shared_ptr<boost::remove_pointer<HBITMAP>::type> SHARED_HBITMAP;

bool CreateHBitmap(SHARED_HBITMAP &result, unsigned int width, unsigned int height, size_t num_channels, const unsigned char * const *pixel_list);
bool GilViewToHBitmap(SHARED_HBITMAP &result, const boost::gil::rgb8c_view_t &view);
bool ReadImageAsHBitmap(SHARED_HBITMAP &result, const wchar_t *filename);

template<class image>
bool ReadImage(const boost::filesystem::path &path, image &im) {
	if(!boost::filesystem::is_regular_file(path)) {
		return false;
	}
	const wchar_t * const bmp_list[] = {L".bmp"};
	const wchar_t * const jpg_list[] = {L".jpg", L".jpeg"};
	const wchar_t * const png_list[] = {L".png"};
	const std::wstring ext = path.extension().wstring();
#define FIND(list, value) (std::find(&list[0], &list[sizeof(list) / sizeof(wchar_t *)], value) != &list[sizeof(list) / sizeof(wchar_t *)])
	if(FIND(bmp_list, ext)) {
		// TODO
	} else if(FIND(jpg_list, ext)) {
		boost::gil::jpeg_read_and_convert_image(path.string(), im);
	} else if(FIND(png_list, ext)) {
		boost::gil::png_read_and_convert_image(path.string(), im);
	} else {
		return false;
	}
#undef FIND
	return true;
}

} // Image

} // click3

} // org
