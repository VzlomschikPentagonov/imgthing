#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <cstdio>
#include <cstdint>

#define HEADER_SIZE 54
#define BITMAPINFOHEADER 40
#define NUM_COL_PLANES 1
#define BPP 24
#define BYTES_PER_PIXEL 3
#define SIZEOF_INT8_T 1
#define SIZEOF_INT16_T 2
#define SIZEOF_INT32_T 4
#define BLACK 0
#define PATH_BUF_SIZE 128
#define NUM_OF_ADDRESSES 6
#define FORMAT_OFFSET_0 0
#define FORMAT_OFFSET_1 1
#define FILESIZE_OFFSET 2
#define HEADER_SIZE_OFFSET 14
#define COL_PLANES_OFFSET 26
#define BPP_OFFSET 28
#define IMAGESIZE_OFFSET 34
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define I_BYTES (i<<3)

typedef struct Pixel{
	uint8_t blue;
	uint8_t green;
	uint8_t red;
}Pixel;

typedef struct Size{
	uint16_t width;
	uint16_t height;
}Size;

typedef struct Bitmap{
	uint32_t filesize;
	uint16_t width;
	uint16_t height;
	uint8_t padding;
}Bitmap;

Bitmap bitmap_set(uint16_t, uint16_t);
void header_get(Bitmap, int8_t*);
void bitmap_get(int8_t*, Bitmap, Pixel*, const char*);

#endif
