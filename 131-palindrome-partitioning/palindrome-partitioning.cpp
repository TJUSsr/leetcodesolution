//
// Given a string s, partition s such that every substring of the partition is a palindrome.
//
//
// Return all possible palindrome partitioning of s.
//
//
// For example, given s = "aab",
//
// Return
//
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
public:
    //通常需要全部解的时候，进行DFS遍历，需要最优解的时候，进行动态规划
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        DFS(s,temp,res);
        return res;
    }
private:
    bool isP(const string& s){
        return s==string(s.rbegin(),s.rend());
    }
    
    void DFS(const string s, vector<string>& temp, vector<vector<string>>& res){
        if(s.empty()){
            res.push_back(temp);
            return;
        }
        for(int i=1;i<=s.size();++i){
            auto word=s.substr(0,i);
            if(isP(word)){
                temp.push_back(word);
                DFS(s.substr(i),temp,res);
                temp.pop_back();
            }
        }
        return;
    }
};
