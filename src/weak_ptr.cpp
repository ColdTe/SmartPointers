#include<iostream>
#include<memory>
#include<array>
#include<type_traits>

int main(){
  auto sharedPtr { std::make_shared<int>(42)};
  auto copyPtr { sharedPtr };
  std::weak_ptr<int> weakPtr { sharedPtr };

  if(!weakPtr.expired())
    std::cout << "not expired";
  sharedPtr.reset();
  if(weakPtr.expired())
    std::cout << "expired";

  sharedPtr = copyPtr;
  std::shared_ptr LockedPtr { weakPtr.lock() };
  std::cout << "The number is " << *LockedPtr;

}
