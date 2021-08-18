
/**
 * Deque implementation using an array as underlying data structure
 */

#include "deque_a.h"

// Basic default constructor
DequeA::DequeA(){
    this->deque = new int[1];
    this->top = this->bottom = this->count = 0;
    this->insertFlag = 1;
    this->length = 1;
}

// Cleanup pointers
DequeA::~DequeA(){
    delete[] this->deque;
}

/* Public method implementations */

void DequeA::addLast(int item){
    
    // Array full, double size and move elements
    if(this->count == this->length){
        this->increaseSize();
    }

    // Add item
    this->deque[this->bottom] = item;
    this->bottom++;
    this->count++;
}

void DequeA::addFirst(int item){

    // If first value add to first index
    if(this->count == 0) {
        this->deque[this->top] = item;
        this->count++;
        return;
    }

    // Increase size if array is full using repeated doubling
    if(this->count == this->length){
        this->increaseSize();
    }

    // If at index 0, move to back and begin adding values
    if(this->top == 0){
        this->insertFlag = this->insertFlag * -1;
        this->top = this->length - 1;
    }
    // Move top to next index
    else this->top += this->insertFlag;

    // Insert item into deque and increment count
    this->deque[this->top] = item;
    this->count++;
}

void DequeA::show(){

    // Iterate through list and print contents one at a time
    for(int i = 0; i < this->length; i++){
        std::cout << this->deque[i] << " ";
    }

    std::cout << std::endl;
}

int DequeA::size() { return this->count; }

/* Private Methods */

void DequeA::increaseSize(){
    this->length = this->length*2;
    int* new_deque = new int[this->length];
    
    // Move items into new array
    for(int i = 0; i < this->count; i++){
        // Reset top if needed since using a circular array
        if(this->top >= this->count) this->top = 0;

        // move items from top to bottom
        new_deque[i] = this->deque[top];
        this->top++;
    }

    // Delete old deque from memory to prevent memory leaks
    delete[] this->deque;
    this->deque = new_deque;
    this->top = 0;
    this->insertFlag = 1;
    this->bottom = this->count;
}