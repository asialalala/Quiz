#include "question.hh"
#include "size.hh"
#include <fstream>
#include <cstdlib>

void Question::Get_information()
{
  std::fstream file;

  file.open("questions.txt", std::ios::in);
  if(file.good()==false)
    {
      std::cerr <<  "Nie udalo sie otworzyc pliku.\n";
      exit(1);
    }

  _nr = 1;
  int nr_line = (_nr - 1)*6 + 1;
  int actual_nr = 1;
  std::string line;

  while(getline(file, line))
    {
      if(actual_nr == nr_line)
	  _question = line;
      if(actual_nr == nr_line+1)
	_a = line;
      if(actual_nr == nr_line+2)
	_b = line;
      if(actual_nr == nr_line+3)
	_c = line;
      if(actual_nr == nr_line+4)
	_d = line;
      if(actual_nr == nr_line+5)
	_correct = line;
      ++actual_nr;
    }
  
  file.close(); 
}


void Question::Ask() const
{
  std::cout << "Pytanie brzmi:\n" << _question <<  std::endl;
  std::cout << "Odpowiedzi:\n";
  std::cout << std::endl;
  std::cout << "a) " << _a << std::endl;
  std::cout << "b) " << _b << std::endl;
  std::cout << "c) " << _c << std::endl;
  std::cout << "d) " << _d << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Question &question)
{
  question.Ask();

  return out;
}

void Question::Save(std::string answer)
{
  // dorobic kontrole bledow

  if(answer != "a" && answer != "b" && answer != "c" && answer != "d")
    {
      std::cerr << "Nie ma takiej odpowiedzi. Sprobuje jeszcze raz." <<
	std::endl;
      std::cin >> answer;
    }
  _answer = answer;
}

/* Zrobic przeciazenie z tego
std::istream &operator>>(std::istream &in, Question &question)
{
    std::cout << "1";
  std::string answer;
    std::cout << "2";
  in >> answer;
    std::cout << "3";
  question.Save(answer);
    std::cout << "4";

  return in;
  }
*/

bool Question::Compare()
 {
   if(_correct == _answer)
     {
       scores++;
       return true;
     }
   return false;
 }



void Question::Dashboard()
{
  std::cout << "Poprawna odpowiedz udzielono na " << scores;
  switch (scores)
    {
    case 1:
      std::cout << " pytanie.";
      break;
    case 2:
      std::cout << " pytania.";
      break;
    case 3:
      std::cout << " pytania.";
      break;
    case 4:
      std::cout << " pytania.";
      break;
    default:
      std::cout << " pytan.";
      break;
    }

  std::cout <<  std::endl;
}

