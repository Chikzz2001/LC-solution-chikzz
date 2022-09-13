class Solution {
    bool valid(int data)
    {
        return ((data>>7)&1)&!((data>>6)&1);
    }
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        for(int i=0;i<n;)
        {
            if(((data[i]>>7)&1)&((data[i]>>6)&1)&((data[i]>>5)&1)&((data[i]>>4)&1)&(!((data[i]>>3)&1)))
            {
                if(i+1==n||!valid(data[i+1]))return 0;
                if(i+2==n||!valid(data[i+2]))return 0;
                if(i+3==n||!valid(data[i+3]))return 0;
                i+=4;
            }
            else if(((data[i]>>7)&1)&((data[i]>>6)&1)&((data[i]>>5)&1)&(!((data[i]>>4)&1)))
            {
                 if(i+1==n||!valid(data[i+1]))return 0;
                 if(i+2==n||!valid(data[i+2]))return 0;
                 i+=3;
            }
            else if(((data[i]>>7)&1)&((data[i]>>6)&1)&(!((data[i]>>5)&1)))
            {
                if(i+1==n||!valid(data[i+1]))return 0;
                i+=2;
            }
            else if(!((data[i]>>7)&1))
                i++;
            else
                return 0;
        }
        return 1;
    }
};