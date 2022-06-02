// https://leetcode.com/problems/single-number/
// Single Number - Leetcode

#include <iostream>
#include <vector>  
#include <map>
using namespace std;

class Solution {
public:
    void hashMapNumbers(int num, map<int, int> &hMap) {
        hMap[num] += 1;
        cout << " --- Hash Map [" << num << "] is: " << hMap[num] << endl;
    }

    int singleNumber(vector<int>& nums) {
        int retResult = 0, numToDisplay = 0;
        map<int, int> hMap;
        cout << "Displaying through func: " << endl;
         // go through vector of ints, and input them into hash map function
        for (int i = 0; i < nums.size(); i++) {     // iterate through vector of ints
            cout << nums[i];
            hashMapNumbers(nums[i], hMap);
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << "\nValue at nums[" << i << "] is: " << nums[i];
        }

        // now iterate through hMap and find the hMap with only 1 as the value
        cout << "\n\n";
        for (int i = 1; i <= hMap.size(); i++) {
            cout << "i== " << i << " hMap[i] == " << hMap[i] << "\t";

            /*
            if (hMap[i] == 1) {
                cout << "\n\nThe element that only appears once is: " << hMap[i] << endl;       // we need the key here, we know the iterator
            }
            */
        }
        return retResult;
    }
};

// hMap[1] = 1
// hMap[2] = 1
// hMap[1] = 2
// hMap[3] = 1
// hMap[3] = 2

// now to search through these... hMap[nums[i]]

int main()
{
    vector<int> nums = { 1, 3, 1, 3, 2 };       // every int appears twice, except for one
    Solution sol;
    int answer = sol.singleNumber(nums);
    //cout << "The answer is: " << answer << endl;

    return 0;
}