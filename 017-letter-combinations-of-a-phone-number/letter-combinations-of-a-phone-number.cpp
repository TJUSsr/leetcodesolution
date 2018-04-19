// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: &quot;23&quot;
// Output: [&quot;ad&quot;, &quot;ae&quot;, &quot;af&quot;, &quot;bd&quot;, &quot;be&quot;, &quot;bf&quot;, &quot;cd&quot;, &quot;ce&quot;, &quot;cf&quot;].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string temps;
        DFS(digits,res,temps,0);
        return res;
    }
private:
    void DFS(string& digits,vector<string>& res,string& temps,int i){
        if(i==digits.size()){
            res.push_back(temps);
            return;
        }
        for(int j=0;j<hash[digits[i]].size();++j){
            temps+=hash[digits[i]][j];
            DFS(digits,res,temps,i+1);
            temps.erase(temps.size()-1);
        }
        return;
    }
    
    unordered_map<char,string> hash={
        {'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
        {'8',"tuv"},{'9',"wxyz"}
    };
};
