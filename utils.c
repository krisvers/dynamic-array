#include <utils.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

void * new(size_t size) {
	void * ptr = malloc(size);
	assert(ptr != NULL);

	return ptr;
}

void * renew(void * ptr, size_t size) {
	printf("%p\n", ptr);
	assert(ptr != NULL);
	void * p = new(size);
	assert(p != NULL);
	
	memmove(p, ptr, size);
	ptr = delete(ptr);

	return p;
}

void * delete(void * ptr) {
	assert(ptr != NULL);
	free(ptr);

	return NULL;
}
