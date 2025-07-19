#include "../include/operations.hpp"

void add(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue + scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green + scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red + scanline_2[j].red;
	}
}

void subtract(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue - scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green - scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red - scanline_2[j].red;
	}
}

void multiply(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue * scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green * scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red * scanline_2[j].red;
	}
}

void bitwise_or(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue | scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green | scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red | scanline_2[j].red;
	}
}

void bitwise_and(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue & scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green & scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red & scanline_2[j].red;
	}
}

void bitwise_xor(Bitmap bitmap,
	     Pixel* scanline_1,
	     Pixel* scanline_2,
	     Pixel* scanline_out){
	uint16_t j;
	for(j = 0; j < bitmap.width; j++){
		scanline_out[j].blue = scanline_1[j].blue ^ scanline_2[j].blue;
		scanline_out[j].green = scanline_1[j].green ^ scanline_2[j].green;
		scanline_out[j].red = scanline_1[j].red ^ scanline_2[j].red;
	}
}
