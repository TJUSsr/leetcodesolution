// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given &quot;abcabcbb&quot;, the answer is &quot;abc&quot;, which the length is 3.
//
// Given &quot;bbbbb&quot;, the answer is &quot;b&quot;, with the length of 1.
//
// Given &quot;pwwkew&quot;, the answer is &quot;wke&quot;, with the length of 3. Note that the answer must be a substring, &quot;pwke&quot; is a subsequence and not a substring.
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
