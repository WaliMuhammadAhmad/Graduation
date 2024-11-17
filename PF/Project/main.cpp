#include <iostream>
#include <string>   //library for string input/output
#include <fstream>  //library for input/output to file
#include <iomanip>  //for field widths
#include <stdlib.h> //for cin.get()>>>{press enter to continue}
using namespace std;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>Function Prototypes<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void members();                    // to display members of group
void display();                    // to display title
char displayMenu();                // to display menu
void readDataFromFile();           // to read data already stored in file
void takingInputAndManageSalary(); // to take input and manage salary
void storeDataToFile();            // to store data from array to file
string inputMonth();               // to store month in specific format
long calculateSalary(int);         // to calculate the Salary
void inputDataOfNewEmployee();     // to input data of new employee
void storeDataOfNewEmployee();     // to store data of new employee
void printSalarySlip();            // to print salary
string createSalarySlip(int);      // to save salary slip as new file
void to_end();                     // for case 4
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct Data
{
    string id;
    string name;
    string designation;
    long basicSalary;
    string month;
    int noOfLeaves;
    int leavesAllowed;
    long perLeaveDeductionRate;
    long salary;
};

const int SIZE = 15;
Data employee[SIZE];
int index = 0;

int main()
{
    char selection = ' ';
    members();
    do
    {
        readDataFromFile(); // to store data from file into array
        selection = displayMenu();
        switch (selection)
        {
        case '1': // If User Enters 1
            takingInputAndManageSalary();
            storeDataToFile();
            break;

        case '2': // If User Enters 2.
            printSalarySlip();
            break;

        case '3': // If User Enters 3
            inputDataOfNewEmployee();
            break;

        case '4':     // If User Enters 4
            to_end(); // for ending
            break;
        }
    } while (selection != '4');

    return 0;
}
//*******************************************************************
// >>>>>>>>>>>>>>>>>>>>>Function Definitions<<<<<<<<<<<<<<<<<<<<<<<<<
//*******************************************************************
void members()
{
    display();
    cout << "                   Press Enter to check the members of the group:              ";
    cin.get();
    system("clear");
    cout << "                                   Members                                         " << endl;
    cout << "###################################################################################" << endl;
    cout << endl;
    cout << "       1)         Numan Ahmed                   (Reg : 2021-SE-24)" << endl;
    cout << "       2)         M.Farjad Waseem               (Reg : 2021-SE-56)" << endl;
    cout << "       3)         Wali Muhammad                 (Reg : 2021-SE-39)" << endl;
    cout << endl;
    cout << "###################################################################################" << endl;
    cout << "                          Press any key to open menu...                          " << endl;
    cin.get();
    system("clear");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void display()
{
    // system("cls");
    cout << "################################################################################################" << endl;
    cout << "#                                                                                              #" << endl;
    cout << "#             _____   _      _    _      _        ______                 _____    _____        #" << endl;
    cout << "#            //      / \\    //|  | \\    |/       ||    ||     \\    //   //       //            #" << endl;
    cout << "#           //      /   \\  // |  |  \\   /|       ||    ||      \\  //   //       //             #" << endl;
    cout << "#          //____  /     \\//  |  |  /  /|        ||    ||       \\//   //____   //____          #" << endl;
    cout << "#         //      /           |  | /  /|         ||    ||       //   //       //               #" << endl;
    cout << "#        //      /            |  |/  /|          ||    ||      //   //       //                #" << endl;
    cout << "#       //____  /             |  |  /|_________  ||____||     //   //______ //_______          #" << endl;
    cout << "#                                                                                              #" << endl;
    cout << "#                                                                                              #" << endl;
    cout << "#                                                                                              #" << endl;
    cout << "#      _      _   ____   _        ____   ____   ____  _      _  _____  _       _____           #" << endl;
    cout << "#     | \\    / | |    | | \\    | |    | |      |     | \\    / ||      | \\    |   |             #" << endl;
    cout << "#     |  \\  /  | |    | |  \\   | |    | |      |___  |  \\  /  ||____  |  \\   |   |             #" << endl;
    cout << "#     |   \\/   | |____| |   \\  | |____| |  __  |     |   \\/   ||      |   \\  |   |             #" << endl;
    cout << "#     |        | |    | |    \\ | |    | |    | |     |        ||      |    \\ |   |             #" << endl;
    cout << "#     |        | |    | |     \\| |    | |____| |____ |        ||_____ |     \\|   |             #" << endl;
    cout << "#                                                                                              #" << endl;
    cout << "################################################################################################" << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////
char displayMenu()
{
    char choice;
    //  now u will see the menu
    cout << "                                           MENU                                                              " << endl;
    cout << "#############################################################################################################" << endl;
    cout << "#  1. Enter Information of employee to manage salary of specific month.                                     #" << endl;
    cout << "#  2. Print Salary Slip.                                                                                    #" << endl;
    cout << "#  3. Enter information of new employee.                                                                    #" << endl;
    cout << "#  4. Quit.                                                                                                 #" << endl;
    cout << "#############################################################################################################" << endl;

    do
    {
        cout << "# >>> Enter your choice within(1-4):        ";
        cin >> choice;
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
    system("clear");
    return choice;
}
////////////////////////////////////////////////
void readDataFromFile()
{
    // CONVERT TO FUNCTION READ FILE
    fstream File;
    File.open("EmployeesManagementSystem.txt", ios::in);
    string tempfirst, tempsecond, fullname;
    index = 0; // every time it read the from start
    while (!File.eof())
    {
        File >> employee[index].id;
        if (File.eof())
        {
            break;
        }
        File >> tempfirst;
        File >> tempsecond;
        fullname = tempfirst + " " + tempsecond;
        employee[index].name = fullname;
        File >> employee[index].designation;
        File >> employee[index].basicSalary;
        File >> employee[index].month;
        File >> employee[index].noOfLeaves;
        File >> employee[index].leavesAllowed;
        File >> employee[index].perLeaveDeductionRate;
        File >> employee[index].salary;
        index++;
    }
    File.close();
    return;
}
////////////////////////////////////////////////////////////////////////////////////////
void takingInputAndManageSalary()
{
    bool checkMatch = true;
    string tempMonth, tempid;
    string tempfirst, tempsecond;
    do
    {
        checkMatch = false; /// to check id exists or not
        cout << endl
             << "Enter the Employee Id: ";
        cin >> tempid;
        if (tempid == "-1")
        {
            return; // loop will  terminate if user enters -1 as id
        }
        for (int j = 0; j < index; j++)
        { /// comparing with existing ids
            if (tempid == employee[j].id)
            {
                checkMatch = true; // to check the id was matched or not after ending of the for loop
                cout << endl
                     << "Name :" << employee[j].name;
                cout << endl
                     << "Designation: " << employee[j].designation;
                cout << endl
                     << "Basic Salary: " << employee[j].basicSalary;
                tempMonth = inputMonth();
                if (tempMonth == employee[j].month)
                {
                    cout << endl
                         << "Enter No of leaves taken by the employee: ";
                    cin >> employee[j].noOfLeaves;

                    cout << endl
                         << "Enter the No of leaves allowed to the Employee: ";
                    cin >> employee[j].leavesAllowed;

                    cout << endl
                         << "Enter per leave deduction rate: ";
                    cin >> employee[j].perLeaveDeductionRate;

                    employee[j].salary = calculateSalary(j);
                }
                else
                {
                    employee[index].id = tempid;
                    employee[index].name = employee[j].name;
                    employee[index].designation = employee[j].designation;
                    employee[index].basicSalary = employee[j].basicSalary;
                    employee[index].month = tempMonth;

                    cout << endl
                         << "Enter number of leaves taken by the employee: ";
                    cin >> employee[index].noOfLeaves;

                    cout << endl
                         << "Enter the no of leaves allowed to the Employee: ";
                    cin >> employee[index].leavesAllowed;

                    cout << endl
                         << "Enter per leave deduction rate: ";
                    cin >> employee[index].perLeaveDeductionRate;

                    employee[index].salary = calculateSalary(index);

                    ++index;
                }
                break;
            }
        }
        if (checkMatch == false)
        {
            cout << "\nId does not exist.\n";
        }
    } while (true);
}
/////////////////////////////////////////////////////////////////////////////////////////
void storeDataToFile()
{
    ofstream outToFile;
    outToFile.open("EmployeesManagementSystem.txt");
    for (int j = 0; j < index; j++) // to store data from zero index to last index
    {
        outToFile << employee[j].id << "\t";
        outToFile << employee[j].name << "\t";
        outToFile << employee[j].designation << "\t";
        outToFile << employee[j].basicSalary << "\t";
        outToFile << employee[j].month << "\t";
        outToFile << employee[j].noOfLeaves << "\t";
        outToFile << employee[j].leavesAllowed << "\t";
        outToFile << employee[j].perLeaveDeductionRate << "\t";
        outToFile << employee[j].salary << "\n";
    }
    outToFile.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void inputDataOfNewEmployee() // input new employee data >>>>CASE 3
{
    bool flag = false;
    string tempfirst, tempsecond;
    do
    { /// to check id exists or not
        flag = false;
        cout << endl
             << "Enter the Employee Id: ";
        cin >> employee[index].id;
        for (int j = 0; j < index; j++)
        { /// comparing with existing ids
            if (employee[index].id == employee[j].id)
            {
                cout << "ID already exists. \n";
                flag = true;
                break;
            }
        }
    } while (flag == true);
    cout << endl
         << "Enter the first name of Employee: ";
    cin >> tempfirst;
    cout << endl
         << "Enter the last name of Employee: ";
    cin >> tempsecond;
    employee[index].name = tempfirst + " " + tempsecond; // combine first name and last name
    cout << endl
         << "Enter the Employee Designation: ";
    cin >> employee[index].designation;
    cout << endl
         << "Enter the Employee Basic Salary: ";
    cin >> employee[index].basicSalary;
    cout << endl;
    employee[index].month = inputMonth();
    cout << "Enter the number of leaves: ";
    cin >> employee[index].noOfLeaves;
    cout << endl
         << "Enter the no of leaves allowed to the Employee: ";
    cin >> employee[index].leavesAllowed;
    cout << endl
         << "Enter per leave deduction rate: ";
    cin >> employee[index].perLeaveDeductionRate;
    employee[index].salary = calculateSalary(index);
    storeDataOfNewEmployee();
    index++; // to increment array index
    return;
}
/////////////////////////////////////////////////////////////////////////////////

void storeDataOfNewEmployee()
{
    ofstream outToFile; // add data at the end of existing file
    outToFile.open("EmployeesManagementSystem.txt", ios::app);
    outToFile << employee[index].id << "\t";
    outToFile << employee[index].name << "\t";
    outToFile << employee[index].designation << "\t";
    outToFile << employee[index].basicSalary << "\t";
    outToFile << employee[index].month << "\t";
    outToFile << employee[index].noOfLeaves << "\t";
    outToFile << employee[index].leavesAllowed << "\t";
    outToFile << employee[index].perLeaveDeductionRate << "\t";
    outToFile << employee[index].salary << "\n";
    outToFile.close();
}
/////////////////////////////////////////////////////////////////////////////////
void printSalarySlip()
{
    int j = 0;
    char c; ////////c to display menu
    string mon;
    mon = inputMonth(); ////to input month from user
    while (j < index)
    {
        if (employee[j].month == mon)
        {
            cout << endl
                 << setw(35) << setfill('*') << " \n";
            cout << "Salary Month : " << employee[j].month << endl;
            cout << "Employee Name : " << employee[j].name << endl;
            employee[j].salary = calculateSalary(j);
            cout << "Salary : " << employee[j].salary << endl;
            cout << createSalarySlip(j) << endl;
            cout << setw(35) << setfill('*') << " \n\n";
        }
        ++j; //////to check next record
    }
    cout << "Enter any key to display menu:       ";
    if (cin >> c)
        system("clear");
}
/////////////////////////////////////////////////////////////////////////////////////////////
string createSalarySlip(int i)
{
    string fileName;
    fileName = employee[i].id + "_" + employee[i].name + "_" + employee[i].month + "_salaryslip.txt";
    fstream slip;
    slip.open(fileName, ios::out);
    slip << "Salary Month: " << employee[i].month << endl;
    slip << "Employee Name: " << employee[i].name << endl;
    slip << "Designation: " << employee[i].designation << endl;
    slip << "Salary: " << employee[i].salary << endl;

    return fileName;
}
//////////////////////////////////////////////////////////////////////////////////////////////
long calculateSalary(int j)
{

    if (employee[j].noOfLeaves > employee[j].leavesAllowed)
    {
        employee[j].salary = employee[j].basicSalary - (employee[j].noOfLeaves - employee[j].leavesAllowed) * employee[j].perLeaveDeductionRate;
    }
    else
    {
        employee[j].salary = employee[j].basicSalary;
    }
    return employee[j].salary;
}
///////////////////////////////////////////////////////////////////////////////////////////////
string inputMonth()
{
    string tempMonth;
    bool monthCheck = true;
    do
    {
        cout << "\nEnter the Month                  : ";
        cin >> tempMonth;
        if (tempMonth == "1" || tempMonth == "jan" || tempMonth == "Jan" || tempMonth == "JAN" || tempMonth == "January" || tempMonth == "january" || tempMonth == "JANUARY")
        {
            tempMonth = "January";
            return tempMonth;
        }
        else if (tempMonth == "2" || tempMonth == "feb" || tempMonth == "Feb" || tempMonth == "FEB" || tempMonth == "February" || tempMonth == "february" || tempMonth == "FEBRUARY")
        {
            tempMonth = "February";
            return tempMonth;
        }
        else if (tempMonth == "3" || tempMonth == "mar" || tempMonth == "Mar" || tempMonth == "MAR" || tempMonth == "March" || tempMonth == "march" || tempMonth == "MARCH")
        {
            tempMonth = "March";
            return tempMonth;
        }
        else if (tempMonth == "4" || tempMonth == "apr" || tempMonth == "Apr" || tempMonth == "APR" || tempMonth == "April" || tempMonth == "april" || tempMonth == "APRIL")
        {
            tempMonth = "April";
            return tempMonth;
        }
        else if (tempMonth == "5" || tempMonth == "may" || tempMonth == "May" || tempMonth == "MAY")
        {
            tempMonth = "May";
            return tempMonth;
        }
        else if (tempMonth == "6" || tempMonth == "June" || tempMonth == "june" || tempMonth == "JUNE")
        {
            tempMonth = "June";
            return tempMonth;
        }
        else if (tempMonth == "7" || tempMonth == "July" || tempMonth == "july" || tempMonth == "JULY")
        {
            tempMonth = "July";
            return tempMonth;
        }
        else if (tempMonth == "8" || tempMonth == "aug" || tempMonth == "Aug" || tempMonth == "AUG" || tempMonth == "August" || tempMonth == "august" || tempMonth == "AUGUST")
        {
            tempMonth = "August";
            return tempMonth;
        }
        else if (tempMonth == "9" || tempMonth == "sep" || tempMonth == "Sep" || tempMonth == "SEP" || tempMonth == "September" || tempMonth == "september" || tempMonth == "SEPTEMBER")
        {
            tempMonth = "September";
            return tempMonth;
        }
        else if (tempMonth == "10" || tempMonth == "oct" || tempMonth == "Oct" || tempMonth == "OCT" || tempMonth == "October" || tempMonth == "october" || tempMonth == "OCTOBER")
        {
            tempMonth = "October";
            return tempMonth;
        }
        else if (tempMonth == "11" || tempMonth == "nov" || tempMonth == "Nov" || tempMonth == "NOV" || tempMonth == "November" || tempMonth == "november" || tempMonth == "NOVEMBER")
        {
            tempMonth = "November";
            return tempMonth;
        }
        else if (tempMonth == "12" || tempMonth == "dec" || tempMonth == "Dec" || tempMonth == "DEC" || tempMonth == "December" || tempMonth == "december" || tempMonth == "DECEMBER")
        {
            tempMonth = "December";
            return tempMonth;
        }
        else
        {
            cout << "\n///////////Invaid Input////////////\n";
            monthCheck = false; ////If it is true month will be asked again
        }
    } while (!monthCheck);
    return tempMonth;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void to_end()
{
    cout << "####################################################################################" << endl;
    cout << "#         _________            ______       _____   _     _     _                  #" << endl;
    cout << "#            ||     ||  ||    ||           ||      ||\\   ||    ||\\                 #" << endl;
    cout << "#            ||     ||__||    ||___        ||__    || \\  ||    || \\                #" << endl;
    cout << "#            ||     ||  ||    ||           ||      ||  \\ ||    || /                #" << endl;
    cout << "#            ||     ||  ||    ||_____      ||____  ||   \\||    ||/                 #" << endl;
    cout << "#                                                                                  #" << endl;
    cout << "####################################################################################" << endl;
}
