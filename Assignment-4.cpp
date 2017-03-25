// Blake Bartenbach
//   Assignment 4 - More Conversions
//
#include <iostream>
#include <string>

using namespace std;

void init();
void showMenu();
void parseMenuOption(int selection);
int getMenuSelection();
double getPoundsEntry();
double getFeetEntry();
double getInchesEntry();
double getDouble(string prompt);

class Converter {
    private:
        double pounds;
        double inches;
        double feet;
        double centimeters;
        double kilograms;

	public:
        Converter(double x) { 
            pounds = x;
        }
        Converter(double xinches, double xfeet) {
            feet = xfeet;
            inches = xinches;
        }

        void convertFeetAndInches() {
            centimeters = 0.0;
            centimeters+=(feet*30.48);
            centimeters+=(inches*2.54);
        }
        void convertPounds() {
            kilograms = pounds * 0.45359;
        }
        double getKilograms() {
            return kilograms;
        }
        double getPounds() {
            return pounds;
        }
        double getFeet() {
            return feet;
        }
        double getInches() {
            return inches;
        }
        double getCentimeters() {
            return centimeters;
        }
};

int main() {
	init();
	while (true) {
		showMenu();
		int selection = getMenuSelection();
		parseMenuOption(selection);
	}
}

void parseMenuOption(int selection) {
	switch (selection) {
	  case 1: {
		  Converter converter(getInchesEntry(), getFeetEntry());
          converter.convertFeetAndInches();
          system("cls");
          cout << "\n  " << converter.getFeet() << "\"" << converter.getInches() << "'" << " converts to " << converter.getCentimeters() << " centimeters\n\n";
          break;
      }
	  case 2: {
		  Converter converter(getPoundsEntry());
          converter.convertPounds();
          system("cls");
          cout << "\n  " << converter.getPounds() << " pounds converts to " << converter.getKilograms() << " kilograms\n\n";
          break;
      }
	  case 3: {
		  exit(0);
          break;
      }
	  default: {
          system("cls");
          cout << "\n  Invalid menu option\n\n";
          cin.clear();
          showMenu();
		  parseMenuOption(getMenuSelection());
          break;
      }
	}
}

void init() {
	cout << "\n  Conversion Program - By Blake Bartenbach\n\n";
}

void showMenu() {
	cout << "[1] Convert Feet & Inches to Centimeters\n";
	cout << "[2] Convert Pounds to Kilograms\n";
	cout << "[3] Exit Program\n\n";
	cout << "Selection: ";
}

double getFeetEntry() {
    return getDouble("\nEnter the number of feet: ");
}

double getInchesEntry() {
    return getDouble("\nEnter the number of inches: ");
}

double getDouble(string prompt) {
    cout << prompt;
    double entry = 0.0;
    cin >> entry;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\nInvalid entry\n";
        entry = getDouble(prompt);
    }
    return entry;
}

double getPoundsEntry() {
    return getDouble("\nEnter the amount in pounds: ");
}

int getMenuSelection() {
	int selection = 0;
	cin >> selection;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return 4;
    }
	return selection;
}