/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaImage.hpp"

CacaImage::CacaImage(const std::string &path)
{
	unsigned int rmask = 0x00ff0000;
	unsigned int gmask = 0x0000ff00;
	unsigned int bmask = 0x000000ff;
	unsigned int amask = 0xff000000;
	unsigned int bpp = 32;
	unsigned int depth = 4;

	_im_image = imlib_load_image(path.c_str());
	imlib_context_set_image(_im_image);
	_pixels = imlib_image_get_data_for_reading_only();
	_size = arc::VertexF(imlib_image_get_width(), imlib_image_get_height());

	_dither = caca_create_dither(bpp, _size.x(), _size.y(),
				depth * _size.x(), rmask, gmask, bmask, amask);
}

CacaImage::~CacaImage()
{
	imlib_context_set_image(_im_image);
	imlib_free_image();
	caca_free_dither(_dither);
}

caca_dither_t *CacaImage::getDither()
{
	return _dither;
}

uint32_t *CacaImage::getPixels()
{
	return _pixels;
}
