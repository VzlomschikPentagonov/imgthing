#include "../include/bitmap.hpp"

using namespace std;

Parameters parameters_get(const char* path){
	char image_path[PATH_BUF_SIZE];
	snprintf(image_path, PATH_BUF_SIZE, "%s.bmp", path);
	image_file = fopen(image_path, "r+b");
	Parameters parameters;
	for(i = 0; i < SIZEOF_INT16_T; i++){
		fseek(image_file, WIDTH_OFFSET + i);
		parameters.width = bitmap.width >> I_BYTES;
		fseek(image_file, HEIGHT_OFFSET + i);
		parameters.height = bitmap.height >> I_BYTES;
	}
	return parameters;
}

Bitmap bitmap_set(uint16_t width,
                  uint16_t height){
	Bitmap bitmap;
	bitmap.width = width;
	bitmap.height = height;
	bitmap.padding = width & 3;
	bitmap.filesize = width * height * BYTES_PER_PIXEL + height * bitmap.padding;
	return bitmap;
}

void header_get(Bitmap bitmap,
                int8_t* header_buffer){
	uint8_t i;
	for(i = 4; i < HEADER_SIZE; i++){
		header_buffer[i] = 0;
	}
	int8_t addresses[NUM_OF_ADDRESSES] =
	{FORMAT_OFFSET_0, FORMAT_OFFSET_1, HEADER_SIZE_OFFSET,
	HEADER_SIZE_OFFSET, COL_PLANES_OFFSET, BPP_OFFSET};
	int8_t values[NUM_OF_ADDRESSES] = {'B', 'M', HEADER_SIZE,
	BITMAPINFOHEADER, NUM_COL_PLANES, BPP};
	for(i = 0; i < NUM_OF_ADDRESSES; i++){
		header_buffer[addresses[i]] = values[i];
	}
	for(i = 0; i < SIZEOF_INT32_T; i++){
		header_buffer[FILESIZE_OFFSET + i] = bitmap.filesize + HEADER_SIZE >> I_BYTES;
		header_buffer[IMAGESIZE_OFFSET + i] = bitmap.filesize >> I_BYTES;
	}
	for(i = 0; i < SIZEOF_INT16_T; i++){
		header_buffer[WIDTH_OFFSET + i] = bitmap.width >> I_BYTES;
		header_buffer[HEIGHT_OFFSET + i] = bitmap.height >> I_BYTES;
	}
}

void bitmap_get(int8_t* header,
                Bitmap* bitmaps,
                const char* path){
	char image_path[PATH_BUF_SIZE];
	snprintf(image_path, PATH_BUF_SIZE, "%s.bmp", path);
	image_file = fopen(image_path, "w+b");
	fwrite(&header, HEADER_SIZE, SIZEOF_INT8_T, image_file);
	uint16_t i;
}
