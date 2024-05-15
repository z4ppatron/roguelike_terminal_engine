#pragma once
// Represents the games current context.
#include <vector>
#include <string>

enum class ContextType {

};

class Context {
private:
  std::vector<ContextType> contexts; 
  unsigned current_ctx;
  
public:
  
  Context();
   
  Context(std::initializer_list<ContextType> = {});

  ~Context();
  
  std::string print() const;
  std::vector<ContextType> get_contexts();
  int get_current_ctx();
  void push_back_context();
};
