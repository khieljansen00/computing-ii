#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
typedef void* RATIONAL;

RATIONAL rational_default_init();

void rational_destroy(RATIONAL* hRational);

#endif