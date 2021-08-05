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
    
    // Sets the element at a specific index in the array.
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
      if (this->numberOfElements == 0)
        throw std::invalid_argument("Cannot remove when list is empty.");

      int newSize = this->numberOfElements - 1;
      T *newArray = new T[newSize];
      
      int newArrayIndex = 0, oldArrayIndex = 0;
      bool arrayModified = false;

      for (; oldArrayIndex < this->numberOfElements; oldArrayIndex++) {
        ArrayOperation removalDetails = ArrayOperation();
        removalDetails.array = newArray;
        removalDetails.currentIndex = index;
        removalDetails.oldArrayIndex = &oldArrayIndex;
        removalDetails.newArrayIndex = &newArrayIndex;
        removalDetails.arrayModified = &arrayModified;
        
        this->processRemoval(removalDetails);
      }

      if (arrayModified)
        this->replaceArray(newArray, newSize);

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
        InsertionOperation additionDetails = InsertionOperation();
        additionDetails.elementToInsert = &element;
        additionDetails.array = newArray;
        additionDetails.currentIndex = index;
        additionDetails.oldArrayIndex = &oldArrayIndex;
        additionDetails.newArrayIndex = &newArrayIndex;
        additionDetails.arrayModified = &arrayModified;

        this->processInsertion(additionDetails);
      }

      if (arrayModified)
        this->replaceArray(newArray, newSize);

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
      int oldSize = this->numberOfElements;
      int newSize = oldSize + 1;
      T *newArray = new T[newSize];

      for (int i = 0; i < oldSize; i++) {
        T elementToCopy = this->get(i);
        newArray[i] = elementToCopy;
      }

      this->replaceArray(newArray, newSize);
    }

    /**
     * Deletes the old array associated with this object and replaces
     * it with a new one. Requires the size of the array to be manually
     * passed in due to C++ primitive array limitations.
     */
    void replaceArray(T* newArray, int newSize)
    {
      delete this->array;

      this->array = newArray;
      this->numberOfElements = newSize;
    }

    struct ArrayOperation
    {
      T* array;
      int currentIndex;
      int *oldArrayIndex;
      int *newArrayIndex;
      bool *arrayModified;
    };

    struct InsertionOperation
      : ArrayOperation
    {
      T* elementToInsert;
    };

    void processRemoval(ArrayOperation details)
    {
      T* array = details.array;
      int currentIndex = details.currentIndex;
      int* oldArrayIndex = details.oldArrayIndex;
      int* newArrayIndex = details.newArrayIndex;
      bool* arrayModified = details.arrayModified;

      bool shouldIgnoreElement = (*oldArrayIndex == currentIndex);

      if (shouldIgnoreElement)
        *arrayModified = true;

      else {
        array[*newArrayIndex] = this->get(*oldArrayIndex);
        (*newArrayIndex)++;
      }
    }

    void processInsertion(InsertionOperation details)
    {
      T* array = details.array;
      T* elementToInsert = details.elementToInsert;
      int currentIndex = details.currentIndex;
      int* oldArrayIndex = details.oldArrayIndex;
      int* newArrayIndex = details.newArrayIndex;
      bool* arrayModified = details.arrayModified;

      if (*newArrayIndex == currentIndex) {
        array[*newArrayIndex] = *elementToInsert;
        *arrayModified = true;
      }

      else {
        array[*newArrayIndex] = this->get(*oldArrayIndex);
        (*oldArrayIndex)++;
      }
    }
};

#endif