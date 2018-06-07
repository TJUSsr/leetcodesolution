// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//
//     1 -&gt; A
//     2 -&gt; B
//     3 -&gt; C
//     ...
//     26 -&gt; Z
//     27 -&gt; AA
//     28 -&gt; AB 
//     ...
//
//
// Example 1:
//
//
// Input: 1
// Output: &quot;A&quot;
//
//
// Example 2:
//
//
// Input: 28
// Output: &quot;AB&quot;
//
//
// Example 3:
//
//
// Input: 701
// Output: &quot;ZY&quot;
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        if(n==0) return res;
        while(n>0){
            --n;
            int temp=n%26;
            res+='A'+temp;
            n/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
