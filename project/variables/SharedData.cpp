//
// Created by noam on 15/01/2020.
//

#include "SharedData.h"

void SharedData::AddVariable(const string& name, float value, const string& sim, const string& binding_direction) {
  // Adds the variable to the symbol table.
  this->symbol_table->Add(name, new VariableInfo(value, sim));

  // Adds the variable to the correct binding vector.
  if (binding_direction == "->") {
    this->right_binding_variables.emplace_back(name, sim);
  } else if (binding_direction == "<-") {
    this->left_binding_variables.emplace_back(name, sim);
  }

  // Adds the variable to the interpreter.
  this->interpreter->setVariables(name + "=" + to_string(value));
}

void SharedData::UpdateVariable(const string& name, float value) {
  // Updates the value in the symbol table.
  this->symbol_table->get(name)->SetValue(value);

  // Tells The client to update the value in the simulator if the variable has right binding.
  VariableInfo *variable_info = this->varRightBinding(name);
  if (variable_info != nullptr) {
    this->client_outgoing_messages.push("set " + variable_info->GetSim() + " " + to_string(value) + "\n");
  }

  // Updates the variable's value in the interpreter.
  this->interpreter->setVariables(name + "=" + to_string(value));
}

VariableInfo *SharedData::varRightBinding(const string& variable) {
  return this->symbol_table->get(variable);
}

VariableInfo *SharedData::simLeftBinding(const string& sim) {
  // Checks if this sim is in the left binding vector.
  for (const auto& var : this->left_binding_variables) {
    if (var.second == sim) {
      return this->symbol_table->get(var.first);
    }
  }
  return nullptr;
}

SharedData::~SharedData() {
  delete this->symbol_table;
  delete this->interpreter;
}

bool SharedData::VariableExists(const string &name) {
  return this->symbol_table->Exists(name);
}
