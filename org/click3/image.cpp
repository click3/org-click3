
//�O�����C�u�����[�̌x���͖��������Ă���
#pragma warning(push)
#pragma warning(disable: 4061) // case��`����Ă��Ȃ��񋓎q������܂�
#pragma warning(disable: 4100) // �錾���ꂽ�������g�p���Ă��܂���
#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4180) // �֐��|�C���^�[�ɑ΂��Ė����ȑ����q���g�p���Ă��܂�
#pragma warning(disable: 4189) // �ϐ��ɑ����Q�Ƃ���Ă��܂���
#pragma warning(disable: 4191) // �֐��|�C���^�[�̃L���X�g�͊댯�ł�
#pragma warning(disable: 4201) // ��W���̊g���@�\�A�����̍\����/���p�̂��g�p���Ă��܂�
#pragma warning(disable: 4263) // ���z�֐����I�[�o�[���C�h���Ă��܂����A�����̌^���Ⴂ�܂�
#pragma warning(disable: 4264) // �����̌^�݈̂Ⴄ�����֐�����`���ꂽ���߁A���z�֐��ɂ̓A�N�Z�X�ł��Ȃ��Ȃ�܂�
#pragma warning(disable: 4265) // ���z�֐����܂ރN���X�̃f�X�g���N�^���񉼑z�֐��ł�
#pragma warning(disable: 4266) // ���z�֐��̂��ׂẴI�[�o�[���[�h���I�[�o�[���C�h���Ă��܂���
#pragma warning(disable: 4302) // �L���X�g��̌^�̕������������ߏ�񂪌����Ă���\��������܂�
#pragma warning(disable: 4350) // const�Ȃ��̎Q�Ɠn���̓��e�������󂯎�邱�Ƃ��ł��Ȃ����߁A�ʂ̃R���X�g���N�^���Ă΂�܂�
#pragma warning(disable: 4365) // signed/unsigned���Ⴄ�^�ϊ����s���܂���
#pragma warning(disable: 4512) // ������Z�q�𐶐����邽�߂ɕK�v�ȃR���X�g���N�^���A�N�Z�X�ł��܂���A������Z�q�����܂���ł���
#pragma warning(disable: 4548) // �����ȃJ���}��
#pragma warning(disable: 4555) // ����p�̂Ȃ���
#pragma warning(disable: 4571) // catch(...)�ō\������O(SEH)�̓L���b�`����܂���
#pragma warning(disable: 4611) // ���ɂ�蓮�삪�قȂ�\���̂���@�\���g�p����Ă��܂�
#pragma warning(disable: 4619) // �����������݂��x���ԍ��͑��݂��܂���
#pragma warning(disable: 4625) // ��{�N���X�̃R�s�[�R���X�g���N�^���A�N�Z�X�s�\�Ȃ̂ŃR�s�[�R���X�g���N�^�����܂���ł���
#pragma warning(disable: 4626) // ��{�N���X�̑�����Z�q���A�N�Z�X�s�\�Ȃ̂ő�����Z�q�����܂���ł���
#pragma warning(disable: 4640) // static�ȃ��[�J���ϐ��̏��������X���b�h�Z�[�t�ł͂���܂���
#pragma warning(disable: 4668) // ��`����Ă��Ȃ��V���{����#if/#elif�Ŏg�p����܂���
#pragma warning(disable: 4738) // ���������_�̌v�Z���ʂ�32bit�Ɋi�[���Ă��邽�߃p�t�H�[�}���X���ቺ���Ă��܂�
#pragma warning(disable: 4819) // �\���ł��Ȃ��������܂�ł��܂��B
#pragma warning(disable: 4820) // �\���̂̃p�b�e�B���O���������܂���
#pragma warning(disable: 4928) // �����̃��[�U�[��`�̈Öق̌^�ϊ����s���Ă��܂�
#pragma warning(disable: 4986) // �ڍוs��
#pragma warning(disable: 4987) // ��W���̊g���@�\���g�p����Ă��܂�
#pragma warning(disable: 4996) // �Z�L�����e�B�[�z�[���ɂȂ肤��W��C�֐����g�p����Ă��܂�

// RELEASE�r���h���̂ݔ�������x���̖�����
#ifndef _DEBUG
#pragma warning(disable: 4710) // inline�錾����Ă���֐�/���\�b�h��inline�W�J���܂���ł���
#pragma warning(disable: 4711) // inline�錾����Ă��Ȃ��֐�/���\�b�h��inline�W�J���܂���
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
// libpng1.4����ꕔ�萔���폜���ꂽ���߁A�Ȃ���Β�`���Ă��
#if !defined png_infopp_NULL
#define png_infopp_NULL (png_infopp)NULL
#endif
#if !defined int_p_NULL
#define int_p_NULL (int*)NULL
#endif
#include "boost/gil/extension/io/png_io.hpp"

#pragma warning(pop)
//�O�����C�u�����[�̌x�����������܂�

#pragma warning(disable: 4127) // ���������萔�ł�
#pragma warning(disable: 4191) // �֐��|�C���^�[�̃L���X�g�͊댯�ł�
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
