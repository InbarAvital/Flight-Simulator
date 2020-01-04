//
// Created by noam on 27/12/2019.
//

#include <thread>
#include <iostream>
#include "SleepCommand.h"
#include "../expressions/Interpreter.h"

SleepCommand *SleepCommand::instance = nullptr;

SleepCommand *SleepCommand::GetInstance() {
  if (SleepCommand::instance == nullptr) {
    SleepCommand::instance = new SleepCommand();
  }
  return SleepCommand::instance;
}

int SleepCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Support variables.
  string parameter = tokens[index + 1];
  int milliseconds;
  Interpreter *interpreter = new Interpreter();
  try {
    milliseconds = (int) interpreter->interpret(parameter)->calculate();
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
  } catch (const char* e) {
    cout << e << endl;
  }
  return 2;
}

SleepCommand::~SleepCommand() {
  SleepCommand::instance = nullptr;
}
