#include "Menu.h"
#include "User.h"
#include "Student.h"
#include "Files.h"
void authorization_menu() {
	info();
	cout << "Авторизация:\n";
	cout << "1. Вход" << endl;
	cout << "2. Выход" << endl;
	int a;
	cin >> a;

	while (true) {//проверка ввода
		if (cin.fail() || a < 1 || a>2) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка!" << endl;
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
	cout << "Программу выполнил:  " << endl;
	cout << "Студет группы: " << endl;
	cout << "Преподаватель: " << endl;
	cout << "Текущая дата и время: " << stm.wHour << ":" << stm.wMinute << " " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "\n\n";
	cout << "Год разработки:\t\t\t2023\n" << endl << endl;
	system("pause");
	system("cls");
}


void about_time() {//возможность вставки на страницу текущей даты и времени
	SYSTEMTIME stm;
	GetLocalTime(&stm);
	cout << "\n\nТекущая дата и время: " << stm.wHour << ":" << stm.wMinute << " " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "\n\n";
}

void about_programm() {//информация о разработчике, руководителе проекта, год разработки
	cout << "\n\nРазработчик проекта: " << endl;
	cout << "Год разработки: 2023" << endl;
}

void admin_menu() {
	system("cls");
	cout << "-------------------------------------------------" << endl;
	cout << "|\t\tМеню администратора\t\t|" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "Управление учетными записями пользователей: " << endl;
	cout << "1. Просмотр всех учетных записей пользователей" << endl;
	cout << "2. Добавление учетной записи пользователя" << endl;
	cout << "3. Редактирование учетной записи пользователя" << endl;
	cout << "4. Удаление учетной записи пользователя" << endl << endl;
	cout << "Работа с файлом данных: " << endl;
	cout << "5. Создать файл" << endl;
	cout << "6. Открыть файл" << endl;
	cout << "7. Удалить файл" << endl << endl;
	cout << "Работа с данными: " << endl;
	cout << "8. Просмотр данных" << endl;
	cout << "9. Добавление записи" << endl;
	cout << "10. Удаление записи о студенте" << endl;
	cout << "11. Редактирование студента" << endl;
	cout << "12. Выйти из программы" << endl << endl;
	cout << "Выберите пункт ..." << endl;
	int i;
	cin >> i;
	while (true) {//проверка ввода
		if (cin.fail() || i < 1 || i >= 13) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Введите корректное значение " << endl;
			cin >> i;
		}
		if (!cin.fail() && i >= 1 && i <= 13) break;
	}
	while (i != 12) {
		switch (i) {
		case 1: {
			vector<User> users = read_user_file();
			if (users.empty()) {
				cout << "Файл пуст!";
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

				cout << "Введите логин: "; cin >> login;
				for (size_t i = 0; i < users.size(); i++) {
					if (login != users[i].getLogin() && login != "1") {//нельзя создать новую уч.запись с логином главного админа
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
					cout << "Такой пользователь уже есть!" << endl;
				}
			}
			cout << "Введите пароль: "; cin >> password;
			check = true;
			while (check) {
				cout << "Введите статус:\n1. админ\n2. пользователь\n"; cin >> ans;
				while (true) {//проверка ввода
					if (cin.fail()) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Ошибка! " << endl;
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
				default: cout << "Ошибка!\n";
				}
			}
			fstream out;
			out.open("UserTable.txt", ios_base::app);//добавление новой уч.записи
			if (out.is_open()) {
				out << login << " " << password << " " << status << " ";//запись в поток
			}
			out.close();
			cout << "Запись успешно создана!" << endl;
			break;
		}
		case 3: {
			string login, password, status;
			bool check = true;
			vector<User> users = read_user_file();
			if (users.empty()) {//проверка файла на пустоту
				cout << "Файл пуст!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << users.size() << endl;
			cout << "Введите id пользователя, которого хотите изменить: "; cin >> id;
			while (true) {//проверка ввода
				if (cin.fail() || id > users.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Ошибка! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= users.size() && id > 0) break;
			}

			id -= 1;
			while (check) {
				cout << "1. Изменить логин" << endl;
				cout << "2. Изменить пароль" << endl;
				cout << "3. Изменить статус" << endl;
				cout << "4. Выйти" << endl;
				int num; cin >> num;
				while (true) {//проверка ввода
					if (cin.fail() || num <= 0 || num >= 5) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Ошибка! " << endl;
						cin >> num;
					}
					if (!cin.fail() && num >= 1 && num <= 4) break;
				}
				switch (num) {
				case 1: {
					bool check2 = true;
					while (check2) {
						bool inc;
						cout << "логин: "; cin >> login;
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
							cout << "Такой пользователь уже есть!" << endl;
						}
					}
					users[id].setLogin(login);//инициализация переменной логина пользователя
					break;
				}
				case 2: {
					cout << "пароль: "; cin >> password;
					users[id].setPassword(password);//инициализация переменной пароля 
					break;
				}
				case 3: {
					int ans;
					bool check2 = true;
					while (check2) {
						cout << "статус:\n1.админ\n2.пользователь\n"; cin >> ans;
						while (true) {//проверка ввода
							if (cin.fail() || ans != 1 || ans != 2) {
								cin.clear();
								cin.ignore(cin.rdbuf()->in_avail());
								cout << "Ошибка! " << endl;
								cin >> ans;
							}
							if (!cin.fail() && (ans == 1 || ans == 2)) break;
						}
						switch (ans) {//выбор статуса
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
						default: cout << "Ошибка!\n";
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
			cout << "Запись успешно изменена!" << endl;
			break;
		}
		case 4: {
			vector<User> users = read_user_file();
			string ans;
			if (read_user_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << "Введите id пользователя, которого хотите удалить: "; cin >> id;
			while (true) { //проверка ввода
				if (cin.fail() || id > users.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Ошибка! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= users.size() && id > 0) break;
			}


			cout << "Вы действительно хотите удалить запись?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				id -= 1;
				if (id > 0 && id < users.size() - 1) {//удаление между первым и последним элементом
					users.erase(users.cbegin() + id);
				}
				else if (id == 0) {
					users.erase(users.begin());//удаление первого элемента
				}
				else if (id == users.size() - 1) {
					users.pop_back();//удаление последнего эл-та
				}
				users_file_update(users);
				cout << "Запись успешно удалена\n";
			}
			else {
				cout << "Удаление отменено!\n";
			}
			break;
		}
		case 5: {
			string file_name;
			cout << "Для создания введите название файла с его расширением: "; cin >> file_name;
			ofstream ofs(file_name);//создание файла
			ofs.close();
			cout << "Файл успешно создан!\n";
			about_time();
			break;

		}
		case 6: {
			string file_name, line;
			cout << "Для открытия введите название файла с его расширением: "; cin >> file_name;
			ifstream in(file_name);
			try {//обработка исключений
				if (!in.is_open()) {//создание исключения на случай не открытия файла, при срабатывании которого catch ловит его
					throw "Ошибка открытия файла...";
					about_time();
				}
				if (in.is_open())
				{
					cout << "\nОткрытие файла...\n\n";
					while (getline(in, line))
					{
						cout << line << endl;
					}
					cout << endl;
				}
				in.close();
				if (line.empty()) {
					throw "Файл пуст!";
					about_time();
				}
			}
			catch (const char* msg) {//если словил искл. то выведет его пользователю
				cout << msg << endl;
			}
			break;
		}
		case 7: {
			string ans;
			char file_name[80];
			cout << "Для удаления введите название файла с его расширением: "; cin >> file_name;
			cout << "Вы действительно хотите удалить файл?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				remove(file_name); //удалить
				cout << "Файл удалён!\n";
				about_time();
			}
			else {
				cout << "Удаление отменено!\n";
				about_time();
			}
			break;
		}
		case 8: {
			try {
				vector<Student> students = read_file();
				if (students.empty()) {
					throw "Файл пуст!";
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
			cin.ignore();//игнорирование оператора cin
			cout << "Введите группу: ";
			getline(cin, group);
			group.push_back(separator);

			cout << "Введите фио: ";
			getline(cin, name);
			name.push_back(separator);

			

			

			cout << "Введите зачеты(1 сдан, 0 не сдан): ";
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

			cout << "Введите оценки(5 оценок): ";
			for (size_t i = 0; i < 5; i++)
			{
				do {
					cout << "Оценка " << i << " = ";
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
			cout << "Запись успешно создана!" << endl;
			break;
		}
		case 10: {
			string ans;
			vector<Student> students = read_file();
			if (students.empty()) {
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(students);
			int id;
			cout << "Введите id студента, которого хотите удалить: "; cin >> id;
			while (true) { //проверка ввода
				if (cin.fail() || id > students.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Ошибка! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= students.size() && id > 0) break;
			}
			cout << "Вы действительно хотите удалить запись?(y/n): "; cin >> ans;
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
				cout << "Запись успешно удалена!\n";
			}
			else {
				cout << "Удаление отменено!\n";
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
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(students);
			int id;
			cout << "Введите id студента, которого хотите изменить: "; cin >> id;
			while (true) { //проверка ввода
				if (cin.fail() || id > students.size() || id <= 0) {
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Ошибка! " << endl;
					cin >> id;
				}
				if (!cin.fail() && id <= students.size() && id > 0) break;
			}
			id -= 1;
			while (check) {
				cout << "1. Изменить группу" << endl;
				cout << "2. Изменить фио" << endl;
				cout << "3. Изменить зачеты" << endl;
				cout << "4. Изменить оценки" << endl;
				cout << "5. Выйти" << endl;
				int num; cin >> num;
				while (true) {//проверка ввода
					if (cin.fail() || num <= 0 || num >= 6) {
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "Ошибка! " << endl;
						cin >> num;
					}
					if (!cin.fail() && num >= 1 && num <= 6) break;
				}
				switch (num) {
				case 1: {
					cin.ignore();
					cout << "Введите группу: "; getline(cin, group);
					students[id].setGroup(group);
					break;
				}
				case 2: {
					cin.ignore();
					cout << "Введите фио: "; getline(cin, name);
					students[id].setName(name);
					break;
				}
				case 3: {
					cout << "Введите номер зачета который хотите изменить(1-5): ";
					int num;
					do {
						cin >> num;
					} while (num < 1 || num >5);
					cout << "Введите новое значение(1 - сдан, 0 - не сдан): ";
					cin >> exams;
					students[id].setExams(exams, num);
					break;
				}
				case 4: {
					cout << "Введите номер предмета в котором хотите изменить оценку (1-5): ";
					int num;
					do {
						cin >> num;
					} while (num < 1 || num >5);
					cout << "Введите новое значение(1-10): ";
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
			cout << "Запись успешно изменена!\n";
			break;
		}
		}
		puts("Нажмите любую клавишу, чтобы продолжить");
		system("pause");
		system("cls");
		admin_menu();
	}

	system("cls");
	authorization_menu();
}

//меню пользователя
void user_menu() {
	system("cls");
	cout << "Меню пользователя: " << endl;
	cout << "1. Вывод студентов" << endl;
	cout << "2. Подсчет среднего балла групп" << endl; // XXXX задание по подсчету среднего балла
	cout << "3. Подсчет среднего балла студента и его группы" << endl;// XXXX задание по подсчету среднего балла
	cout << "4. Поиск студентов по критериям" << endl;
	cout << "5. Сортировка студентов по критериям" << endl << endl;
	cout << "6. Выход из программы" << endl;
	cout << "Выберите пункт ..." << endl;
	Student students;
	int i;
	cin >> i;
	while (true) {//проверка ввода
		if (cin.fail() || i < 1 || i >= 7) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> i;
		}
		if (!cin.fail() && i >= 1 && i <= 6) break;
	}
	while (i != 6) {
		switch (i) {
		case 1: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(students);
			break;
		}
		case 2: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			show_all_scolarship(students);
			break;
		}
		case 3: {
			vector<Student> students = read_file();
			if (read_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			string group;
			cout << "Введите номер группы: \n";
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
	const string main_login = "admin";//Главный админ системы, нельзя удалить
	const string main_password = "admin";
	string login;
	string password;
	bool error = false;
	int block = 0;
	while (block != 3) {
		if (block == 1) {
			cout << "Осталось " << 3 - block << " попытки!\n";
		}
		else if (block == 2) {
			cout << "Осталась " << 3 - block << " попытка!\n";
		}
		cout << "Введите логин: ";
		cin >> login;
		cout << "Введите пароль: ";
		cin >> password;
		if (login == main_login && password == main_password) {
			admin_menu();
		}
		else {
			vector<User> users = read_user_file(); // вызов функции чтения для получения данных обо всех учетных записях
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
			puts("Ошибка входа!\n");
			system("pause");
			system("cls");
		}
	}
}