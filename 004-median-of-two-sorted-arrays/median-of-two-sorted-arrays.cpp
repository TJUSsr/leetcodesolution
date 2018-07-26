// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2&nbsp;cannot be both empty.
//
// &nbsp;
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        double median = 0;
        
        if(nums1.size()>nums2.size()){
            vector<int> nums = nums1;
            nums1=nums2;
            nums2=nums;
        }
        int mini = 0; 
        int maxi = nums1.size();
        int curi;
        int curj;
        int half = (nums1.size()+nums2.size()+1)/2;
        curi = (mini+maxi)/2;
        curj = half - curi;
        while(true){
            
            if(curi<nums1.size() && nums2[curj-1]>nums1[curi])
                mini = curi + 1;
            else if(curi>0 && nums1[curi-1]>nums2[curj])
                maxi = curi - 1;
            else
                break;
            
            curi = (mini+maxi)/2;
            curj = half - curi;
        }
        double maxleft;
        if(curi==0) maxleft = nums2[curj-1];
        else if(curj==0) maxleft = nums1[curi-1];
        else maxleft = nums1[curi-1]>nums2[curj-1]?nums1[curi-1]:nums2[curj-1];
        double minright;
        if(curi==nums1.size()) minright = nums2[curj];
        else if(curj==nums2.size()) minright = nums1[curi];
        else minright = nums1[curi]<nums2[curj]?nums1[curi]:nums2[curj];
        
        if((nums1.size()+nums2.size())%2)
            median = maxleft;
        else
            median = (maxleft+minright)/2.0;
        
        return median;
    }
};
