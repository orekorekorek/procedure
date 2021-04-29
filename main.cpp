#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функции перевода из байтов в мегабайты.
 * \param bytes объем информации в байтах.
 * \return Возвращает объем информации в мегабайтах.
 */
double BytesToMegabytes(double bytes);

/**
 * \brief Функции перевода из мегабайтов в гигабайты.
 * \param bytes объем информации в мегабайтах.
 * \return Возвращает объем информации в гигабайтах.
 */
double MegabytesToGigabytes(double megabytes);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
    cout << "Input a capacity in bytes = ";
    double capacityInBytes;
    cin >> capacityInBytes;

    const auto capacityInMegabytes = BytesToMegabytes(capacityInBytes);
    const auto capacityInGigabytes = MegabytesToGigabytes(capacityInMegabytes);

    cout << setprecision(10)
         << "\nThe capacity in MegaBytes is " << capacityInMegabytes
         <<"\nThe capacity in GigaBytes is "<< capacityInGigabytes << endl;

    return 0;
}

double BytesToMegabytes(const double bytes)
{
    return bytes / 1000000;
}

double MegabytesToGigabytes(const double megabytes)
{
    return megabytes / 1000;
}
