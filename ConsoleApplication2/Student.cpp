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



//����� 
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
	cout << "\n\t\t\t\t���������� � ���������\n";

	cout << "---------------------------------------------------------------------------------------------------------------------\n";

	cout << "| " << setw(4) << left << "id" << left << "| "
		<< setw(6) << "������" << left << "| "
		<< setw(32) << "���" << left << "| "
		<< setw(8) << "������� ��������" << left << "| "
		<< setw(12) << "������ " << left << "| \n";
	cout << "---------------------------------------------------------------------------------------------------------------------\n";

}
void head(string str) {
	cout << "\n\t\t\t\t���������� � ���������\n";

	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

	cout << "| " << setw(4) << left << "id" << left << "| "
		<< setw(6) << "������" << left << "| "
		<< setw(32) << "���" << left << "| "
		<< setw(8) << "������� ��������" << left << "| "
		<< setw(14) << "������ " << left << "| "
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

void show_all_scolarship(vector <Student> studenst)//� ��� ������� ���������� ������ �������� ������ Student
{
	string str = "������� ���� ";
	int cnt_group_member = 0;
	int sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		//int j = i + 1;
		//if (studenst[i].getGroup() == Group) {
			studenst[i].show_scholarship(i, studenst[i]);// j - id ��������, ��� ������� �������� ���������� ����� show
			cnt_group_member++;
			sum_max = sum_max + avarage_max(studenst[i]); //zzzz

		//}
	}
	cout << "������� ���� �����(�): " << sum_max/ cnt_group_member << '\n';
}
void show_all_scolarship_by_group(vector <Student> studenst,string group) {
	string str = "������� ���� ";
	int cnt_group_member = 0;
	double sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		
		if (studenst[i].getGroup() == group) {
			studenst[i].show_scholarship(i, studenst[i]);// j - id ��������, ��� ������� �������� ���������� ����� show
			cnt_group_member++;
			sum_max = sum_max + avarage_max(studenst[i]); //zzzz

		}
	}
	cout << "������� ���� �����(�): " << sum_max / cnt_group_member << '\n';
}
void show_all_students_by_dept(vector <Student> studenst) {
	string str = "���-�� ������ ";
	int cnt_group_member = 0;
	double sum_max = 0;
	head(str);
	for (int i = 0; i < (int)studenst.size(); i++)
	{

			studenst[i].show_dept(i, studenst[i]);// j - id ��������, ��� ������� �������� ���������� ����� show

			

	}

}
void show_all(vector <Student> studenst)//� ��� ������� ���������� ������ �������� ������ TStudent
{
	for (int i = 0; i < (int)studenst.size(); i++)
	{
		int j = i + 1;
		studenst[i].show(j);// j - id ��������, ��� ������� �������� ���������� ����� show
	}
}
vector<Student> read_file() {
	Student student; // ������ ������
	vector<Student> students; //������ ���������
	string line; // ������ ��� ������ ����������
	ifstream in;
	int count = 0;
	in.open("DataTable.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			stringstream ss(line); // ���������� ��� ���������� ������������
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
					students.push_back(student); //������ ��������� ������ � ������
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
	cout << "����� ��:\n1.������\n2.���\n3.��������/���������� ������\n4.������\n";
	cin >> ans;
	while (true) {//�������� �����
		if (cin.fail() || ans < 1 || ans >= 5) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������! " << endl;
			cin >> ans;
		}
		if (!cin.fail() && ans >= 1 && ans <= 6) break;
	}
	switch (ans) {
	case 1: {
		int students_count = 0;
		cin.ignore();
		cout << "������� ������: "; getline(cin, group);
		head();
		for (int i = 0; i < students.size(); i++)
		{
			if (group == students[i].getGroup()) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\n����� �������(�) �� ������!\n" << endl;
		}
		break;
	}
	case 2: {
		int students_count = 0;
		cin.ignore();
		cout << "������� ���: "; getline(cin, name);
		head();
		for (int i = 0; i < students.size(); i++)
		{
			if (name == students[i].getName()) {
				students_count++;
				students[i].show(i + 1);
			}
		}
		if (students_count == 0) {
			cout << "\n����� �������(�) �� ������!\n" << endl;
		}
		break;
	}


	case 3: {
		int students_count = 0;
		cout << "����� �� ��������/�� �������� ������(1/0): ";
		bool find_by_exam;
		cin >> find_by_exam;
		int numExam;
		cout << "\n������� ����� ������(1-5)";
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
			cout << "\n����� �������(�) �� ������!\n" << endl;
		}
		break;
	}
	case 4: {
		int students_count = 0;
		cout << "������� ������: ";
		int max;
		cin >> max;
		int numSubject;
		cout << "\n������� ����� ��������(1-5)";
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
			cout << "\n����� �������(�) �� ������!\n" << endl;
		}
		break;
	}


	default: cout << "������ �� �������!\n";
	}

}

//����������
void Student::sort() {
	vector<Student> students = read_file();
	int ans;
	cout << "����������� ��:\n1.������\n2.���\n3. �������� ����� ������� �������� ������ X\n4. �� ���-�� ��������������\n";

	cin >> ans;
	while (true) {//�������� �����

		if (cin.fail() || ans < 1 || ans >= 6) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������! " << endl;
			cin >> ans;
		}
		if (!cin.fail() && ans >= 1 && ans <= 6) break;
	}
	cout << "����������..." << endl;
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
		show_all_scolarship_by_group(sorted_students, Group); // ���� �������� Group
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
		show_all_students_by_dept(sorted_students); // ���� �������� Group
		break;
	}


	default: cout << "������ �� �������!\n";
	}
}