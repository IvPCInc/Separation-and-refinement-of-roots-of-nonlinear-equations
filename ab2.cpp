#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double F(double x) {
	return pow(x, 3) + 3 * pow(x, 2) + 8 * x - 3;
}

vector<double>Del(double a, double b) {
	vector<double> roots;
	double st = (b - a) / 20;
	for (int i = 0; i < 20; i++) {
		double x1 = a + i * st;
		double x2 = x1 + st;
		if (F(x1) * F(x2) < 0) {
			roots.push_back(x1);
			roots.push_back(x2);
		}
	}
	return roots;
}

double FindSqrt(double a, double b, double eps) {
	double x;
	x = (a + b) / 2; // иницилизация x как середина отрезка
	while ((b - a) > eps) { // пока отрезок не станет меньше eps
		x = (a + b) / 2; // пересчитываем как середину отрезка
		if (F(a) * F(x) < 0) {
			b = x; // корень находиться в левой половине [a,x]
		}
		else
			a = x; // корень находиться в правой половине [b,x]
		x = (a + b) / 2;
	}
	return x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a = -5, b = 3, eps = 0.001;

	vector<double> sqrT = Del(a, b);
	cout << "Потенциальные корни: ";
	for (double root : sqrT) {
		cout << root << " ";
	}
	cout << endl;

	cout << "Уточненные корни: ";
	for (int i = 0; i < sqrT.size(); i += 2) {
		if (i + 1 < sqrT.size()) {
			double root = FindSqrt(sqrT[i], sqrT[i + 1], eps);
			cout << root << " ";
		}
	}
	cout << endl;
	return 0;
}