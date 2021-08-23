
/**
 * Deque implementation using an array as underlying data structure
 */

#include "deque_a.h"

// Basic default constructor
DequeA::DequeA(){
    this->deque = new int[1];
    this->top = this->bottom = this->count = 0;
    this->length = 1;
}

// Cleanup pointers
DequeA::~DequeA(){
    delete[] deque;
}

/* Public method implementations */

void DequeA::addLast(int item){
    
    // Array full, double size and move elements
    if(count == length) increaseSize();

    // If bottom at last index, check if item can be added to front of array
    if(bottom == length - 1) bottom = 0;
    else bottom++;

    // Add item
    deque[bottom] = item;
    count++;
}

void DequeA::addFirst(int item){

    // If array full, resize
    if(count == length) increaseSize();

    if(top <= 0) top = length - 1;
    else top--;

    // Insert item into deque and increment count
    deque[top] = item;
    count++;
}

int DequeA::removeFirst(){

    // Check count != 0
    if(count == 0) return -1;

    int item = deque[top];
    deque[top] = -1;

    if(top == length - 1) top = 0;
    else top++;

    count--;

    // if size count is 1/4 length decrease size 
    if(count == length/4){
        decreaseSize();
    }
    
    return item;
}

int DequeA::removeLast(){
    // Verify deque is not empty
    if(count == 0) return -1;

    // remove item and move bottom index to next available value
    int item = deque[bottom];
    if(bottom == 0) bottom = length - 1;
    else bottom--;

    count--;

    // resize if needed
    if(count == length/4) decreaseSize();

    return item;
}

void DequeA::show(){

    // Iterate through list and print contents one at a time
    for(int i = 0; i < length; i++){
        std::cout << deque[i] << " ";
    }

    std::cout << std::endl;
}

int DequeA::size() { return count; }

int DequeA::arrayLength() { return length; }

/* Private Methods */

void DequeA::increaseSize(){
    length = length*2;

    // Create new array for deque
    int* new_deque = new int[length];

    // Move items into new array
    for(int i = 0; i < count; i++){
        // Reset top if needed since using a circular array
        if(top >= count || top < 0) top = 0;

        // move items from top to bottom
        new_deque[i] = deque[top];
        top++;
    }

    // TODO: Remove once templates are implemented
    for(int i = count; i < length; i++){
        new_deque[i] = -1;
    }

    // Delete old deque array pointer
    delete[] deque;
    deque = new_deque;
    top = 0;
    bottom = count - 1;
}

void DequeA::decreaseSize(){
    length = length / 2;

    int* new_deque = new int[length];
    for(int i = 0; i < count; i++){
        if(top == length) top = 0;
        new_deque[i] = deque[top];
        top++;
    }

    delete[] deque;
    deque = new_deque;
    top = 0;
    bottom = count;
}
