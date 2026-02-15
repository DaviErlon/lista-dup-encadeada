# Lista Duplamente Encadeada Circular em C

Implementação de uma lista duplamente encadeada circular em linguagem C,
com armazenamento de elementos do tipo char.

A estrutura mantém ponteiros para o próximo e o anterior nó,
além de controle interno do tamanho da lista.


Características

- Lista duplamente encadeada
- Estrutura circular (último aponta para o primeiro)
- Controle de tamanho (length)
- Inserção no início, fim e por índice
- Remoção no início, fim e por índice
- Busca por valor e por índice
- Impressão formatada
- Funções de limpeza e destruição


Estrutura

Cada nó contém:
- data (char)
- ponteiro para o próximo nó
- ponteiro para o nó anterior

A lista contém:
- ponteiro para o primeiro nó (head)
- quantidade de elementos (length)


Principais Funções

Criação e Liberação
- list_create()
- list_clear()
- list_destroy()

Inserção
- list_insert_front()
- list_insert_back()
- list_insert_by_index()

Remoção
- list_remove_first()
- list_remove_last()
- list_remove_by_index()

Busca
- list_find_data()
- list_get_data()


Compilação (Linux)

Para compilar usando make:

make

Para executar:

./main

Para limpar o executável:

make clean

O projeto utiliza gcc com flags como:
-Wall -Wextra -std=c11
e pode ser compilado com otimização usando:
-O2

Projeto desenvolvido para fins de estudo de estruturas de dados em C.