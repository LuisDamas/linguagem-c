#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// Inicializar a raiz da árvore
void node_init(NODE** root)
{
  *root = NULL;
}

// Verifica se um valor existe na árvore
// usando a comparação 
NODE* node_search(NODE* root, PERSON *person,
                  int (*compare)(PERSON*, PERSON*))
{
  int cmp = compare(person, root->data);

  if (cmp == 0)  return root;
  if (cmp < 0) return node_search(root->left, person, compare);
  return node_search(root->right, person, compare);
}

// Verifica se um valor existe na árvore
int node_exists(NODE* root, PERSON *person,
                int (*compare)(PERSON*, PERSON*))
{
  return node_search(root, person, compare)!=NULL;
}

// Verifica se a árvore está balanceada
int node_isBalanced(NODE *root)
{
  if (root==NULL) return 1; // true

  int left_count = node_count(root->left);
  int right_count = node_count(root->right);

  if (abs(left_count - right_count) > 1)
    return 0;

  return node_isBalanced(root->left) &&
         node_isBalanced(root->right);
}

// Encontrar o nó com o menor valor
NODE* node_getMinNode(NODE *root)
{
  if (root == NULL || root->left == NULL)
    return root;

  return node_getMinNode(root->left);
}

// Encontrar o nó com o maior valor
NODE* node_getMaxNode(NODE *root)
{
  if (root == NULL || root->right == NULL)
    return root;

  return node_getMaxNode(root->right);
}

// Contar os nós existentes na árvore
int node_count(NODE *root)
{
  if (root == NULL) return 0;

  return 1 + node_count(root->left) + 
             node_count(root->right);
}

// Criar um novo nó
NODE* node_createNode(PERSON *person)
{
  NODE *new_node = (NODE*) malloc(sizeof(NODE));
  if (new_node == NULL)
    return NULL;

  new_node->data = person;
  new_node->left = new_node->right = NULL;
  return new_node;
}

// Inserir um novo valor na árvore
void node_insert(NODE** root, PERSON *person,
                 int (*compare)(PERSON*, PERSON*),
                 char *bst_name)
{
  // Só insere nas folhas
  if (*root == NULL)
  {
    *root = node_createNode(person);
    return;
  }

  int cmp = compare(person, (*root)->data);

  // Não se admitem repetições
  if (cmp == 0)
  {
    printf("BST: [%s] Registo já existe!!! -> ", bst_name);
    person_print(person, 0);
    printf(" --> ");
    person_print((*root)->data, 1);
    return;
  }

  if (cmp < 0)
    node_insert(&(*root)->left, person, compare, bst_name);
  else
    node_insert(&(*root)->right, person, compare, bst_name);
}

// Remover um nó da BST, se existir
void node_remove(NODE** root, PERSON *person,
                 int (*compare)(PERSON*, PERSON*),
                 char* bst_name)
{
  if (*root == NULL) // registo não existe na bst
  {
    printf("[%s] Registo não existe!!! -> ", bst_name);
    person_print(person, 1);
    return;
  }

  int cmp = compare(person, (*root)->data);
  if (cmp < 0)
  {
    node_remove(&(*root)->left, person, compare, bst_name);
    return;
  }

  if (cmp > 0)
  {
    node_remove(&(*root)->right, person, compare, bst_name);
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
  NODE* min_node_right = node_getMinNode((*root)->right);

  // Copiar o valor do mínimo para o nó original
  (*root)->data = min_node_right->data;

  // Remove o nó com o valor de min_node_right
  node_remove(&(*root)->right, min_node_right->data, 
              compare, bst_name);
}

// Imprimir a árvore em ordem
void node_print_inOrder(NODE* root)
{
  if (root == NULL) return;

  node_print_inOrder(root->left);
  person_print(root->data, 1);
  node_print_inOrder(root->right);
}

// Imprimir a árvore em pré-ordem
void node_print_preOrder(NODE* root)
{
  if (root == NULL) return;

  person_print(root->data, 1);
  node_print_preOrder(root->left);
  node_print_preOrder(root->right);
}

// Imprimir a árvore em pós-ordem
void node_print_postOrder(NODE* root)
{
  if (root == NULL) return;

  node_print_postOrder(root->left);
  node_print_postOrder(root->right);
  person_print(root->data, 1);
}

