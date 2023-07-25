class Solution {
    int bs(vector<int>& arr,int &n,int lo,int hi)
    {
        if(lo>hi)return -1;
    
        int mid=lo+(hi-lo)/2;
        
        if(mid>0&&mid<n-1)
        {
        if(arr[mid-1]>arr[mid]&&arr[mid]>arr[mid+1])
            return bs(arr,n,lo,mid);
        else if(arr[mid-1]<arr[mid]&&arr[mid]<arr[mid+1])
             return bs(arr,n,mid,hi);
        else if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
            return mid;
        }
        
        return -1;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        return bs(arr,n,0,n-1);
    }
};