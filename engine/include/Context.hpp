#pragma once
// Represents the games current context.

#include <string_view>
#include <vector>

enum ContextType { NONE = 0, MENU = 1, WORLD = 2 };

class Context {
private:
  std::vector<ContextType> contexts;
  ContextType current_ctx;

public:
  static constexpr std::string_view ContextTypes[] = {"None", "Menu", "World"};

  Context();
  ~Context() = default;

  Context(std::initializer_list<ContextType>);

  std::vector<ContextType> get_contexts() const;
  int get_current_ctx() const;
};

std::ostream &operator<<(std::ostream &out, const ContextType &ctxtype);
std::ostream &operator<<(std::ostream &out, const Context &ctx);
