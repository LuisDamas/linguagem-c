#pragma once
#include "person.h"

typedef struct Node {
  PERSON *data;
  struct Node *left, *right;
} NODE;

// Inicializar a raiz da árvore
void node_init(NODE** root);

// Procurar um valor na árvore usando 
// a função de comparação
NODE* node_search(NODE* root, PERSON *person,
                  int (*compare)(PERSON*, PERSON*));

// Verifica se um valor existe na árvore
int node_exists(NODE* root, PERSON *person,
                  int (*compare)(PERSON*, PERSON*));

// Verifica se a árvore está balanceada
int node_isBalanced(NODE* root);

// Encontrar o nó com o menor valor
NODE* node_getMinNode(NODE *root);

// Encontrar o nó com o maior valor
NODE* node_getMaxNode(NODE *root);

// Contar os nós existentes na árvore
int node_count(NODE* root);

// Criar um novo nó
NODE* node_createNode(PERSON *person);

// Inserir um novo valor na árvore
void node_insert(NODE** root, PERSON *person,
                 int (*compare)(PERSON*, PERSON*),
                 char* bst_name);

// Remover um valor da árvore, se existir
void node_remove(NODE** root, PERSON *person,
                 int (*compare)(PERSON*, PERSON*),
                 char* bst_name);

// Imprimir a árvore em ordem
void node_print_inOrder(NODE* root);

// Imprimir a árvore em pré-ordem
void node_print_preOrder(NODE* root);

// Imprimir a árvore em pós-ordem
void node_print_postOrder(NODE* root);
