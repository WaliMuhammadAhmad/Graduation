#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"User.h"
#include"Room.h"

using namespace std;

class Customer final : protected User
{

private:

	Room a;
	string username;
	string password;
	
protected:

	static int new_id;

public:

	Customer();
	Customer(string local_username, string local_password, string local_name,
		string local_address, long long local_phone_number, int local_days,
		float local_payment_advance,double local_bill, int local_booking_id, 
		int local_room, bool local_status);
	bool Customer_Sign_in(string , string );
	void Customer_Sign_up(string , string,string,string );
	void Check_In(int);
	bool Bool_Search_Room(int);
	/*bool search_duplicate_room();*/
};