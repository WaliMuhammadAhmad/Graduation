#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Admin.h"

using namespace std;

Admin::Admin()
{
	no_of_rooms = 0;
	no_of_cust = 0;
	Adminname = " ";
	password = " ";
}

Admin::Admin(int room_no, int customer_no, string local_name, string local_password)
{
	no_of_rooms = room_no;
	no_of_cust = customer_no;
	Adminname = local_name;
	password = local_password;
}


bool Admin::Admin_Sign_in(string local_name, string local_pass)
{

	Adminname = local_name;
	password = local_pass;

	string file_Adminname, file_password;

	bool found = false;

	fstream Output_Data;

	Output_Data.open("Admin_Sign_up.txt", ios::in);

	while (Output_Data.eof() == 0)
	{
		Output_Data >> file_Adminname >> file_password;

		if (file_Adminname == Adminname && file_password == password)
		{
			found = true;
			break;
		}

	}

	Output_Data.close();

	return found;

}

void Admin::Summary()
{

	fstream Output_Data;

	Output_Data.open("Customer_Data.txt", ios::in);

	Output_Data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;
	while (Output_Data.eof() == 0)
	{
		cout << "Summary for " << name << " are\n\n";

		cout << "Booking id : " << booking_id << endl;
		cout << "Name of Customer : " << name << endl;
		cout << "Customer's phone number : " << phone_number << endl;
		cout << "Customer's address : " << address << endl;
		cout << "Customer's Room : " << room << endl;
		cout << "Status of customer : " << status << endl;
		cout << "Staying days of customer : " << days << "\n\n";
		Output_Data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;

	}

	Output_Data.close();

}

void Admin::Check_Out(int booking_id_cust,int new_room)
{

	int new_booking_id = booking_id_cust;

	fstream Output_Data;
	fstream temp;

	Output_Data.open("Customer_Data.txt", ios::in);
	temp.open("Temp.txt", ios::out | ios::app);

	Output_Data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;
	while (Output_Data.eof() == 0)
	{
		if (new_booking_id != booking_id)
		{
			temp << room << ' ' << name << ' ' << address << ' ' << phone_number << ' ' << days << ' ' << payment_advance << ' ' << bill << ' ' << booking_id << ' ' << status << endl;
		}
		Output_Data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;

	}

	temp.close();
	Output_Data.close();
	remove("Customer_Data.txt");
	rename("temp.txt", "Customer_Data.txt");

	a.Room_Check_Out(new_room);

}

void Admin::Search_Cust(int Booking_id_Cust)
{

	int new_booking_id = Booking_id_Cust;

	fstream Output_Data;

	Output_Data.open("Customer_Data.txt", ios::in);

	while (Output_Data.eof() == 0)
	{
		Output_Data >> room >> name >> address >> phone_number >> days >> payment_advance >> bill >> booking_id >> status;

		if (new_booking_id == booking_id)
		{

			cout << "Details for Customer " << name << " are\n\n";

			cout << "Booking id : " << booking_id << endl;
			cout << "Name of Customer : " << name << endl;
			cout << "Customer's phone number : " << phone_number << endl;
			cout << "Customer's address : " << address << endl;
			cout << "Customer's Room : " << room << endl;
			cout << "Status of customer : " << status << endl;
			cout << "Staying days of customer : " << days << "\n\n";

			break;
		}
	}

	Output_Data.close();
}

void Admin::Admin_Signup(string local_name, string local_pass)
{

	Adminname = local_name;
	password = local_pass;

	fstream Input_Data;

	Input_Data.open("Admin_Sign_up.txt", ios::out | ios::app);

	Input_Data << Adminname << ' ' << password << endl;

	Input_Data.close();

}