#include "../include/bitmap.hpp"

Bitmap bitmap_set(uint16_t width,
                  uint16_t height){
	Bitmap bitmap;
	uint16_t i, j;
	bitmap.width = width;
	bitmap.height = height;
	bitmap.padding = width & 3;
	bitmap.filesize = width * height * BYTES_PER_PIXEL + height * bitmap.padding;
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			bitmap.data[i][j].blue = BLACK;
			bitmap.data[i][j].green = BLACK;
			bitmap.data[i][j].red = BLACK;
		}
	}
	return bitmap;
}

int8_t* header_write(Bitmap bitmap){
	int8_t* header_buffer = calloc(HEADER_SIZE, SIZEOF_INT8_T));
	FILE* header_file = fopen("../bmpheader/header", "r+b");
	fread(&header_buffer, HEADER_SIZE, SIZEOF_INT8_T, header_file);
	uint8_t i;
	for(i = 0; i < SIZEOF_INT32_T; i++){
		header_buffer[FILESIZE_OFFSET + i] = bitmap.filesize + HEADER_SIZE >> I_BYTES;
		header_buffer[IMAGESIZE_OFFSET + i] = bitmap.filesize >> I_BYTES;
	}
	for(i = 0; i < SIZEOF_INT16_T; i++){
		header_buffer[WIDTH_OFFSET + i] = width >> I_BYTES;
		header_buffer[HEIGHT_OFFSET + i] = height >> I_BYTES;
	}
	fclose(header_file);
	return header_buffer;
}

void bitmap_get(int8_t* header,
				Bitmap bitmap,
				const int8_t* filename,
				const int8_t* path){
	int8_t image_path[PATH_BUF_SIZE];
	snprintf(image_path, PATH_BUF_SIZE, "%s/%s.bmp", path, filename);
	FILE* image_file = fopen(filename, "w+b");
	uint8_t i;
	fwrite(&header, HEADER_SIZE, SIZEOF_INT8_T, image_file);
	fflush(image_file);
}
