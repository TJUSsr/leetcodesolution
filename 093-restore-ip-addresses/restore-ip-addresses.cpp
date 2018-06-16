// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: &quot;25525511135&quot;
// Output: [&quot;255.255.11.135&quot;, &quot;255.255.111.35&quot;]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        DFS(res,temp,s,0,0,0,s.size());
        return res;
    }
private:
    void DFS(vector<string>& res, string temp, const string& s, int num, int count, int i, int size){
        if(i==size&&count==4){
            res.push_back(temp);
            return;
        }
        if(i==size||count==4) return;
        while(num<=255){
            num=num*10+(s[i]-'0');
            if(num<=255){
                temp.push_back(s[i]);
                if(count!=3)
                    temp.push_back('.');
                DFS(res,temp,s,0,count+1,i+1,s.size());
                if(count!=3)
                    temp.pop_back();
                if(num==0)
                    break;
            }
            ++i;
        }
        return;
    }
};
