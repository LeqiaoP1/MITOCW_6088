// Implementation for class Expression and its derived classes
#include "Expression.h"
#include <iostream>
#include <string>


NumLeaf:: NumLeaf(std::string input)
{
}

NumLeaf::~NumLeaf()	// dtor
{
}

void NumLeaf::print( ) const
{
  std::cout << m_val;
}

float NumLeaf::eval( ) const 
{
  return m_val;
}


BinaryExpr::BinaryExpr( std::string input )
{
  /*std::size_t foundPos;
    if (foundPos = input.find("+"))
  */
}




float BinaryExpr:: eval() const 
{
  // no checking at unusual cases
  if (op.compare("+") == 0)
    return ( lhs->eval() + rhs->eval() );

  if (op.compare("-") == 0)
    return ( lhs->eval() - rhs->eval() );

  if (op.compare("*") == 0)
    return ( lhs->eval() * rhs->eval() );

  if (op.compare("/") == 0)
    return ( lhs->eval() / rhs->eval() );
}


// with parentheses
void BinarExpr::print() const
{
  std::cout<<"(";
  lhs->print();
  std::cout << " " << op << " ";
  rhs->print();
  std::cout<<")";
}


   
