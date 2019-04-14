#include"Human.h"
Human::Human(std::string firstname,std::string lastname, int haircolor , int eyecolor
	,int age, bool gender , int numberofchildren)
{
  FirstName =firstname;
  lastName = lastname;
  hairColor = haircolor;
  eyeColor =eyecolor;
  this->age = age;
  this->gender = gender;
  numberOfChildren = numberofchildren;
}

Human::Human(const Human & person)
{
  this->FirstName = person.FirstName;
  this->lastName = person.lastName;
  this->hairColor =person.hairColor;
  this->eyeColor = person.eyeColor;
  this->age = person.age;
  this->gender = person.gender;
  this->numberOfChildren = person.numberOfChildren;
  this->father = person.father;
  this->mother = person.mother;
  
  }
Human::~Human()
{
  delete childs;
}
std::string Human::getFirstName()
{
  return this->FirstName;
}

std::string Human::getLastName()
{
  return this->lastName;
}
			       
bool Human::getGender()
{
  return this->gender;
}

int Human::getHairColor()
{
  return hairColor;
}

int Human::getEyeColor()
{
  return eyeColor;
}

int Human::getAge()
{
  return age;
}

bool Human::operator>(Human *person)
{
  return (this->age > person->age);
}

bool Human::operator==(Human* person)
{
  if (this->age== person->age && this->gender == person->gender && this->hairColor == person->hairColor && this->eyeColor == person->eyeColor && this->numberOfChildren == person->numberOfChildren)
    return 1;
  else
    return 0;
}

Human* Human::operator+(Human & person2)
{
   srand (time(NULL));
  
   Human** newchilds;
   newchilds = new Human*[numberOfChildren];
   for(int i{}; i<this->numberOfChildren;i++)
     {
       newchilds[i]=childs[i];
     }
   delete childs;
   childs = new Human*[numberOfChildren+1];

    for(int i{}; i<this->numberOfChildren;i++)
     {
       childs[i]=newchilds[i];
     }
    delete newchilds;
    this->numberOfChildren++;
   person2.numberOfChildren++;
   
   if(this->spouse == &person2)
     {
       int babyhaircolor =(rand()%2 > 0) ? this->hairColor : person2.hairColor;
       int babyeyecolor =(rand()%2 > 0) ? this->eyeColor : person2.eyeColor;
       bool babygender =(rand()%2 > 0) ? this->gender : person2.gender;
       std::string babyfirstname = (babygender =1 && this->gender==1) ? this->FirstName : person2.FirstName;
       std::string babylastname = (this->gender==1) ? person2.lastName : this->lastName;
       Human* baby= new Human{babyfirstname,babylastname,babyhaircolor,babyeyecolor,0,babygender,0};
       baby->father = (this->gender == 0) ? this : &person2;
       baby->mother = (this->gender == 1) ? this : &person2;
       childs[numberOfChildren] = baby;
       return baby;
     }
   else
     {
       std::string babylastname = (this->gender==1) ? person2.lastName : this->lastName;
       int babygender =(rand()%2 > 0) ? this->gender : person2.gender;
       Human* baby=new Human{"bastard",babylastname,0,0,0,babygender,0};
       return baby;
     }

     }


void Human::operator++()
{
  this->age++;
}

bool Human::isChildOf(Human* person)
{
  if(this->mother == person || this->father == person)
    return 1;
  else
    return 0;
}

bool Human::isFatherOf(Human* person)
{
  if(this->father == person)
    return 1;
  else
    return 0;
}

bool Human::isMotherOf(Human* person)
{
  if(this->mother == person)
    return 1;
  else
    return 0;
}

void Human::printChildren()
{
  for(int i{};i<numberOfChildren;i++)
    {
      std::cout<<this->childs[i]->FirstName<<std::endl;
    }
}
