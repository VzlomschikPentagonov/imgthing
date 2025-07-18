#include "../include/bitmap.hpp"
#include "../include/operations.hpp"

FILE* image_1;
FILE* image_2;
FILE* image_out;

int main(){
	uint16_t i;
	Parameters parameters[2] = {parameters_get("../images/image1"),
	                            parameters_get("../images/image2")};
	Bitmap bitmap = bitmap_set(parameters[0].width, parameters[0].height);
	Pixel scanline_in_1[bitmap.width], scanline_in_2[bitmap.width],
	      scanline_out[bitmap.width];
	int8_t header[HEADER_SIZE];
	header_get(bitmap, header);
	bitmap_get(header, bitmap, "../images/test");
	for(i = 0; i < bitmap.height; i++){
		bitmap_read(image_1, image_2,
		            scanline_in_1, scanline_in_2);
		add(bitmap, scanline_in_1, scanline_in_2,
		           image_out, scanline_out);
	}
	fclose(image_1);
	fclose(image_2);
	fclose(image_out);
	return 0;
}
