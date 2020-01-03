//
// Created by noam on 03/01/2020.
//

#include "Plus.h"

double Plus::calculate() {
  return this->left_exp->calculate() + this->right_exp->calculate();
}
