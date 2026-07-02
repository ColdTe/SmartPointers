#include<iostream>
#include<filesystem>
#include<sstream>
#include<fstream>
#include<string>

class Reader{
  private:
    std::stringstream ss{};
    std::ifstream file{};
    std::string output{};
  public:
    Reader(std::filesystem::path vertexPath){
      file.open(vertexPath,std::ios::in);
      ss << file.rdbuf();
      output = ss.str();
    }
    std::string_view getOutput(){
      return output;
    }
};


int main(){
  std::filesystem::path path = "./vertex.vert";
  Reader r{path};
  std::cout << r.getOutput();
}
