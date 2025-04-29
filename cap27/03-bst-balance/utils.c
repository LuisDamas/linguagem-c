#include <stdio.h>
#include "utils.h"

static void print_spaces(int n_spaces)
{
  printf("%*s", n_spaces, "");
}

static void pretty_print_aux(NODE *root, int column)
{
  if (root->right!=NULL)
  {
    pretty_print_aux(root->right, column + STEP+1);
    print_spaces(column+STEP); printf("%s\n", RIGHT_SEP);
  }
//  else
//    pretty_print_aux(root->right, column + 2*STEP);

  print_spaces(column); printf("%2d\n", root->value);

  if (root->left!=NULL)
  {
    print_spaces(column+STEP); printf("%s\n", LEFT_SEP);
    pretty_print_aux(root->left, column + STEP+1);
  }
}

void pretty_print(NODE *root)
{
  pretty_print_aux(root, 0);
}


static NODE *tree_to_sorted_list(NODE *root, NODE *link)
{
 NODE* aux;
 if(root == NULL)
    return link;

 aux = tree_to_sorted_list(root->left, root);

 root->left = NULL;
 root->right = tree_to_sorted_list(root->right, link);

 return aux;
}

// Transformar a lista numa árvore
static NODE *sorted_list_to_BST(NODE **ptrToRoot, int n)
{
 if(n == 0)
   return NULL;

 NODE *leftChild = sorted_list_to_BST(ptrToRoot, n/2);
 NODE *parent = *ptrToRoot;

 parent->left = leftChild;
 *ptrToRoot = (*ptrToRoot)->right;
 parent->right = sorted_list_to_BST(ptrToRoot, n-(n/2 + 1));

 return parent;
}

void bst_balance(NODE **ptrToRoot)
{
  int count = bst_count(*ptrToRoot);

  *ptrToRoot = tree_to_sorted_list(*ptrToRoot, NULL);
  *ptrToRoot = sorted_list_to_BST(ptrToRoot, count);
}

