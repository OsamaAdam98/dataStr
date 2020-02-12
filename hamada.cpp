#include <iostream>
using namespace std;

int main()
{
  int var = 20;
  int *ptr;
  ptr = &var;
  cout << "value at *ptr " << *ptr << "\n";
  cout << "value at var " << var << "\n";
  cout << "the address of the ptr " << &ptr << "\n";
}