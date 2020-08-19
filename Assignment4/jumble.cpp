/*  A cpp file for CISC320 assignment 4
*
*   Author: Wansi Liang
*   Student number: 20067725
*/
#include <string>
#include <iostream>
#include <ctime>
#include "jumble.h"
using namespace std;

//Exception class
BadJumbleException::BadJumbleException(const string& message) : message(message) {}
string& BadJumbleException::what() {
  return message;
}

//Retutn the size of the jumble
int JumblePuzzle::getSize() const {
  return size;
}

//Return the hidden word location user entered -- column
int JumblePuzzle::getColPos() const {
  return randCol;
}

//Return the hidden word location user entered-- row
int JumblePuzzle::getRowPos() const {
  return randRow;
}

//Return the difficulty level the user entered
int JumblePuzzle::getDifficulty() const {
  return difficultyLevel;
}

//Return the hidden word direction user entered
char JumblePuzzle::getDirection() const {
  return direction;
}

//Return a jumble
charArrayPtr* JumblePuzzle::getJumble() const {
  return newCharArray(jumble, size);
}

//Constructor
JumblePuzzle::JumblePuzzle(const string& hidden, const string& difficulty) : hiddenWord(hidden) {
  int hiddenLength = hidden.length();

  //Hidden wrod has more than 10 or less than 3 alphabets
  if (hiddenLength > 10)
    throw BadJumbleException("The length of hidden word should less than 10");
  if (hiddenLength < 3)
    throw BadJumbleException("The length of hidden word should greater than 3");

  //Transform user input difficulty to lowercase
  for (const char& ch : difficulty)
    putchar(tolower(ch));

  if (difficulty == "easy")
    difficultyLevel = 2;
  else if (difficulty == "medium")
    difficultyLevel = 3;
  else if (difficulty == "hard")
    difficultyLevel = 4;
  else
    throw BadJumbleException("Wrong difficulty level");

  size = hiddenLength * difficultyLevel;
  jumble = new charArrayPtr[size];
  for (int i=0; i<size; i++)
    jumble[i] = new char[size];

  //Possible directions
  char directionList[] = {'n', 'e', 's', 'w'};
  int row, col;
  bool flag = true;
  for (row=0; row<size; row++)
    for (col=0; col<size; col++)
      jumble[row][col] = 97 + getRandomNum(26);

  //Get random numbers for row and column to hide the hidden word
  randRow = getRandomNum(size);
  randCol = getRandomNum(size);
  int length = size / difficultyLevel;

  while (flag) {
    int index = 0;
    row = randRow;
    col = randCol;

    //Get a random direction
    int dirRandNum = getRandomNum(4);
    direction = directionList[dirRandNum];

    //If the dirction is north
    if (direction == 'n') {
      while (index < length && row >= 0) {
        jumble[row][randCol] = hiddenWord.at(index);
        row--;
        index++;
      }
    }

    //If the direction is east
    else if (direction == 'e') {
      while (index < length && col < size) {
        jumble[randRow][col] = hiddenWord.at(index);
        col++;
        index++;
      }
    }

    //If the direction is south
    else if (direction == 's') {
      while (index < length && row < size) {
        jumble[row][randCol] = hiddenWord.at(index);
        row++;
        index++;
      }
    }

    //If the dirction is west
    else if (direction == 'w') {
      while (index < length && col >= 0) {
        jumble[randRow][col] = hiddenWord.at(index);
        col--;
        index++;
      }
    }

    //If the hidden word is not completely hidden, redo the loop
    if (index <= length)
      flag = false;
  }
}

//Clone
JumblePuzzle::JumblePuzzle(const JumblePuzzle& jp) {
  size = jp.getSize();
  randCol = jp.getColPos();
  randRow = jp.getRowPos();
  difficultyLevel = jp.getDifficulty();
  direction = jp.getDirection();
  jumble = newCharArray(jp.getJumble(), size);
  hiddenWord = jp.hiddenWord;
}

//Create a jumble
charArrayPtr* JumblePuzzle::newCharArray(const charArrayPtr* newJumble, const int newSize) const {
  charArrayPtr* puzzle = new charArrayPtr[newSize];
  for (int i=0; i<newSize; i++)
    puzzle[i] = new char[size];
  for (int j=0; j<newSize; j++)
    for (int k=0; k<newSize; k++)
      puzzle[j][k] = newJumble[j][k];
  return puzzle;
}

//Delete the 2D array/jumble
JumblePuzzle::~JumblePuzzle() {
  for (int i=0; i<size; i++)
    delete[] jumble[i];
  delete[] jumble;
  jumble = nullptr;
}

//Get a random number
int JumblePuzzle::getRandomNum(int range) {
  return rand() % range;
}
