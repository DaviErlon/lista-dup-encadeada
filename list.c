#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/**
 * Este arquivo contém as definições das estruturas
 * e a implementação das funções utilizadas nesta
 * implementação de lista duplamente encadeada circular.
 *
 * Os comentários separam o código em tópicos que agrupam
 * elementos com propósitos semelhantes.
 */

/**
 * Definição das estruturas
 */

typedef struct node node;

struct node
{
    char data;
    node *next;
    node *prev;
};

struct list
{
    node *head;
    int length;
};

/**
 * Pequenas funções de auxílio
 */

node *find_node(List list, int index)
{
    node *tmp = list->head;
    int len = list->length;

    if (index <= len / 2)
    {
        for (int i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
    }
    else
    {
        tmp = list->head->prev;

        for (int i = len - 1; i > index; i--)
        {
            tmp = tmp->prev;
        }
    }

    return tmp;
}

bool list_is_empty(List list)
{
    if (!list)
    {
        return false;
    }
    return list->head == NULL;
}

int list_length(List list)
{
    if (!list)
    {
        return 0;
    }
    return list->length;
}

/**
 * Funções de alocação e desalocação de mémoria
 */

List list_create()
{
    List list = malloc(sizeof(List));
    if (list)
    {
        list->head = NULL;
        list->length = 0;
    }
    return list;
}

void list_destroy(List list)
{
    if (!list_is_empty(list))
    {
        node *curr = list->head;
        node *next;

        do
        {
            next = curr->next;
            free(curr);
            curr = next;
        } while (curr != list->head);
    }

    free(list);
}

node *node_alloc(char data)
{
    node *novoNo = malloc(sizeof(node));
    if (novoNo)
    {
        novoNo->data = data;
        novoNo->next = NULL;
        novoNo->prev = NULL;
    }
    return novoNo;
}

/**
 * Funções de inserção de elementos
 */

void list_insert_front(List list, char data)
{
    if (!list)
    {
        return;
    }
    node *newNode = node_alloc(data);
    if (newNode)
    {
        if (list_is_empty(list))
        {
            newNode->next = newNode;
            newNode->prev = newNode;

            list->head = newNode;
        }
        else
        {
            node *right = list->head;
            node *left = list->head->prev;

            newNode->next = right;
            newNode->prev = left;

            right->prev = newNode;
            left->next = newNode;

            list->head = newNode;
        }
        list->length++;
    }
}

void list_insert_back(List list, char data)
{
    if (!list)
    {
        return;
    }

    node *newNode = node_alloc(data);
    if (newNode)
    {
        if (list_is_empty(list))
        {

            newNode->next = newNode;
            newNode->prev = newNode;

            list->head = newNode;
        }
        else
        {
            node *right = list->head;
            node *left = list->head->prev;

            newNode->next = right;
            newNode->prev = left;

            right->prev = newNode;
            left->next = newNode;
        }
        list->length++;
    }
}

void list_insert_by_index(List list, char data, int index)
{
    if (!list)
    {
        return;
    }

    int len = list->length;

    if (index < 0 || index > len)
        return;

    if (index == 0)
    {
        list_insert_front(list, data);
        return;
    }

    if (index == len)
    {
        list_insert_back(list, data);
        return;
    }

    node *newNode = node_alloc(data);
    if (newNode)
    {
        node *right = find_node(list, index);
        node *left = right->prev;

        newNode->next = right;
        newNode->prev = left;

        left->next = newNode;
        right->prev = newNode;

        list->length++;
    }
}

/**
 * Funções de remoção de elementos
 */

char list_remove_first(List list)
{
    if (list_is_empty(list))
    {
        return '\0';
    }

    node *first = list->head;
    char data = first->data;

    if (list_length(list) == 1)
    {
        list->head = NULL;
    }
    else
    {
        node *right = first->next;
        node *left = first->prev;

        right->prev = left;
        left->next = right;

        list->head = right;
    }

    free(first);
    list->length--;

    return data;
}

char list_remove_last(List list)
{
    if (list_is_empty(list))
    {
        return '\0';
    }

    node *last = list->head->prev;
    char data = last->data;

    if (list_length(list) == 1)
    {
        list->head = NULL;
    }
    else
    {
        node *right = last->next;
        node *left = last->prev;

        right->prev = left;
        left->next = right;
    }

    free(last);
    list->length--;

    return data;
}

char list_remove_by_index(List list, int index)
{
    int len = list_length(list);
    if (list_is_empty(list) || index < 0 || index >= len)
    {
        return '\0';
    }

    if (index == 0)
    {
        return list_remove_first(list);
    }
    if (index == len - 1)
    {
        return list_remove_last(list);
    }

    node *curr = find_node(list, index);
    char data = curr->data;

    node *right = curr->next;
    node *left = curr->prev;

    right->prev = left;
    left->next = right;

    free(curr);
    list->length--;

    return data;
}

void list_clear(List list)
{
    if (!list_is_empty(list))
    {
        node *curr = list->head;
        node *next;

        do
        {
            next = curr->next;
            free(curr);
            curr = next;
        } while (curr != list->head);

        list->head = NULL;
        list->length = 0;
    }
}

/**
 * Funções de busca de elementos
 */

int list_find_data(List list, char data)
{
    if (list_is_empty(list))
    {
        return -1;
    }

    int index = 0;
    node *curr = list->head;
    do
    {
        if (curr->data == data)
        {
            return index;
        }
        curr = curr->next;
        index++;
    } while (curr != list->head);

    return -1;
}

char list_get_data(List list, int index)
{
    int len = list_length(list);
    if (list_is_empty(list) || index < 0 || index >= len)
    {
        return '\0';
    }

    node *curr = find_node(list, index);
    return curr->data;
}

/**
 * Função para imprimir a lista completa
 */

void list_print(List list)
{
    printf("[");
    if (list && !list_is_empty(list))
    {
        node *tmp = list->head;

        printf("%c", tmp->data);
        while (tmp->next != list->head)
        {
            tmp = tmp->next;
            printf(", %c", tmp->data);
        }
    }
    printf("]\n");
}
