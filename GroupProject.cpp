// GroupProject.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <array>
#include <fstream>



using namespace std;

class TicketManager
{
public:
	
	TicketManager();
	~TicketManager();
	void OpenFiles();
		

private:

};

TicketManager::TicketManager()
{
	


}
TicketManager::~TicketManager()
{	//Write/update file with seats available.
	//close out files used. 
}
void TicketManager::OpenFiles() {
	ifstream SeatAvailability;
	SeatAvailability.open("SeatAvailability.dat");
	ifstream SeatPrices;
	SeatPrices.open("SeatPrices.dat");

	if (SeatAvailability.is_open()) {
		cout << "SeatAvailability is open." << endl;
	}

	if (SeatPrices.is_open()) {
		cout << "SeatPrices is open." << endl;
	}
	

	
}



int main()
{

	char temp[450];
	



	const int seatRow = 15;
	const int seatColumn = 30;
	
	string line;

	ifstream seatingChart("SeatAvailability.dat");
	
	
	
	
	
	if (seatingChart.is_open())
	{
		while (getline(seatingChart, line))
		{
			cout << line << '\n';
			
		}


		

		cout << endl << endl << endl;
		cout << "break line" << endl << endl;
		string myArray[5];

		for (int i = 0; i < 5; ++i)
		{
			seatingChart >> myArray[i];
		}

		cout << endl << "yes" << endl;













		seatingChart.close();
	}

	else cout << "Unable to open file";
	
	

	
	system("Pause");
	return 0;
}
