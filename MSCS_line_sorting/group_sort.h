#ifndef GROUP_SORT
#define GROUP_SORT

#include <map>
#include <array>
#include <string>

/**
 * helper function that takes a reference to an integer next which tracks the starting index for the previous section,
 * a reference to an integer end which tracks the ending index for the current section, and a reference to an integer size
 * (representing the total number of members in a section). the function makes changes to the arguments through pass by reference
 * and returns void.
*/
void set_indices(int& next, int& end, const int& size) {
    if (size != 0) { // check if the group to sort has any members
        // assign ending index and starting index for next section
        end = next + size - 1;
        next = end + 1;
    }
    return;
}

/**
 * function that takes a pointer to an array of strings, line, representing the current order of
 * members, and an integer, size, representing the size of the line of members. the function sorts
 * the line into order (u, c, m, s) by counting the number of members in each major and accounting
 * for each major's size in a dictionary groups. then, the function determines the starting and ending
 * indices of each major's section in line and sorts the line into place. the function makes changes to
 * the line argument and returns void.
 */
void group_sort(std::string* line, const int size) {
    // base case, line is empty or has one member
    if (size <= 1) { // already sorted
        return;
    }
    // represent each major as a dictionary of number of people in each grouping
    std::map<std::string, int> groups = {{"u", 0}, {"c", 0}, {"m", 0}, {"s", 0}};

    // go through the line and count each person in each major
    for (int p = 0; p < size; p++) {
        std::string person = line[p];
        if (person != "u" && person != "c" && person != "m" && person != "s") { // person's major is unaccounted for, so group with undeclared
            person = "u"; // consider them as part of the undeclared majors for now
        }
        // increment current size of major to account for current person and assign corner the new size
        groups[person] += 1;
        line[p] = ".";
    }

    // initialize starting and ending indices for line to default value of -1
    int u_start = -1, c_start = -1, m_start = -1, s_start = -1;
    int u_end = -1, c_end = -1, m_end = -1, s_end = -1;
    int last_index = 0; // keeps track of the firstmost starting index for a section

    // retrieve information about starting and ending indices for the sections
    set_indices(last_index, u_end, groups["u"]);
    c_start = last_index;   // starting point for computer science majors
    set_indices(last_index, c_end, groups["c"]);
    m_start = last_index;   // starting point for math majors
    set_indices(last_index, m_end, groups["m"]);
    s_start = last_index;   // starting point for statistics majors
    set_indices(last_index, s_end, groups["s"]);

    // create a dictionary to hold the valid starting and ending points for each major in the line
    std::map<std::string, std::array<int, 2>> valid_pos = {
        {"u", {u_start, u_end}}, {"c", {c_start, c_end}}, 
        {"m", {m_start, m_end}}, {"s", {s_start, s_end}}
    };

    // loop through the line and sort people into position
    for (int p = 0; p < size; p++) {
        // check which person's major is valid for the current position (if there are still people in the major to sort)
        if (p >= valid_pos["c"][0] && p <= valid_pos["c"][1] && groups["c"] > 0) {  // there exists a computer science major to sort here
            groups["c"] -= 1;   // one less person to sort from computer science majors
            line[p] = "c";  // place them in line
        } else if (p >= valid_pos["m"][0] && p <= valid_pos["m"][1] && groups["m"] > 0) { // there exists a math major to sort here
            groups["m"] -= 1;   // decrement corner size
            line[p] = "m"; 
        } else if (p >= valid_pos["s"][0] && p <= valid_pos["s"][1] && groups["s"] > 0) {   // there exists a statistics major to sort here
            groups["s"] -= 1;   // decrement corner size
            line[p] = "s";
        } else {    // some other major or undeclared
            groups["u"] -= 1;   // decrement corner size
            line[p] = "u";  // place them in line as undeclared
        }
    } // end sorting loop

    return;
}

#endif