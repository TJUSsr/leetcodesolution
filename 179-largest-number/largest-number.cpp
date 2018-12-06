// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
//
// Input: [10,2]
// Output: "210"
//
// Example 2:
//
//
// Input: [3,30,34,5,9]
// Output: "9534330"
//
//
// Note: The result may be very large, so you need to return a string instead of an integer.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

bool comp(const string& lhs,const string& rhs){
    auto s1=lhs+rhs;
    auto s2=rhs+lhs;
    return s1<s2;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        if(nums.empty()) return res;
        if(nums.front()==0&&nums.back()==0)
            return "0";
        vector<string> num;
        for(const auto&i:nums){
            num.push_back(to_string(i));
        }
        sort(num.begin(),num.end(),comp);
        for(auto it=num.rbegin();it!=num.rend();++it){
            res+=*it;
        }
        return res;
    }
};
