#include<iostream>
#include<vector>


int binarySearch(const int target, const std::vector<int> &array){
  if(array.empty())
    return -1;
  std::size_t i{};
  int j{static_cast<int>(array.size() - 1)};
  std::size_t mid{};
  while(i<=j){
    mid = i + (j-i)/2;
    if(target > array[mid])
      i = mid + 1;
    else if(target == array[mid])
      return mid;
    else
      j = mid-1;
  }
  return -1;
}

int main(){
  const std::vector<int> array{1,2,3,4,5};
  std::cout << binarySearch(4,array);
}
