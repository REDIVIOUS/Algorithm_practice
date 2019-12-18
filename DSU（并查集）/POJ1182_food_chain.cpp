#include <iostream>
#define N 50010
using namespace std;

//�������鼯����root����ʾ��ǰ��͸��ڵ��Ƿ��жϹ���ϵ�� 
//������ϵ����relation��0Ϊ����ͬ�࣬1Ϊ���ڵ�Ըýڵ㣬2Ϊ�ýڵ�Ը��ڵ� 
int root[N];
int relation[N];
int sum=0; //������� 
int n,k; //���������������� 
int d,x,y; //˵����x���y���� 

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
		relation[v]=(relation[v]+relation[u])%3; 
		return root[v]; //���ظ��ڵ� 		
	} 
}

//�ϲ�a��b���ڵļ��� 
void unionroot(int x, int y, int d){
	int rootx=findroot(x);
	int rooty=findroot(y);
	//����Ѿ��ϲ������´����ϵ 
	if(rootx==rooty){
		//���x��yΪͬ�࣬�Ƚϸ��ڵ� 
		if(d==1&&relation[x]!=relation[y]){
			sum++;
		}
		//���x��y���Ƚϸ��ڵ� 
		if(d==2){
			if(relation[x]==0&&relation[y]!=1){
				sum++;
			}
			else if(relation[x]==1&&relation[y]!=2){
				sum++;
			}
			else if(relation[x]==2&&relation[y]!=0){
				sum++;
			}
		}
	}
	else{
		//û�кϲ���ϲ�
		root[rooty]=rootx; //��rooty�ϲ�
		relation[rooty]=(relation[x]-relation[y]+3+d-1)%3;
	}
}

int main(){
	scanf("%d %d",&n,&k);
	int i;
	//��ʼ�����鼯�͹�ϵ���� 
	for(i=1;i<=n;i++){
		root[i]=i;
		relation[i]=0; 
	} 
	for(i=0;i<k;i++){
		scanf("%d %d %d",&d,&x,&y);
		//x��y����x��y��N�� 
		if(x>n||y>n||(d==2&&x==y)){
			sum=sum+1;
			continue; 
		}
		else{
			unionroot(x,y,d);
		}
	}
	printf("%d\n",sum);
	return 0;
} 
