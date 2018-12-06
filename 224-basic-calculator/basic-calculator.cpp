// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// Example 1:
//
//
// Input: "1 + 1"
// Output: 2
//
//
// Example 2:
//
//
// Input: " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int calculate(string s) {
        stack<int>  n;
        stack<char> flag;
        int i=0,size=s.size();
        while(i<size){
            if(s[i]==' ') {++i;continue;}
            else if(s[i]>='0'&&s[i]<='9'){
                int number=0;
                while(i<size&&s[i]>='0'&&s[i]<='9') number=10*number+s[i]-'0',++i;
                if(flag.empty()||flag.top()=='(')
                    n.push(number);
                else if(flag.top()=='+'){int temp=number+n.top();n.pop();n.push(temp);flag.pop();}
                else if(flag.top()=='-'){int temp=n.top()-number;n.pop();n.push(temp);flag.pop();}    
            }
            else if(s[i]=='('||s[i]=='+'||s[i]=='-') flag.push(s[i]),++i;
            else if(s[i]==')'){
                if(flag.top()=='(')
                    flag.pop();
                while(!flag.empty()&&flag.top()!='('){
                    int rhs=n.top();n.pop();
                    int lhs=n.top();n.pop();
                    int temp;
                    if(flag.top()=='+') temp=lhs+rhs;
                    else temp=lhs-rhs;
                    n.push(temp);
                    flag.pop();
                }
                ++i;
            }
        }
        return n.top();
    }
};
