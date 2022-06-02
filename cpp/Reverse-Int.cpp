// https://leetcode.com/problems/reverse-integer/

/*
# Reverse-Int
https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:
Input: x = 0
Output: 0
 

Constraints:
-231 <= x <= 231 - 1
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        double UNDER_ONE = 0.99;
        int tempX = x;
        long int returnValue = 0;
        int divideBy = 10;
        bool negativeNumberDetected = false;

        // first we must find out how many digits exist in this number
        // everytime we divide the number by 10, we know it's +1 digit long
        // 123 / 10 = 12.3      12.3 / 10 = 1.23        1.23 / 10 = 0.123
        // if the number < 1, then we've figured out how many digits the number is, (123) is 3 digits long

        // what if x = -123? 0.99 < -123, we should first check if x < 0, then we'll know it's a negative number, we can then use it's abs value, and simply add the - at the end of the conversion
        if(x < 0) {
            x = abs(x);
            negativeNumberDetected = true;
        }
        while (UNDER_ONE < x) {
            tempX = x % divideBy;                       // x % 10 gives us the last digit, so 123 % 10 = 3, then we need to remove the 3, tempX stores our reversed number
            if (returnValue == 0) returnValue = 0;       // when we want the first digit, we siply assign the last mod
            if (((returnValue * divideBy) < 0) || (returnValue * divideBy) > 2147483647) return 0; // if the answer becomes negative, then we've entered overflow territory
            else returnValue *= divideBy;               // 3.. how to get 32?... 3 x 10 = 30, then we add the mod of the tempX 30 + (2) = 32
            returnValue += tempX;
            x /= 10;
        }
        if(negativeNumberDetected) returnValue *= -1;
     return returnValue;
    }
};

int main() {
    Solution sol;
    int x = 1534236469;
    //  2147483647 is the max int #
    int answer = sol.reverse(x);
    cout << "Answer is: " << answer << endl;
    cout << "\n";

    return 0;
}