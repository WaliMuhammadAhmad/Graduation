#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Customer.h"

using namespace std;

Customer::Customer()
{

	name = " ";
	address = " ";
	phone_number = 0;
	days = 0;
	payment_advance = 0.0;
	bill = 0.0;
	booking_id = 0;
	room = 0;
	status = true;
	username = " ";
	password = " ";

}

Customer::Customer(string local_username, string local_password, string local_name, string local_address, long long local_phone_number, int local_days, float local_payment_advance, double local_bill, int local_booking_id, int local_room, bool local_status)
{
	name = local_name;
	address = local_address;
	phone_number = local_phone_number;
	days = local_days;
	payment_advance = local_payment_advance;
	bill = local_bill;
	booking_id = local_booking_id;
	room = local_room;
	status = local_status;
	username = local_username;
	password = local_password;
}

bool Customer::Customer_Sign_in(string local_name, string local_pass)
{
	username = local_name;
	password = local_pass;

	string file_username, file_password;

	bool found = false;

	fstream Output_Data;

	Output_Data.open("User_Sign_up.txt", ios::in);

	while (Output_Data.eof()==0)
	{

		Output_Data >> file_username >> file_password>>name>>address;

		if (file_username == username && file_password == password)
		{
			found = true;
			break;
		}

	}

	Output_Data.close();

	return found;

}

void Customer::Customer_Sign_up(string local_username, string local_pass, string local_name, string local_address)
{

	username = local_username;
	password = local_pass;
	name = local_name;
	address = local_address;

	fstream Input_Data;

	Input_Data.open("User_Sign_up.txt", ios::out | ios::app);

	Input_Data << username << ' ' << password << ' ' << name << ' ' << address << endl;

	Input_Data.close();

}

void Customer::Check_In(int room_no)
{

	int rent = 50;

	Customer cust;

	int file_room = 0;

	/*if (search_duplicate_room() == true)
	{
		cout << "You have already booked this room\n";
	}

	else
	{*/

		room = room_no;

		fstream Input_Data;

		Input_Data.open("Customer_Data.txt", ios::out | ios::in | ios::app);

		cout << "Enter Customer name : \n";
		cin.ignore();
		getline(cin, name);

		cout << "Enter Customer's Address : \n";
		getline(cin, address);

		cout << "Enter Customer's mobile/phone number : \n";
		cin >> phone_number;

		cout << "Enter days how many days that customer will stay : \n";
		cin >> days;

		while (days <= 0 || days > 31)
		{
			cout << "Invalid input\n";
			cout << "Enter days again how many days that customer will stay : \n";
			cin >> days;
		}

		cout << "Enter Advance payment : \n";
		cin >> payment_advance;

		while (payment_advance < 0)
		{
			cout << "Invalid input\n";
			cout << "Enter Advance payment : \n";
			cout << payment_advance;
		}

		bill = days*rent;

		new_id += 4;

		booking_id = new_id;

		status = true;

		Input_Data << room << ' ' << name << ' ' << address << ' ' << phone_number << ' ' << days << ' ' << payment_advance << ' ' << bill << ' ' << booking_id << ' ' << status << endl;

		Input_Data.close();

		a.Room_Data(room);
	/*}*/

}

bool Customer::Bool_Search_Room(int room_no)
{

	bool status, found = false;

	fstream output_data;

	output_data.open("Customer_Data.txt", ios::in);

	while (output_data.eof() == 0)
	{
		output_data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;
		
		if (room == room_no)
		{
			
			found = true;
			break;
		}
	}

	output_data.close();

	return found;
}

//bool Customer::search_duplicate_room()
//{
//	
//	string local_username, local_address;
//
//	bool status, found = false;
//
//	fstream output_data,read_data;
//
//	output_data.open("User_Sign_up.txt", ios::in);
//	read_data.open("Customer_Data.txt", ios::in);
//
//	while (output_data.eof() == 0)
//	{
//
//		output_data >> username >> password >> local_username >> local_address;
//
//		read_data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;
//
//		if (name == local_username && address == local_address)
//		{
//
//			found = true;
//			break;
//		}
//	}
//
//	output_data.close();
//	read_data.close();
//
//	return found;
//}


int Customer::new_id = 0;