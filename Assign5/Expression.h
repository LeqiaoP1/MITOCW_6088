
/*
 * 6.088 IAP 2010  
 * Assignment #5: Inheritance and Polymorphism
 * 
 * Expression.h
 * Header file for the abstract base class Expression
 */

#ifndef EXPRESSION
#define EXPRESSION

#include <string>

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
  NumLeaf(std::string input);

  //dtor
  ~NumLeaf();

  virtual void print( ) const;

  virtual float eval( ) const;

 private:
  float m_val;
};



class InfixArithExpr : public Expression {
 public:
  InfixArithExpr( std::string input );

  virtual float eval() const;
	
  virtual void print() const;

 private:
  std::string op;
  Expression	*lhs, *rhs;
};

#endif  // EXPRESSION
