#include "../include/bitmap.hpp"

int main(){
	uint16_t i;
	Bitmap bitmaps[2] = {bitmap_set(50, 100),
	                     bitmap_set(64, 64)};
	printf("%d, %hd, %hd, %hhd\n", bitmap.filesize, bitmap.width,
			bitmap.height, bitmap.padding);
	Pixel scanline[bitmap.width];
	int8_t header[HEADER_SIZE];
	header_get(bitmap, header);
	for(i = 0; i < bitmap.width; i++){
		scanline[i].blue = 255;
		scanline[i].green = 127;
		scanline[i].red = 63;
	}
	for(i = 0; i < HEADER_SIZE; i++) printf("%hhd ", header[i]);
	bitmap_get(header, bitmap, scanline, "../images/test");
	return 0;
}
