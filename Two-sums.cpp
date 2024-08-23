class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int, int>pairIdx;

        for(int i=0;i<nums.size();++i){
            int num = nums[i];
            if(pairIdx.find(t-num)!= pairIdx.end()){
                return {i,pairIdx[t-num]};
            }
            pairIdx[num]=i;
        }
        return{};
    }
};