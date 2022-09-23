for(int i=n;i>=1;i--)
{
string t;
for(int j=0;j<=log2(i);j++)
{
if(i&(1<<j))
t+='1';
else
t+='0';
}
//cout<<t<<" "<<t.length()<<"\n";
// reverse(t.begin(),t.end());
for(int j=0;j<t.length();j++)
{
if(t[j]=='1')
{
res=(res%M+fpow(2,len+j)%M)%M;
}
}
//s+=t;
len+=t.length();
}
//dp=vector<long long int>(s.length()+1,-1);
return res;
}
};
```