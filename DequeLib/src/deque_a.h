#ifndef DEQUEA_H
#define DEQUEA_H

#include <iostream>

/**
 * Deque implementation using an array as underlying data structure
 */ 
class DequeA {

/* Private Variables */
private:
    /**
     * Total number of items in the deque
     */
    int count;

    /**
     * The current top index in the deque
     */
    int top;

    /**
     * The current bottom index in the deque
     */
    int bottom;

    /**
     * Current length of the array being used to hold deque values
     */
    int length;

    /**
     * Flag used to insert items in the top of the deque. 
     * Gets flipped to negative one when top index moves to back of array
     * to allow ciclical insert
     */
    int insertFlag;

    /**
     *  Array pointer that points to underlying array being used for deque implementation
     */
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

    /**
     * Print the contents of the deque to the console
     * 
     * @param
     * @return 
     */
    void show();

    /**
     * Get the length of the underlying array data structure
     * 
     * @param
     * @return length of array
     */
    int arrayLength();

/* Private Methods */
private:
    /**
     * Increase the size of the array using the repeated doubling method
     * 
     * @param 
     * @return
     */
    void increaseSize();

    /**
     * Decrease the size of the array to half its current length
     * 
     * @param
     * @return
     */
    void decreaseSize();

    /**
     * Copy array contents from deque into new array
     * 
     * @param
     * @return pointer to newly created array
     */
    int* copyArray();
};

#endif