#include "../Header.h"

std::string FunctionAST::graphgen(std::string origin) { 
	std::string pos = std::to_string(counter);
	std::string result = std::to_string(counter) + " [label=\"Function " + name + "\"];\n";
	result += origin + " -> " + std::to_string(counter++) + ";\n";
	result += body->graphgen(pos);
	return result;
}

shared_mts_obj FunctionAST::eval(const shared_future_map * const arguments, shared_mts_obj_map * const variables) {
	return body->eval(arguments, variables);
}
