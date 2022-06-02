// https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
what to do....
Input: strs = ["flower","flow","flight"]
Output: "fl"
we're given a vector of strings...
"flower" is 1st element
"flow" is 2nd element
"flight" is 3rd element
we need to find the longest common prefix amonst the strings, "fl" is the longest common prefix amongst the strings above, (prefix = start of the string)
the longest common prefix 
"power"
"run"
"rubber"
in this case above, the first string has no common prefix, we need to continue scanning with the second string
(at this point we can start comparing strings using an index starting from "rubber" (the next element in line after the one we're checking) from our array of strings to scan)
logic:
starting with the the first string, we're going to compare the first char in it with all the other strings, if any other strings match with the first char
we'll use a hash map to map the index of the string array given, with a count of the longest common prefix amongst the other strings
*/

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string ret = "";
    // cout << "\nWithin long Func, displaying the vector of strings given: ";  // for debugging purposes
    for (int i = 0; i < strs.size(); i++) {  // this should be removed once program is ready to submit
      cout << strs[i] << ", ";               // only using this for testing purposes
    }
    cout << "\n\n";

    unordered_map<string, int> hMap;
    unordered_map<string, int>::iterator it;
    string indexStringToCompare = "";  // used to compare strings in the array
    string nextStringForComparison = "";
    // flag that only one entry has been passed in the argument, we will return this as the answer
    bool onlyOneEntry = true;   

    // where to start scanning from strs[index] will be the string we're looking at first, we'll use the next for loop to iterate through the rest of the strings
    for (int index = 0; index < (strs.size() - 1); index++) {  
      indexStringToCompare = strs[index];                // the string we will start comparing from (the index we're currently looking at)
      nextStringForComparison = strs[index + 1];

      for (int j = (strs.size() - 1); index < j; j--) {  // this is where we're going to compare the strings to from the first for loop
        int charIndex = 0;                     // use this to compare each char
        int identicalCount = 0;
        string strPrefix = "";

        //cout << "\nComparing: " << indexStringToCompare << ", and " << nextStringForComparison << endl;       // for debugging purposes
        // if charIndex position of "flower" is the same as "flow" flower[0] == flow[0] then we're going to check if(flower[1] == flow[1]) and keep continuing until a break
        while ((indexStringToCompare[charIndex] == nextStringForComparison[charIndex]) && indexStringToCompare[charIndex] != '\0') {        // empty strings cannot pass this
          identicalCount++;
          strPrefix += indexStringToCompare[charIndex];
          charIndex++;
        }
        //cout << "(Count of prefix, literal string prefix) = (" << identicalCount << ", " << strPrefix << ")" << endl;     // for debugging purposes
        // will not insert duplicate keys, (we won't need to store duplicates regardless)
        pair<string, int> prefixPair(strPrefix, identicalCount);
        hMap.insert(prefixPair);
        nextStringForComparison = strs[j];
      }

      // base cases
      if (hMap.size() == 0) return "";  // if hash map is empty
        for (auto const &pair: hMap) {
            cout << "{ " << pair.first << " : " << pair.second << "}" << endl;
        }
        onlyOneEntry = false;   // if we got up to here, there is more than one entry in the argument
    }
        if(onlyOneEntry)
            return strs[0];
        int smallestIdenticalCount = 10000;
        for (auto const &pair: hMap) {
        if(pair.second < smallestIdenticalCount)
            ret = pair.first;
        smallestIdenticalCount = pair.second;
    } return ret;
  }
};

int main() {
  cout << "Longest Common Prefix Program Run\n\n";

  Solution sol;
  vector<string> vect{"", ""};
  string answer = "";
  answer = sol.longestCommonPrefix(vect);
  cout << "\nLongest Common Prefix = " << answer << endl;

  cout << "\n\n";
  return 0;
}