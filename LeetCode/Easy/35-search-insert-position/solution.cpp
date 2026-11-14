class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int index = INT_MIN;
        int start = 0 , end = n-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                index = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                index = mid + 1;
                start = mid + 1;
            }
        }
        return index;
    }
};
