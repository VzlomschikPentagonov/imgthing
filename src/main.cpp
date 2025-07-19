#include "../include/bitmap.hpp"
#include "../include/operations.hpp"

FILE* image_1;
FILE* image_2;
FILE* image_out;

int main(){
	uint16_t i, choice;
	image_1 = fopen("../images/img1.bmp", "r+b");
	image_2 = fopen("../images/img2.bmp", "r+b");
	Parameters image_param_1 = parameters_get(image_1);
	Bitmap bitmap = bitmap_set(image_param_1.width, image_param_1.height);
	Pixel scanline_in_1[bitmap.width], scanline_in_2[bitmap.width],
	      scanline_out[bitmap.width];
	int8_t header[HEADER_SIZE];
	header_get(bitmap, header);
	image_out = fopen("../images/imgout.bmp", "w+b");
	fwrite(&header, HEADER_SIZE, SIZEOF_INT8_T, image_out);
	fseek(image_1, HEADER_SIZE, SEEK_SET);
	fseek(image_2, HEADER_SIZE, SEEK_SET);
	system("clear");
	printf("Choose operation:\n\n"
	       "1. Add\n"
	       "2. Subtract\n"
	       "3. Multiply\n"
	       "4. Bitwise OR\n"
	       "5. Bitwise AND\n"
	       "6. Bitwise XOR\n");
	scanf("%hu", &choice);
	for(i = 0; i < bitmap.height; i++){
		fread(&scanline_in_1, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_1);
		fseek(image_1, bitmap.padding, SEEK_CUR);
		fread(&scanline_in_2, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_2);
		fseek(image_2, bitmap.padding, SEEK_CUR);
		switch(choice){
			case 1:
				add(bitmap, scanline_in_1, scanline_in_2, scanline_out);
				break;
			case 2:
				subtract(bitmap, scanline_in_1, scanline_in_2, scanline_out);
				break;
			case 3:
				multiply(bitmap, scanline_in_1, scanline_in_2, scanline_out);
				break;
			case 4:
				bitwise_or(bitmap, scanline_in_1, scanline_in_2, scanline_out);
				break;
			case 5:
				bitwise_and(bitmap, scanline_in_1, scanline_in_2, scanline_out);
				break;
			case 6:
				bitwise_xor(bitmap, scanline_in_1, scanline_in_2, scanline_out);
		}
		fwrite(&scanline_out, bitmap.width * BYTES_PER_PIXEL, SIZEOF_INT8_T, image_out);
		fflush(image_out);
	}
	return 0;
}
