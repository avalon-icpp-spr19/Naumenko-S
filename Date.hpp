#pragma once
#include <string>

namespace ext
{
	enum Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	enum DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum Season
	{
		Winter,
		Spring,
		Summer,
		Autumn
	};

	struct Date
	{
		int year;
		Month month;
		int day;
	};

	/*
	���������� ��������� ����
	https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
	������ "���������� ������ ���������� ��� (JDN) �� ���� �������������� ���������"
	�������� ������					��������� ���������
	1.12.2018					2458454
	1.1.2018					2458120
	1.6.2000					2451697
	21.12.2012					2456283
	*/
	unsigned int countJND(Date date)
	{
		int a = (14 - date.month) / 12;
		int y = date.year + 4800 - a;
		int m = date.month + 12 * a - 3;
		return (date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045);
	}

	/*
	������������ ���������� ���� ����� ����� ������.
	��� ����������� ����������� CountJND
	*/
	int countDistance(Date from, Date to);

	/*
	������� � ������� ���� � �������: dd.mm.yyyy (2.10.2001)
	���� �������� DateFormat ����� MonthAsString, �� ������� ���� � �������: dd monthName yyyy (2 ������� 2001)
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt);

	/*
	���������� ����� (����, �����, ����, �����) ������������ ����
	*/
	Season getSeason(Date date)
	{
		Season answ;
		switch (date.month)
		{
		case December:
		case January:
		case February:
			answ = Winter;
			break;
		case March:
		case May:
		case April:
			answ = Spring;
		case July:
		case June:
		case August:
			answ = Summer;
		default:
			answ = Autumn;
			break;			
		}
	return answ;
	}

	/*
	������ ���� �������
	*/
	void swap(Date * lhs, Date * rhs);

	/*
	���������� ���� �� ���������������
	*/
	bool isSame(Date* lhs, Date * rhs);

	/*
	���������� ��������� �� ������� ����
	*/
	Date * max(Date * lhs, Date * rsh);

	/*
	���������� ��������� �� ������� ����
	*/
	Date * min(Date * lhs, Date * rsh);

	/*
	���������� ��������� �� ����������� ���� � ���������� ������� ���
	*/
	Date * getMinDate(Date dates[], int size);

	/*
	���������� ��������� �� ������������ ���� � ���������� ������� ���
	*/
	Date * getMaxDate(Date dates[], int size);

	/*
	��������� ����� �� ������������ ���� � ������������� ����������.
	� ������ ������ ���������� true, � ��������� ���� �� ����������� ������.
	���� ���� � ����������� ����������� ������������ �� �����,
	���������� false.
	*/
	bool tryFillDate(Date * date, int year, int month, int day);
}