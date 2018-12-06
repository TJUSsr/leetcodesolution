// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
// Example 1:
//
//
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
//
// Example 2:
//
//
// Input:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// Output: []
//
//


static const auto _=[](){
    std:ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> res;
        if(s.empty()||words.empty()) return res;
        int i, wSize = words.size(), wL=words[0].size(), start, cur, sL=s.size(), wCnt;
        if(sL<wL*wSize) return res;
        
        //build the map
        for(i=0; i<wSize; ++i)
            map[words[i]] = map.count(words[i])>0? ++map[words[i]]:1;
            
        for(i=0; i<wL; ++i)
        {// go through each possible starting point sequences
            start = cur = i; // start is the starting point of the current search window, cur is the end of the current search window
            wCnt = wSize; // reset the words to be searched
            while(start<=sL-wL*wSize)
            { // if it is a valid start
                if(map.count(s.substr(cur,wL))==0){// if the current word is not one in the map, then move the starting window to the next word positon, reset wCnt and recover map counts.
                        for(wCnt = wSize; start!=cur; start+=wL) ++map[s.substr(start,wL)];
                        start +=wL; //skip the current invalid word;
                }
                else if(map[s.substr(cur,wL)]==0){
                 // if the current word is a valid word in the map, but it is already found in the current search window, then we have to move start to skip the previously found one, and update wCnt and map counts accordingly.
                    for(;s.substr(cur,wL)!=s.substr(start,wL); start+=wL)
                    {
                        ++map[s.substr(start,wL)];
                        ++wCnt;
                    }
                    start += wL;//skip the previously found one
                }
                else{
                // if the current word is a valid one and it is not found before in the current search window
                    --map[s.substr(cur,wL)]; // then reduce its counter
                    if(--wCnt == 0) { // update wCnt, if we find all the words
                        res.push_back(start); // save start
                        ++map[s.substr(start,wL)]; //moving start to skip the first word in the current search window
                        start +=wL;
                        ++wCnt;
                    }
                }
                cur+=wL; // update cur
            }
            for(;start<cur;start+=wL)  ++map[s.substr(start,wL)];//reset the map count
        }
        return res;
    }
};
