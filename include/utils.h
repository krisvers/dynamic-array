#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void * new(size_t size);
void * renew(void * ptr, size_t size);
void * delete(void * ptr);

#endif
