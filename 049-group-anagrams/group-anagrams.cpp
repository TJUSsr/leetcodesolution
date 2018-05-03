// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: [&quot;eat&quot;, &quot;tea&quot;, &quot;tan&quot;, &quot;ate&quot;, &quot;nat&quot;, &quot;bat&quot;],
// Output:
// [
//   [&quot;ate&quot;,&quot;eat&quot;,&quot;tea&quot;],
//   [&quot;nat&quot;,&quot;tan&quot;],
//   [&quot;bat&quot;]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not&nbsp;matter.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty()) return res;
        res.reserve(strs.size());
        unordered_map<string,vector<string>*> hash;
        string ts;
        for(const auto& s:strs){
            ts=s;
            sort(ts.begin(),ts.end());
            if(hash.count(ts)){
                hash[ts]->push_back(s);
            }else{
                vector<string> tempres(1,s);
                res.push_back(tempres);
                hash[ts]=&res[res.size()-1];
            }
        }
        return res;
    }
};
