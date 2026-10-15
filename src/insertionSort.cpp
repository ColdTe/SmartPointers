#include<iostream>
#include<vector>

void insertionSort(std::vector<int> &array){
  for(int i{1}; i < array.size();++i){
    int key{array[i]};
    int j{i-1};
    while(j >= 0 && key < array[j]){
      array[j+1] = array[j];
      --j;
    }
    array[j+1] = key;
  }
}


int main(){
  std::vector<int> array{5,3,1,2,4};
  insertionSort(array);
  for(const auto &x : array){
    std::cout << x;
  }
}
