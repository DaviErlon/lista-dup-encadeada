#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct list* List;

List list_create(void);
void list_destroy(List list);

bool list_is_empty(List list);
int  list_length(List list);

void list_insert_front(List list, char data);
void list_insert_back(List list, char data);
void list_insert_by_index(List list, char data, int index);

char list_remove_first(List list);
char list_remove_last(List list);
char list_remove_by_index(List list, int index);

int list_find_data(List list, char data);
char list_get_data(List list, int index);

void list_print(List list);
void list_clear(List list);

#endif
