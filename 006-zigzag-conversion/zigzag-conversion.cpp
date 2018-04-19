// The string &quot;PAYPALISHIRING&quot; is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: &quot;PAHNAPLSIIGYIR&quot;
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = &quot;PAYPALISHIRING&quot;, numRows = 3
// Output: &quot;PAHNAPLSIIGYIR&quot;
//
//
// Example 2:
//
//
// Input: s = &quot;PAYPALISHIRING&quot;, numRows =&nbsp;4
// Output:&nbsp;&quot;PINALSIGYAHRPI&quot;
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        string res;
        int size=2*numRows-2;
        for(int i=0;i<numRows;++i){
            for(int j=i;j<s.size();j+=size){
                res+=s[j];
                int temp=j+size-2*i;
                if(i!=0&&i!=numRows-1&&temp<s.size())
                    res+=s[temp];
            }
        }
        return res;
    }
};
