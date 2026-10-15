#include<iostream>
#include<vector>
#include<string>
#include<string_view>
#include<string>

std::vector<int> stringMatcher(const std::string_view pattern, const std::string_view string){
  std::vector<int> shifts{};
  if(pattern.length() > string.length())
    return std::vector<int> {};
  for(int s{}; s <= (string.length() - pattern.length());++s){
    int j{};
    while(j < pattern.length() && string[s+j] == pattern[j]){
      ++j;
    }
    if(pattern.length() == j)
      shifts.push_back(s);
  }
  return shifts;
}


int main(){
  const std::string string{"abcaa"};
  const std::string pattern{"abc"};
  std::vector<int> shifts{stringMatcher(pattern,string)};
  for(const auto &x : shifts){
    std::cout << x;
  }
}
