#include <iostream>

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
                    // Pass
                }

                this->numberOfElements++;
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
                return 1;
            }

        private:
            double *array;
            int numberOfElements;
    };
}