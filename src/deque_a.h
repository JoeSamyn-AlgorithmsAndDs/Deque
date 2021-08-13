#ifndef DEQUEA_H
#define DEQUEA_H

/**
 * Deque implementation using an array as underlying data structure
 */ 
class DequeA {

/* Private Variables */
private:
    int count;
    int top;
    int bottom;
    int length;
    int* deque;

public:
    DequeA();
    ~DequeA();

    /**
    * Get the number of items in the deque
    *
    * @param
    * @return number of items in the deque
    */
    int size();

    /**
    * Add item to the front of the deque
    * 
    * @param item to add into the deque
    * @return none
    */
    void addFirst(int item);

    /**
     * Add item to the end of the deque
     * 
     * @param item to add 
     * @return none 
     */
    void addLast(int item);

    /**
     * Remove first item from the deque
     * 
     * @param 
     * @return item removed from the deque
     */ 
    int removeFirst();

    /**
     * Remove last item from the deque
     * 
     * @param 
     * @return item removed from the deque
     */ 
    int removeLast();

/* Private Methods */
private:
    /**
     * Increase the size of the array using the repeated doubling method
     * 
     * @param 
     * @return
     */
    void increaseSize();
};

#endif