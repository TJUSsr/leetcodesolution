// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if(s.empty()||t.empty()||t.size()>s.size()) return res;
        int d[256]={0};
        int map[256]={0};
        int count=0,tsize=0;
        for(const auto& c:t){
            ++d[c];
            if(d[c]==1)
                ++tsize;
        }
        int left=-1,right=9999999, i=0,size=s.size()-1;
        queue<int> q;
        while(i<=size){
            if(d[s[i]]){
                q.push(i);
                ++map[s[i]];
                if(map[s[i]]==d[s[i]])
                    ++count;
                while(map[s[q.front()]]>d[s[q.front()]]){
                    map[s[q.front()]]-=1;
                    q.pop();
                }
                if(count==tsize){
                    if(i-q.front()<right-left){
                        left=q.front();
                        right=i;
                    }
                }
            }
            ++i;
        }
        if(left==-1) return res;
        res=s.substr(left,right-left+1);
        return res;
    }
};
