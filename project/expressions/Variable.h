//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_VARIABLE_H_
#define EX3_EXPRESSIONS_VARIABLE_H_

#include <string>
#include "Expression.h"

class Variable : public Expression {
 public:
  Variable(string n, double v): name(std::move(n)), value(v) {}
  double calculate() override;
  Variable &operator++();
  Variable &operator--();
  Variable &operator+=(double v);
  Variable &operator-=(double v);
  Variable &operator++(int);
  Variable &operator--(int);
  virtual ~Variable() = default;

 private:
  string name;
  double value;
};

#endif //EX3_EXPRESSIONS_VARIABLE_H_
