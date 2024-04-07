#include "User.h"

User::User(string login, string password, string status) {
	setLogin(login);
	setPassword(password);
	setStatus(status);
}
void User::setLogin(string login) {
	this->login = login;
}
void User::setPassword(string password) {
	this->password = password;
}
void User::setStatus(string status) {
	this->status = status;
}
void show_users_all(vector <User> users) {
	for (int i = 0; i < (int)users.size(); i++)
	{
		int j = i + 1;
		users[i].show_users(j);
	}
}
void user_head() {
	cout << "\n\t\t\tИнформация о пользователях\n"
		<< "------------------------------------------------------------------\n"
		<< "|  " << "id" << "  |\t" << "login" << "\t\t|\t" << "password" << "\t| " << "status" << " |\n"
		<< "------------------------------------------------------------------\n";
}
void User::show_users(int i) {
	cout << "|  " << setw(4) << left << i << "|  " << setw(22) << login << "|  " << setw(21) << password << "| " << setw(7) << status << "|\n"
		<< "------------------------------------------------------------------\n";
}
string User::getLogin() {
	return login;
}
string User::getPassword() {
	return password;
}
string User::getStatus() {
	return status;
}

