#ifndef BMPHEADER_HPP
#define BMPHEADER_HPP

#include <stdio.h>
#include <stdlib.h>
#define HEADER_SIZE 54
#define SIZEOF_INT8_T 1
#define I_BYTES (i<<3)

typedef struct Header{
	uint32_t filesize;
	uint16_t width;
	uint16_t height;
	uint8_t padding;
}Header;

Header set_header(uint16_t, uint16_t);
void write_header(Header, const int8_t*);

#endif
