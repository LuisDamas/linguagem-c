#pragma once

typedef struct Node {
  int value;
  struct Node *left, *right;
} NODE;

// Inicializar a BST
void bst_init(NODE** root);

// Procurar um valor na BST
NODE* bst_search(NODE* root, int key);

// Verifica se um valor existe na BST
int bst_exists(NODE* root, int key);

// Verifica se a árvore está balanceada
int bst_isBalanced(NODE *root);

// Encontrar o nó com o menor valor
NODE* bst_getMinNode(NODE* root);

// Encontrar o nó com o maior valor
NODE* bst_getMaxNode(NODE* root);

// Contar os nós existentes na BST
int bst_count(NODE* root);

// Criar um novo nó
NODE* bst_createNode(int key);

// Inserir um novo valor na BST
void bst_insert(NODE** root, int key);

// Remover um nó da BST, se existir
void bst_remove(NODE** root, int key);

// Imprimir a BST em ordem
void bst_print_inOrder(NODE* root);

// Imprimir a BST em pré-ordem
void bst_print_preOrder(NODE* root);

// Imprimir a BST em pós-ordem
void bst_print_postOrder(NODE* root);
