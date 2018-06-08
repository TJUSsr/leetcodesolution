// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where &quot;adjacent&quot; cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
// Example:
//
//
// Input: 
// words = [&quot;oath&quot;,&quot;pea&quot;,&quot;eat&quot;,&quot;rain&quot;] and board =
// [
//   [&#39;o&#39;,&#39;a&#39;,&#39;a&#39;,&#39;n&#39;],
//   [&#39;e&#39;,&#39;t&#39;,&#39;a&#39;,&#39;e&#39;],
//   [&#39;i&#39;,&#39;h&#39;,&#39;k&#39;,&#39;r&#39;],
//   [&#39;i&#39;,&#39;f&#39;,&#39;l&#39;,&#39;v&#39;]
// ]
//
// Output:&nbsp;[&quot;eat&quot;,&quot;oath&quot;]
//
//
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.


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


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty()||board[0].empty()) return res;
        Trie Tree;
        Trie TreeRes;
        for(const auto&s:words){
            Tree.insert(s);
        }
        int h=board.size()-1, w=board[0].size()-1;
        vector<vector<bool>> flag(h+1,vector<bool>(w+1,false));
        string tempres;
        for(int i=0;i<=h;++i){
            for(int j=0;j<=w;++j)
                DFS(board,h,w,TreeRes,Tree,tempres,i,j, flag);
        }
        tempres.clear();
        DFS(TreeRes.root,res,tempres);
        return res;
    }
private:
    void DFS(vector<vector<char>>& board, int h, int w, Trie& TreeRes, Trie& Tree, string& tempres, int i, int j, vector<vector<bool>>& flag){
        if(i<0||i>h||j<0||j>w||flag[i][j])
            return;
        tempres+=board[i][j];
        if(Tree.search(tempres)) TreeRes.insert(tempres);
        if(Tree.startsWith(tempres)){
            flag[i][j]=true;
            DFS(board,h,w,TreeRes,Tree,tempres,i-1,j,flag);
            DFS(board,h,w,TreeRes,Tree,tempres,i,j-1,flag);
            DFS(board,h,w,TreeRes,Tree,tempres,i+1,j,flag);
            DFS(board,h,w,TreeRes,Tree,tempres,i,j+1,flag);
            flag[i][j]=false;
        }
        tempres.erase(tempres.end()-1);
        return;
    }
    //将结果按照字典序转化为合适的格式
    void DFS(Dic* root,vector<string>& res,string& tempres){
        if(root==nullptr) return;
        if(root->c!='#')
            tempres+=root->c;
        if(root->finish)
            res.push_back(tempres);
        for(int i=0;i<26;++i){
            DFS(root->dic[i],res,tempres);
        }
        if(root->c!='#')
            tempres.erase(tempres.end()-1);
        return;
    }
};
