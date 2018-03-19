#include <iostream>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define ll long long
ll prime[100005];
void prime1()
{
  ll i,j,k;
  for(i=0;i<100000;i++)
	    prime[i]=0;
	prime[1]=1;
	ll val=sqrt(100000);
	for(i=2;i<val;i++)
	{
	    if(prime[i]==0)
	    {
	        for(j=(i*i);j<100000;j=j+i)
	            prime[j]=1;
	    }
	}
}

ll gcd(ll n1,ll n2)
{
    if (n2 != 0)
       return gcd(n2, n1%n2);
    else 
       return n1;
}
ll modular(ll x,ll y,ll m)
{
    if (y == 0)
        return 1;
    ll val=modular(x,y/2,m)%m;
    val=(val*val)%m;
    
    if(y%2 == 0)
        return val;
    else
        return (x*val)%m;
}

int main() {
  ll n,i,j,k;
  prime1();
  ll p,q;
  cout<<"Enter p and q:";
  cin>>p>>q;
  while(!(prime[p]==0&&prime[q]==0))
  {
    cout<<"p and q should be prime number."<<endl;
    cout<<"Enter p and q:";
    cin>>p>>q;
  }
  ll eu=(p-1)*(q-1),e,count=0;
  for(i=1;i<eu;i++)
  {
    if(gcd(i,eu)==1)
      count++;
  }
  n=p*q;
  do{
    cout<<"Enter value of e:";
    cin>>e;
  }while(gcd(e,eu)!=1);
  ll d=modular(e,count-1,eu);
  cout<<"Public Key: "<<e<<" "<<n<<endl;
  cout<<"Private Key:"<<d<<" "<<n<<endl;
  string s;
  cout<<"Enter plaintext:";
  cin>>s;
  ll size=s.length();
  ll arr[size];
  for(i=0;i<size;i++)
  {
    arr[i]=s[i];
  }
  for(i=0;i<size;i++)
  {

    arr[i]=modular(arr[i],e,n);
  }
  cout<<"Cipher Text:"<<endl;
  for(i=0;i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  cout<<"Enter of size of ciphertext:";
  cin>>size;
  cout<<"Enter cipher text"<<endl;
  ll val[size];
  for(i=0;i<size;i++)
    cin>>val[i];
  for(i=0;i<size;i++)
  {
    val[i]=modular(val[i],d,n);
  }
  string ty="";
  for(i=0;i<size;i++)
    ty+=('A'+val[i]);
  cout<<"Plain Text is "<<ty<<endl;
  return 0; 
}