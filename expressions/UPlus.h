//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_UPLUS_H_
#define EX3_EXPRESSIONS_UPLUS_H_

#include "UnaryOperator.h"

class UPlus : public UnaryOperator {
 public:
  explicit UPlus(Expression *e) : UnaryOperator(e) {}
  double calculate() override;
};

#endif //EX3_EXPRESSIONS_UPLUS_H_
