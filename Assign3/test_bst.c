#include <assert.h>
#include <stdio.h>
#include "bst.h"

int main() {
 
  /* initilize a size 32 */
  bst_t* cur = make_tree(32);
  printf ("size of array: %d \n", cur->size);
  init_tree(cur);
  print_bst(cur);

 /* Insert 1. */
  insert(1, cur);
  assert(find_val(1, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 0. */
  insert(0, cur);
  assert(find_val(0, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 2. */
  insert(2, cur);
  assert(find_val(2, cur) == TRUE);
  print_bst(cur); 
  printf("\n ----- \n");

  /* Insert 4. */
  insert(4, cur);
  assert(find_val(4, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 3 */
  insert(3, cur);
  insert(2, cur);
  assert(find_val(3, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* ADD YOUR TESTS HERE. */
  
  /* Delete the list. */
  delete_bst(cur);

  return 0;
}
