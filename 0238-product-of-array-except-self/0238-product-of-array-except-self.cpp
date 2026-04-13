class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prevProd(n);
        vector<int> afterProd(n);

        prevProd[0] = nums[0];
        afterProd[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            prevProd[i] = prevProd[i-1] * nums[i];
        }
        for(int i=n-2; i>=0; i--){
            afterProd[i] = afterProd[i+1] * nums[i];
        }

        vector<int> tbr(n);
        tbr[0] = afterProd[1];
        tbr[n-1] = prevProd[n-2];
        for(int i=1; i<n-1; i++){
            tbr[i] = prevProd[i-1]*afterProd[i+1];
        }

        return tbr;
    }
};