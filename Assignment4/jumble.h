/*  A header file for CISC320 assignment 4
*
*   Author: Wansi Liang
*   Student number: 20067725
*/
#pragma once

using namespace std;

typedef char* charArrayPtr;

class BadJumbleException {
public:
  BadJumbleException(const string&);
  string& what();

private:
  string message;
};

class JumblePuzzle {
public:
  int getSize() const;
  int getColPos() const;
  int getRowPos() const;
  int getDifficulty() const;
  char getDirection() const;
  charArrayPtr* getJumble() const;
  JumblePuzzle(const string&, const string&);
  JumblePuzzle(const JumblePuzzle&);
  ~JumblePuzzle();

private:
  int size;
  int randCol;
  int randRow;
  int difficultyLevel;
  char direction;
  charArrayPtr* jumble;
  string hiddenWord;
  charArrayPtr* newCharArray(const charArrayPtr*, const int) const;
  int getRandomNum(int);
};
