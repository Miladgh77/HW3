#include"Vectorplus.h"

Vectorplus::Vectorplus()
{
  std::cout<<"default const"<<std::endl;
  size = 0;
  capacity = 1;
  vectorplus = new int[1];
}
Vectorplus::Vectorplus(const Vectorplus& vecplus)
{
    std::cout << "copy const" <<std::endl;
  size = vecplus.size;
  capacity = vecplus.capacity;
  vectorplus = new int[capacity];
  for(int i{};i<size;i++)
    {
      vectorplus[i]=vecplus.vectorplus[i];
    }
}
Vectorplus::Vectorplus(Vectorplus&& vecplus)
{
  std::cout << "move const" <<std::endl;
  size = vecplus.size;
  capacity = vecplus.capacity;
  vectorplus = vecplus.vectorplus;
  vecplus.vectorplus = nullptr;
}
Vectorplus::~Vectorplus()
{
  std::cout<<"distructed"<<std::endl;
  delete vectorplus;
}
  


void Vectorplus::pop_back()
{
  if (size == capacity/2)
    {
      capacity /=2;
       newarr = new int[size-1];
      for(int i{} ; i<size-1 ; i++)
	{
	  newarr[i]=vectorplus[i];
	}
      
       delete vectorplus;
       vectorplus = new int[capacity];
       for(int i{} ; i<size-1 ; i++)
	{
	  vectorplus[i] = newarr[i];
	}
       delete newarr;
    }
  else
    {
      vectorplus[size] = 0;
    }
  size--;
      
}

void Vectorplus::push_back(int newvalue)
{
   if (size == capacity)
    {
      capacity *= 2;
      newarr = new int[size+1];
      for(int i{} ; i<size ; i++)
	{
	  newarr[i]=vectorplus[i];
	}
      
       delete vectorplus;
       vectorplus = new int[capacity];
       newarr[size] = newvalue;
       for(int i{} ; i<size ; i++)
	{
	  vectorplus[i] = newarr[i];
	}
       vectorplus[size] = newvalue;
       delete newarr;
    }
  else
    {
      vectorplus[size] = newvalue;
    }
   size++;
}

void Vectorplus::show()
{
  for(int i{}; i<size ; i++)
    {
      std::cout << *(vectorplus + i);
      if (i!=size-1)
	std::cout<< " , ";
    }
  std::cout<< std::endl;
}

Vectorplus Vectorplus::operator+(const Vectorplus& vecplus)
{
  Vectorplus copy{*this};
  for(int i{} ; i<size ;i++)
    {
      copy.vectorplus[i] += vecplus.vectorplus[i];
    }
  
  return copy;
}
int Vectorplus::operator*(const Vectorplus& vecplus)
{
  int sum{};
  for(int i{} ; i<size ;i++)
    {
      sum += vectorplus[i] * vecplus.vectorplus[i];
    }
  
  return sum;
}
bool Vectorplus::operator<(const Vectorplus& vecplus)const
{
  return(size < vecplus.size);
}

bool Vectorplus::operator==(const Vectorplus& vecplus)const
{
  return(size==vecplus.size); 
}
