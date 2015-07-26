/*

Base58 Encoding and Decoding

*/

#include "base58.h"

void removeCharsFromString( string &str, char* charsToRemove ) {
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

int ord(char letter){
  return static_cast<int>(letter); //this is ord in python which will convert the letter into a ascii integer
}

std::pair<int, int> divmod(int x, int y){
  int quotient = x / y;
  int remain = x % y;

  return std::make_pair(quotient, remain);
}

void b58Encode(const char* v){
  int p = 1;
  long acc = 0;
  long mod;
  std::string final = "";

  const char *v_reverse = reverse(v);

  for(int i=0;i<strlen(v);i++)
  {
    acc += p*ord(v_reverse[i]);
    p = p << 8;
  }

  while(acc > 0){
    acc = divmod(acc, 58).first;
    mod = divmod(acc, 58).second;

    final += chars[mod];
  }
}

int main(){
  b58Encode("bob");
  return 0;

}