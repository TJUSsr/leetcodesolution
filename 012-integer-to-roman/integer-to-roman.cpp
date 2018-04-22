// Roman numerals are represented by seven different symbols:&nbsp;I, V, X, L, C, D and M.
//
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//
// For example,&nbsp;two is written as II&nbsp;in Roman numeral, just two one&#39;s added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//
// 	I can be placed before V (5) and X (10) to make 4 and 9.&nbsp;
// 	X can be placed before L (50) and C (100) to make 40 and 90.&nbsp;
// 	C can be placed before D (500) and M (1000) to make 400 and 900.
//
//
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
//
//
// Input:&nbsp;3
// Output: &quot;III&quot;
//
// Example 2:
//
//
// Input:&nbsp;4
// Output: &quot;IV&quot;
//
// Example 3:
//
//
// Input:&nbsp;9
// Output: &quot;IX&quot;
//
// Example 4:
//
//
// Input:&nbsp;58
// Output: &quot;LVIII&quot;
// Explanation: C = 100, L = 50, XXX = 30 and III = 3.
//
//
// Example 5:
//
//
// Input:&nbsp;1994
// Output: &quot;MCMXCIV&quot;
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//


static int x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } else if (x == 4) res = res + roman[n] + roman[n - 1];
            else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            }
            else if (x == 9) res = res + roman[n] + roman[n - 2];
            num %= value[n];            
        }
        return res;
    }

};
