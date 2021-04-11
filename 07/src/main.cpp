#include "main.h"
using namespace std;

class Date {
	private:
		int m_day;
		int m_month;
		int m_year;
	
	public:
		Date(int d = 1, int m = 1, int y = 2021) : m_day(d), m_month(m), m_year(y) {
		}
		
		void setDate(int day, int month, int year) {
			m_day = day;
			m_month = month;
			m_year = year;
		}
		
		int getYear() const {
			return m_year;
		}

		int getMonth() const {
			return m_month;
		}

		int getDay() const {
			return m_day;
		}

		friend ostream& operator<< (ostream &out, const Date &date);
		
};

ostream& operator<< (ostream &out, const Date &date) {
	out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
	return out;
}


unique_ptr<Date>& isLatest(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
	if (d1 -> getYear() > d2 -> getYear())
		return d1;
	else if (d1 -> getYear() < d2 -> getYear())
		return d2;
	else if (d1 -> getMonth() > d2 -> getMonth())
		return d1;
	else if (d1 -> getMonth() < d2 -> getMonth())
		return d2;
	else if (d1 -> getDay() > d2 -> getDay())
		return d1;
	else
		return d2;
}

unique_ptr<Date>& swapDate(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
	d1.swap(d2);
	return d1;
}

int main(int argc, char** args) {
	// Task 1
	unique_ptr<Date> date(new Date());
	unique_ptr<Date> today(new Date());
	today -> setDate(11, 4, 2021);
	cout << "Date contains: " << *date;	
	cout << "Today: " << *today;
	date = move(today);
	if (date)
		cout << *date;
	else
		cout << "Date pointer is NULL\n";

	if (today)
		cout << *today;
	else
		cout << "Today pointer is NULL\n";

	// Task 2
	unique_ptr<Date> date1(new Date(1, 1, 2021));
	unique_ptr<Date> date2(new Date(2, 1, 2021));
	cout << *isLatest(date1, date2);

	// Task 3
	cout << *swapDate(date1, date2);

	return EXIT_SUCCESS;
}
