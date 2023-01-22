//This program records the monthly expense.

#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

//Menu bar: 
//1. Enter record for the selected month.
//2. Listing the record for the specific month.
//2. Total expense for the entire year. 
//Ask the user which month they want to put the records. Open the file name the month. 

// Create a struct contains the main categories that will be recorded.
struct Info
{
    int shopping, groceries, renting, dinning, gas; 
    string description;
    char date[20];
     
};

void menu(); 
void add(fstream &, int, Info); 
void view(fstream &, int , Info); 
void total(fstream &, int, Info);
void monthSelection();
void categorySelection(); 

int main ()
{
    int answer;
    fstream record;
    Info category;

    menu(); 
    cin >> answer; 
    switch(answer)
    {
        case 1: 
        {   
            int month; 
            cout << "Enter the month you would like to record the expense.\n";
            monthSelection();
            cin >> month; 
            add(record, month, category); 
            break;
        }
        case 2: 
        {
            int month; 
            cout << "Enter the month you would like to view the expense.\n";
            monthSelection();
            cin >> month;
            view(record, month, category);
            break;
        }
        case 3: 
        {   
            int month; 
            cout << "Enter the month you would like to view the total expense.\n";
            monthSelection();
            cin >> month; 
            total(record, month, category); 
            break;
            
        }
        case 4: 
            return 0;
        default: 
            cout << "Your choice is not valid.";

    }
    



}
void menu()
{
    cout << "Select the following options: \n";
    cout << "1)Enter the new expense for the chosen month.\n";
    cout << "2)View the expenses for the chosen month.\n";
    cout << "3)Total expense of the entire year.\n";
    cout << "4)Exit.\n";
}

void monthSelection()
{
    cout << "1) January\n2) February\n3) March\n4) April\n5) May\n6) June\n7) Juy\n8) August\n9) September\n10) October\n11) November\n12) December\n";
}

void add(fstream &record, int month, Info category)
{
    switch(month)
            {
                case 1: 
                {
                    record.open("January.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 2: 
                {
                    record.open("February.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 3:
                {
                    record.open("March.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 4:
                {
                    record.open("April.txt", ios::out | ios::app |ios::binary);
                    break;
                }
                case 5:
                {
                    record.open("May.txt", ios::out | ios::app |ios::binary);
                    break;
                }
                case 6:
                {
                    record.open("June.txt", ios::out | ios::app|ios::binary );
                    break;
                }
                case 7:
                {
                    record.open("July.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 8:
                {
                    record.open("August.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 9:
                {
                    record.open("September.txt", ios::out | ios::app |ios::binary );
                    break;
                } 
                case 10: 
                {
                    record.open("October.txt", ios::out | ios::app |ios::binary );
                    break;
                }
                case 11:
                {
                    record.open("November.txt", ios::out | ios::app |ios::binary);
                    break;
                } 
                case 12:
                {
                    record.open("December.txt", ios::out | ios::app |ios::binary);
                    break;
                }
                default: 
                    cout << "Your choice is not valid.";
                
            }

            cout << "Enter the date: ";
            cin >> category.date ;
            cout << "Enter the expenses for the following category:\n";
            cout << "Shopping: $";
            cin >> category.shopping;
            cout << "Groceries: $";
            cin >> category.groceries; 
            cout << "Dining: $";
            cin >> category.dinning;
            cout << "Gas: $";
            cin >> category.gas;
            cout << "Renting: $";
            cin >> category.renting;

            record.write(reinterpret_cast<char *>(&category), sizeof(category));

            record.close();
}

void view (fstream &record, int month, Info category)
{
    switch(month)
            {
                case 1: 
                {
                    record.open("January.txt", ios::in |ios::binary );
                    break;
                }
                case 2: 
                {
                    record.open("February.txt", ios::in |ios::binary );
                    break;
                }
                case 3:
                {
                    record.open("March.txt", ios::in |ios::binary );
                    break;
                }
                case 4:
                {
                    record.open("April.txt", ios::in |ios::binary);
                    break;
                }
                case 5:
                {
                    record.open("May.txt", ios::in |ios::binary);
                    break;
                }
                case 6:
                {
                    record.open("June.txt", ios::in |ios::binary );
                    break;
                }
                case 7:
                {
                    record.open("July.txt", ios::in|ios::binary );
                    break;
                }
                case 8:
                {
                    record.open("August.txt", ios::in |ios::binary );
                    break;
                }
                case 9:
                {
                    record.open("September.txt", ios::in |ios::binary );
                    break;
                } 
                case 10: 
                {
                    record.open("October.txt", ios::in |ios::binary );
                    break;
                }
                case 11:
                {
                    record.open("November.txt", ios::in |ios::binary);
                    break;
                } 
                case 12:
                {
                    record.open("December.txt", ios::in |ios::binary);
                    break;
                }
                default: 
                    cout << "Your choice is not valid.";
                
            }

            if (!record)
            {
                cout << "This month does not contain any record.";
            }

            record.read(reinterpret_cast<char*>(&category), sizeof(category));

            while (!record.eof())
            {
                cout << "Date: " << month << "/" << category.date << endl;
                cout << "Shopping: $" << category.shopping << endl;
                cout << "Groceries: $" << category.groceries << endl;
                cout << "Dining: $" << category.dinning << endl;
                cout << "Gas: $" << category.gas << endl;
                cout << "Renting: $"<< category.renting << endl << endl;

                record.read(reinterpret_cast<char*>(&category), sizeof(category));
            }

            record.close();
}

void total (fstream &record, int month, Info category)
{
    switch(month)
            {
                case 1: 
                {
                    record.open("January.txt", ios::in |ios::binary );
                    break;
                }
                case 2: 
                {
                    record.open("February.txt", ios::in |ios::binary );
                    break;
                }
                case 3:
                {
                    record.open("March.txt", ios::in |ios::binary );
                    break;
                }
                case 4:
                {
                    record.open("April.txt", ios::in |ios::binary);
                    break;
                }
                case 5:
                {
                    record.open("May.txt", ios::in |ios::binary);
                    break;
                }
                case 6:
                {
                    record.open("June.txt", ios::in |ios::binary );
                    break;
                }
                case 7:
                {
                    record.open("July.txt", ios::in|ios::binary );
                    break;
                }
                case 8:
                {
                    record.open("August.txt", ios::in |ios::binary );
                    break;
                }
                case 9:
                {
                    record.open("September.txt", ios::in |ios::binary );
                    break;
                } 
                case 10: 
                {
                    record.open("October.txt", ios::in |ios::binary );
                    break;
                }
                case 11:
                {
                    record.open("November.txt", ios::in |ios::binary);
                    break;
                } 
                case 12:
                {
                    record.open("December.txt", ios::in |ios::binary);
                    break;
                }
                default: 
                    cout << "Your choice is not valid.";
                
            }

    record.read(reinterpret_cast<char*>(&category), sizeof(category)); // Maybe this line need to change in order to calculate the expense 

    int shopping, renting, dinning, gas, groceries, totals; 

    shopping += category.shopping; 
    renting += category.renting;
    dinning += category.dinning;
    gas += category.gas;
    groceries += category.groceries; 
    totals = shopping + renting + dinning + gas + groceries;

    cout << "Total expenses for month " << month << " :" << endl;
    cout << "Shopping : $" << shopping << endl; 
    cout << "Groceries: $" << groceries << endl;
    cout << "Dining: $" << dinning << endl;
    cout << "Gas: $" << gas << endl;
    cout << "Renting: $"<< renting << endl ;
    cout << "Total : $" << totals << endl << endl;

    record.close(); 
}

