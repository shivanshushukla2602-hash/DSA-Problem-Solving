class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int l = 0 , h = length-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target){return mid;}
            if(nums[mid]>target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
