// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j&&!((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))) ++i;
            while(i<j&&!((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))) --j;
            if(i==j) return true;
            if(comp(s[i],s[j])){
                ++i;
                --j;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
private:
    bool comp(const char& a, const char& b){
        if(a>='0'&&a<='9'&&b>='0'&&b<='9')
            return a==b;
        if(((a>='a'&&a<='z')||(a>='A'&&a<='Z'))&&((b>='a'&&b<='z')||(b>='A'&&b<='Z')))
            return a-32==b||a+32==b||a==b;
        return false;
    }
};
