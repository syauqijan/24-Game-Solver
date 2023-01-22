#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

int convertString(string s);

string convertOp(int op);

float operation(float a, float b, int op);

void printSolution(vector<string> v);

bool isDuplicate(vector<string> v, string s);

bool checkInput(string s);

vector<vector<int>> permutation(vector<int> &nums);

void saveFile(vector<string> solution, string a, string b, string c, string d);

#endif
