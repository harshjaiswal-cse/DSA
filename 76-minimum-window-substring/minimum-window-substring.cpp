#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // map to store character frequencies in t
        vector<int> targetCount(128, 0);
        for (char c : t) {
            targetCount[c]++;
        }

        // map to store character frequencies in current window
        vector<int> windowCount(128, 0);
        
        int left = 0, right = 0;
        int required = t.length(); // Total characters needed
        int formed = 0;           // Characters currently satisfied in window
        
        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            // If current char frequency in window is <= its frequency in t,
            // it contributes to our 'formed' count.
            if (targetCount[c] > 0 && windowCount[c] <= targetCount[c]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                
                // If removing this char makes the window invalid
                if (targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};