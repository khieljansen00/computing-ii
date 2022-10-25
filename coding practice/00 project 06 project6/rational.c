#include <stdio.h>
#include <stdlib.h>

#include "rational.h"

struct rational {
    int numerator;
    int denominator;
};
typedef struct rational Rational;

RATIONAL rational_default_init() {
    Rational* pRational = (Rational*)malloc(sizeof(Rational));
    if (pRational != NULL) {
        pRational->numerator = 0;
        pRational->denominator = 1;
    }
    return (RATIONAL)pRational;
}

void rational_destroy(RATIONAL* hRational) {
    Rational* pRational = (Rational*)*hRational;
    free(pRational);
    *hRational = NULL;
}