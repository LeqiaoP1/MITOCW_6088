#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* Returns a bst_t structure with an int array vals of size "size" and the
 * size field set appropriately. */
bst_t* make_tree(int size)
{
  bst_t *ret = malloc( sizeof(bst_t) );

  if (ret == NULL)
    {
      printf("malloc() failed -- for bst_t \n");
      return ret; // NULL detected as error
    }

  ret->size = size;
  ret->vals = malloc( size*sizeof(int) ); // element type "int"
  if (ret->vals == NULL)
    {
      free(ret);
      return NULL;
    }

  return ret;
} 

/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */

/* initial value with -1 */
/* requirement: all inserted int must be non-negative */
void init_tree(bst_t* tree)
{
  int i = 0;

  for (i = 0; i < tree->size; i++)
    {
      tree->vals[i] = -1;
    }
}

/*
 * Inserts a new value into a given tree.
 */
void insert(int val, bst_t* tree)
{
  int index = 0;
  if (tree != NULL)
    {
      while ( index < tree->size )
	{
	  if (tree->vals[index] == -1)
	    {
	      tree->vals[index] = val;
	      break;
	    }
	  else
	    {
	      if (tree->vals[index] == val)
		{
		  break; // no need for insertion
		}
	      else
		{
		  if (tree->vals[index] > val)
		    index = index * 2 + 1; // go to left child
		  else
		    index = index * 2 + 2; // go to right child
		}
	    }
	}

      if (index >= tree->size) // array oveflows
	printf("insert() failed -- index overflow \n ");
    }
}

bool find_val(int val, bst_t* tree)
{
  int index = 0;
  if (tree != NULL)
    {
      while ( index < tree->size )
	{
	  if (tree->vals[index] == -1)
	    return FALSE;

	  if (tree->vals[index] == val)
	    return TRUE;
	  else
	    {
	      if (tree->vals[index] > val)
		index = index * 2 + 1; // go to left child
	      else
		index = index * 2 + 2; // go to right child
	    }
	}

      if (index >= tree->size) // array oveflows
	printf("find_val() failed -- index overflow \n ");
    } 
  return FALSE;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree)
{
  if (tree != NULL)
    {
      free(tree->vals);
      free(tree);
    }
}

/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree)
{
  int index = 0;
  if (tree != NULL)
    {
      for (index = 0; index < tree->size; index++)
	{
	  printf("%3d ", index);
	}
      printf("\n");
      
      for (index = 0; index < tree->size; index++)
	{
	  printf("%3d ", tree->vals[index]);
	}

      printf("\n\n");
    }
}

