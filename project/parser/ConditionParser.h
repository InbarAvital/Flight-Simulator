//
// Created by noam on 03/01/2020.
//

#ifndef EX3_PARSER_CONDITIONPARSER_H_
#define EX3_PARSER_CONDITIONPARSER_H_

#include "../commands/Command.h"
#include "Parser.h"

// The Condition Parser is in charge of analyzing the lexical tokens
// and executing the commands in the given order when a condition
// is satisfies.
class ConditionParser : public Command {
 public:
  // Input: p - The original parser.
  // Constructs a ConditionParser with the commands map from the original Parser.
  explicit ConditionParser(Parser *p): commands(p->GetCommands()) {}

  virtual ~ConditionParser() = default;

 protected:
  // Output: whether the condition is satisfied or not.
  bool CheckCondition();

  // Initializes the condition's arguments and operator.
  void InitCondition(vector<string> tokens, int index);

  // Input: name - the key of some command from the commands map.
  // Output: The matching command from the map.
  Command *GetCommand(string name);

 private:
  map<string, Command *> commands;
  string left_argument;
  string right_argument;
  string condition_operator;
};

#endif //EX3_PARSER_CONDITIONPARSER_H_
