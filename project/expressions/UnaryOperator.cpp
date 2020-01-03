//
// Created by noam on 03/01/2020.
//

#include "UnaryOperator.h"

UnaryOperator::~UnaryOperator() {
  delete this->exp;
}
