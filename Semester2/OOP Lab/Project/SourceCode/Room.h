#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"User.h"

using namespace std;

class Room final : protected User
{

protected:

	char Room_Type;
	char Room_Size;
	char Room_Ac;
	int Room_Number;
	double rent;
	bool status;

public:

	Room();
	void Room_Data(int );
	void Display_specificRoomDetails(int );
	void Display_AllRoomDetails();
	void Room_Check_Out(int );
	void Display_CategoryRoomDetails(char ,char, char);
};