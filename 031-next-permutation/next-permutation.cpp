// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant&nbsp;extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 &rarr; 1,3,2
// 3,2,1 &rarr; 1,2,3
// 1,1,5 &rarr; 1,5,1
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void Isort(vector<int>& nums,const int& mark,const int& sz){
        if(mark==sz)
            return;
        for(int i=mark+1;i<=sz;++i){
            int temp=nums[i],j=i;
            for(;j-1>=mark&&temp<nums[j-1];--j){
                nums[j]=nums[j-1];
            }
            nums[j]=temp;
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        int sz=nums.size()-1,mark=0;
        bool reverse=true;
        for(int i=sz;i>=0;--i){
            if(i-1>=0&&nums[i]<=nums[i-1])
                continue;
            if(i-1>=0){
                reverse=false;
                mark=i;
                break;
            }
        }
        if(reverse){
            for(int j=0;j<=sz/2;++j){
                int temp=nums[j];
                nums[j]=nums[sz-j];
                nums[sz-j]=temp;
            }
        }else{
            int index=mark;
            for(int i=mark+1;i<=sz;++i){
                if(nums[i]>nums[mark-1]&&nums[i]<nums[index])
                    index=i;
            }
            int temp=nums[index];
            nums[index]=nums[mark-1];
            nums[mark-1]=temp;
            //Isort(nums,mark,sz);这里原本写了一个简单的插入排序，改为了调用std的sort()
            sort(nums.begin()+mark,nums.end());
        }
        return;
    }
};
