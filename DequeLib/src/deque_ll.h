#ifndef DEQUELL_H
#define DEQUELL_H

class DequeLL {

/* Private Variables */
private:
    int size;
    int* queue;

public:
    DequeLL();
    int size();
    void addFirst(int item);
    void addLast(int item);
    int removeFirst();
    int removeLast();
};

#endif