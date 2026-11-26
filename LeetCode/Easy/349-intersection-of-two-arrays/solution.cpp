class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(nums1.begin() , nums1.end());
        vector<int> ans;

        for(int x : nums2){
            if(us.find(x) != us.end()){
                ans.push_back(x);
                us.erase(x);
            }
        }

        return ans;
    }
};
