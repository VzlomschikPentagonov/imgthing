#include "../include/bitmap.hpp"

//FILE* header_file;
FILE* image_file;

int main(){
	uint16_t i;
//	header_file = fopen("header", "r+b");
	image_file = fopen("../images/test.bmp", "w+b");
	Bitmap bitmap = bitmap_set(50, 100);
	printf("%d, %hd, %hd, %hhd\n", bitmap.filesize, bitmap.width,
			bitmap.height, bitmap.padding);
	Pixel scanline[bitmap.width];
	int8_t header[HEADER_SIZE];
	header_get(bitmap, header);
	fwrite(&header, HEADER_SIZE, SIZEOF_INT8_T, image_file);
	for(i = 0; i < bitmap.width; i++){
		scanline[i].blue = 255;
		scanline[i].green = 127;
		scanline[i].red = 63;
	}
	for(i = 0; i < HEADER_SIZE; i++) printf("%hhd ", header[i]);
//	bitmap_get(header, bitmap, scanline, "../images/test");
	for(i = 0; i < bitmap.height; i++){
		fwrite(&scanline, bitmap.width * BYTES_PER_PIXEL + bitmap.padding,
				SIZEOF_INT8_T, image_file);
	}
	fflush(image_file);
	fclose(image_file);
	return 0;
}
