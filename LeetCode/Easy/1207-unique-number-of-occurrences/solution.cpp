class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> um;

        for(int x : arr){
            um[x]++;
        }

        unordered_set<int> us;

        for(auto x : um){
            if(us.find(x.second) != us.end()){
                return false;
            }

            us.insert(x.second);
        }
        return true;
    }
};
