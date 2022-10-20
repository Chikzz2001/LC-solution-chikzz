class Solution {
public:
    string intToRoman(int num) {
        
        string res;
        if(num>=1000)
        {res.append(num/1000,'M');
        num%=1000;}
        
        if(num/100)
        {
        if(num/100==4)
            res+="CD";
        else if(num/100==9)
            res+="CM";
        else if(num/100<5)
            res.append(num/100,'C');
        else if(num/100>=5)
        {
            res+="D";
            res.append(num/100-5,'C');
        }
        num%=100;
        }

        if(num/10)
        {
        if(num/10==4)
            res+="XL";
        else if(num/10==9)
            res+="XC";
        else if(num/10<5)
            res.append(num/10,'X');
        else if(num/10>=5)
        {
            res+="L";
            res.append(num/10-5,'X');
        }
        num%=10;
        }
       
        if(num)
        {
        if(num==4)
            res+="IV";
        else if(num==9)
            res+="IX";
        else if(num<5)
            res.append(num,'I');
        else if(num>=5)
        {
            res+="V";
            res.append(num-5,'I');
        }
        }
        
        return res;
    }
};