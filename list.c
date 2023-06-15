#include <list.h>
#include <utils.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

void list_resize(list_t * list, size_t new_capacity) {
	assert(list != NULL);

	if (list->data == NULL) {
		list->data = new(list->element_size * new_capacity);
		for (size_t i = 0; i < new_capacity * list->element_size; ++i) {
			((unsigned char *) list->data)[i] = 0;
		}
		list->capacity = new_capacity;
		return;
	}

	list->data = renew(list->data, list->element_size * new_capacity);
	for (size_t i = list->capacity * list->element_size; i < new_capacity * list->element_size; ++i) {
		((unsigned char *) list->data)[i] = 0;
	}
	list->capacity = new_capacity;
}

list_t * list_new(size_t element_size) {
	assert(element_size != 0);

	list_t * list;
	list = new(sizeof(list_t));
	list->length = 0;
	list->capacity = 0;
	list->element_size = element_size;
	list_resize(list, 1);

	return list;
}

list_t * list_delete(list_t * list) {
	assert(list != NULL);
	assert(list->data != NULL);

	list->data = delete(list->data);
	list = delete(list);

	return NULL;
}

void list_shift(list_t * list, size_t start_index, int direction) {
	assert(list != NULL);
	assert(list->data != NULL);

	memmove((void *) ((uintptr_t) list->data) + (start_index * list->element_size), (void *) ((uintptr_t) list->data) + ((start_index - direction) * list->element_size), ((list->capacity - (start_index - direction)) * list->element_size));
}

void list_generic_print(list_t * list) {
	assert(list != NULL);

	printf("list (%p) has %zu elements of size %zu and %zu capacity:\n  [ ", (void *) list, list->length, list->element_size, list->capacity);

	for (size_t i = 0; i < list->length; ++i) {
		for (size_t e = 0; e < list->element_size; ++e) {
			printf("%02x, ", ((unsigned char *) list->data)[(i * list->element_size) + e]);
		}
	}

	puts("]");
}
