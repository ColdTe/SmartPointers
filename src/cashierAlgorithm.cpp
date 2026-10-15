#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

std::map<int,int> cashierAlgorithm(int number){
  std::map<int,int> coin_map{};
  std::vector<int> coin_vec{15,10,5,1};
  for(int i{}; i < coin_vec.size();++i){
    while(number >= coin_vec[i]){
      coin_map[coin_vec[i]] = number / coin_vec[i];
      number %= coin_vec[i];
    }
  }
  return coin_map;
}


int main(){
  std::map<int,int> coin_map = cashierAlgorithm(67);
  for(const auto &[x,y] : coin_map){
    std::cout << x << " : " << y;
    std::cout << std::endl;
  }
}
