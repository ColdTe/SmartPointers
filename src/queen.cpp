#include<iostream>
#include<random>
#include<array>

void print(const std::array<std::array<int,5>,5> &arr,int n){
for(int i{};i < n;++i){
    for(int j{};j < n;++j){
      std::cout << arr[i][j];
    }
    std::cout << std::endl;
  }
}

void assignRandom(std::array<std::array<int,5>,5> &arr,int n){
  std::random_device rd;
  std::mt19937 gen(rd());
  for(int i{}; i < n;++i){
    for(int j{}; j < n;++j){
      int y = gen() % 2;
      arr[i][j] = y;
    }
  }
}

void clearRows(std::array<std::array<int,5>,5> &arr,int n){
  for(int i{}; i < n;++i){
    for(int j{};j < n - 1;++j){
      for(int k{j+1};k < n;++k){
        if(arr[i][j] & arr[i][k])
          arr[i][k] = 0;
      }
    }
  }
}

void clearColumns(std::array<std::array<int,5>,5> &arr,int n){
  for(int j{};j<n;++j){
    for(int i{};i<n-1;++i){
      for(int k{i+1};k<n;++k){
        if(arr[i][j] & arr[k][j])
          arr[k][j] = 0;
      }
    }
  }
}


int main(){
  std::array<std::array<int,5>,5> x{};
  assignRandom(x,5);
  print(x,5);
  std::cout << std::endl;
  std::cout << "Cleared Rows\n";
  clearRows(x,5);
  print(x,5);
  std::cout << std::endl;
  std::cout << "Cleared Columns\n";
  clearColumns(x,5);
  print(x,5);
}
