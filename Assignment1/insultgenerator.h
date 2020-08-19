/*
*	insultgenerator.h
*
*		Author: Wansi Liang
*		A header file for CISC320 assignment 1
*/

#include <string>
#include <vector>

using namespace std;

const string file("InsultsSource.txt");

//Throw exception when the file cannot be opened or cannot be read
class FileException {
public:
	FileException(const string&);
	string what() const;
private:
	string message;
};

//Throw exception when numbers out of bounds
class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
};

//Generate insults
class InsultGenerator {
public:
	InsultGenerator();
	void initialize();
	string talkToMe() const;
	vector<string> generate(int) const;
	void generateAndSave(string, int) const;
private:
	vector<string> col1;
	vector<string> col2;
	vector<string> col3;
	int total;
};
