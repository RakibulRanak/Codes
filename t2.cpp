#include<bits/stdc++.h>
using namespace std;
int BIT[100005],a[100005],s;

void update(int x, int delta)
{
    for(; x<= s; x+= x&-x)
        BIT[x] += delta;
}

long long int query(int x)
{
    long long int sum = 0;
    for(; x>0; x-= x&-x)
        sum+=BIT[x];
    return sum;
}

int main()
{
    int t,que;
    scanf("%d",&t);

    for(int j=1; j<=t; j++)
    {


        scanf("%d %d",&s,&que);



        for(int i=1; i<=s; i++)
        {

            scanf("%d",&a[i]);
            update(i,a[i]);
        }
        printf("Case %d:\n",j);
        for(int i=0;i<que;i++)
        {
            int temp;

            scanf("%d",&temp);

            if(temp==1)
            {
               int t1;
               scanf("%d",&t1);
                printf("%d\n",a[t1+1]);
               update(t1+1,-1*a[t1+1]);
               a[t1+1]=0;
            }
            else if(temp==2)
            {
                int t2,t3;
                scanf("%d %d",&t2,&t3);
                a[t2+1]+=t3;
                update(t2+1,t3);
            }
            else
            {
                int t4,t5;
                scanf("%d %d",&t4,&t5);
                printf("%lld\n",(query(t5+1)-query(t4)));
            }
        }
        memset(BIT,0,100005);
        memset(a,0,100005);
        //cout<<BIT[3]<<" "<<a[3]<<endl;

    }
    return 0;
}

