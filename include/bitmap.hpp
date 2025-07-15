#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <stdio.h>
#include <stdlib.h>
#define HEADER_SIZE 54
#define BYTES_PER_PIXEL 3
#define SIZEOF_INT8_T 1
#define SIZEOF_INT16_T 2
#define SIZEOF_INT32_T 4
#define BLACK 0
#define PATH_BUF_SIZE 128
#define FILESIZE_OFFSET 2
#define IMAGESIZE_OFFSET 34
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define I_BYTES (i<<3)

typedef struct Pixel{
	uint8_t blue;
	uint8_t green;
	uint8_t red;
}Pixel;

typedef struct Bitmap{
	uint32_t filesize;
	uint16_t width;
	uint16_t height;
	uint8_t padding;
	Pixel[height][width] data;
}Bitmap;

Bitmap bitmap_set(uint16_t, uint16_t);
int8_t* bitmap_set(Bitmap);
void bitmap_get(Bitmap, const int8_t* const int8_t*);

#endif
