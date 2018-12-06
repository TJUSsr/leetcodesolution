// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty())
            return res;
        if(strs[0].empty())
            return res;
        int i=0;
        char c0;
        while(1){
            c0=strs[0][i];
            for(int j=1;j<strs.size();++j){
                if(i==strs[j].size())
                    return res;
                if(c0!=strs[j][i])
                    return res;
            }
            res+=c0;
            ++i;
            if(i==strs[0].size())
                return res;
        }
    }
};
