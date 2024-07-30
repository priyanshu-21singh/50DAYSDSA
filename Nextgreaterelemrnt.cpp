class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nextgreater;
        stack<int> s;
        for (auto& num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextgreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans;
        for (auto& num : nums1) {
            if (nextgreater.find(num) != nextgreater.end()) {
                ans.push_back(nextgreater[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
