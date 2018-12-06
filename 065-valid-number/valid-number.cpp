// Validate if a given string can be interpreted as a decimal number.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false
//
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
//
//
// 	Numbers 0-9
// 	Exponent - "e"
// 	Positive/negative sign - "+"/"-"
// 	Decimal point - "."
//
//
// Of course, the context of these characters also matters in the input.
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
