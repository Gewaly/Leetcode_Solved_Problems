class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        int pivot = low;
        if (target >= nums[pivot] && target <= nums[n - 1])
            return binarySearch(nums, target, pivot, n - 1);
        return binarySearch(nums, target, 0, pivot - 1);
    }
};