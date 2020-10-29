#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const double a = -5.0, b = 2.0;

double func(double x) {
	return (1-x)*(1-x)+exp(x);
}

void separator(int lhs, int rhs) {
	cout << "+";
	cout << setfill('-') << setw(lhs) << "+";
	for (int i = 0; i < 10; i++) {
		cout << setw(rhs) << "+";
	}
	cout << endl;
}

void printfirsttable(double q, double P) { 
	separator(8, 7);
	cout << "| q\\P   |";
	cout << setfill(' ');
	for (int i = 0; i < 10; i++) {
		cout << setw(6) << P + i * 0.01 << "|";
	}
	cout << endl;
	separator(8, 7);
	cout << setfill(' ');
	for (q = 0.005; q < 0.105;) {
		cout << "|" << setw(7) << q << "|";
		for (P = 0.9; P < 1;) {
			double N = log(1 - P) / log(1 - q);
			cout << setw(6) << ceil(N) << "|";
			P += 0.01;
		}
		cout << endl;
		q += 0.005;
	}
	separator(8, 7);
}

long double min(double q, double P) {
	srand(time(NULL));
	int N = ceil(log(1 - P) / log(1 - q));
	vector<long double> val;
	for (int i = 0; i < N; ++i) {
		double x = a + (b - a) * rand() / RAND_MAX;
		val.push_back(func(x));
	}
	return *min_element(val.begin(), val.end());
}

void get_min(double q, double P) { 
	separator(8, 9);
	cout << "| q\\P   |";
	cout << setfill(' ');
	for (int i = 0; i < 10; i++) {
		cout << setw(8) << P + i * 0.01 << "|";
	}
	cout << endl;
	separator(8, 9);
	cout << setfill(' ');
	for (q = 0.005; q < 0.105;) {
		cout << "|" << setw(7) << q << "|";
		for (P = 0.9; P < 1;) {
			cout << setw(8) << setprecision(4) << min(q, P) << "|";
			P += 0.01;
		}
		cout << endl;
		q += 0.005;
	}
	separator(8, 9);
}

long double min_sin(double q, double P) {
	srand(time(NULL));
	int N = ceil(log(1 - P) / log(1 - q));
	vector<long double> val;
	for (int i = 0; i < N; ++i) {
		double x = a + (b - a) * rand() / RAND_MAX;
		val.push_back(func(x) * sin(5 * x));
	}
	return *min_element(val.begin(), val.end());
}

void get_min_sin(double q, double P) {
	separator(8, 9);
	cout << "| q\\P   |";
	cout << setfill(' ');
	for (int i = 0; i < 10; i++) {
		cout << setw(8) << P + i * 0.01 << "|";
	}
	cout << endl;
	separator(8, 9);
	cout << setfill(' ');
	for (q = 0.005; q < 0.105;) {
		cout << "|" << setw(7) << q << "|";
		for (P = 0.9; P < 1;) {
			cout << setw(8) << setprecision(4) << min_sin(q, P) << "|";
			P += 0.01;
		}
		cout << endl;
		q += 0.005;
	}
	separator(8, 9);
}

int main() {
	double q = 0.005, P = 0.9;
	printfirsttable(q, P);
	cout << endl;
	get_min(q, P);
	cout << endl;
	get_min_sin(q, P);
	return 0;
}
