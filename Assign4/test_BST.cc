#include <iostream>
#include "BST.h"

int main () {

  BST tree;

  // Test case 1: insert 1
  std::cout << "Test case 1: Insert 1\n";
  tree.insert(1);

  std::cout << "print: \n";
  tree.print_inorder();
  std::cout << "\n";

  if (tree.find(1)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1.\n";

  // Test case 2: insert 7
  std::cout << "Test case 2: Insert 7\n";
  tree.insert(7);

  std::cout << "print: \n";
  tree.print_inorder();
  std::cout << "\n";

  if (tree.find(1) && tree.find(7)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1, 7.\n";

  // Test case 3: insert -1
  std::cout << "Test case 3: Insert -1\n";
  tree.insert(-1);

  std::cout << "print: \n";
  tree.print_inorder();
  std::cout << "\n";

  if (tree.find(-1) && tree.find(7) && tree.find(1))
    std::cout << "Passed!\n";
  else     
    std::cout << "Failed! Tree should contain -1, 1, 7.\n";

  // ADD YOUR TESTS HERE
  int testInts[] = {-1, 2, 10, 7, 8, 9};
  for (unsigned i = 0; i < sizeof(testInts)/sizeof(int); i++)
    {
      tree.insert(testInts[i]);
    }

  std::cout << "print: \n";
  tree.print_inorder();
  std::cout << "\n";

  return 0;
}
