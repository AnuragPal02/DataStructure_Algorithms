class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        int presum = 0;
        int count = 0;
        mp[0].push_back(-1);
        for(int i=0;i<n;i++){
            presum += nums[i];
            auto it = mp.find(presum-k);
            if(it!=mp.end()){
               int target = presum-k;
               count += mp[target].size();
            }
            mp[presum].push_back(i);
        }
        return count;
    }
};