#pragma once
class Date
{
	public:
		int getDay();
		void setDay(int d);
		int getMonth();
		void setMonth(int m);
		bool isDateValid(int d, int m);
		Date(int d, int m);

	private:
		int day;
		int month;
		int year = 2022;
};

