// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Massiv {

public:
	void create(int* mass, int value)  //создание массива
	{
		for (int x = 0; x < value; x++) {
			cout << "Введите " << x << " элемент: ";
			cin >> mass[x];
		}
	}
public:
	void output(int* mass, int value) { //вывод массива
		for (int x = 0; x < value; x++) {
			cout << mass[x] << "\n";
		}
	}
public:
	int Search(int* mass, int value, int index) { //вывод массива
		int searched_obj = 0;
		for (int x = 0; x < value; x++) {
			if (x == index) {
				return mass[x];
			}
		}
	}
public:
	void Sort(int* mass, int value) { //вывод массива

		int min, temp; // для поиска минимального элемента и для обмена
		for (int i = 0; i < value - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < value; j++)
			{
				if (mass[j] < mass[min])
					min = j;
			}
			temp = mass[i];
			mass[i] = mass[min];
			mass[min] = temp;
		}
		for (int x = 0; x < value; x++) {
			cout << mass[x] << "\n";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int key = 1;
	int value = 0;
	cout << "Введите количество элементов массива: ";
	cin >> value;
	int* mass = new int[value];
	Massiv Work_Mass;
	int search_obj = 0;
	int search = 0;

	while (key == 1) {
		int obj;
		cout << "Выберите действие: ";
		cout << "1 - ввод массива, 2 - вывод массива, 3 - Поиск элемента по ключу, 4 - Сортировка массива с помощью прямого выбора, 0 - выход\n";
		cin >> obj;
		if (obj == 0) {
			break;
		}
		switch (obj)
		{
		case 1:
			Work_Mass.create(mass, value);
			cout << "Массив создан!\n";
			break;
		case 2:
			cout << "Вывод массива:\n";
			Work_Mass.output(mass, value);
			break;
		case 3:

			cout << "Введите значение от 1 до " << value << '\n';
			cin >> search;
			while (search<1 || search > value) {
				cout << "Введите значение от 1 до " << value << '\n';
				cin >> search;
			}
			search_obj = Work_Mass.Search(mass, value, search - 1);
			cout << search_obj << '\n';
			break;
		case 4:
			Work_Mass.Sort(mass, value);
			break;
		}
	}
}

