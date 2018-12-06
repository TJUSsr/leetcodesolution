// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like . or *.
//
//
// Example 1:
//
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
//
// Example 2:
//
//
// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//
//
// Example 3:
//
//
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
//
// Example 4:
//
//
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
//
//
// Example 5:
//
//
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false
//
//


static const auto __ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
	bool isMatch(string s, string p) {	
		if (s.empty()&&p.empty()) return true;
		if ( p.empty()) return false;
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i < s.size() + 1; ++i)
		{
			
			for (int j = 1; j < p.size() + 1; ++j)
			{
				if (i>0&&(s[i-1] == p[j-1] || p[j-1] == '.')) dp[i][j] = (dp[i - 1][j - 1]?true:dp[i][j]);
				if (p[j-1] == '*')
				{
					if (i>0&&(p[j - 1-1] == s[i-1]|| p[j - 1 - 1] == '.'))
					{
						dp[i][j] = dp[i][j - 1] || dp[i - 1][j]||dp[i][j-2];
					}
					else
					{
						dp[i][j] = dp[i][j - 2];
					}
				}
			}
		}
		return dp[s.size()][p.size()];		
	}
};
