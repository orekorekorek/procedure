#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Расчет функции e в степени 2x.
 * \param x Показатель степени.
 * \return Значение e в степени 2x.
 */
double GetePower2X(const double x);

/**
 * \brief Вычисление рекуррентного члена ряда.
 * \param x Параметр функции, аппроксимируемой рядом.
 * \param index Индекс члена ряда.
 * \return Значение рекуррентного члена.
 */
double GetRecurrent(const double x, const unsigned int index);

/**
 * \brief Вычисление суммы ряда от x, до того момента пока |x_i - x_{x-1}| >= epsilon
 * \param x Показатель степени.
 * \param epsilon Погрешность вычислений.
 * \return Значение e в степени 2x.
 */
double GetSumOfSeries(const double x, const double epsilon);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto leftBound = 0.1;
    const auto rightBound = 1.0;
    const auto epsilon = 0.0002;
    const auto step = 0.01;

    auto x = leftBound;
    while (x <= rightBound + epsilon)
    {
        const auto function = GetePower2X(x);
        const auto series = GetSumOfSeries(x, epsilon);

        cout << x << "|  |" << function << "|  |" << series << endl;

        x += step;
    }

    return 0;
}

double GetePower2X(const double x)
{
    return exp(2*x);
}

double GetRecurrent(const double x, const unsigned int index)
{
    return 2 * x / (index + 1);
}

double GetSumOfSeries(const double x, const double epsilon)
{
    auto previous = 0.0;
    auto current = 1.0;
    auto sum = current;
    unsigned int index = 0;

    do
    {
        previous = current;
        current = previous * GetRecurrent(x, index);
        sum += current;
        index++;
    } while (abs(previous - current) >= epsilon);

    return sum;
}
