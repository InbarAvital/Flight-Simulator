//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_UNARYOPERATOR_H_
#define EX3_EXPRESSIONS_UNARYOPERATOR_H_

#include "Expression.h"

class UnaryOperator : public Expression {
 public:
  explicit UnaryOperator(Expression *e) : exp(e) {}
  virtual ~UnaryOperator();

 protected:
  Expression *exp;
};

#endif //EX3_EXPRESSIONS_UNARYOPERATOR_H_
