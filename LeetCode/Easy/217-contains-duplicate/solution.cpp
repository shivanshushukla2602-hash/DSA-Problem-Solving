class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> um;

        for(int x : nums){
            um[x]++;
        }

        for(auto x : nums){
            if(um[x] >= 2){
                return true;
            }
        }
        return false;
    }
};
