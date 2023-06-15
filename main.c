#include <stdio.h>
#include <stdint.h>
#include <list.h>
#include <utils.h>

int main(void) {
	list_t * int_list = list_new(4);
	list_resize(int_list, 4);
	int_list->length = 4;

	list_at(uint32_t, int_list, 1) = 69420;

	list_insert(uint32_t, int_list, 0, 412);

	list_remove(uint32_t, int_list, 0);
	list_remove(uint32_t, int_list, 0);
	list_remove(uint32_t, int_list, 0);
	list_remove(uint32_t, int_list, 0);

	list_clear(int_list);

	int_list = list_delete(int_list);
	return 0;
}
