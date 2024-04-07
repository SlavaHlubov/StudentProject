#include "Student.h"
#include "Menu.h"

void Student::setGroup(string group) {
	this->group = group;
}
void Student::setName(string name) {
	this->name = name;
}


void Student::setExams(bool exams, int i) {
	this->exams[i] = exams;
}
void Student::setMax(int max, int i) {
	this->max[i] = max;
}

string Student::getGroup() {
	return group;
}

string Student::getName() {
	return name;
}

bool Student::getExams(int i) {
	return exams[i];
}
int Student::getMax(int i) {
	return max[i];
}



//вывод 
void Student::show(int i) // popravit
{
	cout << "| " << setw(4) << left << i << left << "| "
		<< setw(6) << getGroup() << left << "| "
		<< setw(32) << getName() << left << "| "
		<< getExams(0) << ' ' << getExams(1) << ' ' << getExams(2) << ' ' << getExams(3) << ' '
		<< setw(8) << getExams(4) << left << setw(2) << "| " << left
		<< setw(3) << getMax(0) << left
		<< setw(3) << getMax(1) << left
		<< setw(3) << getMax(2) << left
		<< setw(3) << getMax(3) << left
		<< setw(3) << getMax(4) << left << "| \n";
	cout << "---------------------------------------------------------------------------------------------------------------------\n";
}
int debt(Student student) {
	int sum_debt = 0;
	for (int i = 0; i < 5; i++) {
		if (student.getExams(i) == 0)
			sum_debt++;
	}
	
	return sum_debt;
}
double avarage_max(Student student)
{
	int sum = 0;
	for (int i = 0; i < 5; i++) sum += student.getMax(i);
	return sum / 5.0;
}
void Student::show_dept(int i, Student st)
{
	cout << "| " << setw(4) << left << i << left << "| "
		<< setw(6) << getGroup() << left << "| "
		<< setw(32) << getName() << left << "| "
		<< getExams(0) << ' ' << getExams(1) << ' ' << getExams(2) << ' ' << getExams(3) << ' '
		<< setw(8) << getExams(4) << left << setw(2) << "| " << left
		<< setw(3) << getMax(0) << left
		<< setw(3) << getMax(1) << left
		<< setw(3) << getMax(2) << left
		<< setw(3) << getMax(3) << left
		<< setw(3) << getMax(4) << left
		<< "| "
		<< setw(12) << debt(st) << left << "| \n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

}

void head() {
	cout << "\n\t\t\t\tИнформация о студентах\n";

	cout << "---------------------------------------------------------------------------------------------------------------------\n";

	cout << "| " << setw(4) << left << "id" << left << "| "
		<< setw(6) << "Группа" << left << "| "
		<< setw(32) << "Фио" << left << "| "
		<< setw(8) << "Сданные экзамены" << left << "| "
		<< setw(12) << "Оценки " << left << "| \n";
	cout << "---------------------------------------------------------------------------------------------------------------------\n";

}
void head(string str) {
	cout << "\n\t\t\t\tИнформация о студентах\n";

	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

	cout << "| " << setw(4) << left << "id" << left << "| "
		<< setw(6) << "Группа" << left << "| "
		<< setw(32) << "Фио" << left << "| "
		<< setw(8) << "Сданные экзамены" << left << "| "
		<< setw(14) << "Оценки " << left << "| "
		<< setw(10) << str << left << "| \n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

}
void Student::show_scholarship(int i, Student st)
{
	cout << "| " << setw(4) << left << i << left << "| "
		<< setw(6) << getGroup() << left << "| "
		<< setw(32) << getName() << left << "| "
		<< getExams(0) << ' ' << getExams(1) << ' ' << getExams(2) << ' ' << getExams(3) << ' '
		<< setw(8) << getExams(4) << left << setw(2) << "| " << left
		<< setw(3) << getMax(0) << left
		<< setw(3) << getMax(1) << left
		<< setw(3) << getMax(2) << left
		<< setw(3) << getMax(3) << left
		<< setw(3) << getMax(4) << left
		<< "| "
		<< setw(12) << avarage_max(st) << left << "| \n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

}

void show_all_scolarship(vector <Student> studenst)//в эту функцию передается вектор объектов класса Student
{
	string str = "Средний балл ";
	int cnt_group_member = 0;
	int sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		//int j = i + 1;
		//if (studenst[i].getGroup() == Group) {
			studenst[i].show_scholarship(i, studenst[i]);// j - id студента, для каждого студента вызывается метод show
			cnt_group_member++;
			sum_max = sum_max + avarage_max(studenst[i]); //zzzz

		//}
	}
	cout << "Средний балл групп(ы): " << sum_max/ cnt_group_member << '\n';
}
void show_all_scolarship_by_group(vector <Student> studenst,string group) {
	string str = "Средний балл ";
	int cnt_group_member = 0;
	double sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		
		if (studenst[i].getGroup() == group) {
			studenst[i].show_scholarship(i, studenst[i]);// j - id студента, для каждого студента вызывается метод show
			cnt_group_member++;
			sum_max = sum_max + avarage_max(studenst[i]); //zzzz

		}
	}
	cout << "Средний балл групп(ы): " << sum_max / cnt_group_member << '\n';
}
void show_all_students_by_dept(vector <Student> studenst) {
	string str = "Кол-во долгов ";
	int cnt_group_member = 0;
	double sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{

			studenst[i].show_dept(i, studenst[i]);// j - id студента, для каждого студента вызывается метод show

			

	}

}
void show_all(vector <Student> studenst)//в эту функцию передается вектор объектов класса TStudent
{
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		int j = i + 1;
		studenst[i].show(j);// j - id студента, для каждого студента вызывается метод show
	}
}
vector<Student> read_file() {
	Student student; // объект класса
	vector<Student> students; //вектор студентов
	string line; // строка для записи считывания
	ifstream in;
	int count = 0;
	in.open("DataTable.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			stringstream ss(line); // переменная для разделения считываемого
			while (getline(ss, line, separator)) {
				switch (count) { 
				case 0: {
					student.setGroup(line);
					break;
				}

				case 1: {
					student.setName(line);
					break;
				}

				case 2: {
					stringstream ss2(line);
					int i = 0;
					while (getline(ss2, line, ' ')) {
						student.setExams(atoi(line.c_str()), i); // line = "1 1 1 1 1"
						i++;
					}
					break;
				}
				case 3: {
					stringstream ss2(line);
					int i = 0;
					while (getline(ss2, line, ' ')) {
						student.setMax(atoi(line.c_str()), i);
						i++;
					}
					break;
				}

				}

				count++;
				if (count == 4) {
					count = 0;
					students.push_back(student); //запись считанных данных в вектор
				}

			}
		}
	}
	in.close();
	return students;
}



void Student::search() {
	vector<Student> students = read_file();
	string group, name;
	bool form_of_study;
	int pass_hours;

	int ans;
	cout << "Поиск по:\n1.Группе\n2.ФИО\n3.Сданному/несданному зачету\n4.Оценке\n";
	cin >> ans;
	while (true) {//проверка ввода
		if (cin.fail() || ans < 1 || ans >= 5) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> ans;
		}
		if (!cin.fail() && ans >= 1 && ans <= 6) break;
	}
	switch (ans) {
	case 1: {
		int students_count = 0;
		cin.ignore();
		cout << "Введите группу: "; getline(cin, group);
		head();
		for (int i = 0; i < students.size(); i++)
		{
			if (group == students[i].getGroup()) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\nТакой студент(ы) не найден!\n" << endl;
		}
		break;
	}
	case 2: {
		int students_count = 0;
		cin.ignore();
		cout << "Введите ФИО: "; getline(cin, name);
		head();
		for (int i = 0; i < students.size(); i++)
		{
			if (name == students[i].getName()) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\nТакой студент(ы) не найден!\n" << endl;
		}
		break;
	}


	case 3: {
		int students_count = 0;
		cout << "Поиск по сданному/не сданному зачету(1/0): ";
		bool find_by_exam;
		cin >> find_by_exam;
		int numExam;
		cout << "\nВведите номер зачета(1-5)";
		do {
			cin >> numExam;
		} while (numExam < 1 || numExam > 5);
		head();

		for (int i = 0; i < students.size(); i++)
		{
			if (find_by_exam == students[i].getExams(numExam)) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\nТакой студент(ы) не найден!\n" << endl;
		}
		break;
	}
	case 4: {
		int students_count = 0;
		cout << "Введите оценку: ";
		int max;
		cin >> max;
		int numSubject;
		cout << "\nВведите номер предмета(1-5)";
		do {
			cin >> numSubject;
		} while (numSubject < 1 || numSubject > 5);
		head();

		for (int i = 0; i < students.size(); i++)
		{
			if (max == students[i].getMax(numSubject)) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\nТакой студент(ы) не найден!\n" << endl;
		}
		break;
	}


	default: cout << "Данных не найдено!\n";
	}

}

//сортировка
void Student::sort() {
	vector<Student> students = read_file();
	int ans;
	cout << "Сортировать по:\n1.Группе\n2.ФИО\n3. Среднему баллу каждого студента группы X\n4. По кол-ву задолженностей\n";

	cin >> ans;
	while (true) {//проверка ввода

		if (cin.fail() || ans < 1 || ans >= 6) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> ans;
		}
		if (!cin.fail() && ans >= 1 && ans <= 6) break;
	}
	cout << "Сортировка..." << endl;
	switch (ans) {
	case 1: {
		vector< Student> sorted_students = students;
		vector<string> sorter;
		for (int i = 0; i < sorted_students.size(); i++) {
			sorter.push_back(sorted_students[i].getGroup());
		}
		string temp;
		Student temp_client;
		for (int i = 0; i < sorted_students.size() - 1; i++) {
			for (int j = 0; j < sorted_students.size() - i - 1; j++) {
				if (sorter[j] < sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_students[j];
					sorter[j] = sorter[j + 1];
					sorted_students[j] = sorted_students[j + 1];
					sorter[j + 1] = temp;
					sorted_students[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_students);
		break;
	}
	case 2: {
		vector<Student> sorted_students = students;
		vector<string> sorter;
		for (int i = 0; i < sorted_students.size(); i++) {
			sorter.push_back(sorted_students[i].getName());
		}
		string temp;
		Student temp_client;
		for (int i = 0; i < sorted_students.size() - 1; i++) {
			for (int j = 0; j < sorted_students.size() - i - 1; j++) {
				if (sorter[j] < sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_students[j];
					sorter[j] = sorter[j + 1];
					sorted_students[j] = sorted_students[j + 1];
					sorter[j + 1] = temp;
					sorted_students[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_students);
		break;
	}
	case 3: {
		string Group;
		cout << "Enter number of group: ";
		cin.ignore();
		getline(cin, Group);
		vector< Student> sorted_students = students;
		vector<double> sorter;
		for (int i = 0; i < sorted_students.size(); i++) {
			sorter.push_back(avarage_max(sorted_students[i]));
		}
		int temp;
		Student temp_client;
		for (int i = 0; i < sorted_students.size() - 1; i++) {
			for (int j = 0; j < sorted_students.size() - i - 1; j++) {
				if (sorter[j] < sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_students[j];
					sorter[j] = sorter[j + 1];
					sorted_students[j] = sorted_students[j + 1];
					sorter[j + 1] = temp;
					sorted_students[j + 1] = temp_client;
				}
			}
		}
		show_all_scolarship_by_group(sorted_students, Group); // Сюда передать Group
		break;
	}
	case 4: {
		
		
		vector< Student> sorted_students = students;
		vector<double> sorter;
		for (int i = 0; i < sorted_students.size(); i++) {
			sorter.push_back(debt(sorted_students[i]));
		}
		int temp;
		Student temp_client;
		for (int i = 0; i < sorted_students.size() - 1; i++) {
			for (int j = 0; j < sorted_students.size() - i - 1; j++) {
				if (sorter[j] < sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_students[j];
					sorter[j] = sorter[j + 1];
					sorted_students[j] = sorted_students[j + 1];
					sorter[j + 1] = temp;
					sorted_students[j + 1] = temp_client;
				}
			}
		}
		show_all_students_by_dept(sorted_students); // Сюда передать Group
		break;
	}


	default: cout << "Данных не найдено!\n";
	}
}