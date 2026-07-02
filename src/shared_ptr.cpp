#include<iostream>
#include<memory>
#include<vector>
#include<string>

class Character {
 public:
  std::string Name;
  Character(std::string Name = "Frodo")
  : Name{Name} {
    std::cout << "Creating " << Name << '\n';
  }

  ~Character(){
    std::cout << "Deleting " << Name << '\n';
  }
};


int main(){
  // shared_ptr is a smart pointer type that is copy constructible
  auto s_ptr {std::make_shared<Character>("Gandalf")};
  auto sc_ptr {s_ptr}; // allowed
  
// the underlying resource is deleted when all its owners are deleted
  std::cout << s_ptr.use_count() << '\n'; //returns the number of owners
  std::vector<int> arr{1,2,3};
  
  // A std::shared_ptr can own an object and point at a different one 
  // It is an interesting feature where the object being shared don't necessarily have to be the one being pointed at 
  // Below is an implentation of the said notion 
  
 auto ptr {std::make_shared<Character>("MyCharacter")};
 std::shared_ptr<std::string> namePtr { ptr,&ptr->Name};
 std::cout << *namePtr;
 std::cout << namePtr.use_count();
}
