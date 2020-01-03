//
// Created by noam on 03/01/2020.
//

#ifndef EX3_COMMANDS_IFCOMMAND_H_
#define EX3_COMMANDS_IFCOMMAND_H_

#include "../parser/ConditionParser.h"

// An if statement with a condition.
class IfCommand : public ConditionParser {
 public:
  // Input: p - The original parser.
  // Constructs an If Command with the commands map from the original Parser.
  explicit IfCommand(Parser &p): ConditionParser(p) {}

  int Execute(vector<string> &tokens, int index) override;
};

#endif //EX3_COMMANDS_IFCOMMAND_H_
