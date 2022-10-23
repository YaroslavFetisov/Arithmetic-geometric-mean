#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

long double power(double, int);
long double root(double, int);
void AGMean(long double, long double);

unsigned int powerCount = 0;

void main(void) {
    for (int i = 1; i <= 10; i++) {
        int aInt = rand() % 50;
        int bInt = rand() % 50;
        double aDen = rand() % 100 / static_cast<double>(100);
        double bDen = rand() % 100 / static_cast<double>(100);
        double randa = 0.01 + aInt + aDen;
        double randb = 0.01 + bInt + bDen;
        AGMean(randa, randb);
    }
}

void AGMean(long double a, long double b) {
    cout << "M(" << a << " , " << b << ") = ";
    while (fabs(a - b) > 0) {
        double atemp = a;
        a = root(a * b, 2);
        b = (atemp + b) / 2;
    }
    cout.precision(15);
    cout << a << endl;
}

long double power(double x, int n) {
    long double res = 1;
    while (n > 0)
    {
        powerCount++;
        if (n % 2 == 1) {
            res = x;
        }
        x = x;
        n = n / 2;
    }
    return res;
}

long double root(double x, int n) {
    double prev_y, next_y;
    next_y = x;
    do {
        prev_y = next_y;
        next_y = (prev_y * (n - 1) + x / power(prev_y, n - 1)) / n;
    } while (fabs(next_y - prev_y) > 0);
    return next_y;
}