/*	A header file of Cisc 320 assignment 5
*
*		Author: Wansi Liang
*		Student number: 20067725
*/

#pragma once

#include <string>
using namespace std;

class Shape {
public:
	Shape();
	Shape(int length, int width, const string& colour);
	virtual ~Shape();
	int getLength() const;
	int getWidth() const;
  string getColour()const;
  virtual void draw() = 0;
private:
	int length, width;
  string colour;
};

class Square : public Shape {
public:
	Square(int length, int width, const string& colour);
	void drawOutside() const;
  ~Square();
  void draw();
};

//When the shape is able to be filled with colour
class Filled {
public:
	Filled(const string& fillColour);
	virtual ~Filled();
	virtual void fill() = 0;
	string getFilledColour() const;
private:
	string fillColour;
};

class FilledSquare : public Square, public Filled {
public:
	FilledSquare(int length, int width, const string& colour, const string& fillColour);
	void fill();
  ~FilledSquare();
  void draw();
};

//When the shpae is able to put text
class Text {
public:
	Text(const string& text);
	virtual ~Text();
	virtual void drawText() = 0;
	string getText() const;
private:
	string text;
};

class FilledTextSquare : public FilledSquare, public Text {
public:
	FilledTextSquare(int length, int width, const string& colour, const string& fillColour, const string& text);
	void drawText();
  ~FilledTextSquare();
  void draw();
};

class Circle : public Shape {
public:
	Circle(int length, int width, const string& colour);
	void drawOutside() const;
  ~Circle();
  void draw();
};

class FilledCircle : public Circle, public Filled {
public:
	FilledCircle(int length, int width, const string& colour, const string& fillColour);
	void fill();
  ~FilledCircle();
  void draw();
};

class Arc : public Shape {
public:
	Arc(int length, int width, const string& colour);
	void draw();
  ~Arc();
};
