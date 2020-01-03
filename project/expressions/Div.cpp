//
// Created by noam on 03/01/2020.
//

#include "Div.h"

double Div::calculate() {
  if (this->right_exp->calculate() == 0) {
    throw "Invalid division";
  }
  return this->left_exp->calculate() / this->right_exp->calculate();
}
