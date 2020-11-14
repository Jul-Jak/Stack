#pragma once

#include <iostream>
#include "utstackx.h"

bool Correct_Placement_of_Brackets(std::string s) {
	TStack <char> stack;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack.push(s[i]);
		else if (!stack.isEmpty()) {
			if (stack.top() == '(' && s[i] == ')') stack.pop();
			else if (stack.top() == '[' && s[i] == ']') stack.pop();
			else if (stack.top() == '{' && s[i] == '}') stack.pop();
		}
		else return false;
		}
	if (stack.isEmpty()) return true;
	else return false;
}
int main(int argc, char** argv) {
	if (argc > 1)
		std::cout << Correct_Placement_of_Brackets(argv[1]) << std::endl;
	return 0;
}