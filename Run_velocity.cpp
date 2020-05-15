/* Написать программу, вычисляющую скорость, с которой бегун пробежал дистанцию.Исходными данными являются:
	длина дистанции (м)
	время (минуты и секунды)  */

#include <iostream>
#include <Windows.h> // для кириллицы
#include <string>    // для std::string

using std::cout; using std::cin; using std::endl; using std::string;

// получаем от пользователя дробное число, выводя соответствующий текст в качестве запроса
double get_number(const string& text_for_user)
{
	cout << text_for_user;
	double answer;
	cin >> answer;
	while (cin.fail() || (answer < 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели нечто некорректное, введите положительное число: ";
		cin >> answer;
	}
	return answer;
}

// вычисляем среднюю скорость по расстоянию и времени:
double velocity_calculation(double distance, double time)
{
	// сначала переводим расстояние из метров в километры
	const unsigned metres_in_1_kilimetre = 1000;
	distance = distance/metres_in_1_kilimetre;

	// время введено в формате минуты.секунды, сделаем из этого отдельно целые минуты и целые секунды:
	unsigned minutes = static_cast<unsigned>(time); // целые минуты - это отбрасываем дробную часть времени
	double seconds = (time - minutes) * 100; // секунды - это дробная часть времени
	
	time = minutes + (seconds / 60);      // перевели время в минуты

	//	скорость = расстояние / время, т.к. нам нужны километры в час, то время ещё делится на 60 (= расстояние умножается на 60)
	return (distance*60 / time);
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); // для ввода-вывода на кириллице

	while (true)
	{
		// запрашиваем у пользователя данные
		double distance = get_number("Введите длину дистанции в метрах: ");
		double time     = get_number("Введите время в формате минуты.секунды: ");

		cout << "Средняя скорость составила: " << velocity_calculation(distance, time) << " км/час " << endl << endl;
	}

	return 0;
}