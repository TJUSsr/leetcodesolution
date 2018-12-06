// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.size()-1,j=b.size()-1;
        int c=0;
        while(i>=0&&j>=0){
            c=a[i]-'0'+b[j]-'0'+c;
            res+=('0'+c%2);
            c/=2;
            --i,--j;
        }
        if(i==-1)
            while(j>=0){
                c=b[j]-'0'+c;
                res+=('0'+c%2);
                c/=2;
                --j;
            }
        else if(j==-1)
            while(i>=0){
                c=a[i]-'0'+c;
                res+=('0'+c%2);
                c/=2;
                --i;
            }
        if(c!=0) res+=('0'+c);
        reverse(res.begin(),res.end());
        return res;
    }
};
