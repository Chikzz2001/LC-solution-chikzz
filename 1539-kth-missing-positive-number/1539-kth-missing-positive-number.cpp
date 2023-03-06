class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1,j=0;
        while(1) {
            if(j<arr.size()&&i==arr[j])j++;
            else k--;
            if(!k)return i;
            i++;
        }
        return arr.size()+k;
    }
};