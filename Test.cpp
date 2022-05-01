/**
 *
 * AUTHORS: Ori Darshan
 *
 * Date: 2021-03
 */

#include "doctest.h"
#include "Game.hpp"
using namespace zich;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


TEST_CASE("Good Input")
{
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    // Constractors
    Matrix matrix1{identity, 3, 3};
    Matrix matrix2 = matrix1;
    Matrix matrix3 = matrix2;
    CHECK(matrix1 == matrix2);
    // CHECK_NOTHROW(Matrix matrix2);
    // CHECK_NOTHROW();
    // CHECK_NOTHROW();
    // CHECK_NOTHROW(Matrix matrix4{arr, 3, 3});
    // comparison operators
    CHECK(matrix1 == matrix2);
    CHECK_FALSE(matrix1 != matrix2);
    //#1 write to the notebook:
    for (int i = 0; i < 25; i++)
    {
        CHECK_NOTHROW(int a = 2;);
    }    
}
