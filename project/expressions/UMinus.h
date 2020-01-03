//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_UMINUS_H_
#define EX3_EXPRESSIONS_UMINUS_H_

#include "UnaryOperator.h"

class UMinus : public UnaryOperator {
 public:
  explicit UMinus(Expression *e) : UnaryOperator(e) {}
  double calculate() override;
};

#endif //EX3_EXPRESSIONS_UMINUS_H_
