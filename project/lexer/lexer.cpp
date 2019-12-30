//
// Created by inbar on 12/26/2019.
//
#include <iostream>
#include "lexer.h"
/**
 * This function receives a name of a file and uses the
 * "splitAll" function to split the text in the file. -- THE LEXER
 *
 * Returns a vector of the splitted text
 */
vector<string> lexer(string file_name) {
    ifstream file;
    string data;
    vector<string> split_by;
    // here I assign the characters that will split the text code.
    split_by.push_back(" ");
    split_by.push_back(")");
    split_by.push_back("(");
    split_by.push_back(",");
    vector<string> commands;
    file.open(file_name);
    if (!file) {
        exit(1);   // call system to stop
    }
    // goes to each line and splits it.
    while (getline (file, data)) {
        commands = addVectors(commands, splitAll(data, split_by));
    }
    file.close();
    return commands;
}
using namespace std;
/*
 * Arguments:
 *          # string str = the string we want to split
 *          # string split_by = the string to split "str" by.
 *
 * We split the "str" string every time we see the "split_by" string and
 * delete the "split_by" string from str as well.
 *
 * Returns a vector of the splitted parts of the string.
 */
vector<string> split(string str, string split_by) {
    // true every time we find a split_by string
    bool found;
    // a string to add until we find a split_by string
    string to_add;
    // the splitted list we send in the end
    vector<string> splitted;
    // for loop on each char in "str"
    for(int i = 0; i < str.length(); i++) {
        found = true;
        // for loop to check if this current char is the beginning of "split_by"
        for(int j = 0; j < split_by.length(); j++) {
            if(str[i + j] != split_by[j]) {
                found = false;
                i += j;
                break;
            }
        }
        // if we find a "split_by", we add what was before the it and not yes
        // added to the list, ignore the "split_by", and continue
        if(found) {
            i += split_by.length() - 1 ;
            if(to_add != "")
                splitted.push_back(to_add);
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
 * Arguments: 2 vectors of strings
 *
 * Adds the vectors and sends the updated vector
 *
 */
vector<string> addVectors(vector<string> a, vector<string> b) {
    vector<string> added;
    // adds the a members
    for(string str : a){
        added.push_back(str);
    }
    // adds the b members
    for(string str : b){
        added.push_back(str);
    }
    return added;
}

/*
 * Gets a string and a vector of strings and splits the string
 * using the "split" function on each one of the strings in the vector.
 *
 * This function also supports ignoring things after '//' and leaving
 * the expression after the "=" sign to be left as it is without splitting it,
 * but with deleting spaces.
 *
 */
vector<string> splitAll(string str, vector<string> split_by) {
    string final = "";
    bool have_equal = false;
    for(int i = 0; i<str.length()-1; i++) {
        // the support for '//'
        if(str[i] == '/' && str[i+1] == '/'){
            str = final;
            break;
        }
        final+=str[i];
        // checks if there is an '=' sign
        if(str[i] == '=' || str[i+1] == '='){
            have_equal = true;
        }
    }
    // the list we will eventually return
    vector<string> after_split;
    // if this is a line with "=" sign
    if(have_equal) {
        string before_equal = "";
        string after_equal = "";
        bool passed_equal = false;
        // this loop splits the string to - before the
        // equal sign(including), and after it.
        for(int i = 0; i < str.length(); i++) {
            if(passed_equal) {
                after_equal+=str[i];
            }
            else {
                before_equal+=str[i];
            }
            if(str[i] == '=') {
                passed_equal = true;
            }
        }
        // splits the part before the equal part normally
        after_split = split(before_equal, " ");
        // deletes spaces from after the equal
        string without_spaces = "";
        for(int i = 0; i < after_equal.length(); i++) {
            if(after_equal[i] != ' ') {
                without_spaces+=after_equal[i];
            }
        }
        after_split.push_back(without_spaces);
    }
    else {
        after_split.push_back(str);
        vector<string> end;
        // goes on each split we want to make
        for(string spt : split_by) {
            // this will include the splits of this current
            // split_by and will eventually be updated to "after_split"
            vector<string> after_split2;
            // for each string in "after_split"
            for(string prt : after_split) {
                vector<string> during_split;
                // spliting
                during_split = split(prt, spt);
                // adding this part's split to the final split
                after_split2 = addVectors(after_split2, during_split);
            }
            after_split = after_split2;
        }
    }
    return after_split;
}