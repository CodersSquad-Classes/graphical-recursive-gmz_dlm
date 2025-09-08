// File: main.cpp

#include "src/koch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define OUTPUT "lines.txt"

int main () {
	Point p1 = {0, 0};
	Point p2 = {1000, 0};
	Line l = {p1, p2};

	std::vector<Line> result = koch(l, 3);

	std::stringstream ss;

	for (const Line &line : result) {
		ss << "(" << line.first.first << ", " << line.first.second << ")";
		ss << "(" << line.second.first << ", " << line.second.second << ")" << std::endl;
	}

	std::ofstream file(OUTPUT);

	if (!file) {
		std::cerr << "Error writing on " << OUTPUT << "." << std::endl;
		return -1;
	}

	file << ss.str();

	return 0;
}
