#include <iostream>
#include <windows.h>
using namespace std;

struct student
{
	char fam[10];
	char name[10];
	int app[3];

};

void print(int n, student* one)
{
	for (int i = 0; i < n; i++)
	{
		cout << one[i].fam << endl;
		cout << one[i].name << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << one[i].app[j] << ",";

		}
		cout << endl;
	}
}

void student1(int n, student* one)
{
	int temp;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if (one[k].app[j] > one[k].app[j + 1]) {

					temp = one[k].app[j];
					one[k].app[j] = one[k].app[j + 1];
					one[k].app[j + 1] = temp;
				}
			}
		}
	}
}

void student2(int size, student* one)
{
	student temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (one[j].app[0] > one[j + 1].app[0]) {

				temp = one[j];
				one[j] = one[j + 1];
				one[j + 1] = temp;
			}
		}
	}

	print(size, one);



}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n= ";
	cin >> n;
	student* one = new student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите фамилию  ";
		cin >> one[i].fam;
		cout << "Введите имя  ";
		cin >> one[i].name;
		cout << "Введите 3 оценки  ";
		for (int j = 0; j < 3; j++)
		{
			cin >> one[i].app[j];

		}

	}

	cout << endl;

	print(n, one);

	cout << " " << endl;

	student1(n, one);
	student2(n, one);
}