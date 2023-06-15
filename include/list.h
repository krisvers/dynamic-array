#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <assert.h>

typedef struct List {
	size_t length;
	size_t capacity;
	void * data;
	size_t element_size;
} list_t;

void list_resize(list_t * list, size_t new_capacity);
list_t * list_new(size_t element_size);
list_t * list_delete(list_t * list);
void list_shift(list_t * list, size_t start_index, int direction);
void list_generic_print(list_t * list);

#define list_at(type, list, index) \
	((type *) list->data)[index]

#define list_front(type, list) \
	list_at(type, list, 0)

#define list_back(type, list) \
	list_at(type, list, list->length - 1)

#define list_set(type, list, index, value) \
	list_at(type, list, index) = value

#define list_shrink(list) \
	{ assert(list != NULL); list_resize(list, list->length); }

#define list_insert(type, list, index, value)		\
	{						\
		assert(list != NULL);			\
		++list->length;				\
		if (list->length >= list->capacity) {	\
			list_resize(list,		\
			list->capacity			\
			+ (list->capacity >> 1));	\
		}					\
		list_shift(list, index, 1);		\
		list_set(type, list, index, value);	\
	}						\

#define list_remove(type, list, index)			\
	{						\
		if (index < list->length) {		\
			--list->length;			\
		}					\
		list_shift(list, index, -1);		\
		if (list->length <= list->capacity / 2) {\
			list_resize(list,		\
				list->capacity / 2);	\
		}					\
	}						\

#define list_clear(list)							\
	{									\
		for (size_t i = 0; i < list->capacity * list->element_size; ++i) {\
			((unsigned char *) list->data)[i] = 0;			\
		}								\
		list->length = 0;						\
	}									\

#define list_print(type, list, element_formatter) \
	{ printf("[ "); for (size_t i = 0; i < list->length; ++i) { printf(element_formatter", ", list_at(type, list, i)); } puts("]"); }

#define list_print_members(list) \
	{ assert(list != NULL); printf("len: %zu\tcap: %zu\tdata: %p\telement size: %zu\n", list->length, list->capacity, list->data, list->element_size); }

#define list_print_generic(list) \
	{ printf("[ "); for (size_t i = 0; i < list->length; ++i) { for (size_t e = 0; e < list->element_size; ++e) { printf("%02x", *(((unsigned char *) list->data) + (i * list->element_size) + e)); } printf(", "); } puts("]"); }

#endif
