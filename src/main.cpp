#include "../include/bitmap.hpp"
#include "../include/operations.hpp"

FILE* image_1;
FILE* image_2;
FILE* image_out;

int main(){
	uint16_t i;
	image_1 = fopen("../images/image1.bmp", "r+b");
	image_2 = fopen("../images/image2.bmp", "r+b");
	Parameters image_param_1 = parameters_get(/*"../images/image1", */image_1);
	Bitmap bitmap = bitmap_set(image_param_1.width, image_param_1.height);
	Pixel scanline_in_1[bitmap.width], scanline_in_2[bitmap.width],
	      scanline_out[bitmap.width];
	int8_t header[HEADER_SIZE];
	header_get(bitmap, header);
//	bitmap_get(header, "../images/test", image_out);
	image_out = fopen("../images/test.bmp", "w+b");
	fwrite(&header, HEADER_SIZE, SIZEOF_INT8_T, image_out);
	fseek(image_1, HEADER_SIZE, SEEK_SET);
	fseek(image_2, HEADER_SIZE, SEEK_SET);
	for(i = 0; i < bitmap.height; i++){
		fread(&scanline_in_1, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_1);
		fseek(image_1, bitmap.padding, SEEK_CUR);
		fread(&scanline_in_2, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_2);
		fseek(image_2, bitmap.padding, SEEK_CUR);
//		bitmap_read(image_1, image_2,
//		            scanline_in_1, scanline_in_2, bitmap);
		add(bitmap, scanline_in_1, scanline_in_2,
		           /*image_out, */scanline_out);
		fwrite(&scanline_out, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_out);
		fflush(image_out);
	}
	return 0;
}
