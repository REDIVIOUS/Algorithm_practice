
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define For(a,b) for(ll a=1;a<=b;a++)
#define mem(a,b) memset(a,b,sizeof(a))
#define _mem(a,b) memset(a,0,(b+1)<<2)
#define lowbit(a) ((a)&-(a))
using namespace std;
typedef long long ll;
const ll maxn =  1e5;
const ll INF = 0x3f3f3f3f;
ll c[2][maxn];
ll n;
struct edge{
    ll v,w;        
}e[maxn];
bool cmp(edge a,edge b){return a.v<b.v;}
void update(ll x,ll d){
    for(ll i=x;i<=maxn-1;i+=lowbit(i))
        c[d][i] += d?x:1;
}
ll getsum(ll x,ll d){
    ll ans = 0;
    for(ll i=x;i;i-=lowbit(i))
        ans += c[d][i];
    return ans;
}
//0:����ͳ��
//1:�����
 
int main()
{
    cin >> n;
    For(i,n)
        cin >> e[i].v >> e[i].w;
    sort(e+1,e+1+n,cmp);
    ll ans = 0;
    ll cnl,cnr;
    ll bufn,bufw;
    ll all = 0;
    For(i,n){
        bufn = getsum(e[i].w,0);        //��ţiС��ţ�ĸ���
        bufw = getsum(e[i].w,1);        //��ţiС��ţ��λ���ܺ�
        cnl = bufn*e[i].w-bufw;         //ţi���
        cnr = all - bufw - (i-bufn-1)*e[i].w;//ţi�ұ�
        ans += (cnl+cnr)*e[i].v;
        all += e[i].w;                  //�ܳ�
        update(e[i].w,0);
        update(e[i].w,1);
    }
    cout << ans << endl;
 
    return 0;
}
