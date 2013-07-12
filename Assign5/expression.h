
/*
 * 6.088 IAP 2010  
 * Assignment #5: Inheritance and Polymorphism
 * 
 * Expression.h
 * Header file for the abstract base class Expression
 */

#ifndef _EXPRESSION_
#define _EXPRESSION_

#include <string>

class Scanner;
/*
 * Expression
 */
class Expression {

 public: 
  //dtor
  virtual ~Expression(){}
  
  // Returns the result of evaluating this expression.
  virtual float eval() const = 0;

  // Prints the expression. DO NOT evaluate before printing.
  virtual void print() const = 0;  
};


// for constant node
class NumLeaf : public Expression {
 public:
  //ctor
  NumLeaf(Scanner& sc);

  //dtor
  ~NumLeaf();

  virtual void print( ) const;

  virtual float eval( ) const;

 private:
  float m_val;
};


class Term : public Expression {
 public:
  Term (Scanner& sc);
  ~Term();

  virtual float eval() const;
  virtual void print() const;

 private:
  bool hasNegSign;  // "-" Term
  bool hasParenthese; // "(" InfixArithExpression ")"
  Expression  *pExpr;
};

class InfixArithExpr : public Expression {
 public:
  InfixArithExpr(Scanner& sc);

  ~InfixArithExpr();

  virtual float eval() const;
	
  virtual void print() const;

 private:
  std::string op;
  Expression *pTerm;
  Expression *pExpr;
};

#endif  // EXPRESSION
