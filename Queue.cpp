#include <iostream>
using namespace std;

class Queue {
 private:
  int front, rear, size;
  unsigned int capacity;
  int *array;

 public:
  Queue(int cap) {
    capacity = cap;
    front = 0;
    size = 0;
    rear = 0;
    array = (int *)malloc(cap * sizeof(int));
  }

  void resetQueue() {
    front = 0;
    size = 0;
    rear = 0;
    free(array);
    array = (int *)malloc(capacity * sizeof(int));
  }

  bool isFull() { return size == capacity; }

  bool isEmpty() { return size == 0; }

  void enQueue(int data) {
    if ((size < capacity) && size) {
      array[++rear] = data;
      size++;
    } else if (!size) {
      array[rear] = data;
      size++;
    } else {
      cout << "Overflowing" << endl;
    }
  }

  int deQueue() {
    if (--size) {
      return array[front++];
    } else {
      resetQueue();
    }
  }

  int getFront() { return array[front]; }

  int getRear() { return array[rear]; }

  int getSize() { return size; }
};

int main() {
  Queue queue = Queue(5);

  cout << "Enqueuing.." << endl;

  queue.enQueue(1);
  queue.enQueue(2);
  queue.enQueue(3);
  queue.enQueue(4);
  queue.enQueue(5);

  cout << "Front: " << queue.getFront() << endl;
  cout << "Rear: " << queue.getRear() << endl;
  cout << "Size: " << queue.getSize() << endl;

  cout << "Dequeuing.." << endl;

  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();
  queue.deQueue();

  cout << "Front: " << queue.getFront() << endl;
  cout << "Rear: " << queue.getRear() << endl;
  cout << "Size: " << queue.getSize() << endl;
}