#include "Header.h"

// These two functions are called when parsing fails.
void yyerror(char *msg) {
  fprintf(stderr, "%s\tlast token: %s\n", msg, yytext);
  return;
}

void yyerror(const std::string &msg) {
  fprintf(stderr, "%s\tlast token: %s\n", msg.c_str(), yytext);
  return;
}

std::string get_op_string(int op) {
  switch (op) {
    case EQV:
      return "<->";
      //		case LIMP: return "<-";
    case RIMP:
      return "->";
    case EQL:
      return "==";
    case UNEQL:
      return "!=";
    default:
      return std::string(1, char(op));
  }
  return "";
}

void save_graph(ExprAST *expr) {
  std::string begin = "digraph expression\n{\n";
  std::string graph = begin + expr->graphgen("Source") + "}";
  std::ofstream file("graph.dot");
  file << graph;
}

void save_graph(FunctionAST *expr) {
  std::string begin = "digraph expression\n{\n";
  std::string graph = begin + expr->graphgen("Source") + "}";
  std::ofstream file("graph.dot");
  file << graph;
}

// Prints what the interpreter gets mentioned (like an object).
void print_eval(ExprAST *expr, const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto value = expr->eval(arguments, variables);
  apply_visitor(hana::overload([](mts_none) -> void { ; }, [](auto arg) -> void { std::cout << arg << "\n"; }), *value);
  return;
}

// Overloading stream for mts_obj.
std::ostream &operator<<(std::ostream &stream, const mts_obj &rhs) {
  apply_visitor(
          hana::overload([&stream](mts_none) -> void { stream << "None"; },
                         [&stream](mts_return<mts_obj> &arg) -> void { stream << "Return{ " << arg.value << " }"; },
                         [&stream](std::string &arg) -> void { stream << "\"" << arg << "\" "; },
                         [&stream](auto &arg) -> void { stream << arg; }),
          rhs);
  return stream;
}

// Overloading stream for mts_list.
std::ostream &operator<<(std::ostream &stream, const mts_list &rhs) {
  stream << "[";
  if (rhs.size() > 1) {
    for (int i = 0; i < rhs.size() - 1; ++i)
      apply_visitor(hana::overload([&stream](auto arg) -> void { stream << arg << ", "; }), rhs[i]);
  }
  if (rhs.size() >= 1) {
    apply_visitor(hana::overload([&stream](auto arg) -> void { stream << arg; }), rhs[rhs.size() - 1]);
  }
  stream << "]";
  return stream;
}

// Overloading stream for mts_dict.
std::ostream &operator<<(std::ostream &stream, const mts_dict &rhs) {
  stream << "{";
  unsigned size = rhs.size();
  unsigned counter = 1;

  for (const auto &entry : rhs) {
    apply_visitor(hana::overload([&stream](auto arg) -> void { stream << arg << ": "; }), entry.first);
    apply_visitor(hana::overload([&stream](auto arg) -> void { stream << arg; }), entry.second);
    if (counter++ < size) { stream << ", "; }
  }
  stream << "}";
  return stream;
}

// https://en.cppreference.com/w/cpp/language/escape
// Code of this function based on https://stackoverflow.com/questions/5612182/convert-string-with-explicit-escape-sequence-into-relative-character
std::string unescape(const std::string &str) {
  std::string result;
  std::string::const_iterator it = str.begin();
  while (it != str.end()) {
    char c = *it++;
    if (c == '\\' && it != str.end()) {
      switch (*it++) {
        case '\'':
          c = '\'';
          break;
        case '\"':
          c = '\"';
          break;
        case '\?':
          c = '\?';
          break;
        case '\\':
          c = '\\';
          break;
        case 'a':
          c = '\a';
          break;
        case 'b':
          c = '\b';
          break;
        case 'f':
          c = '\f';
          break;
        case 'n':
          c = '\n';
          break;
        case 'r':
          c = '\r';
          break;
        case 't':
          c = '\t';
          break;
        case 'v':
          c = '\v';
          break;
        default:
          // invalid escape sequence
          continue;
      }
    }
    result += c;
  }
  return result;
}