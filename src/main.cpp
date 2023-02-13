#include "question.hh"
#include <iostream>
#include <fstream>
#include "size.hh"

int Question::scores = 0;

int main(int argc, char *argv[])
{
  Question questions_tab [SIZE];
   std::string answer;

  std::cout << "Gotowy na pytania ... ?" << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
    
  for(Question question : questions_tab)
    {
      question.Get_information();
      std::cout << question << std::endl;
      std::cin >> answer;
      question.Save(answer);
      if(question.Compare())
	std::cout << "Dobrze!!" << std::endl;
    }

 questions_tab[0].Dashboard();

  std::cout << "Koniec testu! Dziekujemy za udzial." << std::endl;
  
}


