//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_EXPRESSION_H_
#define EX3_EXPRESSIONS_EXPRESSION_H_

using namespace std;

// Mathematical expression.
class Expression {
 public:
  virtual double calculate() = 0;
  virtual ~Expression() = default;
};

#endif //EX3_EXPRESSIONS_EXPRESSION_H_
