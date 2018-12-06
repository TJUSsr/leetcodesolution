// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//  
//
// Example 1:
//
//
// Input: 1
// Output: "1"
//
//
// Example 2:
//
//
// Input: 4
// Output: "1211"
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

static vector<string> res={"1","11","21","1211","111221"};

class Solution {
public:
    string countAndSay(int n) {
        string temp;
        int j,num;
        if(n>res.size()){
            for(int i=res.size();i<=n;++i){
                string& s=res[i-1];
                temp.clear();
                j=0;
                while(j<s.size()){
                    num=1;
                    while(s[j]==s[j+1]){
                        ++j;
                        ++num;
                    }
                    temp+=to_string(num);
                    temp+=s[j];
                    ++j;
                }
                res.push_back(temp);
            }
        }
        return res[n-1];
    }
};
