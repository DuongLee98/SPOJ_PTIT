#include <iostream>
#include <math.h>
using namespace std;
 
#define MAX 1000000
int snt[MAX+10];
int mcd[MAX+10];
 
int sont(int n)
{
    if (n<2)
        return 0;
    for (int i=2; i<=sqrt(n); i++)
    {
    	if (n%i==0)
    	{
            return 0;
    	}
    }
    return 1;
}
 
void init()
{
    for (int i=1; i<=MAX; i++)
    {
        snt[i] = 1;
        mcd[i] = 0;
    }
}
 
void sangnt()
{
    snt[0] = 0;
    snt[1] = 0;
    for (int i=2; i<=sqrt(MAX); i++)
    {
        if (snt[i] == 1)
        {
            for (int j=2; j<=MAX/i; j++)
            {
                snt[i*j] = 0;
            }
        }
    }
}
 
 
int main()
{
    init();
    sangnt();
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        int ts = 0;
        for (int i=a; i<=b; i++)
        {
            if (snt[i]==1 && snt[i+6]==1 && i+6<=b)
            {
                ts++;
            }
        }
        cout<<ts<<endl;
    }
    return 0;
}
