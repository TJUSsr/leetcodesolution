// Reverse bits of a given 32 bits unsigned integer.
//
// Example:
//
//
// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
// &nbsp;            return 964176192 represented in binary as 00111001011110000010100101000000.
//
//
// Follow up:
// If this function is called many times, how would you optimize it?
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i=1,j=i<<31,res=0;
        for(int k=1;k<=32;++k){
            if((n&i)!=0)
                res=(res|j);
            i=i<<1;
            j=j>>1;
        }
        return res;
    }
};
