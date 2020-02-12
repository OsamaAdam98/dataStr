/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class DynamicArray {
    private :
    
        int *arr, length, capacity;
    
        void expand(){
            capacity *= 2;
            arr = (int *) realloc(arr, capacity*sizeof(int));
            /*int *copy = new int[capacity];
            for(int i = 0; i < length; i++)
                copy[i] = arr[i];
            delete[] arr;
            arr = copy;*/
        }
    public :
    
        DynamicArray(int initial_capacity){
            length = 0;
            capacity = initial_capacity;
            arr = new int[capacity];
        }
        
        ~DynamicArray(){
            delete[] arr;
        }
        int size(){
            return length;
        }
        int append(int element){
            if (length == capacity)
                expand();
            arr[length] = element;
            length++;
        }
        int erase(int index){
            int erased = arr[index];
            length--;
            for (int i = index; i < length; i++)
                arr[i] = arr[i+1];
            return erased;
        }
        void insert(int index, int element){
            if(length == capacity)
                expand();
            for (int i = length; i > index; i--)
                arr[i] = arr[i-1];
            arr[index] = element;
            length++;
        }
        int lookup(int index){
            return arr[index];
        }
};

int main()
{
    int* a = new int[5];
    int* b = a;
    for (int i = 0; i < 5; i++)
        a[i] = i+1;
    
    for (int i = 0; i < 5; i++)
        cout << b[i] << " , " << b+i << " ;; ";

    return 0;
}


