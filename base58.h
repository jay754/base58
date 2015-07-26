#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

const char* chars = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
int base = strlen(chars);

const char* reverse(const char *str);
int ord(char letter);
std::pair<int, int> divmod(int x, int y);
void b58Encode(const char* v);
