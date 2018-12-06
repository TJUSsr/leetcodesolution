// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.
//


static const auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    return nullptr; 
}();

class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        while(r<s.size()){
            if(s[r]==' ') {
                revert(l, r-1, s);
                l=r+1;
            } else if (r == s.size()-1) {
                revert(l, r, s);
            }
            ++r;  
        }
        return s;
    }
private:
    void revert(int l, int r, string& s){
        if(r<=l)
            return;
        for(int i=0;i<=((r-l)>>1);++i){
            auto temp = s[l+i];
            s[l+i]=s[r-i];
            s[r-i]=temp;
        }
    }
};
