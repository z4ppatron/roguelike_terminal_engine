#include <Context.hpp>
#include <iostream>

Context::Context() {
  std::vector ctxs = {ContextType::NONE, ContextType::MENU, ContextType::WORLD};
  this->contexts = ctxs;
  this->current_ctx = ctxs[0];
}

std::vector<ContextType> Context::get_contexts() const {
  return this->contexts;
}

int Context::get_current_ctx() const {
  return this->current_ctx;
}

std::ostream& operator<<(std::ostream& out, const ContextType& ctxtype) {
  return out << Context::ContextTypes[ctxtype];
}

std::ostream& operator<<(std::ostream& out, const Context& ctx) {
  const std::vector<ContextType>& ctxs = ctx.get_contexts();
  out << "Contexts(";
  for (unsigned i = 0; i < ctxs.size(); i++) {
    out << ctxs[i];
    if (i == ctxs.size() - 1) {
      return out << "), Current context: " << ctx.get_current_ctx();
    }
    out << ", ";
  }
  return out << "), Current context: " << ctx.get_current_ctx();
}


