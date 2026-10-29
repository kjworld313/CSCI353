#include "unit_tests.cpp"

#include <iostream>

int test_driver() {
    int sum_successes = 0;  // holds the total number of successful tests
    int num_tests = 0;
    std::cout << "========Testing========" << std::endl;
    std::cout << "0 = Test failed, 1 = Test successful\n" << std::endl;

    // call test on empty line
    int result = empty_line();
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on empty line: " << result << std::endl;

    // call test on single line
    result = single_line();
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on single member line: " << result << std::endl;

    // arrange for sorted line and test
    std::string sorted[21] = {"u", "u", "u", "u", "u", "u", "u", "c", "c", "c", "m", "m", "m", "m", "m", "s", "s", "s", "s", "s", "s"};
    std::string s_expected[21] = {"u", "u", "u", "u", "u", "u", "u", "c", "c", "c", "m", "m", "m", "m", "m", "s", "s", "s", "s", "s", "s"};
    result = test_line(sorted, s_expected, 21); // call test on sorted line and store result
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on a sorted line: " << result << std::endl;

    // arrange for reversed line and test
    std::string reversed[12] = {"s","s","s","m","m","m","c","c","c","u","u","u"};
    std::string r_expected[12] = {"u","u","u","c","c","c","m","m","m","s","s","s"};
    result = test_line(reversed, r_expected, 12);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on a reversed order line: " << result << std::endl;

    // arrange for the first unordered line and test
    std::string ooo_1[8] = {"m", "s", "u", "c", "m", "s", "s", "c"};
    std::string expected_1[8] = {"u", "c", "c", "m", "m", "s", "s", "s"};
    result = test_line(ooo_1, expected_1, 8);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (1st test): " << result << std::endl;

    // arrange for the second unordered line and test
    std::string ooo_2[3] = {"c", "c", "u"};
    std::string expected_2[3] = {"u", "c", "c"};
    result = test_line(ooo_2, expected_2, 3);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (2nd test): " << result << std::endl;

    // arrange for the third unordered line and test
    std::string ooo_3[6] = {"r", "u", "m", "u", "r", "s"};
    std::string expected_3[6] = {"u", "u", "u", "u", "m", "s"};
    result = test_line(ooo_3, expected_3, 6);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (3rd test): " << result << std::endl;

    // arrange for the fourth unordered line and test
    std::string ooo_4[5] = {"c", "c", "c", "m", "u"};
    std::string expected_4[5] = {"u", "c", "c", "c", "m"};
    result = test_line(ooo_4, expected_4, 5);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (4th test): " << result << std::endl;

    // arrange for the fifth unordered line and test
    std::string ooo_5[13] = {"u", "m", "m", "s", "a", "c", "c", "s", "m", "u", "u", "m", "m"};
    std::string expected_5[13] = {"u", "u", "u", "u", "c", "c", "m", "m", "m", "m", "m", "s", "s"};
    result = test_line(ooo_5, expected_5, 13);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (5th test): " << result << std::endl;

    // arrange for the sixth unordered line and test
    std::string ooo_6[7] = {"s", "a", "s", "s", "s", "c", "m"};
    std::string expected_6[7] = {"u", "c", "m", "s", "s", "s", "s"};
    result = test_line(ooo_6, expected_6, 7);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (6th test): " << result << std::endl;

    // arrange for the seventh unordered line and test
    std::string ooo_7[4] = {"s", "a", "a", "a"};
    std::string expected_7[4] = {"u", "u", "u", "s"};
    result = test_line(ooo_7, expected_7, 4);
    sum_successes += result;
    ++num_tests;
    std::cout << "group_sort() on an unordered (non-reversed) line (7th test): " << result << std::endl;

    int total = ((float) sum_successes / (float) num_tests) * 100;

    std::cout << "\nThe total percent of successes is: " << total << "%" << std::endl;

    return total;
}