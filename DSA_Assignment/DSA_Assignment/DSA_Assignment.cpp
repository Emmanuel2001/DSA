// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "ListP.h"

using namespace std;

void ReadStation(ListP &Green, ListP &Red, ListP &Orange, ListP &Blue, ListP &Purple ) {
	ifstream reader("Stations.csv");
	string code, name, lcode;
	bool check = true;
	if (reader.is_open()) {
		while (!reader.eof()) {
			getline(reader, code, ',');
			getline(reader, name);
			cout << code << "\t" << name << endl;
			//add to lists
			lcode = code.substr(0, 2);
			if (lcode == "EW") {
				Green.add(code + "\t" + name);
			}
			else if (lcode == "NS") {
				Red.add(code + "\t" + name);
			}
			else if (code.substr(0,1) == "C") {
				Orange.add(code + "\t" + name);
			}
			else if (lcode == "DT") {
				Blue.add(code + "\t" + name);
			}
			else if (lcode == "NE") {
				Purple.add(code + "\t" + name);
			}
		
		}
	}
	else {
		cout << "Error" << endl;
	}
	reader.close();
}
void displayMenu()
{
	cout << "\nMRT Planning \n";
	cout << "--------------------------------\n";
	cout << "1 Display all stations in a given line \n";
	cout << "2 Display station information for a given station name \n";
	cout << "3 Add and Save a new station on a given line \n";
	cout << "4 Find and Display a route and its price, given the Source and Destination Stations \n";
	cout << "--------------------------------\n";
	cout << "5 Search for the shortest route and its price, given the Source and Destination Stations \n";
	cout << "6 Display up to 3 possible routes with their price and distance, given the Source and Destination Stations \n";
	cout << "Press any other key to Exit \n";
	cout << "--------------------------------\n";
	cout << "Enter option : ";
}

int main()
{
	ListP Green, Red, Orange, Blue, Purple;

	ReadStation(Green, Red, Orange, Blue, Purple);
	int option;
	bool exit = 0;
	while (!exit)
	{
		

		displayMenu();
		cin >> option;

		if (option == 1)
		{
			string name;
			cout << "Enter Line Color (eg. Green, Red)";
			cin >> name;
			if (name == "Green") {
				for (int i = 0; i < Green.getLength(); i++) {
					cout << Green.get(i) << endl;
				}
			}
			if (name == "Red") {
				for (int i = 0; i < Red.getLength(); i++) {
					cout << Red.get(i) << endl;
				}
			}
			if (name == "Orange") {
				for (int i = 0; i < Orange.getLength(); i++) {
					cout << Orange.get(i) << endl;
				}
			}
			if (name == "Blue") {
				for (int i = 0; i < Blue.getLength(); i++) {
					cout << Blue.get(i) << endl;
				}
			}
			if (name == "Purple") {
				for (int i = 0; i < Purple.getLength(); i++) {
					cout << Purple.get(i) << endl;
				}
			}
		}
		else if (option == 2)
		{
			//implement
		}
		else if (option == 3)
		{
			//implement
		}
		else if (option == 4)
		{
			//implement
		}
		else if (option == 5)
		{
			//implement
		}
		else if (option == 6)
		{
			
		}
		else
		{
			exit = 1;
			cout << "Bye!" << endl;
		}
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
