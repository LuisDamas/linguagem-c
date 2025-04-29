#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Inicializar a BST
void bst_init(NODE** root)
{ *root = NULL; }

// Procurar um valor na BST
NODE* bst_search(NODE* root, int key)
{
  if (root == NULL || root->value == key)
    return root;

  // Procurar na subárvore esquerda
  if (key < root->value)
    return bst_search(root->left, key);

  // Senão, procurar na direita
  return bst_search(root->right, key);
}

// Verifica se um valor existe na BST
int bst_exists(NODE* root, int key)
{
  return bst_search(root, key)!=NULL;
}

// Verifica se a árvore está balanceada
int bst_isBalanced(NODE *root)
{
  if (root==NULL) return 1; // true

  int left_count = bst_count(root->left);
  int right_count = bst_count(root->right);

  if (abs(left_count - right_count) > 1)
    return 0;

  return bst_isBalanced(root->left) &&
         bst_isBalanced(root->right);
}

// Encontrar o nó com o menor valor
NODE* bst_getMinNode(NODE* root)
{
  if (root == NULL || root->left == NULL)
    return root;

  return bst_getMinNode(root->left);
}

// Encontrar o nó com o maior valor
NODE* bst_getMaxNode(NODE* root)
{
  if (root == NULL || root->right == NULL)
    return root;

  return bst_getMaxNode(root->right);
}

// Contar os nós existentes na BST
int bst_count(NODE* root)
{
  if (root == NULL) return 0;

  return 1 + bst_count(root->left) + 
             bst_count(root->right);
}

// Criar um novo nó
NODE* bst_createNode(int key)
{
  NODE *new_node = (NODE*) malloc(sizeof(NODE));
  if (new_node == NULL)
    return NULL;

  new_node->value = key;
  new_node->left = new_node->right = NULL;
  return new_node;
}

// Inserir um novo valor na BST
void bst_insert(NODE** root, int key)
{
  // Só insere nas folhas
  if (*root == NULL)
  {
    *root = bst_createNode(key);
    return;
  }

  // Não se admitem repetições
  if (key == (*root)->value) return;

  if (key < (*root)->value)
    bst_insert(&(*root)->left, key);
  else
    bst_insert(&(*root)->right, key);

  // Não se admitem repetições
  // if (key == (*root)->value) return;
}

// Remover um nó da BST, se existir
void bst_remove(NODE** root, int key)
{
  if (*root == NULL) return;

  if (key < (*root)->value)
  {
    bst_remove(&(*root)->left, key);
    return;
  }

  if (key > (*root)->value)
  {
    bst_remove(&(*root)->right, key);
    return;
  }

  // root contém o elemento a apagar

  // Se a subárvore esquerda não existir
  if ((*root)->left == NULL)
  {
    NODE* temp = (*root)->right;
    free(*root);
    *root = temp;
    return;
  }

  // Se a subárvore direita não existir
  if ((*root)->right == NULL)
  {
    NODE* temp = (*root)->left;
    free(*root);
    *root = temp;
    return;
  }

  // Ambas as subárvores estão preenchidas
  // Obter o menor nó à direita
  NODE* min_node_right = bst_getMinNode((*root)->right);

  // Copiar o valor do mínimo para o nó original
  (*root)->value = min_node_right->value;

  // Remover o nó com o valor de min_node_right
  bst_remove(&(*root)->right, min_node_right->value);
}

// Imprimir a BST em ordem
void bst_print_inOrder(NODE* root)
{
  if (root == NULL) return;

  bst_print_inOrder(root->left);
  printf("%d ", root->value);
  bst_print_inOrder(root->right);
}

// Imprimir a BST em pré-ordem
void bst_print_preOrder(NODE* root)
{
  if (root == NULL) return;

  printf("%d ", root->value);
  bst_print_preOrder(root->left);
  bst_print_preOrder(root->right);
}

// Imprimir a BST em pós-ordem
void bst_print_postOrder(NODE* root)
{
  if (root == NULL) return;

  bst_print_postOrder(root->left);
  bst_print_postOrder(root->right);
  printf("%d ", root->value);
}
