#include <stdio.h>
#include "bst.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))
int arr[] = {50, 30, 90, 95, 45, 10, 49, 92, 40};

static void bst_print(NODE *tree, 
                      char *caption, 
                      void(*func_to_print)(NODE*))
{
  printf("  %s [ ", caption); 
  func_to_print(tree);
  puts("]");
}

void print_all(NODE *tree)
{
  printf("Nº Elementos: %d Balanceada: %s\n", bst_count(tree),
         bst_isBalanced(tree)? "Sim": "Não");

  bst_print(tree, "In   Order:", bst_print_inOrder);
  bst_print(tree, "Pre  Order:", bst_print_preOrder);
  bst_print(tree, "Post Order:", bst_print_postOrder);
}

int main(void)
{
  NODE *tree;
  bst_init(&tree);

  print_all(tree);
  printf("Prima <ENTER>"); getchar();

  // Load BST
  for (int i=0; i<LEN(arr); i++)
  {
    printf("\nInserir: %d\n", arr[i]);
    bst_insert(&tree, arr[i]);
    print_all(tree);
    printf("Prima <ENTER>"); getchar();
  }

  // Verificar se os valores entre 40 e 50 
  // existe na BST
  printf("\n");
  for (int i=40; i<=50; i++)
    printf("Valor %d existe? %s\n", i, 
           bst_exists(tree, i)? "Sim": "Não");
  printf("Prima <ENTER>\n"); getchar();

  while(tree!=NULL)
  {
    printf("\nRemover: %d\n", tree->value);
    bst_remove(&tree, tree->value);
    print_all(tree);
    printf("Prima <ENTER>"); getchar();
  }

  return 0;
}
