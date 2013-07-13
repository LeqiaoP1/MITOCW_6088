#include "expression.h"
#include "scanner.h"
#include <iostream>

void TestExpr( const std::string& inputStr);

int main()
{
  TestExpr(  std::string("(1.1 *  1.3) - 10") );
  //TestExpr(  std::string("-(3.0 + -4.0)*-5.0") );
  //TestExpr(  std::string(" 1.0 - 2.0 + 3.0 ") ); // WRONG EVAL() as "1.0 - (2.0 + 3.0) = -4"
  return 0;
}

void TestExpr(const std::string& inputStr)
{
  Scanner sc;

  std::cout << "\n*** Test with string: " << inputStr << std::endl;

  // test the functionality of scanner
  if ( sc.SetInputString(inputStr) == true )
    {
      do {
	Symbol tmp = sc.GetCurrSymbol();
	std::cout << "Symbol: Type " << tmp.GetTypeString() << "\t\tVal " << tmp.val << std::endl;
      }while(sc.MoveToNextSymbol() == true);
    }

  sc.Reset();
  
  // test the eval() and print()
  InfixArithExpr testExpr(sc);
  std::cout << "the evaluated value : " << testExpr.eval() << std::endl;
  std::cout << "the print: ";
  testExpr.print();
  std::cout << std::endl;
  
}

