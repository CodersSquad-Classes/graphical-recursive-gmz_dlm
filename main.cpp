// File: main.cpp

#include "src/koch.hpp"
#include <iostream>

int main () {
	Point p1 = {0, 0};
	Point p2 = {100, 0};
	Line l = {p1, p2};

	std::vector<Line> result = koch(l, 10);

	for (const Line &line : result) {
		std::cout << "(" << line.first.first << ", " << line.first.second << "), ";
		std::cout << "(" << line.second.first << ", " << line.second.second << ")" << std::endl;
	}

	return 0;
}
