// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord(&quot;bad&quot;)
// addWord(&quot;dad&quot;)
// addWord(&quot;mad&quot;)
// search(&quot;pad&quot;) -&gt; false
// search(&quot;bad&quot;) -&gt; true
// search(&quot;.ad&quot;) -&gt; true
// search(&quot;b..&quot;) -&gt; true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
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
    Dic* root;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Tree.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.empty()) return false;
        int size=word.size()-1;
        return DFS(word,size,Tree.root,0,word[0]);
    }
    
    Trie Tree;
    
    bool DFS(const string&word, int size, Dic* root, int i, char c){
        if(root==nullptr)
            return false;
        if(c!='.'){
            auto temp=root->dic[c-'a'];
            if(i==size)
                if(temp==nullptr) return false;
                else return temp->finish;
            return DFS(word,size,temp,i+1,word[i+1]);
        }else{
            bool res;
            for(int k=0;k<26;++k){
                auto temp=root->dic[k];
                if(i==size){
                    if(temp!=nullptr&&temp->finish)
                        res=res||true;
                    else
                        res=res||false;
                }else
                    res=res||DFS(word,size,temp,i+1,word[i+1]);
                if(res)
                    return true;
            }
            return res;
        }
            
        /*
        if(c!='.'&&i==size){
            if(root->dic[c-'a'])
                return root->dic[c-'a']->finish;
            else
                return false;
        }
        if(c=='.'&&i==size)
            for(int k=0;k<26;++k)
                if(root->dic[k]!=nullptr&&root->dic[k]->finish)
                    return true;
            return false;
        if(c=='.'){
            for(int k=0;k<26;++k)
                if(root->dic[k]!=nullptr&&DFS(word,size,root->dic[k],i+1,word[i+1]))
                    return true;
            return false;
        }else{
            if(root->dic[c-'a']==nullptr)
                return false;
            else
                return DFS(word,size,root->dic[c-'a'],i+1,word[i+1]);
        }*/
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
