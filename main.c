#include <stdio.h>
#include "list.h"

int main(){

    List lista = list_create();
    
    bool flag = true;
    char c;
    int index;

    printf("0. Adicionar ao início\n"
           "1. Remover Início\n"
           "2. Adicionar ao final\n"
           "3. Remover Final\n"
           "4. Adicionar no indice\n"
           "5. Remover o indice\n"
           "6. Esvaziar\n"
           "7. Tamanho\n"
           "8. Procura na lista\n"
           "9. Encerrar\n");

    while(flag){
        scanf(" %c", &c);

        switch (c)
        {
        case '0':
            scanf(" %c", &c);
            list_insert_front(lista, c);
            list_print(lista);
            break;
        case '1':
            list_remove_first(lista);
            list_print(lista);
            break;
        case '2':
            scanf(" %c", &c);
            list_insert_back(lista, c);
            list_print(lista);
            break;
        case '3':
            list_remove_last(lista);
            list_print(lista);
            break;
        case '4':
            scanf(" %c", &c);
            scanf("%d", &index);
            list_insert_by_index(lista, c, index);
            list_print(lista);
            break;
        case '5':
            scanf("%d", &index);
            list_remove_by_index(lista, index);
            list_print(lista);
            break;
        case '6':
            list_clear(lista);
            list_print(lista);
            break;
        case '7':
            printf("%d\n", list_length(lista));
            break;
        case '8':
            scanf(" %c", &c);
            index = list_find_data(lista, c); 
            if(index == -1){
                printf("Nao achado\n");
            } else {
                printf("achado no index: %d\n", index);
            }
            break;
        case '9':
            flag = false;
            break;
        default:
            break;
        }
    }

    list_destroy(lista);
    return 0;
}