//
// Created by noam on 03/01/2020.
//

#include "Minus.h"

double Minus::calculate() {
  return this->left_exp->calculate() - this->right_exp->calculate();
}
