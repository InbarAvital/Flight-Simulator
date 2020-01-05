//
// Created by noam on 03/01/2020.
//

#include <iostream>
#include "ConditionParser.h"
#include "../expressions/Interpreter.h"

bool ConditionParser::CheckCondition() {
  // TODO: Support variables.
  double left, right;
  Interpreter *interpreter = new Interpreter();

  // Calculates values for the condition's left and right arguments.
  try {
    left = interpreter->interpret(this->left_argument)->calculate();
    right = interpreter->interpret(this->right_argument)->calculate();
  } catch (const char* e) {
    cout << e << endl;
    return false;
  }

  // Checks if the condition is satisfies according to the condition's operator.
  if (this->condition_operator == "<") {
    return left < right;
  } else if (this->condition_operator == ">") {
    return left > right;
  } else if (this->condition_operator == "<=") {
    return left <= right;
  } else if (this->condition_operator == ">=") {
    return left >= right;
  } else if (this->condition_operator == "==") {
    return left == right;
  } else if (this->condition_operator == "!=") {
    return left != right;
  } else {
    return false;
  }
}

void ConditionParser::InitCondition(vector<string> tokens, int index) {
  this->left_argument = tokens[index + 1];
  this->condition_operator = tokens[index + 2];
  this->right_argument = tokens[index + 3];
}

Command *ConditionParser::GetCommand(string name) {
  return this->commands->at(name);
}
