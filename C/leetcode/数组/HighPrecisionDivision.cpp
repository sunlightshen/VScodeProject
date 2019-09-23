#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution{	
public:
	int L=110;
	int sub(int *a,int *b,int La,int Lb)
	{
	    if(La<Lb) return -1;
	    if(La==Lb)
	    {
	        for(int i=La-1;i>=0;i--)
	            if(a[i]>b[i]) break;
	            else if(a[i]<b[i]) return -1;
	    }
	    for(int i=0;i<La;i++)
	    {
	        a[i]-=b[i];
	        if(a[i]<0) a[i]+=10,a[i+1]--;
	    }
	    for(int i=La-1;i>=0;i--)
	        if(a[i]) return i+1; 
	    return 0;
	}
	string div(string n1,string n2,int nn) 
	{
	    string s,v; 
	    int a[L],b[L],r[L],La=n1.size(),Lb=n2.size(),i,tp=La;  
	    fill(a,a+L,0);fill(b,b+L,0);fill(r,r+L,0);
	    for(i=La-1;i>=0;i--) a[La-1-i]=n1[i]-'0';
	    for(i=Lb-1;i>=0;i--) b[Lb-1-i]=n2[i]-'0';
	    if(La<Lb || (La==Lb && n1<n2)) {
	        return n1;}
	    int t=La-Lb;
	    for(int i=La-1;i>=0;i--)
	        if(i>=t) b[i]=b[i-t];
	        else b[i]=0;
	    Lb=La;
	    for(int j=0;j<=t;j++)
	    {
	        int temp;
	        while((temp=sub(a,b+j,La,Lb-j))>=0) 
	        {
	            La=temp;
	            r[t-j]++;
	        }
	    }
	    for(i=0;i<L-10;i++) r[i+1]+=r[i]/10,r[i]%=10; 
	    while(!r[i]) i--; 
	    while(i>=0) s+=r[i--]+'0';
	   
	    i=tp;
	    while(!a[i]) i--; 
	    while(i>=0) v+=a[i--]+'0';
	    if(v.empty()) v="0"; 
	    if(nn==1) return s;
	    if(nn==2) return v;
	}
	string gcd(string a, string b){
		string s="0";
		while(b.compare(s)){
			string t=div(a,b,2);
			a=b;
			b=t; 
		}
		return a;
	}
};
int main()
{
	Solution solution;
    string a="1000000000000001";
    string b="10";
    cout<<solution.div(a,b,2)<<endl;
    cout<<solution.gcd(a,b)<<endl;
}