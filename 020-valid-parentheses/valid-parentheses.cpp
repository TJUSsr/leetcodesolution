// Given a string containing just the characters &#39;(&#39;, &#39;)&#39;, &#39;{&#39;, &#39;}&#39;, &#39;[&#39; and &#39;]&#39;, determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
// Note that an empty string is&nbsp;also considered valid.
//
// Example 1:
//
//
// Input: &quot;()&quot;
// Output: true
//
//
// Example 2:
//
//
// Input: &quot;()[]{}&quot;
// Output: true
//
//
// Example 3:
//
//
// Input: &quot;(]&quot;
// Output: false
//
//
// Example 4:
//
//
// Input: &quot;([)]&quot;
// Output: false
//
//
// Example 5:
//
//
// Input: &quot;{[]}&quot;
// Output: true
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> st;
        for(const auto&c:s){
            if(c=='('||c=='{'||c=='[')
                st.push(c);
            else if(c==')'){
                if(!st.empty()&&st.top()=='(')
                    st.pop();
                else
                    return false;
            }else if(c=='}'){
                if(!st.empty()&&st.top()=='{')
                    st.pop();
                else
                    return false;
            }else if(c==']'){
                if(!st.empty()&&st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty()?true:false;
    }
};
