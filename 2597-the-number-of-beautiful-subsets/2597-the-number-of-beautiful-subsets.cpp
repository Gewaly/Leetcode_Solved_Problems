void backtrack(const vector<int>& nums, int k, unordered_map<int, int>& flag, int pos, int& res)
{
    if(pos == nums.size())
    {
        res++;
        return;
    }
    backtrack(nums, k, flag, pos + 1, res);
    int num = nums[pos];
    if(!flag[num - k])
    {
        flag[num]++;
        backtrack(nums, k, flag, pos + 1, res);
        flag[num]--;
    }
}

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> flag;
        int res = 0;
        backtrack(nums, k, flag, 0, res);
        return res - 1;
    }
};