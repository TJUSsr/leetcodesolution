// Implement strStr().
//
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
//
//
// Input: haystack = &quot;hello&quot;, needle = &quot;ll&quot;
// Output: 2
//
//
// Example 2:
//
//
// Input: haystack = &quot;aaaaa&quot;, needle = &quot;bba&quot;
// Output: -1
//
//
// Clarification:
//
// What should we return when needle is an empty string? This is a great question to ask during an interview.
//
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C&#39;s&nbsp;strstr() and Java&#39;s&nbsp;indexOf().
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> KMP(string& needle) {
	    vector<int> res(needle.size(), -1);
	    res[0] = -1;
	    int i = 0, j = -1;
	    while (i<needle.size()-1) {
		    if (j == -1 || needle[i] == needle[j]) {
			    ++i;
			    ++j;
			    res[i] = j;
		    }
		    else
			    j = res[j];
	    }
	    return res;
    }
    int strStr(string haystack, string needle) {
	    if (needle.empty()) return 0;
	    if (haystack.size()<needle.size()) return -1;
	    auto nex = KMP(needle);
	    int i = 0, j = 0;
	    while(i<haystack.size()&&(j==-1||j<needle.size())){
		    if (j == -1 || haystack[i] == needle[j]) {
			    ++i;
			    ++j;
		    }
		    else
			    j = nex[j];
	    }
	    if (j == needle.size())
		    return i - j;
	    else
		    return -1;
    }
    /*
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<=haystack.size()-needle.size();++i){
            for(int j=0;j<needle.size();++j){
                if(haystack[i+j]!=needle[j])
                    break;
                else
                    if(j==needle.size()-1)
                        return i;
            }
        }
        return -1;
    }*/
};
