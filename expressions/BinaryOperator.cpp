//
// Created by noam on 03/01/2020.
//

#include "BinaryOperator.h"

BinaryOperator::~BinaryOperator() {
  delete this->left_exp;
  delete this->right_exp;
}
