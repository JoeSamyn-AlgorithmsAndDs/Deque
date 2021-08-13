
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
    delete[] this->deque;
}