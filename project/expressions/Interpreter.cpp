//
// Created by noam on 03/01/2020.
//

#include <regex>
#include "Interpreter.h"
#include "Value.h"
#include "Variable.h"
#include "UPlus.h"
#include "UMinus.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"

list<string> Interpreter::Split(string str, char c) {
  list<string> tokens = list<string>();
  std::size_t found = str.find_first_of(c);

  while (found != std::string::npos) {
    tokens.push_back(str.substr(0, found));
    str = str.substr(found + 1);
    found = str.find_first_of(c);
  }
  if (!str.empty()) {
    tokens.push_back(str);
  }
  return tokens;
}

void Interpreter::setVariables(const string& str) {
  for (const auto& token : this->Split(str, ';')) {
    if (!regex_match(token, regex(R"(^[a-zA-z_]\w*=\-?\d+(\.\d+)?$)"))) {
      throw "Invalid variable initialization";
    }
    list<string> varInfo = this->Split(token, '=');
    string name = varInfo.front();
    double value = std::stod(varInfo.back());

    this->variables[name] = value;
  }
}

Expression *Interpreter::interpret(string str) {
  return CalcExp(ReadTokens(ToTokens(std::move(str))));
}

list<string> Interpreter::ToTokens(string str) {
  list<string> tokens = list<string>();

  string read;
  char pre_char = -1;
  bool flagOp = false;
  bool flagStart = true;
  while (!str.empty()) {
    if (StartsWithNumber(str) && (flagOp || flagStart)) {
      flagOp = false;
      read = ReadNumber(str);
    } else if (StartsWithVariable(str)) {
      flagOp = false;
      read = ReadVariable(str);
    } else if (StartsWithOperator(str)) {
      flagOp = true;
      read = ReadOperator(str, pre_char);
      tokens.push_back(read);
      pre_char = str[0];
      str = str.substr(1);
      continue;
    } else if (str[0] == '(') {
      flagOp = true;
      read = "(";
    } else if (str[0] == ')') {
      flagOp = true;
      read = ")";
    }
    tokens.push_back(read);
    pre_char = str[read.length() - 1];
    str = str.substr(read.length());

    flagStart = false;
  }
  return tokens;
}

int Interpreter::GetPrecedence(char op) {
  switch (op) {
    case '-':
      return 1;
    case '+':
      return 1;
    case '*':
      return 2;
    case '/':
      return 2;
    default:
      throw "Invalid input";
  }
}

deque<string> Interpreter::ReadTokens(const list<string>& tokens) {
  deque<string> output = deque<string>();
  stack<string> operators = stack<string>();
  stack<string> to_push = stack<string>();
  stack<int> parent_stack = stack<int>();
  int parent_count = 0;

  for (const auto& token : tokens) {
    if (IsNumber(token) || IsVariable(token)) {
      output.push_back(token);
    } else if (IsOperator(token)) {
      if (token == "+u" || token == "-u") {
        to_push.push(token);
        parent_stack.push(parent_count);
        continue;
      }
      while (!operators.empty() && operators.top() != "(" &&
          GetPrecedence(operators.top()[0]) >= GetPrecedence(token[0])) {
        output.push_back(operators.top());
        operators.pop();
      }
      operators.push(token);
    } else if (token == "(") {
      parent_count++;
      operators.push(token);
    } else if (token == ")") {
      parent_count--;
      while (!operators.empty() && operators.top() != "(") {
        output.push_back(operators.top());
        operators.pop();
      }
      if (operators.empty()) {
        throw "Invalid input";
      }
      operators.pop();
      if (!parent_stack.empty() && parent_count == parent_stack.top()) {
        output.push_back(to_push.top());
        to_push.pop();
        parent_stack.pop();
      }
    } else {
      throw "Invalid input";
    }
  }
  while (!operators.empty()) {
    if (operators.top() == "(") {
      throw "Invalid input";
    }
    output.push_back(operators.top());
    operators.pop();
  }
  return output;
}

Expression *Interpreter::CalcExp(const deque<string>& output) {
  stack<Expression *> exp_stack = stack<Expression *>();
  Expression *exp = nullptr;

  for (auto token : output) {
    if (IsNumber(token)) {
      exp_stack.push(new Value(std::stod(token)));
    } else if (IsVariable(token)) {
      exp_stack.push(new Variable(token, this->variables[token]));
    } else if (IsOperator(token)) {
      if (token == "+u") {
        exp = exp_stack.top();
        exp_stack.pop();
        exp_stack.push(new UPlus(exp));
      } else if (token == "-u") {
        exp = exp_stack.top();
        exp_stack.pop();
        exp_stack.push(new UMinus(exp));
      } else {
        Expression *right_exp = exp_stack.top();
        exp_stack.pop();
        Expression *left_exp = exp_stack.top();
        exp_stack.pop();
        switch (token[0]) {
          case '+':
            exp_stack.push(new Plus(left_exp, right_exp));
            break;
          case '-':
            exp_stack.push(new Minus(left_exp, right_exp));
            break;
          case '*':
            exp_stack.push(new Mul(left_exp, right_exp));
            break;
          case '/':
            exp_stack.push(new Div(left_exp, right_exp));
            break;
          default:
            throw "Invalid input";
        }
      }
    } else {
      throw "Invalid input";
    }
  }
  return exp_stack.top();
}

bool Interpreter::IsNumber(const string& str) {
  return regex_match(str, regex(R"(^\-?\d+(\.\d+)?$)"));
}

bool Interpreter::IsOperator(const string &str) {
  return regex_match(str, regex(R"(^[\+\-\*\/]$)")) || str == "+u" || str == "-u";
}

bool Interpreter::IsVariable(const string& str) {
  return regex_match(str, regex(R"(^[a-zA-z_]\w*$)"));
}

bool Interpreter::StartsWithNumber(const string& str) {
  return regex_match(str, regex(R"(^\-?\d+(\.\d+)?.*)"));
}

bool Interpreter::StartsWithOperator(const string &str) {
  return regex_match(str, regex(R"(^[\+\-\*\/].*)"));
}

bool Interpreter::StartsWithVariable(const string& str) {
  return regex_match(str, regex(R"(^[a-zA-z_]\w*.*)"));
}

string Interpreter::ReadNumber(const string& str) {
  int i = 0;
  if (str[i] == '-') {
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    i++;
  }
  if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9') {
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    i++;
  }
  return str.substr(0, i);
}

string Interpreter::ReadVariable(const string& str) {
  int i = 1;
  while (str[i] == '_' || (str[i] >= 'a' && str[i] <= 'z') ||
      (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
    i++;
  }
  string var = str.substr(0, i);
  if (this->variables.count(var) != 1) {
    throw "Invalid input";
  }
  return var;
}

string Interpreter::ReadOperator(const string& str, char pre_char) {
  switch (str[0]) {
    case '+':
      if (str[1] == '(' && (pre_char == -1 || pre_char == '(')) {
        return "+u";
      }
      return "+";
    case '-':
      if (str[1] == '(' && (pre_char == -1 || pre_char == '(')) {
        return "-u";
      }
      return "-";
    case '*':return "*";
    case '/':return "/";
    default:throw "Invalid input";
  }
}