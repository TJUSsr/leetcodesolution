// The gray code is a binary numeral system where two successive values differ in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
//
// Note:
// For a given n, a gray code sequence is not uniquely defined.
//
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

static vector<int> res={0,1,3,2};

class Solution {
public:
    int log2(int n){
        if(n==1) return 0;
        int res=0;
        while(n>1){
            n/=2;
            ++res;
        }
        return res;
    }
    vector<int> grayCode(int n) {
        n=pow(2,n);
        int i=res.size();
        while(i<n){
            int bot=log2(i);
            int num=pow(2,bot);
            for(int j=i-1;j>=0;--j){
                res.push_back(num+res[j]);
            }
            i*=2;
        }
        return vector<int>(res.begin(),res.begin()+n);
    }
};
