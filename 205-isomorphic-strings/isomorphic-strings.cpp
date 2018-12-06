// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
//
// Input: s = "egg", t = "add"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        int size=s.size(),i=0;
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        while(i<=size){
            if(map1.count(s[i])||map2.count(t[i])){
                if(map1.count(s[i])==0||map2.count(t[i])==0||map1[s[i]]!=t[i]||map2[t[i]]!=s[i])
                    return false;
            }else{
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            ++i;
        }
        return true;
    }
};
