#include <stdio.h>
#include <string.h>
#include "person.h"
#include "node.h"
#include "bst.h"

// Inicializar a BST
void bst_init(BST* bst, char *caption, 
              int (*compare)(PERSON *, PERSON*))
{
  node_init(&bst->root);
  strcpy(bst->caption, caption);
  bst->compare = compare;
}

// Procurar um valor na BST
NODE* bst_search(BST bst, PERSON *person)
{
  return node_search(bst.root, person, bst.compare);
}

// Verifica se um valor existe na BST
int bst_exists(BST bst, PERSON *person)
{
  return node_exists(bst.root, person, bst.compare);
}

// Verifica se a BST está balanceada
int bst_isBalanced(BST bst)
{
  return node_isBalanced(bst.root);
}

// Encontrar o nó com o menor valor
NODE* bst_getMinNode(BST bst)
{
  return node_getMinNode(bst.root);
}

// Encontrar o nó com o maior valor
NODE* bst_getMaxNode(BST bst)
{
  return node_getMaxNode(bst.root);
}

// Contar os nós existentes na BST
int bst_count(BST bst)
{
  return node_count(bst.root);
}

// Inserir um novo valor na árvore
void bst_insert(BST *bst, PERSON *person)
{
  node_insert(&bst->root, person, bst->compare, bst->caption);
}

// Remover um nó da BST, se existir
void bst_remove(BST *bst, PERSON *person)
{
  node_remove(&bst->root, person, bst->compare, bst->caption);
}

// Imprimir a BST em ordem
void bst_print_inOrder(BST bst)
{
  printf("BST: [%s] count=%d In-Order\n", 
               bst.caption, bst_count(bst));
  node_print_inOrder(bst.root);
}

// Imprimir a BST em pré-ordem
void bst_print_preOrder(BST bst)
{
  printf("BST: [%s] count=%d Pre-Order\n",
               bst.caption, bst_count(bst));
  node_print_preOrder(bst.root);
}

// Imprimir a BST em pós-ordem
void bst_print_postOrder(BST bst)
{
  printf("BST: [%s] count=%d Post-Order\n",
               bst.caption, bst_count(bst));
  node_print_postOrder(bst.root);
}

