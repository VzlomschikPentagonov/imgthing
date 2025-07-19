#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include "bitmap.hpp"

void add(Bitmap, Pixel*, Pixel*, Pixel*);
void subtract(Bitmap, Pixel*, Pixel*, Pixel*);
void multiply(Bitmap, Pixel*, Pixel*, Pixel*);
void bitwise_or(Bitmap, Pixel*, Pixel*, Pixel*);
void bitwise_and(Bitmap, Pixel*, Pixel*, Pixel*);
void bitwise_xor(Bitmap, Pixel*, Pixel*, Pixel*);

#endif
