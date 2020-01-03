//
// Created by noam on 03/01/2020.
//

#include "Mul.h"

double Mul::calculate() {
  return this->left_exp->calculate() * this->right_exp->calculate();
}
