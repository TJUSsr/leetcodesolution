// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: &quot;a&quot; maps to &quot;.-&quot;, &quot;b&quot; maps to &quot;-...&quot;, &quot;c&quot; maps to &quot;-.-.&quot;, and so on.
//
// For convenience, the full table for the 26 letters of the English alphabet is given below:
//
//
// [&quot;.-&quot;,&quot;-...&quot;,&quot;-.-.&quot;,&quot;-..&quot;,&quot;.&quot;,&quot;..-.&quot;,&quot;--.&quot;,&quot;....&quot;,&quot;..&quot;,&quot;.---&quot;,&quot;-.-&quot;,&quot;.-..&quot;,&quot;--&quot;,&quot;-.&quot;,&quot;---&quot;,&quot;.--.&quot;,&quot;--.-&quot;,&quot;.-.&quot;,&quot;...&quot;,&quot;-&quot;,&quot;..-&quot;,&quot;...-&quot;,&quot;.--&quot;,&quot;-..-&quot;,&quot;-.--&quot;,&quot;--..&quot;]
//
// Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, &quot;cab&quot; can be written as &quot;-.-.-....-&quot;, (which is the concatenation &quot;-.-.&quot; + &quot;-...&quot; + &quot;.-&quot;). We&#39;ll call such a concatenation, the transformation&nbsp;of a word.
//
// Return the number of different transformations among all words we have.
//
//
// Example:
// Input: words = ["gin", "zen", "gig", "msg"]
// Output: 2
// Explanation: 
// The transformation of each word is:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."
//
// There are 2 different transformations, "--...-." and "--...--.".
//
//
// &nbsp;
//
// Note:
//
//
// 	The length of words will be at most 100.
// 	Each words[i] will have length in range [1, 12].
//     words[i] will only consist of lowercase letters.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

string d[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int res=0;
        string temp;
        unordered_set<string> Tree;
        for(const auto s:words){
            temp.clear();
            for(const auto c:s){
                temp+=d[c-'a'];
            }
            if(Tree.count(temp))
                continue;
            else{
                Tree.insert(temp);
                ++res;
            }
        }
        return res;
    }
};
