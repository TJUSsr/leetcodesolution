// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//     ...
//
//
// Example 1:
//
//
// Input: 1
// Output: "A"
//
//
// Example 2:
//
//
// Input: 28
// Output: "AB"
//
//
// Example 3:
//
//
// Input: 701
// Output: "ZY"
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
