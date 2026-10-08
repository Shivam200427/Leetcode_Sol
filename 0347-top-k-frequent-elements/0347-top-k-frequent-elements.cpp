class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        typedef pair<int, int> ppi;
        priority_queue<ppi,vector<ppi>,greater<ppi>> minh;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            minh.push({i->second, i->first});
            if(minh.size() > k) {
                minh.pop();
            }
        }
        vector<int> ans;
        while(minh.size() > 0) {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};