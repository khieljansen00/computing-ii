#ifndef RATIONAL_H
#define RATIONAL_H
typedef void* RATIONAL;

RATIONAL rational_default_init();

RATIONAL rational_init(int numerator, int denominator);

void rational_destroy(RATIONAL* hRational);

int rational_get_numerator(RATIONAL hRational);

#endif