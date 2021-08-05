#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class ArrayList
{
  public:
    
    // Creates a new arraylist.
    ArrayList()
    {
      this->numberOfElements = 0;
    }

    // Adds an element to the arraylist.
    void add(T elementToAdd)
    {
      if (this->numberOfElements == 0) {
        this->array = new T[1] {elementToAdd};
        this->numberOfElements++; 
      }

      else {
        this->incrementArraySize();
        this->array[this->numberOfElements - 1] = elementToAdd;
      }
    }

    // Gets an element from the arraylist at a specified index.
    T get(int index)
    {
      return this->array[index];  
    }
    
    void set(int index, T element)
    {
      int size = this->size();
      bool indexWithinRange = (index >= 0 && index < size);
      
      if (indexWithinRange)
        this->array[index] = element;

      else
        throw std::invalid_argument(
          "Index not within range of the arraylist's current size");
    }

    // Removes an element from the arraylist at a specified index.
    void remove(int index)
    {
      int newSize = this->numberOfElements - 1;
      T *newArray = new T[newSize];
      
      int newArrayIndex = 0, oldArrayIndex = 0;
      bool arrayModified = false;

      for (; oldArrayIndex < this->numberOfElements; oldArrayIndex++) {
        bool shouldIgnoreElement = (oldArrayIndex == index);

        if (shouldIgnoreElement)
          arrayModified = true;

        else {
          newArray[newArrayIndex] = this->get(oldArrayIndex);
          newArrayIndex++;
        }
      }

      if (arrayModified) {
        delete this->array;
        this->array = newArray;
        this->numberOfElements = newSize;
      }

      else
        delete newArray;
    }

    // Inserts an element into the arraylist at the specified index.
    void insert(int index, T element)
    {
      int newSize = this->numberOfElements + 1;
      T *newArray = new T[newSize];

      int oldArrayIndex = 0, newArrayIndex = 0;
      bool arrayModified = false;

      for (; newArrayIndex < this->numberOfElements; newArrayIndex++) {
        if (newArrayIndex == index) {
          newArray[newArrayIndex] = element;
          arrayModified = true;
        }

        else {
          newArray[newArrayIndex] = this->get(oldArrayIndex);
          oldArrayIndex++;
        }
      }

      if (arrayModified) {
        delete this->array;
        this->array = newArray;
        this->numberOfElements = newSize;
      }

      else
        delete newArray;
    }

    // Returns the size of the arraylist.
    int size()
    {
      return this->numberOfElements;
    }

  private:
    T *array;
    int numberOfElements;

    /**
     * Copies the current underlying array into a new one with space
     * for one extra element.
     */
    void incrementArraySize()
    {
      int newSize = this->numberOfElements + 1;
      T *newArray = new T[newSize];

      for (int i = 0; i < this->numberOfElements; i++) {
        T elementToCopy = this->get(i);
        newArray[i] = elementToCopy;
      }

      delete this->array;
      this->array = newArray;
      this->numberOfElements++;
    }
};

#endif