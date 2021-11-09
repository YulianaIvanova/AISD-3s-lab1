#include <iostream>
#include "cpp-polyline.h"
using namespace cpp;


int input_of_the_first_number(char* number)
{
	char* s = strchr(number, ' ');
	char data1[2] = { 0 };
	int len = (s - number) / sizeof(char);
	for (int i = 0; i < len; i++) { data1[i] = number[i]; }
	int numb1 = atoi(data1);
	return numb1;
}

int input_of_the_second_number(char* number)
{
	char* s = strchr(number, ' ');
	s++;
	char data2[2] = { 0 };
	int i = 0;
	while (*s)
	{
		data2[i] = *s;
		i++;
		s++;
	}
	int numb2 = atoi(data2);
	return numb2;
}


void adding_two_polylines(polyline* ptr,polyline& tmp)
{
	char number[21] = { 0 };
	cout << "Which polylines should be folded?The result will be written to the end of the collection of objects(polylines)" << endl;
	cout << "Enter the polyline numbers separated by a space : ";
	cin.get();
	cin.getline(number, 21);
	int numb1 = input_of_the_first_number(number);
	int numb2 = input_of_the_second_number(number);
	numb1--;
	numb2--;
	tmp = ptr[numb1] + ptr[numb2];
}


void operations_on_polyline(polyline* ptr, int& n_polyline)
{
	int item = 0;
	bool again = true;
	point vertex;
	polyline tmp;
	while (again)
	{
		print_collection(ptr,n_polyline);
		cout << "1.Adding two polylines(concatenation)\n2.Adding a vertex\n3.Polyline length\n";
		cout << "4.Compare two polylines\n5.Exit"<<endl;
		cout << "Select the menu item to continue: ";
		cin >> item;
		if (item >= 1 && item <= 5)
		{
			try
			{
				
				int var = 0;
				int option = 0;
				char number[21] = { 0 };
				int numb1 = 0;
				int numb2 = 0;
				switch (item)
				{
				case 1:
					system("cls");
					adding_two_polylines(ptr,tmp);
					add_object(ptr, tmp, n_polyline);
					print_collection(ptr, n_polyline);
					cin.get();
					system("cls");
					break;
				case 2:
					system("cls");
					print_collection(ptr, n_polyline);
					cout << "Which polyline will we work with?\nEnter the polyline number: ";
					cin >> var;
					cout << "Add a vertex to the beginning or end of a polyline?\n1.To the beginning\n2.To the end\nSelect the menu item to continue: ";
					cin >> option;
					cout << "Enter the coordinates of the vertex like this (x;y)" << endl;
					cin.get();
					cin >> vertex;
					if (option == 1)
					{
						ptr[var-1] < vertex;
					}
					else if (option == 2)
					{
						ptr[var-1] > vertex;
					}
					system("cls");
					break;
				case 3:
					system("cls");
					print_collection(ptr, n_polyline);
					cout << "Which polyline will we work with?\nEnter the polyline number: ";
					cin >> var;
					cout << "Polyline length: "<< ptr[var - 1].distance();
					cin.get();
					cin.get();
					system("cls");
					break;
				case 4:
					system("cls");
					print_collection(ptr, n_polyline);
					cout << "Which two polylines to compare?\nEnter the polyline numbers separated by a space : ";
					cin.get();
					cin.getline(number, 21);
					numb1 = input_of_the_first_number(number);
					numb2 = input_of_the_second_number(number);
					numb1--;
					numb2--;
					if ((ptr[numb1] == ptr[numb2]) == true)
					{
						cout << "The polylines are equal!";
					}
					else
					{
						cout << "Polylines are unequal!";
					}
					cin.get();
					system("cls");
					break;
				case 5:
					item = 6;
					again = false;
					system("cls");
					break;
				}
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
		}
	}
}


int basic_menu()
{
	//polyline* ptr = new polyline[100];
	polyline ptr[100];
	polyline tmp;
	int n_polyline = 0;//number of polylines in the collection
	bool again = true;
	while (again)
	{
		int choice = 0;
		int index = 0;
		cout << "Class Polyline" << endl;
		cout << "n (x1;y1) (x2;y2) ... (xn;yn)" << endl;
		cout << "\n\n";
		cout << "1.Create an object(polyline)\n2.Print the entire collection of objects\n3.Delete an object(polyline)\n";
		cout << "4.Operations on a polyline\n5.Delete all objects in the collection\n6.Exit"<<endl;
		cout << "Select the menu item to continue: ";
		cin >> choice;
		if (choice >= 1 && choice <= 6)
		{
			try 
			{
				switch (choice)
				{
				case 1:
					cin.get();
					system("cls");
					cout << "Enter the number of vertices of the polyline and the coordinates of the vertices in this way (x;y) via enter" << endl;
					cin >> tmp;
					add_object(ptr, tmp, n_polyline);
					print_collection(ptr, n_polyline);
					cin.get();
					system("cls");
					break;
				case 2:
					cin.get();
					system("cls");
					print_collection(ptr, n_polyline);
					cin.get();
					system("cls");
					break;
				case 3:
					cin.get();
					system("cls");
					print_collection(ptr, n_polyline);
					cout << "Which polyline to delete?\nEnter the number of the polyline: ";
					cin >> index;
					delete_object(ptr, index, n_polyline);
					print_collection(ptr, n_polyline);
					cin.get();
					system("cls");
					break;
				case 4:
					system("cls");
					operations_on_polyline(ptr, n_polyline);
					break;
				case 5:
					n_polyline = 0;
					cin.get();
					system("cls");
					break;
				case 6:
					choice = 7;
					again = false;
					break;
				};
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
				cin.get();
				system("cls");
			}
			catch (const char* err)
			{
				cout << err;
				cin.get();
				system("cls");
			}
		}
	}
	//delete_all_object(ptr);
    return 0;
}

int main()
{
	int start = basic_menu();
	if (start == 0)
		return 0;
}