#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> character;

void printChar(int index, string chosen){
  if(chosen.length() >= L){
    int vow = 0;
    int conso = 0;
    
    for(int i = 0; i < chosen.length(); i++){
      if(chosen[i] == 'a' 
      || chosen[i] == 'e'
      || chosen[i] == 'i'
      || chosen[i] == 'o'
      || chosen[i] == 'u'){
        vow++;
      }
      else{
        conso++;
      }
    }
    
    if(vow >= 1 && conso >= 2){
      cout << chosen << '\n';
    }
    
    return;
  }
  else{
    for(int i = index; i < character.size() - (L-chosen.length()) + 1; i++){
      string str = chosen + character[i];
      printChar(i+1, str);
    }
  }
}

int main() 
{
    cin >> L >> C;
    for(int i = 0; i < C; i++){
      char temp;
      cin >> temp;
      character.push_back(temp);
    }
    
    sort(character.begin(), character.end());
    
    printChar(0, "");
    
    return 0;
}