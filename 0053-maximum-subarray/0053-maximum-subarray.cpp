class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum;
        vector<int> track(nums.size());

        track[0] = maxNum = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(track[i-1]<0){
                if(nums[i]<0){
                    maxNum = max(maxNum, nums[i]);
                }else{
                    maxNum = nums[i];
                }

                track[i] = maxNum;
                continue;
            }

            int sumHere = nums[i] + track[i-1];

            if(sumHere<=0){
                if(nums[i]<=0){
                    track[i] = 0;
                }else{
                    track[i] = nums[i];
                }
            }else{
                track[i] = sumHere;
            }
            maxNum = max(maxNum, track[i]);
        }

        return maxNum;
    }
};