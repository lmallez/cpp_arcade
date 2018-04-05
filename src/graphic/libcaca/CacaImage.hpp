/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef CACAIMAGE_HPP_
	#define CACAIMAGE_HPP_

	#include <caca.h>
	#include <Imlib2.h>
	#include <string>
	#include "src/std/Vertex.hpp"

class CacaImage {
public:
	CacaImage(const std::string &path);
	~CacaImage();

	caca_dither_t *getDither();
	uint32_t *getPixels();

protected:

private:
	Imlib_Image _im_image;
	caca_dither_t *_dither;
	uint32_t *_pixels;
	arc::VertexF _size;
};

#endif /* !CACAIMAGE_HPP_ */
