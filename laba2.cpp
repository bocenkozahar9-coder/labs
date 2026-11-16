#include <iomanip>
#include <iostream>

using namespace std;

const double a = 0.0;
const double b = 0.8;

/// Sums the series until the current term is less than eps in absolute value.
/// The next term is obtained from the previous one by the recurrence relation:
/// x(n+1) = x(n) * (-x * (n + 1) * (2n + 1)) / ((n + 2) * (2n + 3)),x(0) = x.
double s (double x, double eps)
{
    double term =x;
    double sum = x;
    double n = 0;
    while (term >= eps || term <= -eps) {
        term *= -x * (n + 1) * (2 * n + 1) / ((n + 2) * (2 * n + 3));
        sum += term;
        n += 1;
    }
    return sum;
}

///Prints the error header and the diagnostic message on a new line.
void reportError(const char* message)
{
    cout << "\n***** error\n" << message << '\n';
}

/// Reads x and eps, calculates S(x) and prints the result.
int main()
{
    cout << "The author of this program is Dotsenko Zakhar. ITK11\n";
    cout << "This program calculates the sum of a power series S(x) "
            "with given accuracy eps. Variant 165.\n";

    double x;
    cout << "Enter a real from [" << a << ";" << b << "]: ";
    cin >> x;
    if (cin.fail()) {
        reportError("At time of getting x: the input is not a real number.");
        return 0;
    }





    if (x < a || x > b){
        reportError("At time of getting x: the value is outside [a;b].");
        return 0;
    }

    double eps;
    cout << "Enter positive eps: ";
    cin >> eps;
    if (cin.fail()) {
        reportError("At time of getting eps: the input is not a real number.");
        return 0;
    }
    if (eps <= 0){
        reportError("At time of getting eps: the value must be positive.");
        return 0;
    }

    cout << "\n***** do calculations ... ";
    const double result = s(x, eps);
    cout << "done\n";

    cout << scientific << uppercase << setprecision(7)
         << "for x = " << x << '\n';
    cout << setprecision(9) << "for eps = " << eps << '\n';
    cout << fixed << setprecision(8) << "result = " << result << '\n';
}

