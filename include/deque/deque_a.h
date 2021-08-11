#ifndef DEQUEA_H
#define DEQUEA_H

class DequeA {

/* Private Variables */
private:
    int size;
    int* queue;

public:
    DequeA();
    int size();
    void addFirst(int item);
    void addLast(int item);
    int removeFirst();
    int removeLast();
};

#endif