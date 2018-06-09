// Given an array of words and a width&nbsp;maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces &#39; &#39; when necessary so that each line has exactly maxWidth characters.
//
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is inserted between words.
//
// Note:
//
//
// 	A word is defined as a character sequence consisting&nbsp;of non-space characters only.
// 	Each word&#39;s length is&nbsp;guaranteed to be greater than 0 and not exceed maxWidth.
// 	The input array words&nbsp;contains at least one word.
//
//
// Example 1:
//
//
// Input:
// words = [&quot;This&quot;, &quot;is&quot;, &quot;an&quot;, &quot;example&quot;, &quot;of&quot;, &quot;text&quot;, &quot;justification.&quot;]
// maxWidth = 16
// Output:
// [
// &nbsp; &nbsp;&quot;This &nbsp; &nbsp;is &nbsp; &nbsp;an&quot;,
// &nbsp; &nbsp;&quot;example &nbsp;of text&quot;,
// &nbsp; &nbsp;&quot;justification. &nbsp;&quot;
// ]
//
//
// Example 2:
//
//
// Input:
// words = [&quot;What&quot;,&quot;must&quot;,&quot;be&quot;,&quot;acknowledgment&quot;,&quot;shall&quot;,&quot;be&quot;]
// maxWidth = 16
// Output:
// [
// &nbsp; &quot;What &nbsp; must &nbsp; be&quot;,
// &nbsp; &quot;acknowledgment &nbsp;&quot;,
// &nbsp; &quot;shall be &nbsp; &nbsp; &nbsp; &nbsp;&quot;
// ]
// Explanation: Note that the last line is &quot;shall be    &quot; instead of &quot;shall     be&quot;,
// &nbsp;            because the last line must be left-justified instead of fully-justified.
//              Note that the second line is also left-justified becase it contains only one word.
//
//
// Example 3:
//
//
// Input:
// words = [&quot;Science&quot;,&quot;is&quot;,&quot;what&quot;,&quot;we&quot;,&quot;understand&quot;,&quot;well&quot;,&quot;enough&quot;,&quot;to&quot;,&quot;explain&quot;,
// &nbsp;        &quot;to&quot;,&quot;a&quot;,&quot;computer.&quot;,&quot;Art&quot;,&quot;is&quot;,&quot;everything&quot;,&quot;else&quot;,&quot;we&quot;,&quot;do&quot;]
// maxWidth = 20
// Output:
// [
// &nbsp; &quot;Science &nbsp;is &nbsp;what we&quot;,
//   &quot;understand &nbsp; &nbsp; &nbsp;well&quot;,
// &nbsp; &quot;enough to explain to&quot;,
// &nbsp; &quot;a &nbsp;computer. &nbsp;Art is&quot;,
// &nbsp; &quot;everything &nbsp;else &nbsp;we&quot;,
// &nbsp; &quot;do &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&quot;
// ]
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if(words.empty()||maxWidth<=0) return res;
        int left=0, right=0, sum, amount;
        string temp;
        while(1){
            left=right;
            sum=0;
            temp.clear();
            while(right<words.size()&&sum+words[right].size()<=maxWidth){
                sum+=(1+words[right].size());
                ++right;
            } 
            --sum;
            amount=right-left;
            if(amount==1){
                temp+=words[left];
                temp.append(maxWidth-temp.size(),' ');
            }else{
                if(right==words.size()){
                    for(int i=left;i<right;++i){
                        temp+=words[i];
                        if(i!=right-1)
                            temp+=" ";
                    }
                    temp.append(maxWidth-temp.size(),' ');
                }else{
                    int add=(maxWidth-sum+amount-1)/(amount-1);
                    int more=maxWidth-((amount-1)*(add-1)+sum);
                    for(int i=left;i<right;++i){
                        temp+=words[i];
                        if(i<left+more){
                            temp.append(add+1,' ');
                        }
                        else if(i!=right-1){
                            temp.append(add,' ');
                        }
                    }
                }
            }
            res.push_back(temp);
            if(right>=words.size())
                break;
        }
        return res;
    }
};
