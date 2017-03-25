// Assignment 8
// Blake Bartenbach

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TempConvert {
    double temp;

    double getFarenheit() {
	    return (temp * (9.0/5.0)) + 32.0;
    }

    double getCelsius() {
	    return (temp - 32.0) * (5.0/9.0);

    }
};

int main() {

	while (true) {
		cout << "  [0] Convert from Celsius to Farenheit\n";
		cout << "  [1] Convert from Farenheit to Celsius\n";
        cout << "  [2] Exit Program\n\n";
		cout << "Selection: ";
		int menuOption = 0;
		cin >> menuOption;

        // initialize struct
        TempConvert convert;
		
		if (cin.fail()) {
			// invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "Invalid input\n\n";
		}
		else if (menuOption == 0) {
			cout << "\nPlease enter the temperature in Celsius: ";

			//exception handling
			cin.exceptions(istream::failbit | istream::badbit);
			try {
				cin >> convert.temp;
				double newTemp = convert.getFarenheit();
				system("cls");
				cout << convert.temp << "C is " << setprecision(1) << fixed << newTemp << "F\n\n";
			} catch (istream::failure e) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				system("cls");
				cout << "Invalid Input.  Please enter a numerical value.\n" << endl;
			}
		} else if (menuOption == 1) {
		    cout << "\nPlease enter the temperature in Farenheit: ";

			//exception handling
			cin.exceptions(istream::failbit | istream::badbit);
			try {
				cin >> convert.temp;
				double newTemp = convert.getCelsius();
				system("cls");
				cout << convert.temp << "F is " << setprecision(1) << fixed << newTemp << "C\n\n";
			}
			catch (istream::failure e) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				system("cls");
				cout << "Invalid Input.  Please enter a numerical value.\n" << endl;
			}
        } else if (menuOption == 2) {
            exit(0);
        } else {
			system("cls");
			cout << "Invalid input\n\n";
		}
	}
	return 0;
}


