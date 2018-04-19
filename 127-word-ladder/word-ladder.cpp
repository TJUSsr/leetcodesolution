//
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
//
// For example,
//
//
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log","cog"]
//
//
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
//
// Note:
//
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
//
//
//
//
// UPDATE (2017/1/20):
// The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
//


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(),wordList.end());
        length=beginWord.size();
        int res=0;
        queue<string> Qstr;
        Qstr.push(beginWord);
        hash.erase(beginWord);
        while(!Qstr.empty()){
            int num=Qstr.size();
            ++res;
            for(int i=0;i<num;++i){
                auto cur=Qstr.front();
                if(cur==endWord)
                    return res;
                Qstr.pop();
                AddWord(cur,hash,Qstr);
            }
        }
        return 0;
    }
private:
    int length;
    void AddWord(string word, unordered_set<string>& hash, queue<string>& Qstr){
        for(int i=0;i<length;++i){
            char temp=word[i];
            for(int j=0;j<=26;++j){
                word[i]='a'+j;
                if(hash.find(word)!=hash.end()){
                    Qstr.push(word);
                    hash.erase(word);
                }   
            }
            word[i]=temp;
        }
    }
};
