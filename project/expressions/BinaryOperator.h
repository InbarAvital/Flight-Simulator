//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_BINARYOPERATOR_H_
#define EX3_EXPRESSIONS_BINARYOPERATOR_H_

#include "Expression.h"

class BinaryOperator : public Expression {
 public:
  BinaryOperator(Expression *le, Expression *re)
      : left_exp(le), right_exp(re) {}
  virtual ~BinaryOperator();

 protected:
  Expression *left_exp;
  Expression *right_exp;
};

#endif //EX3_EXPRESSIONS_BINARYOPERATOR_H_
