// File: src/koch.hpp

#include <cmath>
#include <vector>
#include <map>
#include <iostream>

/**
 * # Koch curve
 *
 * ## Description:
 *
 * The simplest Koch curve uses a line segment as an initiator. 
 * Then, at each level of recursion, the segment is replaced with four segments
 * that are one-third of the original segment's length. 
 * The first segment is in the direction of the original segment, the next 
 * is rotated −60 degrees, the third is rotated 120 degrees, and the final 
 * segment is in the original direction.
 *
 * ## Usage:
 * Call it as follows:
 *
 * ```cpp
 * Point p0 = {0, 0};
 * Point p1 = {1000, 0};
 * Line l = {p0, p1};
 * 
 * std::vector<Line> generated_lines = koch (l, 5);
 * ```
 *
 * Where: 
 * - `p0` is the first point of the initial line
 * - `p1` is the second point of the initial line
 * - `l` is the initial line
 * 
 * And the second number of the koch function args is the number of
 * iterations you want to do. 
 *
 */

using Point = std::pair<int, int>;
using Line = std::pair<Point, Point>;

const double sin60 = sin ((5 * M_PI) / 3); // = -60 DEG
const double cos60 = cos ((5 * M_PI) / 3); // = -60 DEG
const double sin120 = sin ((2 * M_PI) / 3); // = 120 DEG
const double cos120 = cos ((2 * M_PI) / 3); // = 120 DEG

std::vector<float> vectorize_line(const Line& line) {
	float x = static_cast<float> (line.second.first - line.first.first);
	float y = static_cast<float> (line.second.second - line.first.second);
	return {x, y};
}

void rotate_vector (std::vector<float> &v, float c, float s) {
	float x = v[0] * c + v[1] * (-s);
	float y = v[0] * s + v[1] * c;
	v[0] = x;
	v[1] = y;
}



std::vector<Line> koch (const Line& line, const int n) {

	std::vector<Line> result;
	if (n == 0) {
		result.push_back(line);
		return result;
	}

	std::vector<float> v = vectorize_line(line);

	v[0] /= 3.0f;
	v[1] /= 3.0f;

	std::vector<float> v60 = v;
	rotate_vector(v60, cos60, sin60);

	std::vector<float> v120 = v60;
	rotate_vector(v120, cos120, sin120);

	Point p0 = line.first;
	Point p1 = {static_cast<int> (p0.first + v[0]), static_cast<int>(p0.second + v[1])};
	Point p2 = {static_cast<int> (p1.first + v60[0]), static_cast<int> (p1.second + v60[1])};
	Point p3 = {static_cast<int> (p2.first + v120[0]), static_cast<int> (p2.second + v120[1])};
	Point p4 = line.second;

	std::vector<Line> subs = {
		{p0, p1}, {p1, p2}, {p2, p3}, {p3, p4}
	};

	for (auto& seg : subs) {
		auto rec = koch (seg, n - 1);
		result.insert(result.end(), rec.begin(), rec.end());
	}
	return result;
}
