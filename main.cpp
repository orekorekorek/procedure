#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Функция для расчета a
 * \param x Параметр x
 * \param y Параметр y
 * \param z Параметр z
 * \return
 */
double GetA(const double x, const double y, const double z);
/**
 * \brief Функция для расчета b
 * \param x Параметр x
 * \param y Параметр y
 * \param z Параметр z
 * \return
 */
double GetB(const double x, const double y, const double z);


/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    const auto x = 2.0;
    const auto y = 0.7;
    const auto z = -1.0;

    const auto a = GetA(x, y, z);
    const auto b = GetB(x, y, z);

    cout << "x = " << x << ", y =  "<< y << ", z = " << z << "\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

double GetA (const double x, const double y, const double z)
{
    return pow( (x * y * z) + abs(z * sin(y)) , 1.0 / 3.0);
}

double GetB (const double x, const double y, const double z)
{
    return y * cos(x * z * sin(y)) + 3.0;
}
