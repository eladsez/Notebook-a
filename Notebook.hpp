#include <iostream>
#include <string>

#include "Direction.hpp"

namespace ariel{

    class Notebook{
        public:

            Notebook();

            void write(int page, int row, int column, Direction dir, std::string);

            std::string read(int page, int row, int column, Direction dir, int length);

            void erase(int page, int row, int column, Direction dir, int length);

            void show(int page);
    };
}


