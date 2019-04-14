#ifndef Maxheap_H
#define Maxheap_H
#include<iostream>
class Vectorplus {
 private:
  int* vectorplus;
  int* newarr;
 public:
  int size;
  int capacity;
  Vectorplus();
  Vectorplus(const Vectorplus&);
  Vectorplus(Vectorplus&&);
  ~Vectorplus();
  void pop_back();
  void push_back(int);
  void show();
  bool operator<(const Vectorplus&)const;
  bool operator==(const Vectorplus&)const;
  Vectorplus operator+(const Vectorplus&);
  int operator*(const Vectorplus&);
  // Vectorplus operator=(const Vectorplus&);
};

#endif
