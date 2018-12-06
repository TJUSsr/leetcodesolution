// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
//
// Example 1:
//
//
// Input: "aacecaaa"
// Output: "aaacecaaa"
//
//
// Example 2:
//
//
// Input: "abcd"
// Output: "dcbabcd"


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string shortestPalindrome(string s) {
        string res;
        if(s.empty()) return res;
        int index=s.size()>>1;
        int i=index,j=index;
        while(1){
            while(i-1>=0&&s[i-1]==s[index]) --i;
            index=i;
            while(j+1<s.size()&&s[j+1]==s[index]) ++j;
            while(i-1>=0&&j+1<s.size()&&s[i-1]==s[j+1]) {--i;++j;}
            if(i==0) break;
            index-=1;
            i=index;
            j=index;
        }
        res=string(s.begin()+j+1,s.end());
        reverse(res.begin(),res.end());
        res+=s;
        return res;
    }
};
