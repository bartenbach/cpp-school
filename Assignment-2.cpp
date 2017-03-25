// Blake Bartenbach
// Assignment 2

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
	string name;
	vector<char> grades;
	double gpa;
public:
	Student() { }
	Student(string y) : name(y) {}
	void addGrade(char grade) { grades.push_back(grade); }
	void displayGrades() {
		for (unsigned int i=0 ; i < grades.size() ; i++) {
			cout << "Element[" << i << "]" << grades[i] << endl;
		}
	}
	string getName() { return name; }
	void setGpa(double x) { gpa = x; }
    double getGpa() { return gpa; }
	vector<char> getGrades() { return grades; }
};

char getStudentGrade();
string getStudentName();
double calculateGpa(vector<char>);
void output(vector<Student*>);

inline void init() {
    cout << "GPA Calculator - Programmed by: Blake Bartenbach\n\n";
}

int main() {
    init();
	vector<Student*> students;
	for (int i=0 ; i < 4 ; i++) {
		Student* s = new Student(getStudentName());
		students.push_back(s);
		cout << s->getName() << ":\n";
		for (int i=0 ; i < 5 ; i++) {
			cout << "  Enter grade " << i+1 << ": ";
			s->addGrade(getStudentGrade());
		}
        s->setGpa(calculateGpa(s->getGrades()));
        cout << endl;
	}

    output(students);
    system("pause");
	return 0;
}

void output(vector<Student*> students) {
    cout << "\n\n==============================\n";
    cout << "STUDENT                  GPA\n";
    cout << "-------                  ---\n";
    for (Student* s : students) {
        cout << setw(15) << left << s->getName() << "\t\t";
        cout << setprecision(3) << fixed << setw(5) << s->getGpa() << endl;
	}
    cout << "==============================\n\n";
}

double calculateGpa(vector<char> grades) {
	double total = 0.0;
	for (char grade : grades) {
		switch(grade) {
			case 'A':
				total+=4.0;
				break;
			case 'B':
				total+=3.0;
				break;
			case 'C':
				total+=2.0;
				break;
			case 'D':
				total+=1.0;
				break;
			case 'F':
				break;
			default:
				cout << "ERROR: This should never happen." << endl;
		}
	}
	return total / grades.size();
}

string getStudentName() {
	cout << "Enter the student's name: ";
	string studentName = "";
	cin >> studentName;
	return studentName;
}

char getStudentGrade() {
	char studentGrade;
	cin >> studentGrade;
	switch (toupper(studentGrade)) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'F':
			return toupper(studentGrade);
		default:
			cout << "Invalid Grade.  Please enter a valid letter grade (A,B,C,D,F): ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getStudentGrade();
	}
}
