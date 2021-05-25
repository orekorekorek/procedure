#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
* \param MinValue Нижняя граница
* \param MaxValue Верхняя граница
**/
void RandomArray(int* array, const size_t  size, const int MinValue, const int MaxValue);

/**
* \brief Ввод массива пользователем
* \param array Массив
* \param size Размер массива
**/
void UsersArray(int* array, const size_t size);

/**
* \brief Вывод массива
* \param array Массив
* \param size Размер массива
**/
void Output(int* array, const size_t size);

/**
* \brief Поиск минимального элемента
* \param array Массив
* \param size Размер массива
* \return min Минимальный элемент массива
**/
int GetMinAbsElement(int* array, const size_t size);

/**
* \brief Вывод массива с заменой минимального элемента нулем
* \param array Массив
* \param size Размер массива
**/
void MinReplacedByZero(int* array, const size_t size, const int min);

/**
* \brief Метод, который формируют массив А из элементов массива D
* \param newarray Новый массив
* \param array Старый массив
* \param size Размер массива
**/
void NewArray(const size_t size, int* newarray, int* array);

/**
* \brief Удаление элементов массива, первая и последняя цифра которых четная
* \param array Массив
* \param size Размер массива
**/
void EjectEvenNumbers(int* array, const size_t size);

/**
* \brief Выбор заполнеия массива
**/
enum class ChoiceOfFilling
{
	RANDOM = 1,
	USER = 2
};

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int MinValue = -40, MaxValue = 40;
  int* array;
  size_t size;
	int choice;
  array = new int[size];

	cout << "Введите количество элементов массива: ";
  cin >> size;

	cout << "Введите:\n1 - для того чтобы я сам сгенерировал массив\n2 - если желаете ввести массив вручную" << endl;
  cin >> choice;

	const auto filling = static_cast<ChoiceOfFilling>(choice);
	switch (filling)
	{
	case ChoiceOfFilling::RANDOM:
		RandomArray(array, size, MinValue, MaxValue);
		Output(array, size);
		break;
	case ChoiceOfFilling::USER:
		UsersArray(array, size);
		Output(array, size);
		break;
	default:
		cout << "Такого варианта нет";
	}

	cout << "Удалил из массива все числа, первая и последняя цифра которых четные числа:\n";
	EjectEvenNumbers(array, size);

	int min = GetMinAbsElement(array, size);
	cout << "Заменил минимальный по модулю элемент нулем:\n";
	MinReplacedByZero(array, size, min);

	cout << "Сформировал массив А из массива D:" << endl;
	int* newarray;
	newarray = new int[size];
	NewArray(size, newarray, array);
	Output(newarray, size);

	return 0;
}

void RandomArray(int* array, const size_t  size, const int MinValue, const int MaxValue)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = MinValue + rand() % (MaxValue + 1);
	}
}

void UsersArray(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> array[i];
	}
}

void Output(int* array, const size_t size)
{
	cout << "array[" << size << "]" << "= {";
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ; ";
	}
	cout << "}" << endl;
}

int GetMinAbsElement(int* array, const size_t size)
{
	int min = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (abs(array[i]) <= abs(min))
			min = array[i];
	}
	return min;
}

void PrintReplacement(int* array, const size_t size, const int min)
{
	cout << "array[" << size << "]" << "= {";
	for (size_t i = 0; i < size; i++)
	{
		if (abs(array[i]) == abs(min))
			array[i] = 0;

		cout << array[i] << ";" << setw(3);
	}
	cout <<"}\n\n";
}

void NewArray(const size_t size, int* newarray, int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		if (i >= 3 && i <= 12 )
			newarray[i] = -array[i] * array[i];
		else
			newarray[i] = array[i] - 1;
	}
}

void EjectEvenNumbers(int* array, const size_t size)
{
	int x, newsize = 0;
	for (size_t i = 0; i < size; i++)
  {
		if (array[i] % 2 != 0 && (array[i] / 10) % 2 != 0)
      newsize+=1;
      array[newsize] = array[i];
  }
  Output(array, newsize);
}
