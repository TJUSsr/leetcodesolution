// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};
