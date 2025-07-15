#include "../include/bmpheader.hpp"

Header set_header(uint16_t width,
                  uint16_t height){
	Header header;
	header.width = width;
	header.height = height;
	header.padding = width & 3;
	header.filesize = width * height * 3 + height * header.padding;
	return header;
}

void write_header(Header header,
                  const int8_t* filename){
	int8_t* header_buffer = calloc(HEADER_SIZE, SIZEOF_INT8_T));
	FILE* header_file = fopen("../bmpheader/header", "r+b");
	FILE* image_file = fopen(filename, "w+b");
	uint8_t i;
	fread(&header_buffer, HEADER_SIZE, SIZEOF_INT8_T, header_file);
	for(i = 0; i < 4; i++){
		header_buffer[2 + i] = header.filesize + 54 >> I_BYTES;
		header_buffer[34 + i] = header.filesize >> I_BYTES;
	}
	for(i = 0; i < 2; i++){
		header_buffer[18 + i] = width >> I_BYTES;
		header_buffer[22 + i] = height >> I_BYTES;
	}
	fwrite(&header_buffer, HEADER_SIZE, SIZEOF_INT8_T, image_file);
	fflush(image_file);
	fclose(header_file);
	free(header_buffer);
}
