// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
//
//     A -&gt; 1
//     B -&gt; 2
//     C -&gt; 3
//     ...
//     Z -&gt; 26
//     AA -&gt; 27
//     AB -&gt; 28 
//     ...
//
//
// Example 1:
//
//
// Input: &quot;A&quot;
// Output: 1
//
//
// Example 2:
//
//
// Input: &quot;AB&quot;
// Output: 28
//
//
// Example 3:
//
//
// Input: &quot;ZY&quot;
// Output: 701
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) return 0;
        int res=0;
        for(const auto&c:s){
            res=26*res+(c-'A'+1);
        }
        return res;
    }
};
