// Given an input string (s) and a pattern (p), implement regular expression matching with support for &#39;.&#39; and &#39;*&#39;.
//
//
// &#39;.&#39; Matches any single character.
// &#39;*&#39; Matches zero or more of the preceding element.
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s&nbsp;could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like&nbsp;.&nbsp;or&nbsp;*.
//
//
// Example 1:
//
//
// Input:
// s = &quot;aa&quot;
// p = &quot;a&quot;
// Output: false
// Explanation: &quot;a&quot; does not match the entire string &quot;aa&quot;.
//
//
// Example 2:
//
//
// Input:
// s = &quot;aa&quot;
// p = &quot;a*&quot;
// Output: true
// Explanation:&nbsp;&#39;*&#39; means zero or more of the precedeng&nbsp;element, &#39;a&#39;. Therefore, by repeating &#39;a&#39; once, it becomes &quot;aa&quot;.
//
//
// Example 3:
//
//
// Input:
// s = &quot;ab&quot;
// p = &quot;.*&quot;
// Output: true
// Explanation:&nbsp;&quot;.*&quot; means &quot;zero or more (*) of any character (.)&quot;.
//
//
// Example 4:
//
//
// Input:
// s = &quot;aab&quot;
// p = &quot;c*a*b&quot;
// Output: true
// Explanation:&nbsp;c can be repeated 0 times, a can be repeated 1 time. Therefore it matches &quot;aab&quot;.
//
//
// Example 5:
//
//
// Input:
// s = &quot;mississippi&quot;
// p = &quot;mis*is*p*.&quot;
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
