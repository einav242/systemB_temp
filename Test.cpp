#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;
#include<stdexcept>
#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Good input") {
    ariel::Notebook book;
    //1
	book.write(0,0,0, Direction::Horizontal, "abcd");
    CHECK(book.read(0,0, 0, Direction::Horizontal,4) == "abcd");
    //2
    book.write(0, 1,0, Direction::Vertical, "einav");
    CHECK(book.read(0,1, 0, Direction::Vertical,5) == "einav");
    // //3
    book.write(0,6,0, Direction::Horizontal, "w");
    CHECK(book.read(0,6, 0, Direction::Horizontal,1) == "w");
    // //4
    book.write(0,3,1, Direction::Horizontal, "hi my name is einav");
    CHECK(book.read(0,3, 1, Direction::Horizontal,19) == "hi my name is einav");
    // //5
	book.write(1,0,0, Direction::Vertical, "hello world");
    CHECK(book.read(1,0, 0, Direction::Vertical,11) == "hello world");
    // //6
    book.write(1, 1,1, Direction::Vertical, "my id is 12345678");
    CHECK(book.read(1,1, 1, Direction::Vertical,17) == "my id is 12345678");
    // //7
    book.write(1,2,2, Direction::Vertical, "lalala");
    CHECK(book.read(1,2, 2, Direction::Vertical,6) == "lalala");
    // //8
    book.erase(1,2, 0, Direction::Vertical,6);
    CHECK(book.read(1,2, 0, Direction::Vertical,6) == "~~~~~~");
    // //9
    book.erase(0,0, 0, Direction::Horizontal,4);
    CHECK(book.read(0,0,0, Direction::Horizontal,4) == "~~~~");
    // //10
    book.erase(0,1, 0, Direction::Vertical,5);
    CHECK(book.read(0,1, 0, Direction::Vertical,5) == "~~~~~");
    // //11
    book.erase(0,2, 0, Direction::Horizontal,1);
    CHECK(book.read(0,2, 0, Direction::Horizontal,1) == "~");
    // //12
    book.erase(1,0, 0, Direction::Vertical,11);
    CHECK(book.read(1,0, 0, Direction::Vertical,11) == "~~~~~~~~~~~");
    // //13
    book.erase(0,3, 0, Direction::Horizontal,19);
    CHECK(book.read(0,3, 0, Direction::Horizontal,19) == "~~~~~~~~~~~~~~~~~~~");
}


TEST_CASE("Bad input") {
    ariel::Notebook notebook;
    //14
    notebook.write(1,1,0, Direction::Vertical, "hello");
    notebook.erase(1,1, 0, Direction::Vertical,5);
    CHECK_THROWS(notebook.write(1,1,0, Direction::Vertical, "byebye"));
    // //15
    notebook.write(0,2,0, Direction::Vertical, "einav");
    CHECK_THROWS(notebook.write(0,2,0, Direction::Vertical, "hi"));
    // //16
    notebook.write(0,1,1, Direction::Vertical, "lalala");
    notebook.erase(0,1, 1, Direction::Vertical,6);
    CHECK_THROWS(notebook.write(0,1, 1, Direction::Vertical,"jjj"));
    // //17
    notebook.write(2,2,0, Direction::Vertical, "einav");
    CHECK_THROWS(notebook.write(0,2,0, Direction::Vertical, "hi"));
    // //18
    CHECK_THROWS(notebook.write(-1,1,0, Direction::Vertical, "hello world"));
    // //19
    CHECK_THROWS(notebook.write(1,-1,0, Direction::Vertical, "hello"));
    // //20
    CHECK_THROWS(notebook.write(1,1,-2, Direction::Vertical, "hello world"));

}