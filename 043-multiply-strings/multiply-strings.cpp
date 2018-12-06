// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int n1=num1.size(),n2=num2.size();
        vector<int> res(n1+n2,0);
        int r1,r2,sum;
        for(int i=n1-1;i>=0;--i){
            r1=num1[i]-'0';
            for(int j=n2-1;j>=0;--j){
                r2=num2[j]-'0';
                sum=r1*r2+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        string res1;
        int i=0;
        while(res[i]==0) ++i;
        while(i<n1+n2){
            res1+=res[i]+'0';
            ++i;
        }
        return res1;
    }
};
