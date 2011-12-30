
//外部ライブラリーの警告は無効化しておく
#pragma warning(push)
#pragma warning(disable: 4061) // case定義されていない列挙子があります
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4180) // 関数ポインターに対して無効な装飾子を使用しています
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4191) // 関数ポインターのキャストは危険です
#pragma warning(disable: 4201) // 非標準の拡張機能、無名の構造体/共用体を使用しています
#pragma warning(disable: 4263) // 仮想関数をオーバーライドしていますが、引数の型が違います
#pragma warning(disable: 4264) // 引数の型のみ違う同名関数が定義されたため、仮想関数にはアクセスできなくなります
#pragma warning(disable: 4265) // 仮想関数を含むクラスのデストラクタが非仮想関数です
#pragma warning(disable: 4266) // 仮想関数のすべてのオーバーロードをオーバーライドしていません
#pragma warning(disable: 4302) // キャスト先の型の方が小さいため情報が欠けている可能性があります
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4365) // signed/unsignedが違う型変換が行われました
#pragma warning(disable: 4512) // 代入演算子を生成するために必要なコンストラクタがアクセスできません、代入演算子を作れませんでした
#pragma warning(disable: 4548) // 無効なカンマ式
#pragma warning(disable: 4555) // 副作用のない式
#pragma warning(disable: 4571) // catch(...)で構造化例外(SEH)はキャッチされません
#pragma warning(disable: 4611) // 環境により動作が異なる可能性のある機能が使用されています
#pragma warning(disable: 4619) // 無効化を試みた警告番号は存在しません
#pragma warning(disable: 4625) // 基本クラスのコピーコンストラクタがアクセス不能なのでコピーコンストラクタが作れませんでした
#pragma warning(disable: 4626) // 基本クラスの代入演算子がアクセス不能なので代入演算子が作れませんでした
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4668) // 定義されていないシンボルが#if/#elifで使用されました
#pragma warning(disable: 4738) // 浮動小数点の計算結果を32bitに格納しているためパフォーマンスが低下しています
#pragma warning(disable: 4819) // 表示できない文字を含んでいます。
#pragma warning(disable: 4820) // 構造体のパッティングが発生しました
#pragma warning(disable: 4928) // 複数のユーザー定義の暗黙の型変換が行われています
#pragma warning(disable: 4986) // 詳細不明
#pragma warning(disable: 4987) // 非標準の拡張機能が使用されています
#pragma warning(disable: 4996) // セキュリティーホールになりうる標準C関数が使用されています

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
#endif

#include <stdio.h>

#define UNICODE
#include <windows.h>

#include "jpeglib.h"
#include "png.h"

#include "boost/version.hpp"
#include "boost/static_assert.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/type_traits/remove_pointer.hpp"
#include "boost/gil/gil_all.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/filesystem/operations.hpp"
#include "boost/gil/extension/io/jpeg_io.hpp"
// libpng1.4から一部定数が削除されたため、なければ定義してやる
#if !defined png_infopp_NULL
#define png_infopp_NULL (png_infopp)NULL
#endif
#if !defined int_p_NULL
#define int_p_NULL (int*)NULL
#endif
#include "boost/gil/extension/io/png_io.hpp"

#pragma warning(pop)
//外部ライブラリーの警告無効ここまで

#pragma warning(disable: 4127) // 条件式が定数です
#pragma warning(disable: 4191) // 関数ポインターのキャストは危険です
#pragma warning(disable: 4350) // constなしの参照渡しはリテラルを受け取ることができないため、別のコンストラクタが呼ばれます
#pragma warning(disable: 4503) // 装飾名が4096文字を超えたため切り捨てられます
#pragma warning(disable: 4514) // 使用されていない関数/メソッドが削除されました
#pragma warning(disable: 4640) // staticなローカル変数の初期化がスレッドセーフではありません
#pragma warning(disable: 4710) // インライン関数として選択されましたがインライン展開できませんでした

// RELEASEビルド時のみ発生する警告の無効化
#ifndef _DEBUG
#pragma warning(disable: 4100) // 宣言された引数を使用していません
#pragma warning(disable: 4189) // 変数に代入後参照されていません
#pragma warning(disable: 4710) // inline宣言されている関数/メソッドをinline展開しませんでした
#pragma warning(disable: 4711) // inline宣言されていない関数/メソッドをinline展開しました
#endif

#include "image.h"

namespace org { namespace click3 { namespace Image {

void MyDeleteBitmap(HBITMAP bitmap) {
	if(bitmap == NULL) {
		return;
	}
	::DeleteObject(bitmap);
}

void MyDestroyJpegDecompress(jpeg_decompress_struct *decomp) {
	if(decomp == NULL) {
		return;
	}
	jpeg_destroy_decompress(decomp);
	delete decomp;
}

bool CreateHBitmap(SHARED_HBITMAP &result, unsigned int width, unsigned int height, size_t num_channels, const unsigned char * const *pixel_list) {
	BOOST_ASSERT(width <= INT_MAX);
	BOOST_ASSERT(height <= INT_MAX);
	const unsigned int row = ((width * 3 + 3) & ~3);
	BITMAPINFO bi;
	ZeroMemory(&bi.bmiHeader, sizeof(BITMAPINFOHEADER));
	bi.bmiHeader.biSize         = sizeof(BITMAPINFOHEADER);
	bi.bmiHeader.biWidth        = static_cast<int>(width);
	bi.bmiHeader.biHeight       = static_cast<int>(height);
	bi.bmiHeader.biPlanes       = 1;
	bi.bmiHeader.biBitCount     = 24;
	bi.bmiHeader.biCompression  = BI_RGB;
	bi.bmiHeader.biSizeImage    = row * height;

	LPBYTE lpBuf;
	result.reset(::CreateDIBSection(NULL, &bi, DIB_RGB_COLORS, reinterpret_cast<void**>(&lpBuf), NULL, 0), &MyDeleteBitmap);
	if (!result || result.get() == NULL) {
		return false;
	}

	for(unsigned int line = 0; line < height; line++) {
		BYTE * const pb = lpBuf + row * (height - 1 - line);
		if (num_channels == 1) {
			const BYTE * const p = reinterpret_cast<const BYTE *>(pixel_list[line]);
			for(unsigned int i = 0; i < width; i++) {
				pb[3 * i + 0] = p[i];
				pb[3 * i + 1] = p[i];
				pb[3 * i + 2] = p[i];
			}
		} else if (num_channels == 3) {
			const BYTE * const p = reinterpret_cast<const BYTE *>(pixel_list[line]);
			for(unsigned int i = 0; i < width; i++) {
				pb[3 * i + 0] = p[3 * i + 2];
				pb[3 * i + 1] = p[3 * i + 1];
				pb[3 * i + 2] = p[3 * i + 0];
			}
		} else {
			return false;
		}
	}

	if(0 == ::SetDIBits(NULL, result.get(), 0, height, lpBuf, &bi, DIB_RGB_COLORS)) {
		return false;
	}
	return true;
}

bool GilViewToHBitmap(SHARED_HBITMAP &result, const boost::gil::rgb8c_view_t &view) {
	BOOST_ASSERT(view.height() > 0);
	BOOST_ASSERT(view.width() > 0);
	BOOST_ASSERT(view.height() <= UINT_MAX);
	BOOST_ASSERT(view.width() <= UINT_MAX);
	const unsigned row = view.width() * view.num_channels();
	BOOST_ASSERT(row * view.height() <= UINT_MAX);
	std::vector<unsigned char> buffer(row * static_cast<unsigned int>(view.height()));
	std::vector<unsigned char *> ptr_list(static_cast<unsigned int>(view.height()));
	for(unsigned int i = 0; i < static_cast<unsigned int>(view.height()); i++) {
		ptr_list[i] = &buffer[row * i];
		std::copy(view.row_begin(static_cast<int>(i)), view.row_end(static_cast<int>(i)), reinterpret_cast<boost::gil::rgb8c_view_t::value_type *>(ptr_list[i]));
	}
	if(!CreateHBitmap(result, static_cast<unsigned int>(view.width()), static_cast<unsigned int>(view.height()), view.num_channels(), &ptr_list.front())) {
		return false;
	}
	return true;
}

bool ReadImageAsHBitmap(SHARED_HBITMAP &result, const wchar_t *filename) {
	const boost::filesystem::path path(filename);
	boost::gil::rgb8_image_t image;
	ReadImage(path.string(), image);
	return GilViewToHBitmap(result, boost::gil::const_view(image));
}

} // Image

} // click3

} // org
