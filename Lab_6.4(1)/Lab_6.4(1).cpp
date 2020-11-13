// 1 Спосіб --- "Ітераційний"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>

void value_elements(double* masuv_b, const int elements, double Low, int High);
void vuvestu(double* masuv_b, const int elements);
double min_values(double* masuv_b, const int elements);
double suma(double* masuv_b, const int elements);
void sortirovka(double* masuv_b, const int elements);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int k_elementiv;
	std::cout << "Введіть кількість дійсних елементів: ";
	std::cin >> k_elementiv;
	std::cout << std::endl;
	const int elements = k_elementiv;
	double* masuv_b = new double[elements];

	double Low = 0.01;
	int High = 200;

	value_elements(masuv_b, elements, Low, High);

	std::cout << "сформований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(masuv_b, elements);

	double min = min_values(masuv_b, elements);
	std::cout << "мінімальний елемент масиву b: " << min << std::endl;
	std::cout << std::endl;

	double sum = suma(masuv_b, elements);
	if (sum == 0)
		std::cout << "не існує елемнтів розташованих між першим і останнім додатними елементами: " << std::endl;
	else
		std::cout << "Суму елементів масиву, розташованих між першим і останнім додатними елементами" << sum << std::endl;
	std::cout << std::endl;
	sortirovka(masuv_b, elements);
	std::cout << "Модифікований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(masuv_b, elements);

	delete[] masuv_b;

	return 0;
}

void value_elements(double* masuv_b, const int elements, double Low, int High)
{
	int p_index = 0;
	for (int index = p_index; index < elements; index++)
	{
		int diapzon = 2;
		masuv_b[index] = Low * (rand() % (2 * High)) - diapzon;
	}
}

void vuvestu(double* masuv_b, const int elements)
{
	int p_index = 0;
	for (int index = p_index; index < elements; index++)
		std::cout << std::setprecision(2) << std::setw(6) << masuv_b[index];
	std::cout << std::endl;
	std::cout << std::endl;
}

double min_values(double* masuv_b, const int elements)
{
	int p_index = 0;
	double min = masuv_b[p_index];
	for (int index = p_index + 1; index < elements; index++)
	{
		if (min > masuv_b[index])
			min = masuv_b[index];
		else;
	}
	return min;
}

double suma(double* masuv_b, const int elements)
{
	double sum = 0;
	int p_index = 0;
	for (int index = 0; index < elements; index++)
	{
		if (masuv_b[index] > 0)
		{
			int k_index = elements - 1;

			for (; masuv_b[k_index] < 0; k_index--);

			for (index++; index < k_index; index++)
				sum += masuv_b[index];
			index = elements;
		}
		else;
	}
	return sum;
}

void sortirovka(double* masuv_b, const int elements)
{
	int pp_index = 0;
	double p_index = 0;
	int live = 0;
	for (int index = live; index < elements; index++)
	{
		double value;
		value = masuv_b[index];
		if ((0 <= value && value < 1) || (-1 < value && value <= 0))
		{
			p_index = masuv_b[pp_index];
			masuv_b[pp_index] = masuv_b[index];
			masuv_b[index] = p_index;
			pp_index++;
		}
		else;
	}
}