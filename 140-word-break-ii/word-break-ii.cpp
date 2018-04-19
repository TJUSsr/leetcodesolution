//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
//
//
//
// Return all such possible sentences.
//
//
//
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
//
//
//
// A solution is ["cats and dog", "cat sand dog"].
//
//
//
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
//


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        res.clear();
        dict.clear();
        if(s.empty())
            return res;
        for(const auto c:wordDict){
            dict.insert(c);
        }
        res=PrivateWordBreak(s);
        return res;
    }
private:
    vector<string> res;
    unordered_set<string> dict;
    unordered_map<string, vector<string>> dp;
    vector<string> PrivateWordBreak(string& s){
        if(dp.count(s))
            return dp[s];
        vector<string> tempres;
        if(dict.count(s))
            tempres.push_back(s);
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,PrivateWordBreak(rem));
                tempres.insert(tempres.end(),prev.begin(),prev.end());
            }
        }
        dp[s]=tempres;
        return tempres;
    }
    
    vector<string> combine(string& word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
};
    
    /*
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        res.clear();
        if(s.empty())
            return res;
        dp.clear();
        for(int i=0; i<s.size();++i){
            vector<bool> tempdp(s.size(),false);
            for(int j=i; j<s.size();++j){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i,j-i+1))!=wordDict.end())
                    tempdp[j]=true;
            }
            dp.push_back(tempdp);
        }
        
        output(s.size()-1,s);
        reverse(res.begin(),res.end());
        return res;
    }
private:
    void output(int mark, const string& s){
        if(mark==-1){
            string str;
            for(int i=tempres.size()-1;i>=0;--i){
                str+=tempres[i];
                if(i!=0) str+=' ';
            }
            res.push_back(str);
        }
        else{
            for(int k=0;k<=mark;++k){
                if(dp[k][mark]){
                    tempres.push_back(s.substr(k,mark-k+1));
                    output(k-1,s);
                    tempres.pop_back();
                }
            }
        }
    }
    
    vector<string> res;
    vector<string> tempres;
    vector<vector<bool>> dp;
};*/
