//main.cpp
//This takes your info and determines if your school is realistic
//Calvin Smith

/*
THIS PROGRAM TAKES IN DATA FOR A SPECIFIC COLLEGE, CALCULATES IF IT IS A GOOD DECISION, AND
IT APPENDS IT TO THE END OF A CSV FILE


*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


string getCollege(double years) {
	//Input Data
	string collegeData;
	string name;
	double roomBoard;
	double tuition;
	double fees;
	double gradRate;
	double medianIncome;

	//Output Data
	double score;
	double finalCost;
	string answer;

	//Inputs

	cout << "What is the name of the college" << endl;
	cin >> name;
	cout << "What is the Room and Board of this college?" << endl;
	cin >> roomBoard;
	cout << "What is the tuition of this college?" << endl;
	cin >> tuition;
	cout << "What are the additional fees of this college?" << endl;
	cin >> fees;
	cout << "What percent of attendees graduate this college?" << endl;
	cin >> gradRate; //this will be changed to a decimal later
	cout << "What is the median income of this college?" << endl;
	cin >> medianIncome;

	finalCost = (tuition + roomBoard + fees) * years;

	score = (100 - (finalCost / medianIncome)) * (gradRate / 100); //Number of years it takes to pay it off, times the number of graduates 

	if (score > 65) {
		answer = "Yes";
	} else {
		answer = "No";
	}
	collegeData =
		name + ", " + 
		to_string(medianIncome) + ", " +
		to_string(finalCost) + ", " + 
		to_string(tuition) + ", " + 
		to_string(roomBoard) + ", " + 
		to_string(fees) + ", " + 
		to_string(score) + ", " + 
		to_string(gradRate) + "," +
		answer + "\n";
	return collegeData;
}
bool getContinuation() {
	string inContinue;
	bool answer;
	cout << "Do you want to continue?" << endl;
	cin >> inContinue;
	if (inContinue == "Y" || inContinue == "yes" || inContinue == "y") {
		return true;
	}
	else {
		return false;
	}
}



int main() {
	//Declarations
	double years;
	string fileExport = "Name, Income, Final Cost, Tuition, Room and Board, Fees, Score, Graduation Rate, Is it a Good School? \n";


	//Getting Years to attend
	cout << "How many years are you attending?" << endl;
	cin >> years;
	//The main loop. This is the exact opposite of Functional Programming

	do {
		fileExport += getCollege(years);
	} while (getContinuation());
	
	//File manipulation
	ofstream collegeFile;
	collegeFile.open("college.csv");
	collegeFile << fileExport;
	collegeFile.close();

	return 0;
}