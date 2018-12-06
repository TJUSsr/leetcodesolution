// Write an algorithm to determine if a number is "happy".
//
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
// Example: 
//
//
// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return true;
        unordered_set<long long> set;
        long long next=n;
        int count=100;
        while(1){
            set.insert(next);
            next=process(next);
            if(next==1) return true;
            else if(set.count(next)) return false;
        }
        return false;
    }
private:
    long long process(long long n){
        long long res=0;
        while(n){
            res+=(n%10)*(n%10);
            n/=10;
        }
        return res;
    }
};
