// Implementation file of the class BST

#include "BST.h"
#include <iostream>

// ctor of class BST
BST::BST()
  :pRootVal(NULL), pLeftSubBST(NULL), pRightSubBST(NULL)
{
}

BST::~BST()
{
  if (pRootVal) // already allocated with memory by action insert()
    {
      delete pRootVal;
      pRootVal = NULL;
    }

  if (pLeftSubBST)
    {
      delete pLeftSubBST;
      pLeftSubBST = NULL;
    }

  if (pRightSubBST)
    {
      delete pRightSubBST;
      pRightSubBST = NULL;
    }
}

// inserts "val" into the tree
void BST::insert(int val)
{
  if (pRootVal == NULL) // empty BST
    {
      pRootVal = new int(val);
      pLeftSubBST = new BST();
      pRightSubBST = new BST();
    }
  else
    {

      if (*pRootVal < val)
	{
	  pRightSubBST->insert(val);
	}
      else if (*pRootVal > val)
	{
	  pLeftSubBST->insert(val);
	}
    }
}


bool BST::find(int val)
{
  if (pRootVal == NULL)
    {
      return false;
    }
  else
    {
      if (*pRootVal == val )
	return true;
      else
	{
	  if (*pRootVal < val)
	    {
	      return pRightSubBST->find(val);
	    }
	  else
	    {
	      return pLeftSubBST->find(val);
	    }
	}
    }
}

void BST::print_inorder()
{
  if (pRootVal != NULL)
    {
      pLeftSubBST->print_inorder();
      std::cout << " " << *pRootVal;
      pRightSubBST->print_inorder();
    }
}



