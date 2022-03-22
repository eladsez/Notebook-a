/**
 * @file Test.cpp
 * @author elad sezanayev (you@domain.com)
 * @brief This file is testing the Notebook.cpp file (the Notebook class)
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Good input and Notebook function test") {
    Notebook nb;

    // test for writing from the begining of the row/column horizontal&vertical
    nb.write(0, 0, 0, Direction::Horizontal, "This is the first row!");
    nb.write(1, 0, 0, Direction::Horizontal, "The second row!");
    nb.write(2, 0, 0, Direction::Vertical, "The firts column!");
    nb.write(3, 0, 0, Direction::Vertical, "The second column!");
    // here we read what we wrote above
	CHECK(nb.read(0, 0, 0, Direction::Horizontal, 23) == "This is the first row!");
    CHECK(nb.read(1, 0, 0, Direction::Horizontal, 16) == "The second row!");
    CHECK(nb.read(2, 0, 0, Direction::Vertical, 18) == "The firts column!");
    CHECK(nb.read(3, 0, 0, Direction::Vertical, 19) == "The second column!");
    // trying to read from somewhere we didnt write anything
    CHECK(nb.read(4, 0, 0, Direction::Horizontal, 3) == "___");

    // test to erase what we wrote above horizontal&vertical
    nb.erase(0, 0, 0, Direction::Horizontal, 4);
    nb.erase(2, 0, 0, Direction::Vertical, 3);
    // chacking if its actually removed
    CHECK(nb.read(0, 0, 0, Direction::Horizontal, 4) == "~~~~");
    CHECK(nb.read(2, 0, 0, Direction::Vertical, 3) == "~~~");
}

TEST_CASE("Bad input to Notebook functions") {
    Notebook nb;

    // invalid page&rows&colunms&length numbers inputs, negetive numbers
    CHECK_THROWS(nb.read(-1, 0, 0, Direction::Horizontal, 1));
    CHECK_THROWS(nb.read(0, -1, 0, Direction::Horizontal, 1));
    CHECK_THROWS(nb.read(0, 0, -1, Direction::Horizontal, 1));
    CHECK_THROWS(nb.read(0, 0, 0, Direction::Horizontal, -1));
    CHECK_THROWS(nb.erase(0, 0, 0, Direction::Horizontal, -1));
    CHECK_THROWS(nb.erase(-1, 0, 0, Direction::Horizontal, 1));

    nb.write(0, 0, 0, Direction::Horizontal, "write on erase test");
    nb.erase(0, 0, 0, Direction::Horizontal, 20);
    CHECK_THROWS(nb.write(0, 0, 0, Direction::Horizontal, "write on erase test"));

    // write more then 100 char to a row from 0 and 99 column
    CHECK_THROWS(nb.write(1, 0, 0, Direction::Horizontal, "...................................................................................................."));
    CHECK_THROWS(nb.write(1, 0, 99, Direction::Horizontal, ".........."));

    // check if possible to write more then 100 chars to column
    CHECK_NOTHROW(nb.write(2, 0, 0, Direction::Vertical, "....................................................................................................................."));

    // check for invalid input for column over 100 and length of row over 100
    CHECK_THROWS(nb.read(0, 0, 120, Direction::Horizontal, 10));
    CHECK_THROWS(nb.erase(0, 0, 120, Direction::Horizontal, 10));
    CHECK_THROWS(nb.erase(0, 0, 0, Direction::Horizontal, 150));
    CHECK_THROWS(nb.read(0, 0, 0, Direction::Horizontal, 150));
}