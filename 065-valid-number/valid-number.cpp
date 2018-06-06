// Validate if a given string is numeric.
//
// Some examples:
// &quot;0&quot; =&gt; true
// &quot; 0.1 &quot; =&gt; true
// &quot;abc&quot; =&gt; false
// &quot;1 a&quot; =&gt; false
// &quot;2e10&quot; =&gt; true
//
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isNumber(string s) {
        bool dot=false,flage=false;
        int i=0,j=s.size()-1;
        while(s[i]==' '&&i<=j) ++i;
        while(s[j]==' '&&i<=j) --j;
        if(i>j) return false;
        int b=i;
        for(;i<=j;++i){
            if(s[i]=='+'||s[i]=='-')
                if(i==j) return false;
                else if(i==b||s[i-1]=='e') continue;
                else return false;
            else if(s[i]=='e'){
                if(flage||i==b||i==j||s[i-1]=='+'||s[i-1]=='-'||(s[i-1]=='.'&&i==b+1)) return false;
                flage=true;
            }else if(s[i]=='.'){
                if(dot||flage||(i==j&&i==b)||(i==j&&(s[i-1]<'0'||s[i-1]>'9'))) return false;
                dot=true;
            }else if(s[i]>='0'&&s[i]<='9')
                continue;
            else
                return false;
        }
        return true;
    }
};
