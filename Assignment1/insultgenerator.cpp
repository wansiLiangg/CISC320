/*
*	insultgenerator.cpp
*
*		Author: Wansi Liang
*		A cpp file for CISC320 assignment 1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "insultgenerator.h"

using namespace std;

//Return error message when file cannot be opened or cannot be read
FileException::FileException(const string& message) : message(message) {}
string FileException::what() const {return message;}

//Return error message when numbers out of bounds
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}
string NumInsultsOutOfBounds::what() const {return message;}

//Load all the source phrases from the InsultsSource.txt file into the attributes
void InsultGenerator::initialize() {
	string phrase;
	ifstream fileIn(file.c_str());
	if (fileIn.fail()) {
		throw FileException("Unable to read file " + file);
		return;
	}
	total = 0;
	while (!fileIn.eof()) {
		fileIn >> phrase;
		col1.push_back(phrase);
		fileIn >> phrase;
		col2.push_back(phrase);
		fileIn >> phrase;
		col3.push_back(phrase);
		total++;
	}
	fileIn.close();
}

//Returns a single insult, generated at random
string InsultGenerator::talkToMe() const {
	 return "Thou " + col1.at(rand() % total) + " " + col2.at(rand() % total) + " " + col3.at(rand() % total) + "!";
}

//Generates the requested number of unique insults
vector<string> InsultGenerator::generate(int num) const {
	int maxNum(10000);
	if (num < 1 || num > maxNum)
		throw NumInsultsOutOfBounds("Out of bounds!");
	vector<string> insults;
	int counter(0);
	int num1, num2, num3;
	string insult;
	int array[total][total][total];
	for (num1 = 0; num1 < total; num1++)
		for (num2 = 0; num2 < total; num2++)
			for (num3 = 0; num3 < total; num3++) {
				array[num1][num2][num3] = {0};
			}
	while (counter < num) {
		num1 = rand() % total;
		num2 = rand() % total;
		num3 = rand() % total;
		if (!array[num1][num2][num3]) {
			array[num1][num2][num3] = {1};
			counter++;
		}
	}
	counter = 0;
	for (num1 = 0; num1 < total && counter < num; num1++)
		for (num2 = 0; num2 < total && counter < num; num2++)
			for (num3 = 0; num3 < total && counter < num; num3++)
				if (array[num1][num2][num3]) {
					insult = "Thou " + col1.at(num1) + " " + col2.at(num2) + " " + col3.at(num3) + "!";
					insults.push_back(insult);
					counter++;
				}
	return insults;
}

//Generates the requested number of unique insults and saves them to the filename supplied
void InsultGenerator::generateAndSave(string fileName, int num) const {
	int counter(0);
	int maxNum(10000);
	if (num < 1 || num > maxNum)
		throw NumInsultsOutOfBounds("Out of bounds!");
	vector<string> insults(generate(num));
	ofstream fileOut(fileName.c_str());
	if (fileOut.fail()) {
		throw FileException("Unable to read file " + file);
	}
	while (counter < num) {
		fileOut << insults[counter] << endl;
		counter++;
	}
	fileOut.close();
}

//Constructor
InsultGenerator::InsultGenerator() : total(0) {}
