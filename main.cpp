#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "commands/PrintCommand.h"
#include "commands/SleepCommand.h"
#include "commands/IfCommand.h"
#include "commands/LoopCommand.h"
#include "commands/DefineVarCommand.h"
#include "commands/AssignToVarCommand.h"
#include "commands/OpenServerCommand.h"
#include "commands/ConnectCommand.h"

int main(int argc, char *argv[]) {
  // Tokenizes with a lexer.
  Lexer *lexer = Lexer::GetInstance();
  vector<string> tokens = lexer->Tokenize(argv[1]);
  delete lexer;

  SharedData *shared_data = new SharedData();
  Parser *parser = new Parser(tokens, shared_data);

  // Adds commands to parser.
  parser->AddCommand("Print", new PrintCommand(shared_data));
  parser->AddCommand("openDataServer", new OpenServerCommand(shared_data));
  parser->AddCommand("connectControlClient", new ConnectCommand(shared_data));
  parser->AddCommand("var", new DefineVarCommand(shared_data));
  parser->AddCommand("=", new AssignToVarCommand(shared_data));
  parser->AddCommand("Sleep", new SleepCommand(shared_data));
  parser->AddCommand("if", new IfCommand(parser));
  parser->AddCommand("while", new LoopCommand(parser));

  // Parse the tokens.
  parser->Parse();
  delete parser;

  return 0;
}
