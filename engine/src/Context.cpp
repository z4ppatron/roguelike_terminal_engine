#pragma once

#include <Context.hpp>

template<typename String>
Context::Context(std::initializer_list<String> keys) {
  unsigned i;
  for (auto const& key : keys) {
    this->contexts[key] = i;
    i++;
  }
  this->current_ctx = 0;
}


std::string Context::print() const {
  std::string out = "";
  return out;
}

std::unordered_map<std::string, int> Context::get_contexts() {
  return this->contexts;
}
