class Solution {
    static bool comp(const vector<int>& v1,const vector<int>& v2)
{
    return v1[1]>v2[1];
}
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int unit=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            if(boxTypes[i][0]<truckSize)
            {unit+=(boxTypes[i][0]*boxTypes[i][1]);truckSize-=boxTypes[i][0];}
            else
            {
                unit+=(truckSize*boxTypes[i][1]);break;}         
                } 
              return unit;  
        }
};