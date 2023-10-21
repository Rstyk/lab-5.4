
#include <iostream>
#include <cmath>

using namespace std;

double S0(int N)
{
    double s = 0;
    for (int i = 1; i <= N; i++)
        s += (1.0 / i) + (sqrt(1. + 1.0 * sin(1. * i) * sin(1. * i)));
    return s;
}

double S1(int i, int N)
{
    if (i > N)
        return 0;
    else
        return (1.0 / i) + (sqrt(1. + 1.0 * sin(i) * sin(i))) + S1(i + 1, N);
}

double S2(int i)
{
    if (i < 1)
        return 0;
    else
        return (1.0 / i) + (sqrt(1. + 1.0 * sin(i) * sin(i))) + S2(i - 1);
}

double S3(int i, int N, double t)
{
    t = t + (1.0 / i) + (sqrt(1. + 1.0 * sin(i) * sin(i)));
    if (i >= N)
        return t;
    else
        return S3(i + 1, N, t);
}

double S4(int i, double t)
{
    t = t + (1.0 / i) + (sqrt(1. + 1.0 * sin(i) * sin(i)));
    if (i <= 1)
        return t;
    else
        return S4(i - 1, t);
}

int main()
{
    int N;
    cout << "N = "; cin >> N;
    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(1, N) << endl;
    cout << "(rec up --) S2 = " << S2(N) << endl;
    cout << "(rec down ++) S3 = " << S3(1, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, 0) << endl;

    return 0;
}