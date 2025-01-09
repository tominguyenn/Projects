// This program gathers sales in each quarter for every division and then displays it in a table.
// It also calculates and displays the total sales
// The total number of divisions is set to 6
#include <iostream>
#include <iomanip>
using namespace std;

class DivSales 
{
	private:
		static double totalSales;        // Variable to hold total sales
		double quarterSales[4];          // Array to hold quarter sales

	public:
		DivSales();
		void setSales(double, double, double, double);
		double getSales(int);
		double getTotalSales();
};

// Constructor
DivSales::DivSales()         
{
	quarterSales[0] = 0.0;
	quarterSales[1] = 0.0;
	quarterSales[2] = 0.0;
	quarterSales[3] = 0.0;
	totalSales = 0.0;
}

// Stores sales data from inputed values
void DivSales::setSales(double quarter1, double quarter2, double quarter3, double quarter4)
{
	quarterSales[0] = quarter1;
	quarterSales[1] = quarter2;
	quarterSales[2] = quarter3;
	quarterSales[3] = quarter4;
	for (int count = 0; count < 4; count++)
	{
		totalSales += quarterSales[count];
	}
}

// Outputs individual sales for a quarter in a division
double DivSales::getSales(int n)
{
	return quarterSales[n];
}

// Outputs total sales
double DivSales::getTotalSales()
{
	return totalSales;
}
double DivSales::totalSales;

int main()
{	 
	const int NUM_DIVISIONS = 6;
	DivSales divisionSales[NUM_DIVISIONS] ;               // array for division sales
	double quarter1, quarter2, quarter3, quarter4;        // quarter variables
	
	// Display message to enter sales for each quater per divison
	for (int count = 0; count < 6; count++)
	{
		cout << "Division #" << count + 1 << ":" << endl;
		cout << "Enter the sales for quarter #1: " << " ";
		cin >> quarter1;
		cout << "Enter the sales for quarter #2: " << " ";
		cin >> quarter2;
		cout << "Enter the sales for quarter #3: " << " ";
		cin >> quarter3;
		cout << "Enter the sales for quarter #4: " << " ";
		cin >> quarter4;
		cout << endl;
		divisionSales[count].setSales(quarter1, quarter2, quarter3, quarter4);
	}
	
	// Displays the data
	cout << endl << "Division sales for each quarter:" << endl;
	cout << "Division:\t";
	cout << "Quarter 1:\t";
	cout << "Quarter 2:\t";
	cout << "Quarter 3:\t";
	cout << "Quarter 4:";
	cout << endl;
	for (int count = 0; count < 6; count++)
	{
		cout << count + 1 << "\t";
		for (int count1 = 0; count1 < 4; count1++) 
		{
			cout << "\t";
			cout << "$" << divisionSales[count].getSales(count1);
			cout << "\t";
		}
		cout << endl;
	}
		
	// Total corporate sales
	cout << endl << "The total corporate sales for the year: $";
	cout << divisionSales[NUM_DIVISIONS].getTotalSales();
	return 0;
}
