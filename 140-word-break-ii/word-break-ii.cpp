// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word.&nbsp;Return all such possible sentences.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input:
// s = &quot;catsanddog&quot;
// wordDict = [&quot;cat&quot;, &quot;cats&quot;, &quot;and&quot;, &quot;sand&quot;, &quot;dog&quot;]
// Output:
// [
// &nbsp; &quot;cats and dog&quot;,
// &nbsp; &quot;cat sand dog&quot;
// ]
//
//
// Example 2:
//
//
// Input:
// s = &quot;pineapplepenapple&quot;
// wordDict = [&quot;apple&quot;, &quot;pen&quot;, &quot;applepen&quot;, &quot;pine&quot;, &quot;pineapple&quot;]
// Output:
// [
// &nbsp; &quot;pine apple pen apple&quot;,
// &nbsp; &quot;pineapple pen apple&quot;,
// &nbsp; &quot;pine applepen apple&quot;
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input:
// s = &quot;catsandog&quot;
// wordDict = [&quot;cats&quot;, &quot;dog&quot;, &quot;sand&quot;, &quot;and&quot;, &quot;cat&quot;]
// Output:
// []
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
