/*

Base58 Encoding and Decoding

*/

#include "base58.h"

const char* chars = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
int base = strlen(chars);

int index(const char* string, char checkChar)
{
  for(int i=0;i<strlen(string);i++){
    if(checkChar == string[i]){
      return i;
    }
    else if(checkChar != string[i]){
      NULL;
    }
  }

  return 0;
}

void removeCharsFromString( std::string &str, char* charsToRemove )
{
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}

const char* reverse(const char *str)
{
   static int i=0;
   static char rev[255];
   if(*str)
   {
      reverse(str+1);
      rev[i++] = *str;
   }

  return rev;
}

int ord(char letter)
{
  return static_cast<int>(letter); //this is ord in python which will convert the letter into a ascii integer
}

std::pair<int, int> divmod(int x, int y)
{
  int quotient = x / y;
  int remain = x % y;

  return std::make_pair(quotient, remain);
}

void b58Encode(const char* v)
{
  int p = 1;
  int acc = 0;
  int mod;
  std::string final = "";

  const char *v_reverse = reverse(v);

  for(int i=0;i<strlen(v);i++)
  {
    acc += p*ord(v_reverse[i]);
    p = p << 8;
  }

  while(acc > 0){
    int acc2 = acc;
    acc = divmod(acc, 58).first;
    mod = divmod(acc2, 58).second;

    final += chars[mod];
  }
}

void b58Decode(const char* v)
{
  int p = 1;
  int acc = 0;
  int mod;
  const char* v_reverse = reverse(v);
  std::vector<int> result;

  for(int i=0;i<strlen(v);i++){
    acc += p * index(chars, v_reverse[i]);
    p *= 58;
  }

  while(acc > 0){
    int acc2 = acc;
    acc = divmod(acc, 256).first;
    mod = divmod(acc2, 256).second;

    result.push_back(mod);
  }
}

int main()
{
  b58Encode("bob");
  b58Decode("bob");
  return 0;
}
