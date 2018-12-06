// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Example 1:
//
//
// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
//
// Example 2:
//
//
// Input: version1 = "1.0.1", version2 = "1"
// Output: 1
//
// Example 3:
//
//
// Input: version1 = "7.5.2.4", version2 = "7.5.3"
// Output: -1
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,len1=version1.size(),len2=version2.size();
        int sum1,sum2;
        while(i<len1&&j<len2){
            sum1=0,sum2=0;
            while(i<len1&&version1[i]!='.') sum1=10*sum1+version1[i]-'0',++i;
            while(j<len2&&version2[j]!='.') sum2=10*sum2+version2[j]-'0',++j;
            if(sum1>sum2)
                return 1;
            else if(sum1<sum2)
                return -1;
            if(i==len1||j==len2)
                break;
            ++i,++j;
        }
        if(i==len1&&j==len2)
            return 0;
        if(i==len1){
            while(j<len2){
                if(version2[j]!='.'&&version2[j]!='0')
                    return -1;
                ++j;
            }
            return 0;
        }
        if(j==len2){
            while(i<len1){
                if(version1[i]!='.'&&version1[i]!='0')
                    return 1;
                ++i;
            }
            return 0;
        }
    }
};
