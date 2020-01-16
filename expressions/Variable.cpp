//
// Created by noam on 03/01/2020.
//

#include "Variable.h"

double Variable::calculate() {
  return this->value;
}

Variable &Variable::operator++() {
  this->value++;
  return *this;
}

Variable &Variable::operator--() {
  this->value--;
  return *this;
}

Variable &Variable::operator+=(double v) {
  this->value += v;
  return *this;
}

Variable &Variable::operator-=(double v) {
  this->value -= v;
  return *this;
}

Variable &Variable::operator++(int) {
  this->value++;
  return *this;
}

Variable &Variable::operator--(int) {
  this->value--;
  return *this;
}
