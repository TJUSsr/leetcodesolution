// Write a function that takes a string as input and returns the string reversed.
//
// Example 1:
//
//
//
// Input: "hello"
// Output: "olleh"
//
//
//
// Example 2:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: "amanaP :lanac a ,nalp a ,nam A"
//
//
//
//


static const auto _ =[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string reverseString(string s) {
        int l=s.size()-1;
        for(int i=0; i<s.size()>>1; ++i) {
            auto temp = s[i];
            s[i]=s[l-i];
            s[l-i]=temp;
        }
        return s;
    }
};
