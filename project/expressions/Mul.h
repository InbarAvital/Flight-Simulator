//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_MUL_H_
#define EX3_EXPRESSIONS_MUL_H_

#include "BinaryOperator.h"

class Mul : public BinaryOperator {
 public:
  Mul(Expression *le, Expression *re)
      : BinaryOperator(le, re) {}
  double calculate() override;
};

#endif //EX3_EXPRESSIONS_MUL_H_
