#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Customer.h"
#include"Admin.h"
#include"Room.h"
#include"User.h"

using namespace std;

//Functions prototype
void Admin_User_Choice();
void User_login();
void Admin_login();
void User_Menu();
void Admin_Menu();
void User_Sign_up();
void User_Sign_in();
void Admin_Sign_in();
void Search_rooms();
void search_specific_room();
void Category_room_search();
void Search_By_Room_No();
void User_Search_rooms();
void User_search_specific_room();
void user_Category_room_search();
void user_Search_By_Room_No();
void Check_In();
void Search_Customer();
void Guest_Summary();
void Check_Out();
void exit();


int main()
{

	//Declare variable for choice
	char choice;

	do{

		//Choice between user and admin function
		Admin_User_Choice();

		cout << "Press for again program(Y/N) : \n";
		//Enter y for again run program again
		cin >> choice;

	} while ((choice == 'y') | (choice == 'Y'));
 
	system("pause");
	return 0;

}

void Admin_User_Choice()
{

	//Declare variable for choice b/w user and admin
	int choice;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	//Show on screen
	cout << "1.For User \n";
	cout << "2.For Admin \n";
	cout << "3.Exit \n\n";

	cout << "Enter your choice : ";
	//Enter choice b/w 1 to 3
	cin >> choice;

	//Inout validtion
	while (choice <= 0 || choice > 3)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	//Use switch for choice in menu
	switch (choice)
	{

	case 1:
		User_login();
		break;

	case 2:
		Admin_login();
		break;

	case 3:
		exit();
		break;

	default:
		break;

	}

}

void User_login()
{

	//Declare variable for choice b/w user and admin
	int choice;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.For User account log_in \n";
	cout << "2.For User account sign_up \n";
	cout << "3.Go back to choice\n";
	cout << "4.Exit \n\n";

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 4)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		User_Sign_in();
		break;

	case 2:
		User_Sign_up();
		break;

	case 3:
		Admin_User_Choice();
		break;

	case 4:
		exit();
		break;

	default:
		break;
	}

}

void Admin_login()
{

	//Declare variable for choice b/w user and admin
	int choice;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.For Admin account log_in \n";
	cout << "2.Go back to choice\n";
	cout << "3.Exit \n\n";

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 3)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		Admin_Sign_in();
		break;

	case 2:
		Admin_User_Choice();
		break;

	case 3:
		exit();
		break;

	}

}

void User_Menu()
{

	//Declare variable for choice b/w user and admin
	int choice;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.Search Room\n";
	cout << "2.Search particular room\n";
	cout << "3. Start of program\n";
	cout << "4.Check In \n";
	cout << "5.To log out your account\n";
	cout << "6.Exit \n\n";

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 6)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		User_Search_rooms();
		break;

	case 2:
		User_search_specific_room();
		break;

	case 3:
		Admin_User_Choice();
		break;

	case 4:
		Check_In();
		break;

	case 5:
		Admin_User_Choice();
		break;

	case 6:
		exit();
		break;

	}

}

void Admin_Menu()
{

	//Declare variable for choice b/w user and admin
	int choice;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.Search Room\n";
	cout << "2.Search particular room\n";
	cout << "3.Search particular Customer \n";
	cout << "4.Guest Summary \n";
	cout << "5.Checkout. \n";
	cout << "6.For logout account \n";
	cout << "7.Exit \n\n";

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 7)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		Search_rooms();
		break;

	case 2:
		search_specific_room();
		break;

	case 3:
		Search_Customer();
		break;

	case 4:
		Guest_Summary();
		break;

	case 5:
		Check_Out();
		break;

	case 6:
		Admin_User_Choice();
		break;

	case 7:
		exit();
		break;

	}

}

void User_Sign_up()
{

	Customer cust;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	string username, password, name, address;

	cout << "Enter Username for sign_up : ";
	getline(cin, username);

	cout << "Enter password for sign_up : ";
	getline(cin, password);

	cout << "Enter your name for signup\n";
	getline(cin, name);

	cout << "Enter your address for signup\n\n";
	getline(cin, address);

	if (cust.Customer_Sign_in(username, password) == 1)
	{

		cout << "Your has already account\n";

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		User_login();

	}
	else
	{

		cust.Customer_Sign_up(username, password, name, address);

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		User_login();
	}


}

void User_Sign_in()
{

	//Declare variable for choice b/w user and admin
	int choice;

	Customer cust;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	string username, password;
	
	cout << "Enter Username for sign_in : ";
	getline(cin, username);

	cout << "Enter password for sign_in : ";
	getline(cin, password);

	if (cust.Customer_Sign_in(username, password) == true)
	{
		system("cls");

		cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

		cout << "1.User_menu \n";
		cout << "2.Exit \n\n";

		cout << "Enter your choice : ";
		cin >> choice;

		while (choice <= 0 || choice > 3)
		{
			cout << "Invalid input\n";

			cout << "Enter your choice again : ";
			cin >> choice;
		}

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		switch (choice)
		{

		case 1:
			User_Menu();
			break;

		case 2:
			exit();
			break;

		}
	}
	else
	{
		cout << "Wrong crediential\n";

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		User_login();

	}
}

void Admin_Sign_in()
{

	//Declare variable for choice b/w user and admin
	int choice;

	Admin admin;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	string username, password;

	cout << "Enter Admin for sign_in : ";
	getline(cin, username);

	cout << "Enter password for sign_in : ";
	getline(cin, password);

	if (admin.Admin_Sign_in(username, password) == 1)
	{
		system("cls");

		cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

		cout << "1.Admin_menu \n";
		cout << "2.Exit \n\n";

		cout << "Enter your choice : ";
		cin >> choice;

		while (choice <= 0 || choice > 3)
		{
			cout << "Invalid input\n";

			cout << "Enter your choice again : ";
			cin >> choice;
		}

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		switch (choice)
		{

		case 1:
			Admin_Menu();
			break;

		case 2:
			exit();
			break;

		default:
			break;

		}
	}

	else
	{
		cout << "Wrong crediential\n";

		cout << endl;

		cout << "Press ENTER key for continue : \n";

		cin.get();

		system("cls");

		Admin_login();

	}

}

void exit()
{
	exit(EXIT_SUCCESS);
}


void Search_rooms(){

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	Room room;

	room.Display_AllRoomDetails();

	cout << "Press Enter key for continue\n";

	cin.ignore();

	system("cls");

	Admin_Menu();
}

void search_specific_room()
{

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.search by cetagories\n";
	cout << "2.search by room no\n";
	cout << "3.Go back to the menu\n";
	cout << "4.Exit\n\n";

	int choice;

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 4)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		Category_room_search();
		break;

	case 2:
		Search_By_Room_No();
		break;

	case 3:
		Admin_Menu();
		break;

	case 4:
		exit();
		break;

	default:
		break;

	}

}

void Category_room_search()
{

	Room room;

	char AC,Size,Type;

	cout << "What is the type of AC/Non-AC(A/N) : ";
	cin >> AC;

	while (!(AC == 'A' || AC == 'N'))
	{
		cout << "Invalid input\n";
		cout << "What is the type of AC/Non-AC(A/N) : ";
		cin >> AC;
	}

	cout << "What is the size of room Big/Short(B/S) : ";
	cin >> Size;

	while (!(Size == 'B' || Size == 'S'))
	{
		cout << "Invalid input\n";
		cout << "What is the size of room Big/Short(B/S) again : ";
		cin >> Size;
	}

	cout << "Which Type of room you want Comfort room or normal room(C/N) : ";
	cin >> Type;

	while (!(Type == 'C' || Type == 'N'))
	{
		cout << "Invalid input\n";
		cout << "Which Type of room you want Comfort room or normal room(C/N) again : ";
		cin >> Type;
	}

	room.Display_CategoryRoomDetails(AC,Size,Type);

	cout << "\n\n\n";

	Admin_Menu();

}

void Search_By_Room_No()
{

	Room room;

	int Search_Room_No;

	cout << "Enter Room no which you want to display\n";
	cin >> Search_Room_No;

	while (!(Search_Room_No > 0 && Search_Room_No <= 100))
	{
		cout << "Invalid room number\n";
		cout << "Enter Room no which you want to display\n";
		cin >> Search_Room_No;
	}

	room.Display_specificRoomDetails(Search_Room_No);

	cout << "\n\n\n";

	Admin_Menu();

}


void User_Search_rooms(){

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	Room room;

	room.Display_AllRoomDetails();

	cout << "Press Enter key for continue\n";

	cin.ignore();

	system("cls");

	User_Menu();
}

void User_search_specific_room()
{

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "1.search by cetagories\n";
	cout << "2.search by room no\n";
	cout << "3.Go back to the menu\n";
	cout << "4.Exit\n\n";

	int choice;

	cout << "Enter your choice : ";
	cin >> choice;

	while (choice <= 0 || choice > 4)
	{
		cout << "Invalid input\n";

		cout << "Enter your choice again : ";
		cin >> choice;
	}

	cout << endl;

	cout << "Press ENTER key for continue : \n";

	cin.get();

	system("cls");

	switch (choice)
	{

	case 1:
		user_Category_room_search();
		break;

	case 2:
		user_Search_By_Room_No();
		break;

	case 3:
		User_Menu();
		break;

	case 4:
		exit();
		break;

	default:
		break;

	}

}

void user_Category_room_search()
{

	Room room;

	char AC, Size, Type;

	cout << "What is the type of AC/Non-AC(A/N) : ";
	cin >> AC;

	while (!(AC == 'A' || AC == 'N'))
	{
		cout << "Invalid input\n";
		cout << "What is the type of AC/Non-AC(A/N) : ";
		cin >> AC;
	}

	cout << "What is the size of room Big/Short(B/S) : ";
	cin >> Size;

	while (!(Size == 'B' || Size == 'S'))
	{
		cout << "Invalid input\n";
		cout << "What is the size of room Big/Short(B/S) again : ";
		cin >> Size;
	}

	cout << "Which Type of room you want Comfort room or normal room(C/N) : ";
	cin >> Type;

	while (!(Type == 'C' || Type == 'N'))
	{
		cout << "Invalid input\n";
		cout << "Which Type of room you want Comfort room or normal room(C/N) again : ";
		cin >> Type;
	}

	room.Display_CategoryRoomDetails(AC, Size, Type);

	cout << "\n\n\n";

	User_Menu();

}

void user_Search_By_Room_No()
{

	Room room;

	int Search_Room_No;

	cout << "Enter Room no which you want to display\n";
	cin >> Search_Room_No;

	while (!(Search_Room_No > 0 && Search_Room_No <= 100))
	{
		cout << "Invalid room number\n";
		cout << "Enter Room no which you want to display\n";
		cin >> Search_Room_No;
	}

	room.Display_specificRoomDetails(Search_Room_No);

	cout << "\n\n\n";

	User_Menu();

}


void Check_In(){

	Customer cust;

	int room = 0;

	bool found = false;

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	cout << "Enter room no of customer : \n";
	cin >> room;


	while (!(room > 0 && room <= 100))
	{
		cout << "Invalid room number\n";
		cout << "Enter Room no which you want to display\n";
		cin >> room;
	}

	if (cust.Bool_Search_Room(room)==true)
	{

		cout << "This room has already been booked\n";

		cout << "Press Enter key for continue\n";

		cin.ignore();

		system("cls");

		User_Menu();

	}

	else
	{

		cust.Check_In(room);

		cout << "Press Enter key for continue\n";

		cin.ignore();

		system("cls");

		User_Menu();
	}

}


void Search_Customer(){

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	int booking_cust_id;

	Admin admin;

	cout << "Enter booking id of customer\n";
	cin >> booking_cust_id;

	while (booking_cust_id <= 0)
	{
		cout << "Invalid input\n";
		cout << "Enter booking id again of customer\n";
		cin >> booking_cust_id;
	}

	admin.Search_Cust(booking_cust_id);

	cout << "\n\n\n";

	Admin_Menu();

}


void Guest_Summary(){

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	Admin admin;

	admin.Summary();

	cout << "Press Enter key for continue\n";

	cin.ignore();

	system("cls");

	Admin_Menu();

}


void Check_Out(){

	cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM\n\n\n";

	Admin admin;
	Room room;

	int delete_booking_id=0,room_no;

	cout << "Enter booking id of customer which customer data you want to delete : ";
	cin >> delete_booking_id;

	while (delete_booking_id <= 0)
	{
		cout << "Invalid input\n";
		cout << "Enter booking id again of customer\n";
		cin >> delete_booking_id;
	}

	cout << "Enter also room no you want to delete\n";
	cin >> room_no;

	admin.Check_Out(delete_booking_id,room_no);

	cout << "Record has been deleted sucessfully\n";

	cout << "Press Enter key for continue\n";

	cin.ignore();

	system("cls");

	Admin_Menu();

}

