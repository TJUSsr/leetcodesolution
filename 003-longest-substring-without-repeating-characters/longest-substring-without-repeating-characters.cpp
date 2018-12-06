// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool h[256] = {false};
        int l = 0, ans = 0;
        for (int i = 0, sz = s.size(); i < sz; i++) {
            char c = s[i];
            if (h[c]) {
                while(h[c]) h[s[l++]] = false;
            } else {  
                ans = max(ans, i - l + 1);
            }
            h[c] = true;
        }
        return ans;
    }
};
