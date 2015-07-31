#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>

int index(const char* string, char checkChar);
void removeCharsFromString( std::string &str, char* charsToRemove );
const char* reverse(const char *str);
int ord(char letter);
std::pair<int, int> divmod(int x, int y);
void b58Encode(const char* v);
void b58Decode(const char* v);
