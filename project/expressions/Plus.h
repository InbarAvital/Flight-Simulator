//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_PLUS_H_
#define EX3_EXPRESSIONS_PLUS_H_

#include "BinaryOperator.h"

class Plus : public BinaryOperator {
 public:
  Plus(Expression *le, Expression *re)
      : BinaryOperator(le, re) {}
  double calculate() override;
};

#endif //EX3_EXPRESSIONS_PLUS_H_
