// File: main.cpp

#include "src/koch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>


#define OUTPUT "lines.txt"

int main (int argc, char *argv[]) {
	int n;
	if (argc == 1) {
		n = 4;
	}

	else if (argc > 2) {
		throw std::invalid_argument("Invalid argument: Cannot enter more than 1 argument. Call it as follows: \n\t./main 4\nor\n\t./main 10");
	}

	try {
		n = std::stoi(argv[1]);
	}
	catch (std::invalid_argument err) {
		throw std::invalid_argument("Invalid argument: Cannot enter more than 1 argument. Call it as follows: \n\t./main 4\nor\n\t./main 10");
	}

	Point p1 = {0, 0};
	Point p2 = {1000, 0};
	Line l = {p1, p2};

	std::vector<Line> result = koch(l, n);

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
