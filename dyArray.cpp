#include <iostream>
#include "DynamicArray.cpp"
using namespace std;

int main()
{
  DyArray array = DyArray(15);
  array.append(2);
  array.insert(5, 555);
  for (int i = 0; i < 15; i++)
  {
    cout << array.getElement(i) << endl;
  }
}