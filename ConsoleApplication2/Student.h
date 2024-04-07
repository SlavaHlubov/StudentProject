#pragma once
#pragma once
const char separator = '|';
#include "includes.h"

class Student {
private:

	string group; // ����� ������
	string name; // ���
	bool exams[5]; // 0 �����, 1 �����
	int max[5]; //  ������ �� ������ �� 4� ���������
public:
	Student() {}
	Student(string group, string name, bool exams[5], int max[5]);
	//�������
	void setGroup(string group);
	void setName(string name);


	void setExams(bool exams, int i);
	void setMax(int max, int i);



	//�������
	string  getGroup();

	string getName();
	bool getExams(int);
	int getMax(int);



	//����� ������ � ���������
	void show(int i);
	void show_dept(int i, Student st);
	void show_scholarship(int i, Student);
	void search();//������� ������ � ����������
	void sort();//������� ����������

};
vector<Student> read_file();
void head(string);
void head();
void show_all(vector <Student> studenst);
double avarage_max(Student student);
int debt(Student student);
void show_all_scolarship_by_group(vector <Student> studenstm, string group);

void show_all_scolarship(vector <Student> studenst);
void show_all_students_by_dept(vector <Student> studenst);