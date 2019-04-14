#include"MaxHeap.h"
Maxheap::Maxheap()
{
  maxheap.push_back(0);
}

Maxheap::Maxheap(int* arr,int arrsize)
{
  maxheap.push_back(0);
  for(int i{}; i<arrsize ; i++)
    {
      maxheap.push_back(arr[i]);
      build_max_heap();
    }
 
}

Maxheap::Maxheap(const Maxheap& heap)
{
  for(int i{}; i<=(heap.heapsize) ; i++)
    {
      maxheap.push_back(heap.maxheap[i]);
       build_max_heap();
    }
}
void Maxheap::add(int x)
{
  maxheap.push_back(x);
  build_max_heap();
}

void Maxheap::build_max_heap()
{
  heapsize=maxheap.size()-1;
  for(int i{static_cast<int>(floor(heapsize/2))} ; i>0 ; i--)
    {
      max_heapify(i);
    }
}

void Maxheap::max_heapify(int i)
{
  int largest_index{i};
  int largest{};
  if (2*i<=heapsize)
    if(LeftChild(i-1)>=maxheap[i])
      largest_index=2*i;
  if ((2*i+1)<=heapsize)
    if(RightChild(i-1)>=maxheap[i])
      largest_index=2*i+1;
  if (largest_index!= i)
    {
    largest = maxheap[largest_index];
    maxheap[largest_index] = maxheap[i];
    maxheap[i] = largest;
    max_heapify(largest_index);
    }
 
}

int Maxheap::RightChild(int i)
{
  return maxheap[2*i+3]; 
}

int Maxheap::LeftChild(int i)
{
  return maxheap[2*i+2];
}

void Maxheap::printArray()
{
  for(int i{1} ; i<=heapsize ;i++)
    {
      std::cout <<" "<< maxheap[i];
      if(i!=heapsize)
	std::cout<<",";
    }
  std::cout<<std::endl;
}

int Maxheap::parent(int i)
{
  return maxheap[floor((i+1)/2)];
}

int Maxheap::Max()
{
  return maxheap[1];
}

void Maxheap::Delete()
{
  maxheap[1]=maxheap[heapsize];
  maxheap.erase(maxheap.begin()+heapsize);
  build_max_heap();
}

void Maxheap::Heapsort()
{
  int repeat{heapsize};
  for(int i{} ; i<repeat ; i++)
    {
      std::cout <<" "<< Max();
      Delete();
    }
  
  std::cout<<std::endl;
}

int Maxheap::operator[](size_t i)
{
  return maxheap[i+1];
}


std::ostream& operator<<(std::ostream& os , Maxheap& a)
{
  int height{1};
   os<<a.maxheap[1]<<", ";
  for (int i{1} ; i<a.heapsize ; i++)
    {
   
    if((i+1)==(2^height))
      {
	os<<std::endl;
	height++;
      }
     os<<a.maxheap[i+1]<<", ";
      }
  return os;
}
