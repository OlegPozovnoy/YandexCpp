// � еализуйте функции и методы классов и при необходимости добавьте свои

#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<iomanip>

using namespace std;

class Date {
public:
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}

	int GetDay() const {
		return day;
	}

	Date(const string&  str) {

		stringstream input(str);

		input >> year;
		if (input.peek() != '-')
			throw invalid_argument("Wrong date format: " + str);

		input.ignore(1);

		input >> month;

		if (input.peek() != '-')
			throw invalid_argument("Wrong date format: " + str);

		input.ignore(1);

		if (input.peek() !=EOF)
			input >> day;
		else
			throw invalid_argument("Wrong date format: " + str);
		
		if (input.peek() != EOF)
			throw invalid_argument("Wrong date format: " + str);

		if (!(month >= 1 && month <= 12))
		{
			throw invalid_argument("Month value is invalid: " + to_string(month));
		}
		if (!(day >= 1 && day <= 31)) {
			throw invalid_argument("Day value is invalid: " + to_string(day));
		}

	}

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay() < rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay();
}

ostream& operator<<(ostream& out, const Date& date) {
	out << setfill('0');

	out << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();

	return out;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		int N = data[date].count(event);

		if (N == 0) {
			cout << "Event not found" << endl;
			return false;
		}
		else
		{
			cout << "Deleted successfully" << endl;
			data[date].erase(event);
			return true;
		}

	}

	int  DeleteDate(const Date& date) {
		int N = data[date].size();
		cout << "Deleted " << N << " events" << endl;
		data.erase(date);
		return N;
	}

	void Find(const Date& date) const {

		try {

			for (auto e : data.at(date)) {
				cout << e << endl;
			}

		}
		catch (out_of_range e) {
		
		}

	}

	void Print() const {

		for (auto element : data) {
			for (auto str : element.second) {
				cout << element.first << " " << str << endl;
			}
		}
	}

private:
	map<Date, set<string>> data;

};

int main() {
	Database db;

	string command;
	while (getline(cin, command)) {

		istringstream str(command);
		string command;
		str >> command;

		if (command.size() == 0)
			continue;

		try {
			string date, event;
			if (command == "Add") {//Add ���� �������
				str >> date >> event;
				Date converted_date(date);
				db.AddEvent(converted_date, event);
			}
			else if (command == "Del") //Del ���� �������
			{
				str >> date >> event;
				Date converted_date = Date(date);
				if (event.size() == 0) 
					db.DeleteDate(converted_date);
				else
					db.DeleteEvent(converted_date, event);
			}
			else if (command == "Find") {//Find ����
				str >> date;
				Date converted_date = Date(date);
				db.Find(converted_date);
			}
			else if (command == "Print") {//Find ����
				str >> date;
				db.Print();
			}
			else {
				cout << "Unknown command: " << command << endl;
			}
			// Считайте команды с потока ввода и обработайте каждую
		}
		catch (invalid_argument e) {
			cout << e.what() << endl;
			return 1;
		}
	}

	return 0;
}