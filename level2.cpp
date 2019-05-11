#include <iostream>
#include "Ex.hpp"

using namespace std;
using namespace ext;

struct Date
{
	int day;
	int month;
	int year;
};

int num_correct(float min, float max, float num)
{
	bool cor = false;
	while (!cor)
	{
		if (num < min || num > max)
		{
			cout << "«начние некорретно. ¬ведите заново: ";
			cin >> num;
		}
		else
		{
			cor = true;
		}
	}
	return num;
}

int main()
{
	setlocale(LC_ALL, "rus");
	float procent = 0;
	int simulations = 0;
	cout << "¬ведите желаемый процент совпадени€ дней рождени€ (от 0.1 до 99.9): ";
	cin >> procent;
	procent = num_correct(0.1, 99.9, procent);
	cout << "¬ведите киличество симул€ций (от 100 до 100000): ";
	cin >> simulations;
	simulations = num_correct(100, 100000, simulations);
	float simulate_procent = 0;
	int i = 2;
	while (simulate_procent < procent)
	{
		int succeed_op = 0;
		for(int k = 1; k <= simulations; k++)
		{		
			Date * birthdays = new Date[i];
			for (int j = 0; j < i; j++) //инициализаци€ массива
			{
				birthdays[j].year = GetRandomValue(1, 2019);
				birthdays[j].day = GetRandomValue(1, 31);
				birthdays[j].month = GetRandomValue(1, 12);
				bool hight_year = false;
				hight_year = ((birthdays[j].year % 400 == 0) || (birthdays[j].year % 100 != 0
					&& birthdays[j].year % 4 == 0));
				switch (birthdays[j].month)
				{
				case 2:
					if (!((birthdays[j].day < 30 && hight_year) || (birthdays[j].day < 29 && !hight_year)))
					{
						if (hight_year)
						{
							birthdays[j].day = GetRandomValue(1, 29);
						}
						else
						{
							birthdays[j].day = GetRandomValue(1, 28);
						}
					}
					break;
				case 4: case 6:
				case 9: case 11:
					if (!(birthdays[j].day < 31))
					{
						birthdays[j].day = GetRandomValue(1, 30);
					}
					break;
				}
			}
			bool success = false;
			bool success_three = false;
			for (int j = 0; j < i; ++j) //проверка совпадений
			{
				for (int k = 0; k < i; ++k)
				{
					if ((birthdays[j].day == birthdays[k].day) && (birthdays[j].month == birthdays[k].month) && (k != j))
					{
						success = true;
						break;
					}
				}
			}
			if (success) succeed_op++;			
		}
		simulate_procent = static_cast<float>(succeed_op) /	static_cast<float>(simulations) * 100;
		if (simulate_procent > procent)
		{
			cout << "”казанна€ веро€тность совпадени€ дней рождени€ достигнута в группе размером " << i << " человек" << endl;

			break;
		}
		cout << "¬ группе размером " << i << " человек, достигнута веро€тность в " << static_cast<float>(succeed_op) /
				static_cast<float>(simulations) * 100 << "%" << endl;			
		i++;
	}
}