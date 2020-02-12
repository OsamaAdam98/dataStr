#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

void insertEnd(Node *lastNode, int data);
void printLinkedList(Node *nodeRef);
void deleteNode(Node *prevNode, Node *node, Node *nextNode);

int main() {
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;
  Node *fourth = NULL;

  head = (Node *)malloc(sizeof(Node));
  second = (Node *)malloc(sizeof(Node));
  third = (Node *)malloc(sizeof(Node));
  fourth = (Node *)malloc(sizeof(Node));

  head->data = 5;
  head->next = second;

  second->data = 10;
  second->next = third;

  third->data = 15;
  third->next = fourth;

  fourth->data = 20;
  fourth->next = NULL;

  cout << "Before insertion" << endl;
  printLinkedList(head);

  insertEnd(fourth, 25);
  cout << "After insertion" << endl;
  printLinkedList(head);

  deleteNode(second, third, fourth);
  cout << "After deletion" << endl;
  printLinkedList(head);
}

void insertEnd(Node *lastNode, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  lastNode->next = newNode;
  newNode->next = NULL;
}

void printLinkedList(Node *nodeRef) {
  while (nodeRef != NULL) {
    cout << nodeRef->data << endl;
    nodeRef = nodeRef->next;
  }
}

void deleteNode(Node *prevNode, Node *node, Node *nextNode) {
  prevNode->next = nextNode;
  free(node);
}
