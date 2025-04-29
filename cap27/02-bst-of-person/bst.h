#pragma once
#include "person.h"
#include "node.h"

#define MAX_CAPTION 20

typedef struct
{
  NODE *root;
  char caption[MAX_CAPTION+1];
  int (*compare)(PERSON *, PERSON*);
} BST;

// Inicializar a BST
void bst_init(BST* bst, char *caption,
              int (*compare)(PERSON *, PERSON*));

// Procurar um valor na BST
NODE* bst_search(BST bst, PERSON *person);

// Verifica se um valor existe na BST
int bst_exists(BST bst, PERSON *person);

// Verifica se a BST está balanceada
int bst_isBalanced(BST bst);

// Encontrar o nó com o menor valor
NODE* bst_getMinNode(BST bst);

// Encontrar o nó com o maior valor
NODE* bst_getMaxNode(BST bst);

// Contar os nós existentes na BST
int bst_count(BST bst);

// Inserir um novo valor na árvore
void bst_insert(BST *bst, PERSON *person);

// Remover um nó da BST, se existir
void bst_remove(BST *bst, PERSON *person);

// Imprimir a BST em ordem
void bst_print_inOrder(BST bst);

// Imprimir a BST em pré-ordem
void bst_print_preOrder(BST bst);

// Imprimir a BST em pós-ordem
void bst_print_postOrder(BST bst);
