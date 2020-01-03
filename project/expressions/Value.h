//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_VALUE_H_
#define EX3_EXPRESSIONS_VALUE_H_

#include "Expression.h"

class Value : public Expression {
 public:
  explicit Value(double v): value(v) {}
  double calculate() override;
  virtual ~Value() = default;

 private:
  double value;
};

#endif //EX3_EXPRESSIONS_VALUE_H_
