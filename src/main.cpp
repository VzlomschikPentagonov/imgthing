#include "../include/bmpheader.hpp"

int main{
	Header header = set_header(50, 100);
	write_header(header, "test.bmp");
	return 0;
}
