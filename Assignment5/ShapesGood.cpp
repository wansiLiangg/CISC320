/*	A cpp file of Cisc 320 assignment 5
*
*		Author: Wansi Liang
*		Student number: 20067725
*/

#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

Shape::Shape() : length(0), width(0), colour("purple") {}
Shape::Shape(int len, int wid, const string& col) : length(len), width(wid), colour(col) {}
Shape::~Shape() {}
int Shape::getLength() const { return length; }
int Shape::getWidth() const { return width; }
string Shape::getColour() const {return colour;}

Square::Square(int len, int wid, const string& col) : Shape(len, wid, col) {}
void Square::drawOutside() const {
	cout << "\nDrawing a " + getColour() + " square.";
}
Square::~Square() {}
void Square::draw() {drawOutside();}

//When the shape is able to be filled with colour -- get the fillColour
Filled::Filled(const string& fillC) : fillColour(fillC) {}
Filled::~Filled() {}
string Filled::getFilledColour() const {return fillColour;}

FilledSquare::FilledSquare(int len, int wid, const string& col, const string& fillCol) : Square(len, wid, col), Filled(fillCol) {}
void FilledSquare::fill() {
	cout << " With " + getFilledColour() + " fill.";
}
FilledSquare::~FilledSquare() {}
void FilledSquare::draw() {
  drawOutside();
  fill();
}

//When the shpae is able to put text -- get the text 
Text::Text(const string& tx) : text(tx) {}
Text::~Text() {}
string Text::getText() const {return text;}

FilledTextSquare::FilledTextSquare(int len, int wid, const string& col, const string& fillCol, const string& text) : FilledSquare(len, wid, col, fillCol), Text(text) {}
void FilledTextSquare::drawText() {
	cout << " Containing the text: \"" << getText() << "\".";
}
FilledTextSquare::~FilledTextSquare() {}
void FilledTextSquare::draw() {
  drawOutside();
  fill();
  drawText();
}

Circle::Circle(int len, int wid, const string& col) : Shape(len, wid, col) {}
void Circle::drawOutside() const{
	cout << "\nDrawing a " + getColour() + " circle.";
}
Circle::~Circle() {}
void Circle::draw() {
  drawOutside();
}

FilledCircle::FilledCircle(int len, int wid, const string& col, const string& fillCol) : Circle(len, wid, col), Filled(fillCol) {}
void FilledCircle::fill() {
	cout << " With " + getFilledColour() + " fill.";
}
FilledCircle::~FilledCircle() {}
void FilledCircle::draw() {
  drawOutside();
  fill();
}

Arc::Arc(int len, int wid, const string& col) : Shape(len, wid, col) {}
void Arc::draw() {
	cout << "\nDrawing a " + getColour() + " arc.";
}
Arc::~Arc() {}
