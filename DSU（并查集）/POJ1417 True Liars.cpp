#include <iostream>
#include <string>
#include <cstring>
#define N 1005
using namespace std;

//t t yes
//t e no 
//e t no 
//e e yes
//ͨ�����Ϸ����У��ش�yes����Ϊͬ�� 
int root[N]; //���鼯���� 
int relation[N]; //��ϵ���飬0Ϊͬ�࣬1��Ϊͬ�� 
int dp[N][N]; //��������Ϊjʱǰi����Ʒ�ļ�ֵ 
int setnum[N]; //ÿ�����ڵ㼯�ϵĸ��� 
int weight[2][N]; //��̬�滮weight���飨0����ͬ�࣬1����ͬ�ࣩ 
int index[N]; //ֻ��¼���ڵ������ 
int pre[N]; //dp��ѯ·���� 

//Ѱ�Ҳ��鼯���ڵ㣨����·��ѹ���� 
int findroot(int v){
	if(v==root[v]){ //�ҵ����ڵ� 
		return v;
	}
	else{
		//���¸��ڵ� 
		int u=root[v];
		root[v]=findroot(root[v]); //�ݹ����
		//����Ѱ�Ҹ��ڵ�ʱ�����¹�ϵ 
		relation[v]=(relation[v]+relation[u])%2; 
		return root[v]; //���ظ��ڵ� 		
	} 
}

//�ϲ�a��b���ڵļ��� 
void unionroot(int x, int y, int d){
	int rootx=findroot(x);
	int rooty=findroot(y);
	if(rootx==rooty){
		return;
	}
	//û�кϲ���ϲ�
	root[rooty]=rootx; //��rootx�ϲ�
	relation[rooty]=(relation[x]-relation[y]+2+d)%2;
	setnum[rootx]=setnum[rootx]+setnum[rooty]; //rootx�ӹ�rooty�µ�Ԫ������ 
	setnum[rooty]=0; 
}

void KNAP(int block,int p,int tt){
	dp[0][0]=1; //�����߽磬��0��ͬ�����1�� 
	for(int i=1;i<=block;i++){ //��Ʒһ����block�� 
		for(int j=0;j<=p;j++){ //��ֵ�������װ��Ϊp������ʹ������ 
			if(j>=weight[0][i]){
				dp[i][j]=dp[i-1][j-weight[0][i]];
			}
			if(j>=weight[1][i]){
				dp[i][j]+=dp[i-1][j-weight[1][i]];
			}
		}
	}
	if(dp[block][p]==1){
		int j=p;
		for(int i=block;i>=1;i--){
			if(dp[i][j]==dp[i-1][j-weight[0][i]]){
				pre[i]=0;
				j=j-weight[0][i];
			}
			else if(dp[i][j]==dp[i-1][j-weight[1][i]]){
				pre[i]=1;
				j=j-weight[1][i];
			}
		}
		for(int i=1;i<=tt;i++){
			if(pre[index[root[i]]]==relation[i]){
				cout<<i<<endl;
			}
		}
		cout<<"end"<<endl; 
	}
	else{
		cout<<"no"<<endl;
	} 
} 
int main(){
	int n,p1,p2,tt,block;
	int x,y;
	string a;
	while(cin>>n>>p1>>p2&&(n||p1||p2)){
		memset(weight,0,sizeof(weight));
        memset(dp,0,sizeof(dp));
        memset(index,0,sizeof(index));
        memset(pre,0,sizeof(pre));
		tt=p1+p2;  //�����ܸ��� 
		for(int i=1;i<=tt;i++){
			root[i]=i; //��ʼ�����鼯
			relation[i]=0; //��ʼ����ϵ����
			setnum[i]=1; //ÿ�����ڵ���һ��Ԫ�� 
		}
		//����Ԫ�أ���ɺϲ��͹�ϵȷ�ϣ����첢�鼯 
		for(int i=1;i<=n;i++){
			cin>>x>>y>>a;
			if(a=="yes"){ //��ʾ��ͬ�� 
				unionroot(x,y,0);
			}
			else{ //����ͬ�� 
				unionroot(x,y,1); 
			}
		}
		block=0;
		for(int i=1;i<=tt;i++){
			if(setnum[i]!=0){ //�����һ�����ڵ� 
				block+=1; //���������һ
				index[i]=block; //��¼i�Ŀ����� 
			}
		}
		for(int i=1;i<=tt;i++){
			findroot(i);
			//��Ӧ�鱳��������һ
			//ֻ�и��ڵ��Ӧ������м�ֵ���ֱ��¼���º͸��ڵ�ͬ�ࡢ��ͬ�������  
			weight[relation[i]][index[root[i]]]+=1;
		}
		//���뱳����ѯ�Ĺ��� 
		KNAP(block,p1,tt);
	}
	return 0; 	
}

