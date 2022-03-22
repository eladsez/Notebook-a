#include <iostream>
#include <string>

#include "Notebook.hpp"

ariel::Notebook::Notebook(){}

void ariel::Notebook::write(int page, int row, int column, Direction dir, std::string){}

std::string ariel::Notebook::read(int page, int row, int column, Direction dir, int length){return " ";}

void ariel::Notebook::erase(int page, int row, int column, Direction dir, int length){}

void ariel::Notebook::show(int page){}