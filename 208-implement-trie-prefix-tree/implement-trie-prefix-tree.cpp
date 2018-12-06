// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct Dic{
    vector<Dic*> dic;
    char c;
    bool finish;
    //Dic():c('#'),finish(false),dic(vector<Dic*>(26,nullptr)){}
    Dic(char c_='#', bool finish_=false, vector<Dic*> dic_=vector<Dic*>(26,nullptr)):c(c_),finish(finish_),dic(dic_){}
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new Dic();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp=root;
        for(int i=0;i<word.size();++i){
            if(temp->dic[word[i]-'a']==nullptr)
                temp->dic[word[i]-'a']=new Dic(word[i],false);
            temp=temp->dic[word[i]-'a'];
        }
        temp->finish=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto temp=root;
        for(int i=0;i<word.size();++i){
            if(temp->dic[word[i]-'a']==nullptr)
                return false;
            temp=temp->dic[word[i]-'a'];
        }
        return temp->finish;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto temp=root;
        for(int i=0;i<prefix.size();++i){
            if(temp->dic[prefix[i]-'a']==nullptr)
                return false;
            temp=temp->dic[prefix[i]-'a'];
        }
        return true;
    }
private:
    Dic* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
