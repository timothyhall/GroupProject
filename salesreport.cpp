/*This is the sales report generating app*/
// Jerome Hollifield, Shale Hausler & Timothy Hall

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
	/*************************
	* variables
	*************************/
	const int ROWS = 15,
		COLS = 30,
		ticketVersions = 15;
	double rowPrice[ticketVersions];
	double salesTotal = 0.0;
	char seatChart[ROWS][COLS];

	ifstream seatFile;
	seatFile.open("SeatAvailability.dat");

	/**************************************************
	* if statement to exit program if either 
	* the seat data or seatprices files cannot be found
	**************************************************/
	if (!seatFile) {
		cout << "Unable to open the record. \n"
			<< "Please contact the system administrator.";
		exit(1);
	}

	if (!seatFile.is_open()) {
		cout << "Unable to open the record. \n"
			<< "Please contact the system administrator.";
		exit(1);
	}

	ifstream seatPrice;
	seatPrice.open("SeatPrices.dat");
	if (!seatPrice) {
		cout << "Unable to open the record. \n"
			<< "Please contact the system administrator.";
		exit(1);
	}

	if (!seatPrice.is_open()) {
		cout << "Unable to open the record. \n"
			<< "Please contact the system administrator.";
		exit(1);
	}

	/**************************************************
	*displays ticket prices
	**************************************************/
	for (int i = 0; i < ticketVersions; i++)
	{
		seatPrice >> rowPrice[i];
		/* cout << fixed << setprecision(2)
			<< "$" << rowPrice[i] << endl; */
	}

	for (int i=0; i < ROWS; i++)
	{
		for (int j=0; j < COLS; j++)
		{
			seatFile >> seatChart[i][j];
		}
	}
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (seatChart[i][j] == '*')
			{
				salesTotal = salesTotal + rowPrice[i];
			}
			
		}
	}
	cout << "The total ticket sales are: $" << fixed << setprecision(2) << salesTotal << endl;

	seatFile.close();
	seatPrice.close();
	return 0;
}
