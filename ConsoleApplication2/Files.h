#pragma once
#include "includes.h"
#include "User.h"
#include "Student.h"

void file_update(vector<Student> students) {
	ofstream out;
	out.open("DataTable.txt", ios::out | ios::trunc);
	if (out.is_open()) {
		for (int i = 0; i < students.size(); i++) {
			out << students[i].getGroup() << separator << students[i].getName() << separator
				<< students[i].getExams(0) << ' ' << students[i].getExams(1) << ' ' << students[i].getExams(2) << ' ' << students[i].getExams(3) << ' ' << students[i].getExams(4)
				<< separator << students[i].getMax(0) << ' ' << students[i].getMax(1) << ' ' << students[i].getMax(2) << ' ' << students[i].getMax(3) << ' ' << students[i].getMax(4) << separator;
			out << '\n';
			// запись с разделителем
		}
	}
	out.close();
}

//перезапись всех данных в файл (обновление)
void users_file_update(vector <User> users) {
	ofstream out;
	out.open("UserTable.txt", ios::out | ios::trunc);
	if (out.is_open()) {
		for (int i = 0; i < users.size(); i++) {
			out << users[i].getLogin() << " " << users[i].getPassword() << " " << users[i].getStatus();
			out << '\n';
			// запись с разделителем
		}
	}
	out.close();
}

//чтение файла с пользователями
vector<User> read_user_file() {
	string login, password, status;
	vector<User> users;
	ifstream in;
	in.open("UserTable.txt");

	if (in.is_open())
	{
		while (in >> login >> password >> status)
		{
			users.push_back(User(login, password, status));
		}
	}
	in.close();
	return users;
}
