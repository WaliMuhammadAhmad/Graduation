#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Customer.h"
#include"Room.h"
#include"User.h"

using namespace std;

class Admin final : protected User
{
private:

	Room a;
	Customer cust;
	int no_of_rooms;
	int no_of_cust;
	string Adminname;
	string password;

public:

	Admin();
	Admin(int , int , string , string );
	bool Admin_Sign_in(string , string );
	void Summary();
	void Check_Out(int ,int);
	void Search_Cust(int );
	void Admin_Signup(string , string );
};