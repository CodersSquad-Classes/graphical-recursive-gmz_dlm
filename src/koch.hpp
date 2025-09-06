// File: src/koch.hpp

#include <cmath>
#include <vector>
#include <map>

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
 *
 * ## Dev notes:
 * - This algorithm has a particularity: every iteration, the number of lines multiplies by 4:
 *   n = 1 -> lines = 4;
 *   n = 2 -> lines = 8;
 *   n = 3 -> lines = 12;
 *   ...
 *   So the stop condition of recursiveness is resultant.size() >= 4*n
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
	float y = v[0] * s + v[1] * s;
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
	std::vector<float> v120 = v;

	rotate_vector(v60, cos60, sin60);
	rotate_vector(v120, cos120, sin120);

	Point p0 = line.first;
	Point p1 = {static_cast<int> (p0.first + v[0]), static_cast<int>(p0.second + v[1])};
	Point p2 = {static_cast<int> (p1.first + v60[1]), static_cast<int> (p1.second + v60[1])};
	Point p3 = {static_cast<int> (p2.first + v120[1]), static_cast<int> (p2.second + v120[1])};
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
