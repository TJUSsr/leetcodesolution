// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: &quot;ACGAATTCCG&quot;. When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
// Example:
//
//
// Input: s = &quot;AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT&quot;
//
// Output: [&quot;AAAAACCCCC&quot;, &quot;CCCCCAAAAA&quot;]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> tres;
        vector<string> res;
        if(s.size()<=10) return res;
        unordered_set<string> map;
        string temps;
        for(int i=0;i<s.size()-9;++i){
            temps=s.substr(i,10);
            if(map.count(temps)&&tres.count(temps)==0){
                res.push_back(temps);
                tres.insert(temps);
            }
            else
                map.insert(temps);
            temps.clear();
        }
        return res;
    }
};
