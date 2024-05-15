#pragma once
// Represents the games current context.
#include <unordered_map>
#include <string>

class Context {
private:
  std::unordered_map<std::string, int> contexts; 
  unsigned current_ctx;
  
public:
  
  Context() {
    this->contexts = std::unordered_map<std::string, int>();
    this->current_ctx = 0;
  }
   
  template<typename String = std::string>
  Context(std::initializer_list<String> keys = {});

  ~Context() = default;
  
  std::string print() const;
  std::unordered_map<std::string, int> get_contexts();
  int get_current_ctx();
  void push_back_context();
};
