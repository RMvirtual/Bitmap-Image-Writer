#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>
#include <string>

using namespace std;

namespace Arrays
{
    template <class T>
    class ArrayList
    {
        public:
            /**
             * Creates a new arraylist.
             */
            ArrayList()
            {
                this->numberOfElements = 0;
            }

            /**
             * Adds an element to the arraylist.
             */
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

            /**
             * Gets an element from the arraylist at a specified index.
             */
            T get(int index)
            {
                return this->array[index];  
            }
            
            /**
             * Returns the size of the arraylist.
             */
            int size()
            {
                return this->numberOfElements;
            }

        private:
            T *array;
            int numberOfElements;

            /**
             * Copies the current underlying array into a new one with
             * space for one extra element.
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
}

#endif