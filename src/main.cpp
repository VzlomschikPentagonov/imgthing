#include "../include/bitmap.hpp"

Bitmap bitmap = bitmap_set(50, 100);
int8_t* header = write_header(bitmap);

int main{
	bitmap_get(header, bitmap, "test", "../images");
	return 0;
}
