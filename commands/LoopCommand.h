//
// Created by noam on 03/01/2020.
//

#ifndef EX3_COMMANDS_LOOPCOMMAND_H_
#define EX3_COMMANDS_LOOPCOMMAND_H_

#include "../parser/ConditionParser.h"

// A loop that continues executing as long as its condition is satisfied.
class LoopCommand : public ConditionParser {
 public:
  // Input: p - The original parser.
  // Constructs a Loop Command with the commands map from the original Parser.
  explicit LoopCommand(Parser *p): ConditionParser(p) {}

  int Execute(vector<string> &tokens, int index) override;
};

#endif //EX3_COMMANDS_LOOPCOMMAND_H_
