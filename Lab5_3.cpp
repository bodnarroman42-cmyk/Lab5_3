#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double s(const double x);

int main()
{
    double tp, tk, z;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = ";  cin >> n;

    double dt = (tk - tp) / n;

    cout << "----------------------------------------" << endl;
    cout << "|" << setw(10) << "t" << " |" << setw(15) << "z" << " |" << endl;
    cout << "----------------------------------------" << endl;

    double t = tp;
    while (t <= tk)
    {

        z = s(2.0 * t + 1.0) + 2.0 * s(t * t) + sqrt(abs(s(1.0)));

        cout << "|" << setw(10) << fixed << setprecision(2) << t
            << " |" << setw(15) << scientific << setprecision(6) << z << " |" << endl;

        t += dt;
    }
    cout << "----------------------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1 || x == 0)
    {
        return (pow(cos(x), 2) + 1.0) / (exp(x) + 1.0);
    }
    else
    {
        double S = 0;
        int k = 0;

        double a = (2.0 * x);
        S = a;

        do
        {
            k++;
            
            double R = (4.0 * x * x) / ((2.0 * k) * (2.0 * k + 1.0));
            a *= R;
            S += a;
        } while (k < 4); 

        return (1.0 / sin(2.0 * x)) * S;
    }
}