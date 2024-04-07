#pragma once
#pragma once
const char separator = '|';
#include "includes.h"

class Student {
private:

	string group; // номер группы
	string name; // ФИО
	bool exams[5]; // 0 незач, 1 зачет
	int max[5]; //  Оценка за каждый из 4х предметов
public:
	Student() {}
	Student(string group, string name, bool exams[5], int max[5]);
	//сеттеры
	void setGroup(string group);
	void setName(string name);


	void setExams(bool exams, int i);
	void setMax(int max, int i);



	//геттеры
	string  getGroup();

	string getName();
	bool getExams(int);
	int getMax(int);



	//вывод данных о студентах
	void show(int i);
	void show_dept(int i, Student st);
	void show_scholarship(int i, Student);
	void search();//функция поиска и фильтрации
	void sort();//функция сортировки

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