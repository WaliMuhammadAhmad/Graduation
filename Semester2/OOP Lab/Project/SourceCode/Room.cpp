#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Room.h"

using namespace std;

Room::Room()
{
	Room_Type=' ';
	Room_Size = ' ';
	Room_Ac = ' ';
	Room_Number = 0;
	rent=50;
	status = false;
}

void Room::Room_Data(int room_no)
{

	fstream room_details, Output_Data;

	Output_Data.open("Customer_Data.txt", ios::in);
	room_details.open("Room_Data.txt", ios::out | ios::app);

	Room_Number = room_no;


	cout << "Type of AC/Non-AC(A/N) : ";
	cin >> Room_Ac;

	while (!(Room_Ac == 'A' || Room_Ac == 'N'))
	{
		cout << "Invalid input\n";
		cout << "Enter again AC/Non-AC(A/N) : ";
		cin >> Room_Ac;
	}

	cout << "What size of room you want Big/Short(B/S) : ";
	cin >> Room_Size;

	while (!(Room_Size == 'B' || Room_Size == 'S'))
	{
		cout << "Invalid input\n";
		cout << "What size of room you want Big/Short(B/S) again : ";
		cin >> Room_Size;
	}

	cout << "Which Type of room you want Comfort room or normal room(C/N) : ";
	cin >> Room_Type;

	while (!(Room_Type == 'C' || Room_Type == 'N'))
	{
		cout << "Invalid input\n";
		cout << "Which Type of room you want Comfort room or normal room(C/N) again : ";
		cin >> Room_Type;
	}

	status = true;

	room_details << Room_Number << ' ' << Room_Size << ' ' << Room_Ac << ' ' << Room_Type << ' ' << rent << ' ' << status << endl;

	cout << "Room Added Successfully\n";

	room_details.close();

}

void Room::Display_specificRoomDetails(int room_no)
{

	fstream output_data;

	output_data.open("Room_Data.txt", ios::in);

	while (output_data.eof() == 0)
	{
		output_data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;

		if (Room_Number == room_no)
		{
			cout << "Room type : " << Room_Type << endl;

			cout << "Room Size : " << Room_Size << endl;

			cout << "Room Ac type : " << Room_Ac << endl;

			cout << "Room number : " << Room_Number << endl;

			cout << "Rent of Room : " << rent << endl;

			cout << "Status of room is : " << status << endl;

			break;
		}
	}
}

void Room::Display_CategoryRoomDetails(char AC, char Size, char Type)
{

	fstream output_data;

	output_data.open("Room_Data.txt", ios::in);

	while (output_data.eof() == 0)
	{
		output_data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;

		if (Room_Ac == AC&&Room_Size == Size&&Room_Type == Type)
		{

		
			cout << "Room type : " << Room_Type << endl;

			cout << "Room Size : " << Room_Size << endl;

			cout << "Room Ac type : " << Room_Ac << endl;

			cout << "Room number : " << Room_Number << endl;

			cout << "Rent of Room : " << rent << endl;

			cout << "Status of room is : " << status << endl;

			break;
		}
	}

}

void Room::Display_AllRoomDetails()
{

	fstream output_data;

	output_data.open("Room_Data.txt", ios::in);

	cout << "\n\n";

	output_data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;

	while (output_data.eof() == 0)
	{
		cout << "Details for data of Room#" << Room_Number << "\n\n";

		cout << "Room number : " << Room_Number << endl;

		cout << "Room type : " << Room_Type << endl;

		cout << "Room Size : " << Room_Size << endl;

		cout << "Room Ac type : " << Room_Ac << endl;

		cout << "Rent of Room : " << rent << endl;

		cout << "Status of room is : " << status << endl<<endl;

		output_data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;
	}

}


void Room::Room_Check_Out(int booking_id_cust)
{

	int new_booking_id = booking_id_cust;

	fstream Output_Data;
	fstream temp;

	Output_Data.open("Room_Data.txt", ios::in);
	temp.open("Temp.txt", ios::out | ios::app);

	Output_Data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;

	while (Output_Data.eof() == 0){

		if (new_booking_id != Room_Number)
		{
			temp << Room_Number << ' ' << Room_Size << ' ' << Room_Ac << ' ' << Room_Type << ' ' << rent << ' ' << status << endl;
		}

		Output_Data >> Room_Number >> Room_Size >> Room_Ac >> Room_Type >> rent >> status;

	}

	temp.close();
	Output_Data.close();
	remove("Room_Data.txt");
	rename("temp.txt", "Room_Data.txt");

}