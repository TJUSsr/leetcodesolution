// Given an input string, reverse the string word by word.
//
// Example:&nbsp;&nbsp;
//
//
// Input: &quot;the sky is blue&quot;,
// Output:&nbsp;&quot;blue is sky the&quot;.
//
//
// Note:
//
//
// 	A word is defined as a sequence of non-space characters.
// 	Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// 	You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//
// Follow up:&nbsp;For C programmers, try to solve it in-place in O(1) space.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        int i=0,j=0,l=0;
        int len=s.size();
        int wordcount=0;
        while(true){
            while(i<len&&s[i]==' ') ++i;
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len&&s[i]!=' '){
                s[j]=s[i];
                ++j;
                ++i;
            }
            reverse(s,l,j-1);
            ++wordcount;
        }
        s.resize(j);
        reverse(s,0,j-1);
        return;
    }
private:
    void reverse(string& s, int i, int j){
        while(i<j){
            auto c=s[i];
            s[i++]=s[j];
            s[j--]=c;    
        }
    }
};
