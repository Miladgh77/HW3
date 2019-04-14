#ifndef Human_H
#define Human_H
#include<string>
#include<iostream>
#include<stdlib.h>

class Human {
 private:

 public:
  std::string FirstName ,lastName;
  int hairColor , eyeColor ,age ;
  bool gender;
  int numberOfChildren;
  Human** childs;
  Human* father;
  Human* mother ;
  Human* spouse;
  Human(std::string,std::string, int , int ,int, bool , int);
  Human(const Human &);
  ~Human();
  std::string getFirstName();
  std::string getLastName();
  bool getGender();
  int getHairColor();
  int getEyeColor();
  int getAge();
  bool operator>(Human *);
  bool operator==(Human *);
  Human* operator+(Human &);
  void operator++();
  bool isChildOf(Human*);
  bool isFatherOf(Human*);
  bool isMotherOf(Human*);
  void printChildren();
 
};


#endif
