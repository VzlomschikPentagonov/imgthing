#include "../include/bitmap.hpp"

using namespace std;

Parameters parameters_get(FILE* bitmap_file){
	Parameters parameters;
	parameters.width = 0, parameters.height = 0;
	uint16_t i;
	uint8_t byte_read;
	for(i = 0; i < SIZEOF_INT32_T; i++){
		fseek(bitmap_file, WIDTH_OFFSET + i, SEEK_SET);
		fread(&byte_read, SIZEOF_INT8_T, SIZEOF_INT8_T, bitmap_file);
		parameters.width += byte_read << I_BYTES;
		fseek(bitmap_file, HEIGHT_OFFSET + i, SEEK_SET);
		fread(&byte_read, SIZEOF_INT8_T, SIZEOF_INT8_T, bitmap_file);
		parameters.height += byte_read << I_BYTES;
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
