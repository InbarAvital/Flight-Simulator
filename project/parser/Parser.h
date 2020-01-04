//
// Created by noam on 30/12/2019.
//

#ifndef EX3_PARSER_PARSER_H_
#define EX3_PARSER_PARSER_H_

#include <vector>
#include <string>
#include <map>
#include "../commands/Command.h"

using namespace std;

// The Parser is in charge of analyzing the lexical tokens
// and executing the commands in the given order.
class Parser {
 public:
  // Input: t - The lexical tokens.
  // Constructs a Parser with the given lexical tokens.
  explicit Parser(vector<string> &t): tokens(t) {}

  // Deletes the commands in the commands map.
  virtual ~Parser();

  // Input: name - The lexeme activates a specific command.
  //        command - The corresponding command.
  // Adds a command to this Parser that matches the provided lexeme.
  void AddCommand(const string &name, Command *command);

  // Analyzes the lexical tokens of this Parser and executes the commands.
  void Parse();

  // Output: The commands map of this parser.
  map<string, Command *> &GetCommands() {
    return this->commands;
  }

 private:
  vector<string> tokens;
  map<string, Command *> commands;
};

#endif //EX3_PARSER_PARSER_H_
