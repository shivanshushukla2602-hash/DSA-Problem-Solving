class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 1 , end = n-2;
        
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-2] != nums[n-1]){
            return nums[n-1];
        }
        
        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]){
                return nums[mid];
            }
            if(nums[mid] == nums[mid-1]){
                mid = mid-1;
            }
            if(mid % 2 == 0){
                start = start + 2;
            }
            else{
                end = end - 1;
            }
        }
        return -1;
    }
};
