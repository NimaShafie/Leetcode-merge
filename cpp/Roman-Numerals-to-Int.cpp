#include <iostream>
#include <map>
#include <string>

using namespace std;

const int ROMAN_MULTIPLER = 2;

class Solution {
public:
    int romanToInt(string s) {
        cout << "\nGiven Roman Numerals = " << s << endl << endl;
        int romanTotal = 0;
        char tempChar;
        // intitalize romam numerals to ints
        map<char, int> roman;
        /*
        IV = 4, IX = 9      I before V and X
        XL = 40, XC = 90    X before L and C
        CD = 400, CM = 900  C before D and M
        */
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        map<char, int>::iterator it;

        /*
        read in chars one at a time, and when we find the combination that makes a different number, we then apply it
        for example, 'XIX' = 19
        parsing one char at a time... 'X' = 10, 'I' = 1, 'X' = 10,
        all we have to do is store the last char read, into a temporary variable, and compare it to the next char read, if we find a match for a different number case
        then we apply that number to our total.
        'X' = 10, tempChar = X, then 'I' = 1, there is no XI combination.. we store 'I' as our tempChar, then we read the next char, X, we compare 'I+X' = 'IX' which is a special case, 'IX' == 9
        so we add 9 onto our running total of our first 'X' = 10, to get 10+9 == 19
        */

        for (int i = 0; s[i] != '\0'; i++) {
            cout << "positon " << i << " is equal to: " << roman[s[i]] << endl;
            if (i == 0 || i == 1) tempChar = roman[s[0]];
            else tempChar = roman[s[i - 1]];
            if (tempChar == 1 || tempChar == 10 || tempChar == 100) {
                // if we're looking at the special combination of I+V (6) or I+X (11), we simply need to subtract 2 to get proper result
                if ((tempChar == 1) && (roman[s[i]] == 5 || roman[s[i]] == 10)) romanTotal -= ROMAN_MULTIPLER;
                else if ((tempChar == 10) && (roman[s[i]] == 50 || roman[s[i]] == 100)) romanTotal -= (ROMAN_MULTIPLER * 10);   // X+L (60), X+C (110), XL = 40, XC = 90. need to subtract 20
                else if ((tempChar == 100) && (roman[s[i]] == 500 || roman[s[i]] == 1000)) romanTotal -= (ROMAN_MULTIPLER * 100);   // C+D (600), C+M (1100), CD = 400, CM = 900. need to subtract 200
            }
            romanTotal += roman[s[i]];
        }
        return romanTotal;
    }
};

int main()
{
    cout << "Roman Numerals to Integer Conversion:\n";
    Solution sol;
    int toInt = sol.romanToInt("MCMXXIV"); // should be 1924
    cout << "\n";
    cout << toInt << endl;

    return 0;
}

/*
conversion chart:
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV
Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
*/