//
// Created by noam on 15/01/2020.
//

#ifndef EX3_VARIABLES_VARIABLEINFO_H_
#define EX3_VARIABLES_VARIABLEINFO_H_

#include <string>
#include <utility>

using namespace std;

class VariableInfo {
 public:
  // Input: v - This variable value.
  // Output: s - This variable's sim.
  // Constructs a Variable Info with the provided value.
  VariableInfo(float v, string s): value(v), sim(std::move(s)) {}

  // Output: This variable's value.
  double GetValue() {
    return this->value;
  }

  // Output: This variable's sim.
  string GetSim() {
    return this->sim;
  }

  // Input: v - This variable's new value.
  void SetValue(float v) {
    this->value = v;
  }

 private:
  float value;
  string sim;
};

#endif //EX3_VARIABLES_VARIABLEINFO_H_
