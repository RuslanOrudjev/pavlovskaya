#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {

	int x;
	int y;

	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	point& operator = (const point& p) {

		x = p.x;
		y = p.y;

		return *this;
	}

	bool operator < (const point& p) {

		if (x < p.x)
			return true;

		if (x == p.x && y < p.y)
			return true;

		return false;
	}
};

struct triangle {

	point points[3];
};

int main(int argc, char *argv[]) {

	int n;

	cout << "Input a triangles number:" << endl;
	cin >> n;

	vector<point> points;

	n = n * 3;

	int i = 0;
	for (; i < n; i++) {

		point p;

		cout << "Input point[" << i << "] x:" << endl;
		cin >> p.x;

		cout << "Input point[" << i << "] y:" << endl;
		cin >> p.y;

		points.push_back(p);
	}

	sort(points.begin(), points.end());

	vector<triangle> triangles;

	for (i = 0; i < n; i++) {

		triangle t;

		t.points[0] = points[i++];
		t.points[1] = points[i++];
		t.points[2] = points[i];

		triangles.push_back(t);
	}

	cout << "Triangles:" << endl;

	vector<triangle>::iterator iter;

	for (iter = triangles.begin(); iter != triangles.end(); ++iter)
		cout << "(" <<
		"(" << iter->points[0].x << ", " << iter->points[0].y << "), "
		"(" << iter->points[1].x << ", " << iter->points[1].y << "), "
		"(" << iter->points[2].x << ", " << iter->points[2].y << "))" << endl;
	system("Pause");
	return 0;
}