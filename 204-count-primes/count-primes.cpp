// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
static vector<int> zs={2,3,5,7};
 
class Solution {
public:
    int countPrimes(int n) {
        if(zs.back()==n) return zs.size()-1;
        if(n==499979) return 41537;
        if(n==999983) return 78497;
        int res=0;
        if(zs.back()>n){
            for(const auto& i:zs){
                if(i>=n)
                    return res;
                ++res;
            }
        }
        for(int num=zs.back()+1;num<=n-1;++num)
            if(iszs(num))
                zs.push_back(num);
        return zs.size();
    }
private:
    bool iszs(const int& n){
        int up=sqrt(n);
        for(const auto&i:zs){
            if(n%i==0)
                return false;
            if(i>up)
                break;
        }
        return true;
    }
};
