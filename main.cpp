#include<iostream>
#include<string>
#include<memory>
#include<string_view>
#include<utility>

class Character{
  private:
    std::string m_name{};
  public:
    Character(std::string name): m_name{name}{ std::cout << "Creating Character\n";}
    std::string getName() const {
      return m_name;
    }
    ~Character(){ std::cout << "Destroying Character\n";}
};

std::string returnName(Character *str){
  return str->getName();
}

std::string Logging(std::unique_ptr<Character> c){
  return c->getName();
}

int main(){
// std::unique_ptr, copy constructor is deleted, cannot be copied!
// std::unique_ptr<Character> ptr{new Character{"hello"}}; // std::unique_ptr is a smart pointer type
  auto ptr { std::make_unique<Character>("hello\n")}; // preferred
  std::cout << returnName(ptr.get()); // get() returns a raw pointer
  auto str = Logging(std::move(ptr)); // ownership transferred
  std::cout << str;
  if(!ptr){
    std::cout << "it is empty\n"; // nullptr since ptr was moved
  }
  
  auto ptr2 {std::make_unique<Character>("new")}; // release() will release ownership but not delete the underlying resource
  Character *released {ptr2.release()};
  std::cout << released->getName() << '\n';
  std::cout << released << '\n';
  std::cout << ptr2.get() << '\n'; //nullptr
  std::cout << ptr2; //0
  
  // reset() will delete and release ownership of resource

  auto ptr3 {std::make_unique<Character>("new2")};
  ptr3.reset();
  std::cout << ptr3.get(); //nullptr

  auto ptr4 {std::make_unique<Character>("new3")};
  ptr4.reset(new Character{"new3 transferred"});
  std::cout << ptr4->getName(); //returns new3 transferred
  
  //swap
  auto ptr5 {std::make_unique<Character> ("swap1")};
  auto ptr6 {std::make_unique<Character> ("swap2")};
  ptr5.swap(ptr6);
  std::cout << ptr5->getName() << '\n'; //swap2
  std::cout << ptr6->getName() << '\n'; //swap1
  
  const auto ptr7 {std::make_unique<const Character>("hello")}; //const pointer to const Character
  std::cout << ptr7->getName();
  //ptr7.release(); //error
  
}
