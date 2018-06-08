// Given two words (beginWord and endWord), and a dictionary&#39;s word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = &quot;hit&quot;,
// endWord = &quot;cog&quot;,
// wordList = [&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;lot&quot;,&quot;log&quot;,&quot;cog&quot;]
//
// Output:
// [
//   [&quot;hit&quot;,&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;cog&quot;],
// &nbsp; [&quot;hit&quot;,&quot;hot&quot;,&quot;lot&quot;,&quot;log&quot;,&quot;cog&quot;]
// ]
//
//
// Example 2:
//
//
// Input:
// beginWord = &quot;hit&quot;
// endWord = &quot;cog&quot;
// wordList = [&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;lot&quot;,&quot;log&quot;]
//
// Output: []
//
// Explanation:&nbsp;The endWord &quot;cog&quot; is not in wordList, therefore no possible&nbsp;transformation.
//
//
//
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        if(beginWord==endWord) res.push_back({beginWord});
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()){
            int size=q.size();
            vector<string> toerase;
            for(int i=0;i<size;++i){
                auto temp=q.front();
                if(temp.back()==endWord) res.push_back(temp);
                q.pop();
                auto s=temp.back();
                for(int j=0;j<s.size();++j){
                    auto c=s[j];
                    for(int k=0;k<26;++k){
                        if('a'+k!=c){
                            s[j]='a'+k;
                            if(set.count(s)){
                                temp.push_back(s);
                                q.push(temp);
                                temp.pop_back();
                                toerase.push_back(s);
                            }
                        }
                        s[j]=c;
                    }
                }
            }
            for(const auto s:toerase) set.erase(s);
            if(!res.empty()) break;
        }
        return res;
    }
};
