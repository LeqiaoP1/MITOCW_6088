#include "Expression.h"

int main(){

  // ADD YOUR TESTS HERE
  Expression* pTestExpr1 = new Expression("1.0");

  pTestExpr1.print();
  pTestExpr1.eval();

  return 0;
}

