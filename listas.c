#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no Node;
typedef Node** List;

struct no {
    char info;
    Node* prox;
    Node* ante;
};

Node* nodeAlloc(char info){
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if(novoNo){
        novoNo->info = info;
        novoNo->prox = NULL;
        novoNo->ante = NULL;
    }
    return novoNo;
}

void insertFront(Node** head, char info){
    if((*head) == NULL){
        (*head) = nodeAlloc(info);
        return;
    }
    Node* novoNo = nodeAlloc(info);
    novoNo->prox = (*head);
    (*head)->ante = novoNo;
    (*head) = novoNo;
}

char removeFront(Node** head){
    if((*head) == NULL){
        return '\0';
    }
    char retorno = (*head)->info;
    Node* temp = (*head);
    (*head) = (*head)->prox;
    if((*head) != NULL){
        (*head)->ante = NULL;
    }
    free(temp);
    return retorno;
}

void insertBack(Node** head, char info) {
    Node* novoNo = nodeAlloc(info);
    if ((*head) == NULL) {
        (*head) = novoNo;
        return;
    }

    Node* atual = (*head);
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novoNo;
    novoNo->ante = atual;
}

char removeBack(Node** head){
    if((*head) == NULL){
        return '\0';
    }
    
    Node* atual = (*head);
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    char retorno = atual->info;
    if(atual->ante != NULL){
        atual->ante->prox = NULL;
    }
    free(atual);
    return retorno;
}

void printList(Node** head){
    if((*head) == NULL){
        printf("[]\n");
        return;
    }
    Node* atual = (*head);
    printf("\n[");
    printf("%c", atual->info);
    while(atual->prox != NULL){
        atual = atual->prox;
        printf(", %c",atual->info);
    }
    printf("]\n");
}

void freeList(Node** head){
    if((*head) == NULL){
        return;
    }
    Node* atual = (*head);
    while(atual->prox != NULL){
        atual = atual->prox;
        free(atual->ante);
    }
    free(atual);
    *head = NULL;
}

int lengthList(Node** head){
    int l = 0;
    Node* atual = (*head);
    while(atual != NULL){
        l++;
        atual = atual->prox;
    }
    return l;
}

bool insertInd(Node** head, char c, int index){
    int len = lengthList(head);
    if(index < 0 || index > len){
        return false;
    }
    if(index == 0){
        insertFront(head, c);
        return true;
    }
    if(index == len){
        insertBack(head, c);
        return true;
    }
    Node* atual = (*head);
    for(int i = 0; i < index; i++){
        atual = atual->prox;
    }

    Node* novoNo = nodeAlloc(c);
    novoNo->prox = atual;
    novoNo->ante = atual->ante;    
    atual->ante->prox = novoNo;
    atual->ante = novoNo;
    return true;
}

char removeInd(Node** head, int index){
    int len = lengthList(head);
    if(index < 0 || index >= len){
        return '\0';
    }
    if(index == 0){
        return removeFront(head);
    }
    if(index == len -1){
        return removeBack(head);
    }
    Node* atual = (*head);
    for(int i = 0; i < index; i++){
        atual = atual->prox;
    }
    char retorno = atual->info;
    atual->ante->prox = atual->prox;
    atual->prox->ante = atual->ante;
    free(atual);
    return retorno;
}

int findList(Node** head, char c){
    int index = 0;
    Node* atual = (*head);
    while(atual != NULL){
        if(atual->info == c){
            return index;
        }
        atual = atual->prox;
        index++;
    }
    return -1;
}

int main(){
    Node* no = NULL;
    List lista = &no;
    bool flag = true;
    char c;
    int index;

    printf("0. Adicionar ao inicio\n"
           "1. Remover Inicio\n"
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
            insertFront(lista, c);
            printList(lista);
            break;
        case '1':
            removeFront(lista);
            printList(lista);
            break;
        case '2':
            scanf(" %c", &c);
            insertBack(lista, c);
            printList(lista);
            break;
        case '3':
            removeBack(lista);
            printList(lista);
            break;
        case '4':
            scanf(" %c", &c);
            scanf("%d", &index);
            if(!(insertInd(lista, c, index))){
                printf("ERROR\n");
            } else {
                printList(lista);
            }
            break;
        case '5':
            scanf("%d", &index);
            if(removeInd(lista, index) == '\0'){
                printf("ERROR\n");
            } else {
                printList(lista);
            }
            break;
        case '6':
            freeList(lista);
            printList(lista);
            break;
        case '7':
            printf("%d\n", lengthList(lista));
            break;
        case '8':
            scanf(" %c", &c);
            index = findList(lista, c); 
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
    freeList(lista);
    return 0;
}