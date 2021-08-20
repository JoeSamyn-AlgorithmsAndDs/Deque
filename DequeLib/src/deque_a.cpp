
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
    if(count == length){
        increaseSize();
    }

    // If bottom at last index, check if item can be added to front of array
    if(bottom == length - 1 && deque[top] != -1) bottom = 0;

    // Add item
    deque[bottom] = item;
    bottom++;
    count++;
}

void DequeA::addFirst(int item){

    // If array full, resize
    if(count == length) increaseSize();

    show();

    if(top <= 0 && deque[length - 1] == -1) top = length - 1;

    // Insert item into deque and increment count
    deque[top] = item;
    top--;
    count++;

    show();
}

int DequeA::removeFirst(){
    // Check count != 0
    if(count == 0) return -1;

    // pop value off deque
    int popped = deque[top];
    deque[top] = -1;

    if(top == length - 1) top = 0;

    // if size count is 1/4 length decrease size 
    if(count == length/4){
        decreaseSize();
    }

    count--;

    return popped;
}

int DequeA::removeLast(){
    // Ensure deque is not empty before attempting to remove value
    if(count == 0) return -1;

    int popped = deque[bottom];
    deque[bottom] = -1;

    // if size count is 1/4 length decrease size 
    if(count == length/4){
        decreaseSize();
    }

    bottom--;
    count--;
    return popped;
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

    // Delete old deque from memory to prevent memory leaks
    deque = copyArray();
    top = 0;
    bottom = count - 1;
}

void DequeA::decreaseSize(){
    length = length / 2;

    deque = copyArray();
    top = 0;
    bottom = count;
}

int* DequeA::copyArray(){

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
    return new_deque;
}