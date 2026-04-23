#ifndef LIST_H
#define LIST_H

#ifndef TYPE_LIST
#define TYPE_LIST char
#define Z_VALUE '\0'
#endif

#include <stdbool.h>

typedef struct list List;

List *new_list(void);
void *destroy_list(List *list);

bool list_is_empty(List *list);
int  list_length(List *list);

void list_insert_first(List *list, TYPE_LIST data);
void list_insert_last(List *list, TYPE_LIST data);
void list_insert_by_index(List *list, TYPE_LIST data, int index);

int list_find_data(List *list, TYPE_LIST data);
TYPE_LIST list_get_data(List *list, int index);

TYPE_LIST list_remove_first(List *list);
TYPE_LIST list_remove_last(List *list);
TYPE_LIST list_remove_by_index(List *list, int index);

void list_print(List *list);
void list_clear(List *list);

#endif
