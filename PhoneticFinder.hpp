#include <iostream>
#include <vector>
#include <cstring>
#include <exception>
using namespace std;

namespace phonetic
{
string find(string, string);
bool isMatch(string toSearch, string toFind);
} // namespace phonetic

size_t split(const string &txt, vector<string> &strs, char ch);
string toLowerCase(string word);