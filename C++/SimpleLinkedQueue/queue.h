#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node() {
    next = NULL;
  }
};
class Queue {
  public:
    // constuctor
    Queue();
    bool empty() const;
    void push(const int item);  // Put the data in the rear of queue
    int getFront();  // Get the first data in the queue
    void pop();   // Pop the first data
    int getSize();  // Get the size of queue
  protected:
    Node *front, *rear;
    int count;
};
#endif
