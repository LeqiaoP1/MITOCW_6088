// Implementation for class Expression and its derived classes
#include "expression.h"
#include "scanner.h"
#include <iostream>
#include <string>
#include <cassert>

//---------------------------------------------------
NumLeaf:: NumLeaf(Scanner& sc)
  :m_val(0.0)
{
  Symbol currSym = sc.GetCurrSymbol();
  m_val = currSym.val;
  //sc.MoveToNextSymbol();
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



//---------------------------------------------------
Term::Term(Scanner& sc)
  :hasNegSign(false), hasParenthese(false), pExpr(NULL)
{
  Symbol currSym = sc.GetCurrSymbol();
  if ( currSym.type == PAR_OPEN )
    {
      hasParenthese = true;
      sc.MoveToNextSymbol();
      pExpr = new InfixArithExpr(sc);
      assert(sc.GetCurrSymbol().type == PAR_CLOSE);
      
    }
  else if ( currSym.type == OP_MINUS )
    {
      hasNegSign = true;
      sc.MoveToNextSymbol();
      pExpr = new Term(sc);
    }
  else // numeric
    {
      pExpr = new NumLeaf(sc);
    }
}

Term::~Term()
{
  if (pExpr)
    free(pExpr);

  pExpr = NULL;
}

float Term::eval() const
{
  if (hasNegSign)
    return -(pExpr->eval());
  else
    return (pExpr->eval());
}

void Term::print() const
{
  if (hasParenthese)
    {
      std::cout << "(";
      pExpr->print();
      std::cout << ")";
    }
  else
    if (hasNegSign)
      {
	std::cout <<"-";
	pExpr->print();
      }
    else
      {
	pExpr->print();
      }
}




//---------------------------------------------------
// class 
InfixArithExpr::InfixArithExpr(Scanner& sc )
  :op(""), pTerm(NULL), pExpr(NULL) 
{
  
  pTerm = new Term(sc);
   
  if (sc.MoveToNextSymbol())
    {
      switch ( sc.GetCurrSymbol().type )
	{
	case OP_PLUS:
	  op = "+";
	  break;

	case OP_MINUS:
	  op = "-";
	  break;

	case OP_MULT:
	  op = "*";
	  break;

	case OP_DIV:
	  op = "/";
	  break;

	default:
	  break;
	}

      if (op.compare("") != 0)
	{
	  sc.MoveToNextSymbol();
	  pExpr = new InfixArithExpr(sc);
	}
    }
}

InfixArithExpr::~InfixArithExpr()
{
  if (pTerm)
    free(pTerm);
  
  if (pExpr)
    free(pExpr);

  pTerm = NULL;
  pExpr = NULL;
}


float InfixArithExpr:: eval() const 
{
  if (op.compare("") == 0)
    {
      return pTerm->eval();
    }
  else
    {
      if (op.compare("+") == 0)
	return ( pTerm->eval() + pExpr->eval() );

      if (op.compare("-") == 0)
	return ( pTerm->eval() - pExpr->eval() );

      if (op.compare("*") == 0)
	return ( pTerm->eval() * pExpr->eval() );

      if (op.compare("/") == 0)
	return ( pTerm->eval() / pExpr->eval() );

    }
}


// with parentheses
void InfixArithExpr::print() const
{
  //std::cout<<"(";
  pTerm->print();
  if (op.compare(""))
    {
      std::cout << " " << op << " ";
      pExpr->print();
    }
  //std::cout<<")";
}


   
