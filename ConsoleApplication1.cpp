#include <iostream>
#include <cmath>   
#include <iomanip> 
#include <numbers>   


using namespace std;

// Returns true if the expression is defined for the given x.
bool isInDomain(double x) {

    return x >= -7 && x != 14;
}


// Calculate the expression for x
double f(double x) {

    return sin(14.0 / 58) + 10 * numbers::pi - 54 * numbers::e * 15 / ((x + 12) * (x - 14))
        + 11 * cos(x - 8) - sqrt(x + 7);
}


int main()
{

    cout << "The author of this program is Dotsenko Zakhar\n";
    cout << "This program calculates the value of an expression "
        "by given x. Variant 165.\n";
    cout << "Enter a number not less than -7 and not equal to 14: ";


    double x;
    cin >> x;


    if (cin.fail()) {

        cout << "\nwrong input\n";
        return 0;
    }

    cout << "\n***** do calculations ... ";
    const bool defined = isInDomain(x);
    double result = 0;

    if (defined) {

        result = f(x);
    }

    cout << "done\n";


    cout << fixed << setprecision(5) << "for x = " << x << '\n';

    if (defined) {

        cout << setprecision(9) << "result = " << result << '\n';
    }
    else {

        cout << "result = undefined\n";
    }

}

