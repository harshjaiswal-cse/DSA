#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(string digits, int index, string current, vector<string>& result, vector<string>& mapping) {
        // Base Case: Agar index digits ki length ke barabar hai, matlab combination ready hai
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Current digit ke letters nikaalo (e.g., '2' -> "abc")
        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            // Letter ko add karo aur next digit par jao
            backtrack(digits, index + 1, current + c, result, mapping);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        // Phone keypad mapping
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, "", result, mapping);
        return result;
    }
};