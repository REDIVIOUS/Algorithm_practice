#include <cstdio>
#include <vector>
#define lowbit(x) ((x)&(-x)) 
#define N 100010
using namespace std; 

int in[N],out[N]; //����źͳ���� 
int c[N],flag[N];  //��״����ͣ��Ƿ���ƻ����־ 
vector<int> mylist[N]; //�ڽӱ� 
int count; 

//��״�����getsum����������ǰx�������ĺ�
int getsum(int x){
	int sum=0;
	for(int i=x;i>0;i=i-lowbit(i)){
		sum=sum+c[i]; //����c[i]���ۼ������ 
	}
	return sum; 
} 

//����x����������v������c[i] 
void update(int x,int add){
	for(int i=x;i<=N;i=i+lowbit(i)){
		c[i]=c[i]+add; //���º�x�������йص�����c[i] 
	}
}

//��dfs����,�����ź�����
void DFS(int x){
	in[x]=count;
	int size_x=mylist[x].size();
	for(int i=0;i<size_x;i++){ //����x�������ھӽڵ� 
		count=count+1;
		DFS(mylist[x][i]); 
	}
	out[x]=count;
}
 
int main(){
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		mylist[u].push_back(v); //�ߵ����ӹ�ϵ�����ڽӱ� 
	}
	count=1;
	DFS(1); //����DFS��ʼ��in��out����
	for(int i=1;i<=n;i++){ //��ʼ�����еĽڵ� 
		flag[i]=1;
		update(i,1); //��״����ÿһ���ڵ��1 
	} 
	int m;
	char type;
	int num;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s %d",&type,&num);
		if(type=='Q'){ //����ǲ�ѯ����������� 
			printf("%d\n",getsum(out[num])-getsum(in[num]-1));
		}
		else if(type=='C'){ //����Ǹ��ģ������update���� 
			if(flag[num]==1){ //�����������ƻ�� 
				flag[num]=0; //��Ϊû��ƻ�� 
				update(in[num],-1);
			}
			else{ //����û��ƻ�� 
				flag[num]=1; //��Ϊ��ƻ��״̬ 
				update(in[num],1); 
			}
		} 
	}
	return 0;
}
