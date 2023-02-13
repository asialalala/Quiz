#ifndef QUESTION_HH
#define QUESTION_HH

#include <iostream>
#include <fstream>

class Question
{
private:
  std::string _question;
  std::string _correct;
  std::string _answer;
  std::string _a, _b, _c, _d;
  int _nr;

  static int scores; //zrobic to na static!!
  
public:  
  void Get_information();
  void Ask() const;
  void Save(std::string answer);
  bool Compare();
  static void Dashboard();

};


std::ostream &operator<<(std::ostream &out, const Question &question);
//std::istream &operator>>(std::istream &in, Question &question);

#endif


