#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * \brief Функциия для расчета y.
 * \param x Параметр x.
 * \return Возвращает значение y.
 */
double GetValue(const double x);
/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main() {
        double x = 1;

        for (x; x < 2.1; x+=0.1) {

            double y = GetValue(x);
            cout<<"x = "<< x << " " <<"y = "<< y << '\n';

        }
}

double GetValue(double x) {
    return 0.1 * x * x - x * log(x);
}
