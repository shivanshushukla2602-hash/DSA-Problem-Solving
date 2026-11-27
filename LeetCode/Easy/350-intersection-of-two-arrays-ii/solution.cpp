class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> um;
        vector<int> ans;

        for(int x : nums1){
            um[x]++;
        }
        
        for(int x : nums2){
            if(um[x] > 0){
                ans.push_back(x);
                um[x]--;
            }
        }

        return ans;
    }
};
