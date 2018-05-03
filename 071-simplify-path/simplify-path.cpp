// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = &quot;/home/&quot;, =&gt; &quot;/home&quot;
// path = &quot;/a/./b/../../c/&quot;, =&gt; &quot;/c&quot;
//
// click to show corner cases.
//
// Corner Cases:
//
// &nbsp;
//
// &nbsp;
//
//
// 	Did you consider the case where path = &quot;/../&quot;?
// 	In this case, you should return &quot;/&quot;.
// 	Another corner case is the path might contain multiple slashes &#39;/&#39; together, such as &quot;/home//foo/&quot;.
// 	In this case, you should ignore redundant slashes and return &quot;/home/foo&quot;.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void e_s(string& s){
        int i=s.size()-1;
        while(s[i]!='/'){
            s.erase(i);
            --i;
        }
        s.erase(i);
        return;
    }
    string simplifyPath(string path) {
        string res;
        string tempres;
        if(path.empty()) return res;
        for(int i=0;i<path.size();++i){
            if(!tempres.empty()&&path[i]=='/'){
                if(tempres.back()=='/')
                    continue;
                else{
                    if(tempres=="/."){
                    }else if(tempres=="/.."){
                        if(!res.empty())
                            e_s(res);
                    }else{
                        res+=tempres;
                    }
                    tempres.clear();
                    tempres+='/';
                }
            }else if(i==path.size()-1){
                if(path[i]=='/')
                    continue;
                else
                    tempres+=path[i];
                if(tempres=="/."){}
                else if(tempres=="/.."){
                    if(!res.empty())
                        e_s(res);
                }else{
                    res+=tempres;
                }
            }else
                tempres+=path[i];
        }
        if(res.empty()) return "/";
        else return res;
    }
};
