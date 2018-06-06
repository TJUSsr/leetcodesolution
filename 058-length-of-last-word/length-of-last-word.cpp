// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int res=0;
        int i=s.size()-1;
        while(i>=0&&s[i]==' ') --i;
        for(;i>=0;--i){
            if(s[i]!=' ')
                ++res;
            else
                break;
        }
        return res;
    }
};
