#pragma once

#include "includes.h"

class User {
private:
	string login, password, status;
public:
	User(string login, string password, string status);
	void setLogin(string login);
	void setPassword(string password);
	void setStatus(string status);
	void show_users(int i);
	string getLogin();
	string getPassword();
	string getStatus();
};
void user_head();
void show_users_all(vector <User> users);