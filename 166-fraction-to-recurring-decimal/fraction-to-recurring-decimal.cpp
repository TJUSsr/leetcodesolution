// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: &quot;0.5&quot;
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: &quot;2&quot;
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: &quot;0.(6)&quot;
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string res;
        if(numerator<0^denominator<0) res+='-';
        long long num,den;
        if(numerator<0) num=static_cast<long long>(numerator)*-1;
        else num=static_cast<long long>(numerator);
        if(denominator<0) den=static_cast<long long>(denominator)*-1;
        else den=static_cast<long long>(denominator);       
        long long befordot=num/den;
        num=num%den;
        res+=to_string(befordot);
        if(num==0)
            return res;
        res+='.';
        num*=10;
        unordered_map<long long, int> map;
        while(num){
            long long temp=num/den;
            if(map.count(num)){
                res.insert(map[num],1,'(');
                res+=')';
                return res;
            }
            map[num]=res.size();
            res+=to_string(temp);
            num=(num%den)*10;
        }
        return res;
    }
};
