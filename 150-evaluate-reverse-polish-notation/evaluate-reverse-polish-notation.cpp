// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
// Some examples:
//
//
//   [&quot;2&quot;, &quot;1&quot;, &quot;+&quot;, &quot;3&quot;, &quot;*&quot;] -&gt; ((2 + 1) * 3) -&gt; 9
//   [&quot;4&quot;, &quot;13&quot;, &quot;5&quot;, &quot;/&quot;, &quot;+&quot;] -&gt; (4 + (13 / 5)) -&gt; 6
//
//
// &nbsp;
//


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int temp1;
        int temp2;
        int res;
        for(const auto& c:tokens){
            if(c=="+"){
                temp1=num.top();
                num.pop();
                temp2=num.top();
                num.pop();
                res=temp1+temp2;
                num.push(res);
                continue;
            }
            if(c=="-"){
                temp1=num.top();
                num.pop();
                temp2=num.top();
                num.pop();
                res=temp2-temp1;
                num.push(res);
                continue;
            }
            if(c=="*"){
                temp1=num.top();
                num.pop();
                temp2=num.top();
                num.pop();
                res=temp1*temp2;
                num.push(res);
                continue;
            }
            if(c=="/"){
                temp1=num.top();
                num.pop();
                temp2=num.top();
                num.pop();
                res=temp2/temp1;
                num.push(res);
                continue;
            }
            num.push(atoi(c.c_str()));
        }
        return num.top();
    }
};
