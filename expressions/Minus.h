//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_MINUS_H_
#define EX3_EXPRESSIONS_MINUS_H_

#include "BinaryOperator.h"

class Minus : public BinaryOperator {
 public:
  Minus(Expression *le, Expression *re)
      : BinaryOperator(le, re) {}
  double calculate() override;
};

#endif //EX3_EXPRESSIONS_MINUS_H_
