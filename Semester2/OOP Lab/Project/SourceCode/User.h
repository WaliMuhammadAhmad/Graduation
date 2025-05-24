#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class User

{
protected:
	string name;
	string address;
	long long phone_number;
	int days;
	float payment_advance;
	int booking_id;
	double bill;
	int room;
	bool status;
};