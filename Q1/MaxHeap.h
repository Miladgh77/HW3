#ifndef Maxheap_H
#define Maxheap_H
#include<iostream>
#include<vector>
#include<cmath>
class Maxheap;

std::ostream& operator<<(std::ostream& ,Maxheap&);
class Maxheap {
 private:

  int height;
  void max_heapify(int);
  void build_max_heap();
 public:
  int heapsize;
  std::vector<int>maxheap;
  Maxheap();
  Maxheap(int*,int);
  Maxheap(const Maxheap& heap);
  void add(int);
  void Delete();
  int Max();
  int getHeight();
  int parent(int);
  int RightChild(int);
  int LeftChild(int);
  void printArray();
  void Heapsort();
  int operator[](size_t);
};
#endif
