#include <iostream>

class DyArray
{
private:
  int *array, length, cap;
  void expand()
  {
    cap *= 2;
    array = (int *)realloc(array, cap * sizeof(int));
  }

public:
  DyArray(int initCap)
  {
    length = 0;
    cap = initCap;
    array = new int[cap];
  };
  int append(int element)
  {
    if (length == cap)
      expand();
    array[length] = element;
    length++;
  };
  int erase(int index)
  {
    int erased = array[index];
    length--;
    for (int i = index; i < length; i++)
    {
      array[i] = array[i + 1];
    }
    return erased;
  }
  int insert(int index, int element)
  {
    if (length == cap)
      expand();
    for (int i = index; i < length; i++)
    {
      array[i + 1] = array[i];
    }
    array[index] = element;
    length++;
    return array[index];
  }
  int getElement(int index)
  {
    return array[index];
  }
};