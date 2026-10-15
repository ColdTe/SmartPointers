#include<iostream>
#include<vector>

template<typename T>
int linearSearch(const T target,const std::vector<T> &array){
  for(std::size_t i{}; i < array.size(); ++i){
    if(array[i] == target){
      return static_cast<int>(i);
    }
  }
  return -1;
}

int main(){
  std::vector<int> array{1,2,3,4,5};
  std::cout << linearSearch<int>(4,array);
}
