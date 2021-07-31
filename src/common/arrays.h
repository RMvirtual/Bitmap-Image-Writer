#include <iostream>
#include <string>

using namespace std;

namespace Arrays
{
    template <class T>
    class ArrayList
    {
        public:
            ArrayList()
            {
                this->numberOfElements = 0;
            }

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