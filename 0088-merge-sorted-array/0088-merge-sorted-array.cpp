class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;

        vector<int> newA;
        while(i<m || j<n){
            if(i==m){
                newA.push_back(nums2[j]);
                j++;
            }else if(j==n){
                newA.push_back(nums1[i]);
                i++;
            }else{
                if(nums1[i]<=nums2[j]){
                    newA.push_back(nums1[i]);
                    i++;
                }else{
                    newA.push_back(nums2[j]);
                    j++;
                }
            }
        }

        for(int i=0; i<m+n; i++){
            nums1[i] = newA[i];
        }
    }
};