// Given an absolute path for a file (Unix-style), simplify it. 
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// path = "/a/../../b/../c//.//", => "/c"
// path = "/a//b////c/d//././/..", => "/a/b/c"
//
// In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style
//
// Corner Cases:
//
//
// 	Did you consider the case where path = "/../"?
// 	In this case, you should return "/".
// 	Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// 	In this case, you should ignore redundant slashes and return "/home/foo".
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
