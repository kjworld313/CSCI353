#include "group_sort.h"

// test of group_sort() on a line
bool test_line(std::string* line, std::string* expected, const int size) {
    group_sort(line, size);    // act

    // assert
    for (int p = 0; p < size; p++) {
        // check if line does not match expected, sortedline
        if (line[p] != expected[p]) { //
            return false;   // end function, test failed
        }
    }

    return true; // in order
}


// test of group_sort() on a single member line
bool single_line() {
    // arrange
    const int size = 1;
    std::string line[size] = {"s"};

    group_sort(line, size);    // act

    return (line[0] == "s"); // assert
}

// test of group_sort() on an empty line
bool empty_line() {
    // arrange
    const int capacity = 1;
    std::string line[capacity] = {};

    group_sort(line, 0);    // act

    return (line->empty() == true); // assert
}