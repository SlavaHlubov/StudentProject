#include "Menu.h"
#include "User.h"
#include "Student.h"
#include "Files.h"
void authorization_menu() {
	info();
	cout << "�����������:\n";
	cout << "1. ����" << endl;
	cout << "2. �����" << endl;
	int a;
	cin >> a;

	while (true) {//�������� �����
		if (cin.fail() || a < 1 || a>2) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������!" << endl;
			cin >> a;
		}
		if (!cin.fail() && a >= 1 && a <= 2) break;
	}

	switch (a)
	{
	case 1: login_menu(); break;
	case 2: exit(0); break;
	}
}
void info() {
	SYSTEMTIME stm;
	GetLocalTime(&stm);
	cout << "��������� ��������:  " << endl;
	cout << "������ ������: " << endl;
	cout << "�������������: " << endl;
	cout << "������� ���� � �����: " << stm.wHour << ":" << stm.wMinute << " " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "\n\n";
	cout << "��� ����������:\t\t\t2023\n" << endl << endl;
	system("pause");
	system("cls");
}


void about_time() {//����������� ������� �� �������� ������� ���� � �������
	SYSTEMTIME stm;
	GetLocalTime(&stm);
	cout << "\n\n������� ���� � �����: " << stm.wHour << ":" << stm.wMinute << " " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "\n\n";
}

void about_programm() {//���������� � ������������, ������������ �������, ��� ����������
	cout << "\n\n����������� �������: " << endl;
	cout << "��� ����������: 2023" << endl;
}

void admin_menu() {
	system("cls");
	cout << "-------------------------------------------------" << endl;
	cout << "|\t\t���� ��������������\t\t|" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "���������� �������� �������� �������������: " << endl;
	cout << "1. �������� ���� ������� ������� �������������" << endl;
	cout << "2. ���������� ������� ������ ������������" << endl;
	cout << "3. �������������� ������� ������ ������������" << endl;
	cout << "4. �������� ������� ������ ������������" << endl << endl;
	cout << "������ � ������ ������: " << endl;
	cout << "5. ������� ����" << endl;
	cout << "6. ������� ����" << endl;
	cout << "7. ������� ����" << endl << endl;
	cout << "������ � �������: " << endl;
	cout << "8. �������� ������" << endl;
	cout << "9. ���������� ������" << endl;
	cout << "10. �������� ������ � ��������" << endl;
	cout << "11. �������������� ��������" << endl;
	cout << "12. ����� �� ���������" << endl << endl;
	cout << "�������� ����� ..." << endl;
	int i;
	cin >> i;
	while (true) {//�������� �����
		if (cin.fail() || i < 1 || i >= 13) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������� ���������� �������� " << endl;
			cin >> i;
		}
		if (!cin.fail() && i >= 1 && i <= 13) break;
	}
	while (i != 12) {
		switch (i) {
		case 1: {
			vector<User> users = read_user_file();
			if (users.empty()) {
				cout << "���� ����!";
				break;
			}
			user_head();
			show_users_all(users);
			about_programm();
			about_time();
			break;
		}
		case 2: {
			string login, password, status; int ans; bool check = true;
			vector<User> users = read_user_file();
			bool inc = true;
			while (check) {

				cout << "������� �����: "; cin >> login;
				for (size_t i = 0; i < users.size(); i++) {
					if (login != users[i].getLogin() && login != "1") {//������ ������� ����� ��.������ � ������� �������� ������
						inc = false;
					}
					else {
						inc = true;
						i = users.size();
					}
				}
				if (users.empty()) {
					inc = false;
				}
				if (!inc) {
					check = false;
				}
				else {
					cout << "����� ������������ ��� ����!" << endl;
				}
			}
			cout << "������� ������: "; cin >> password;
			check = true;
			while (check) {
				cout << "������� ������:\n1. �����\n2. ������������\n"; cin >> ans;
				while (true) {//�������� �����
					if (cin.fail()) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "������! " << endl;
						cin >> ans;
					}
					if (!cin.fail()) break;
				}
				switch (ans) {
				case 1: {
					status = "admin";
					check = false;
					break;
				}
				case 2: {
					status = "user";
					check = false;
					break;
				}
				default: cout << "������!\n";
				}
			}
			fstream out;
			out.open("UserTable.txt", ios_base::app);//���������� ����� ��.������
			if (out.is_open()) {
				out << login << " " << password << " " << status << " ";//������ � �����
			}
			out.close();
			cout << "������ ������� �������!" << endl;
			break;
		}
		case 3: {
			string login, password, status;
			bool check = true;
			vector<User> users = read_user_file();
			if (users.empty()) {//�������� ����� �� �������
				cout << "���� ����!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << users.size() << endl;
			cout << "������� id ������������, �������� ������ ��������: "; cin >> id;
			while (true) {//�������� �����
				if (cin.fail() || id > users.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "������! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= users.size() && id > 0) break;
			}

			id -= 1;
			while (check) {
				cout << "1. �������� �����" << endl;
				cout << "2. �������� ������" << endl;
				cout << "3. �������� ������" << endl;
				cout << "4. �����" << endl;
				int num; cin >> num;
				while (true) {//�������� �����
					if (cin.fail() || num <= 0 || num >= 5) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "������! " << endl;
						cin >> num;
					}
					if (!cin.fail() && num >= 1 && num <= 4) break;
				}
				switch (num) {
				case 1: {
					bool check2 = true;
					while (check2) {
						bool inc;
						cout << "�����: "; cin >> login;
						for (size_t i = 0; i < users.size(); i++) {
							if (login != users[i].getLogin() && login != "1") {
								inc = false;
							}
							else {
								inc = true;
								i = users.size();
							}
						}
						if (!inc) {
							check2 = false;
						}
						else {
							cout << "����� ������������ ��� ����!" << endl;
						}
					}
					users[id].setLogin(login);//������������� ���������� ������ ������������
					break;
				}
				case 2: {
					cout << "������: "; cin >> password;
					users[id].setPassword(password);//������������� ���������� ������ 
					break;
				}
				case 3: {
					int ans;
					bool check2 = true;
					while (check2) {
						cout << "������:\n1.�����\n2.������������\n"; cin >> ans;
						while (true) {//�������� �����
							if (cin.fail() || ans != 1 || ans != 2) {
								cin.clear();
								cin.ignore(cin.rdbuf()->in_avail());
								cout << "������! " << endl;
								cin >> ans;
							}
							if (!cin.fail() && (ans == 1 || ans == 2)) break;
						}
						switch (ans) {//����� �������
						case 1: {
							users[id].setStatus("admin");
							check2 = false;
							break;
						}
						case 2: {
							users[id].setStatus("user");
							check2 = false;
							break;
						}
						default: cout << "������!\n";
						}
					}
					break;
				}
				case 4: {
					check = false;
					break;
				}
				}
			}
			users_file_update(users);
			cout << "������ ������� ��������!" << endl;
			break;
		}
		case 4: {
			vector<User> users = read_user_file();
			string ans;
			if (read_user_file().empty()) {
				cout << "���� ����!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << "������� id ������������, �������� ������ �������: "; cin >> id;
			while (true) { //�������� �����
				if (cin.fail() || id > users.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "������! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= users.size() && id > 0) break;
			}


			cout << "�� ������������� ������ ������� ������?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				id -= 1;
				if (id > 0 && id < users.size() - 1) {//�������� ����� ������ � ��������� ���������
					users.erase(users.cbegin() + id);
				}
				else if (id == 0) {
					users.erase(users.begin());//�������� ������� ��������
				}
				else if (id == users.size() - 1) {
					users.pop_back();//�������� ���������� ��-��
				}
				users_file_update(users);
				cout << "������ ������� �������\n";
			}
			else {
				cout << "�������� ��������!\n";
			}
			break;
		}
		case 5: {
			string file_name;
			cout << "��� �������� ������� �������� ����� � ��� �����������: "; cin >> file_name;
			ofstream ofs(file_name);//�������� �����
			ofs.close();
			cout << "���� ������� ������!\n";
			about_time();
			break;

		}
		case 6: {
			string file_name, line;
			cout << "��� �������� ������� �������� ����� � ��� �����������: "; cin >> file_name;
			ifstream in(file_name);
			try {//��������� ����������
				if (!in.is_open()) {//�������� ���������� �� ������ �� �������� �����, ��� ������������ �������� catch ����� ���
					throw "������ �������� �����...";
					about_time();
				}
				if (in.is_open())
				{
					cout << "\n�������� �����...\n\n";
					while (getline(in, line))
					{
						cout << line << endl;
					}
					cout << endl;
				}
				in.close();
				if (line.empty()) {
					throw "���� ����!";
					about_time();
				}
			}
			catch (const char* msg) {//���� ������ ����. �� ������� ��� ������������
				cout << msg << endl;
			}
			break;
		}
		case 7: {
			string ans;
			char file_name[80];
			cout << "��� �������� ������� �������� ����� � ��� �����������: "; cin >> file_name;
			cout << "�� ������������� ������ ������� ����?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				remove(file_name); //�������
				cout << "���� �����!\n";
				about_time();
			}
			else {
				cout << "�������� ��������!\n";
				about_time();
			}
			break;
		}
		case 8: {
			try {
				vector<Student> students = read_file();
				if (students.empty()) {
					throw "���� ����!";
					break;
				}
				head();
				show_all(students);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			about_programm();
			about_time();
			break;
		}
		case 9: {
			string group, name, exam = "",  Max = "";
			bool  exams[5];
			int max[5];
			cin.ignore();//������������� ��������� cin
			cout << "������� ������: ";
			getline(cin, group);
			group.push_back(separator);

			cout << "������� ���: ";
			getline(cin, name);
			name.push_back(separator);

			

			

			cout << "������� ������(1 ����, 0 �� ����): ";
			for (size_t i = 0; i < 5; i++)
			{
				cout << "Exam " << i << " = ";
				cin >> exams[i];
			}

			for (size_t i = 0; i < 5; i++)
			{
				exam += to_string(exams[i]);
				exam += ' ';
			}
			exam.push_back(separator);

			cout << "������� ������(5 ������): ";
			for (size_t i = 0; i < 5; i++)
			{
				do {
					cout << "������ " << i << " = ";
					cin >> max[i];
				} while (max[i] < 1 || max[i] > 10);
			}

			for (size_t i = 0; i < 5; i++)
			{
				Max += to_string(max[i]);
				Max += ' ';
			}
			//Max = "3 4 5 6";
			Max.push_back(separator);

			ofstream out;
			out.open("DataTable.txt", ofstream::app);
			if (out.is_open()) {
				out << group << name << exam << Max << std::endl;
			}
			out.close();
			cout << "������ ������� �������!" << endl;
			break;
		}
		case 10: {
			string ans;
			vector<Student> students = read_file();
			if (students.empty()) {
				cout << "���� ����!";
				break;
			}
			head();
			show_all(students);
			int id;
			cout << "������� id ��������, �������� ������ �������: "; cin >> id;
			while (true) { //�������� �����
				if (cin.fail() || id > students.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "������! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= students.size() && id > 0) break;
			}
			cout << "�� ������������� ������ ������� ������?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				id -= 1;
				if (id > 0 && id < students.size() - 1) {
					students.erase(students.cbegin() + id);
				}
				else if (id == 0) {
					students.erase(students.begin());
				}
				else if (id == students.size() - 1) {
					students.pop_back();
				}
				file_update(students);
				cout << "������ ������� �������!\n";
			}
			else {
				cout << "�������� ��������!\n";
			}
			break;
		}
		case 11: {
			string group, name;
			bool exams;
			int  max;
			bool check = true;
			vector<Student> students = read_file();
			if (students.empty()) {
				cout << "���� ����!";
				break;
			}
			head();
			show_all(students);
			int id;
			cout << "������� id ��������, �������� ������ ��������: "; cin >> id;
			while (true) { //�������� �����
				if (cin.fail() || id > students.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "������! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= students.size() && id > 0) break;
			}
			id -= 1;
			while (check) {
				cout << "1. �������� ������" << endl;
				cout << "2. �������� ���" << endl;
				cout << "3. �������� ������" << endl;
				cout << "4. �������� ������" << endl;
				cout << "5. �����" << endl;
				int num; cin >> num;
				while (true) {//�������� �����
					if (cin.fail() || num <= 0 || num >= 6) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "������! " << endl;
						cin >> num;
					}
					if (!cin.fail() && num >= 1 && num <= 6) break;
				}
				switch (num) {
				case 1: {
					cin.ignore();
					cout << "������� ������: "; getline(cin, group);
					students[id].setGroup(group);
					break;
				}
				case 2: {
					cin.ignore();
					cout << "������� ���: "; getline(cin, name);
					students[id].setName(name);
					break;
				}
				case 3: {
					cout << "������� ����� ������ ������� ������ ��������(1-5): ";
					int num;
					do {
						cin >> num;
					} while (num < 1 || num >5);
					cout << "������� ����� ��������(1 - ����, 0 - �� ����): ";
					cin >> exams;
					students[id].setExams(exams, num);
					break;
				}
				case 4: {
					cout << "������� ����� �������� � ������� ������ �������� ������ (1-5): ";
					int num;
					do {
						cin >> num;
					} while (num < 1 || num >5);
					cout << "������� ����� ��������(1-10): ";
					do {
						cin >> max;
					} while (max < 1 || max > 10);
					students[id].setMax(max, num);
					break;
				}
				case 5: {
					check = false;
					break;
				}
				}
			}
			file_update(students);
			cout << "������ ������� ��������!\n";
			break;
		}
		}
		puts("������� ����� �������, ����� ����������");
		system("pause");
		system("cls");
		admin_menu();
	}

	system("cls");
	authorization_menu();
}

//���� ������������
void user_menu() {
	system("cls");
	cout << "���� ������������: " << endl;
	cout << "1. ����� ���������" << endl;
	cout << "2. ������� �������� ����� �����" << endl; // XXXX ������� �� �������� �������� �����
	cout << "3. ������� �������� ����� �������� � ��� ������" << endl;// XXXX ������� �� �������� �������� �����
	cout << "4. ����� ��������� �� ���������" << endl;
	cout << "5. ���������� ��������� �� ���������" << endl << endl;
	cout << "6. ����� �� ���������" << endl;
	cout << "�������� ����� ..." << endl;
	Student students;
	int i;
	cin >> i;
	while (true) {//�������� �����
		if (cin.fail() || i < 1 || i >= 7) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������! " << endl;
			cin >> i;
		}
		if (!cin.fail() && i >= 1 && i <= 6) break;
	}
	while (i != 6) {
		switch (i) {
		case 1: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "���� ����!";
				break;
			}
			head();
			show_all(students);
			break;
		}
		case 2: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "���� ����!";
				break;
			}
			show_all_scolarship(students);
			break;
		}
		case 3: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "���� ����!";
				break;
			}
			string group;
			cout << "������� ����� ������: \n";
			cin.ignore();
			getline(cin, group);
			show_all_scolarship_by_group(students,group);
			break;
		}
		case 4: {
			students.search();
			break;
		}
		case 5: {
			students.sort();
			break;
		 }

		}
		system("pause");
		system("cls");
		user_menu();
	}
	system("cls");
	authorization_menu();
}
void login_menu() {
	const string main_login = "admin";//������� ����� �������, ������ �������
	const string main_password = "admin";
	string login;
	string password;
	bool error = false;
	int block = 0;
	while (block != 3) {
		if (block == 1) {
			cout << "�������� " << 3 - block << " �������!\n";
		}
		else if (block == 2) {
			cout << "�������� " << 3 - block << " �������!\n";
		}
		cout << "������� �����: ";
		cin >> login;
		cout << "������� ������: ";
		cin >> password;
		if (login == main_login && password == main_password) {
			admin_menu();
		}
		else {
			vector<User> users = read_user_file(); // ����� ������� ������ ��� ��������� ������ ��� ���� ������� �������
			for (int i = 0; i < users.size(); i++) {
				if (login == users[i].getLogin() && password == users[i].getPassword()) {
					error = false;
					if (users[i].getStatus() == "admin") {
						admin_menu();
					}
					else if (users[i].getStatus() == "user") {
						user_menu();
					}
				}
			}

		}
		block++;
		if (block == 3) {
			error = true;
		}
		if (error) {
			puts("������ �����!\n");
			system("pause");
			system("cls");
		}
	}
}