#include <iostream>
#include "Ex.hpp"

using namespace std;
using namespace ext;

const int LENGTH_OF_ARRAY = 23;

struct Date
{
	int day;
	int month;
	int year;
};

int main()
{
	setlocale(LC_ALL, "rus");
	int N = 0;
	cout << "Введите количество симуляций: ";
	cin >> N;
	int succeed_simulation = 0;
	int second_succeed_simulation = 0;
	for (int i = 0; i < N; ++i)
	{
		Date dates[LENGTH_OF_ARRAY] = {};
		for (int j = 0; j < LENGTH_OF_ARRAY; ++j) //инициализация массива с датами
		{
			dates[j].year = GetRandomValue(1, 2019);
			dates[j].day = GetRandomValue(1, 31);
			dates[j].month = GetRandomValue(1, 12);
			bool hight_year = false;		
			hight_year = ((dates[j].year % 400 == 0) || (dates[j].year % 100 != 0 
				&& dates[j].year % 4 == 0));				
			switch (dates[j].month)
			{
			case 2:
				if (!((dates[j].day < 30 && hight_year) || (dates[j].day < 29 && !hight_year)))
				{
					if (hight_year)
					{
						dates[j].day = GetRandomValue(1, 29);
					}
					else
					{
						dates[j].day = GetRandomValue(1, 28);
					}					
				}
				break;
			case 4: case 6:
			case 9: case 11:
				if (!(dates[j].day < 31))
				{			
					dates[j].day = GetRandomValue(1, 30);
				}
				break;
			}		
		}
		bool success = false;
		bool success_three = false;
		for (int j = 0; j < LENGTH_OF_ARRAY; ++j) //проверка двух совпадений
		{
			for (int k = 0; k < LENGTH_OF_ARRAY; ++k)
			{
				if ((dates[j].day == dates[k].day) && (dates[j].month == dates[k].month) && (k != j))
				{
					success = true;
					break;
				}
			}
		}

		//for (int j = 0; j < LENGTH_OF_ARRAY; ++j) //проверка трех совпадений
		//{
		//	for (int k = 0; k < LENGTH_OF_ARRAY; ++k)
		//	{
		//		for (int l = 0; l < LENGTH_OF_ARRAY; ++l)
		//		{
		//			if ((dates[j].day == dates[k].day && dates[k].day == dates[l].day) && 
		//				(dates[j].month == dates[k].month && dates[k].month == dates[l].month) && (k != j && l != k))
		//			{
		//				success_three = true;
		//				break;
		//			}
		//		}				
		//	}
		//}
		if (success) succeed_simulation++;
		//if (success_three) second_succeed_simulation++;
	}
	cout << "Всего проведено симуляций: " << N << endl;
	cout << "Хотя бы два дня рождения совпали в " << succeed_simulation << " случаях";
	cout << ". Процент успешных: " << static_cast<float>(succeed_simulation) / 
		static_cast<float>(N) * 100  << "%" << endl;
	cout << endl;
}