//
// Created by inbar on 12/26/2019.
//
using namespace std;
#include <iostream>
#include "Lexer.h"


/**
 * This function receives a name of a file and uses the
 * "splitAll" function to split the text in the file. -- THE LEXER
 *
 * Returns a vector of the splitted text
 */
vector<string> Lexer::Tokenize(string file_name) {
    ifstream file;
    string data;
    vector<pair<string, int>> split_by;
    // here I assign the characters that will split the text code + delete.
    split_by.push_back(pair<string, int>(" ", 1));
    split_by.push_back(pair<string, int>(")", 1));
    split_by.push_back(pair<string, int>("(", 1));
    split_by.push_back(pair<string, int>(",", 1));
    split_by.push_back(pair<string, int>("\t", 1));
    // here I assign the characters that will split the text code without deleting
    split_by.push_back(pair<string, int>("->", 0));
    split_by.push_back(pair<string, int>("<-", 0));
    split_by.push_back(pair<string, int>("{", 0));
    split_by.push_back(pair<string, int>("}", 0));
    vector<string> commands;
    file.open(file_name);
    if (!file) {
        exit(1);   // call system to stop
    }
    // goes to each line and splits it.
    while (getline (file, data)) {
        commands = AddVectors(commands, SplitAll(data, split_by));
    }
    file.close();
    return commands;
}


/*
 * Arguments:
 *          # string str = the string we want to split
 *          # string split_by = the string to split "str" by.
 *          # bool del = 1 if we want to delete the list strings, 0 if not.
 *
 * We split the "str" string every time we see the "split_by" string.
 * if del is 1, we delete the "split_by" string from str as well.
 *
 * Returns a vector of the splitted parts of the string.
 */
vector<string> Lexer::Split(string str, string split_by, bool del) {
    // true every time we find a split_by string
    bool found;
    // a string to add until we find a split_by string
    string to_add = "";
    // the splitted list we send in the end
    vector<string> splitted;
    // for loop on each char in "str"
    for(int i = 0; i < str.length(); i++) {
        found = true;
        // for loop to check if this current char is the beginning of "split_by"
        int i_copy = i;
        for(int j = 0; j < split_by.length(); j++) {
            if(str[i_copy + j] != split_by[j]) {
                found = false;
                i_copy += j;
                break;
            }
        }
        // if we find a "split_by", we add what was before the it and not yes
        // added to the list, ignore the "split_by", and continue
        if(found) {
            i += split_by.length() - 1;
            if(to_add != "")
                splitted.push_back(to_add);
            if(!del)
                splitted.push_back(split_by);
            to_add = "";
        } else {
            to_add += str[i];
            if(i == str.length() - 1) {
                splitted.push_back(to_add);
            }
        }
    }
    return splitted;
}


/*
 * Arguments: 2 vectors of pair(string and int)
 *
 * Adds the vectors and sends the updated vector
 *
 */
vector<string> Lexer::AddVectors(vector<string> a, vector<string> b) {
    vector<string> added;
    // adds the a members
    for(string st : a){
        added.push_back(st);
    }
    // adds the b members
    for(string st : b){
        added.push_back(st);
    }
    return added;
}


/**
 * Simple sub str function.
 * gets a string and two ints, and returns the string between these
 * two ints(from first to second not icluding the second).
 */
string Lexer::Sub(string str, int start, int finish) {
    string to_send = "";
    for(int i = start; i < finish; i++) {
        to_send += str[i];
    }
    return to_send;
}


/*
 * Gets a string and a vector of pairs of strings and ints and splits the string
 * using the "split" function on each one of the strings in the vector, and also
 * deletes the split_by string if the int is 1.
 *
 * This function also supports ignoring things after '//' and leaving
 * the expression after the "=" sign to be left as it is without splitting it,
 * but with deleting spaces.
 *
 * It also supports "while" and "if", functions, and prints.
 *
 */
vector<string> Lexer::SplitAll(string str, vector<pair<string, int>> split_by) {
    string final = "";
    bool have_equal = false;
    bool have_while = false;
    bool have_if = false;
    bool is_print = false;
    int begin_if_while = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        // the support for '//'
        if (str[i] == '/' && str[i + 1] == '/') {
            str = final;
            break;
        }
        final += str[i];
        // checks if there is an '=' sign
        if (str[i] == '=' || str[i + 1] == '=') {
            have_equal = true;
        }
    }
    int beginning_of_line = 0;
    while(str[beginning_of_line] == ' ') {
        beginning_of_line++;
    }
    // checks if there is a while loop
    if (str.length() > 5 && Sub(str, beginning_of_line, beginning_of_line + 5) == "while") {
        have_while = true;
        begin_if_while = 6;
    }
    // checks if there is an if
    if (str.length() > 2 && Sub(str, beginning_of_line, beginning_of_line + 2) == "if") {
        have_if = true;
        begin_if_while = 3;
    }
    // checks if there is a print
    if (str.length() > 5 && Sub(str, beginning_of_line, beginning_of_line + 5) == "Print") {
        is_print = true;
    }
    str = Sub(str, beginning_of_line, str.length());
    // the list we will eventually return
    vector<string> after_split;
    // if this is a line with "=" sign
    if (have_equal && !have_while && !have_if) {
        string before_equal = "";
        string after_equal = "";
        bool passed_equal = false;
        // this loop splits the string to - before the
        // equal sign(including), and after it.
        for (int i = 0; i < str.length(); i++) {
            if (passed_equal) {
                after_equal += str[i];
            } else {
                before_equal += str[i];
            }
            if (str[i] == '=') {
                passed_equal = true;
            }
        }
        // splits the part before the equal part normally
        vector<string> second = Split(before_equal, " ", 1);
        for (string a : second) {
            after_split = AddVectors(after_split, Split(a, "\t", 1));
        }
        // deletes spaces from after the equal
        after_split.push_back(DeleteStr(after_equal, " "));
    } else if (have_if || have_while) { // if it is a if or a while loop
        string to_add = "";
        after_split.push_back(Sub(str, 0, begin_if_while - 1));
        for(int i = begin_if_while; i < str.length() - 1; i++) {
            if (Sub(str, i, i + 2)  == ">=" || Sub(str, i, i + 2) == "<="
                || Sub(str, i, i + 2) == "==" || Sub(str, i, i + 2) == "!=") {
                after_split.push_back(DeleteStr(to_add, " "));
                after_split.push_back(Sub(str, i, i + 2));
                to_add = "";
                i += 2;
            } else if (str[i]  == '>' || str[i] == '<') {
                after_split.push_back(DeleteStr(to_add, " "));
                after_split.push_back(Sub(str, i, i+1));
                to_add = "";
                i += 1;
            }
            if(i < str.length() - 1) {
                to_add+=str[i];
            }
        }
        after_split.push_back(DeleteStr(to_add, " "));
        after_split.push_back("{");
    } else if (is_print) { // if it is a print function
        after_split.push_back("Print");
        string second = Sub(str, 6, str.length() - 1);
        if(second[0] == '"') // if it is a normal print
            after_split.push_back(second);
        else { // if this is a print of an expression
            after_split.push_back(DeleteStr(second, " "));
        }
    } else { // if it is not a print and not equal sign
        after_split.push_back(str);
        vector<string> end;
        // goes on each split we want to make
        for (pair<string, int> spt : split_by) {
            // this will include the splits of this current
            // split_by and will eventually be updated to "after_split"
            vector<string> after_split2;
            // for each string in "after_split"
            for (string prt : after_split) {
                vector<string> during_split;
                // spliting
                during_split = Split(prt, spt.first, spt.second);
                // adding this part's split to the final split
                after_split2 = AddVectors(after_split2, during_split);
            }
            after_split = after_split2;
        }
    }
    return after_split;
}


/**
 * Deletes every del appearance in str.
 */
string Lexer::DeleteStr(string str, string del) {
    string after_del = "";
    for (int i = 0; i < str.length() - del.length() + 1; i++) {
        if (Sub(str, i, i + del.length()) != del) {
            after_del += str[i];
        }
        else {
            i += del.length() - 1;
        }
    }
    after_del += Sub(str, str.length() - del.length() + 1, str.length());
    return after_del;
}
