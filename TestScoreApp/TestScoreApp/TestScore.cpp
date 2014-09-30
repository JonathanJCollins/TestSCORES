#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;
double average(int numTests, double *testScores) {
	double avg;
	double total = 0.0;
	for (int i = 0; i < numTests; i++){
		total += testScores[i];
	}
	avg = total / numTests;
	return avg;
}
double averageMinusOne(int numTests, double *testScores, double lowScore) {
	double avgnew = 0;
	double total = 0.0;
	for (int i = 0; i < numTests; i++){
		total += testScores[i];
	}
	total = total - lowScore;
	numTests--;
	avgnew = total / (numTests);
	return avgnew;
}
int main(){
	int numTests = 0;
	double *testScores;
	double avgScores = 0;
	double newAvgScores = 0;
	double largeScore = 0;
	double lowScore = 11000;
	int testfun = 0;

	while (numTests <= 0){
		cout << "How many tests did you take?" << endl;
		cin >> numTests;
		if (numTests <= 0){
			cout << "Please input a positive number. THANKS" << endl;
		}
	}

	testScores = new double[numTests];
	cout << "Enter the test scores:" << endl;
	for (int i = 0; i < numTests; i++){
		cin >> testScores[i];
	}
	avgScores = average(numTests, testScores);
	
	for (int h = 0; h < numTests; h++){
		if (testScores[h] > largeScore){
			largeScore = testScores[h];
		}
		if (testScores[h] < lowScore){
			lowScore = testScores[h];
		}
	}
	cout << "The average score was: " << avgScores << endl
		<< "The largest score was: " << largeScore << endl
		<< "Would you like to remove the lowest score?(1 for yes, 2 for no)" << endl;
	cin >> testfun;
	if (testfun == 1){
		newAvgScores = averageMinusOne(numTests, testScores, lowScore);
		cout << "Your new average is: " << newAvgScores << endl; 
	}
	

	
}

