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
		//����Ѱ�Ҹ��ڵ�ʱ�����¹�ϵ 
		relation[v]=(relation[v]+relation[root[v]]+3)%3; 
		//���¸��ڵ� 
		int R=findroot(root[v]); //�ݹ���� 
		root[v]=R; //���ظ��ڵ�
		return R; 		
	} 
}

//�ϲ�a��b���ڵļ��� 
bool unionroot(int x, int y, int d){
	int rootx=findroot(x);
	int rooty=findroot(y);
	//����Ѿ��ϲ������´����ϵ 
	if(rootx==rooty){
		//���x��yΪͬ�࣬�Ƚϸ��ڵ� 
		if(d==1&&relation[x]!=relation[y]){
			return false;
		}
		//���x��y���Ƚϸ��ڵ� 
		if(d==2){
			if(relation[x]==0&&relation[y]!=2){
				return false;
			}
			else if(relation[x]==1&&relation[y]!=0){
				return false;
			}
			else if(relation[x]==2&&relation[y]!=1){
				return false;
			}
		}
		return true;
	}
	//û�кϲ���ϲ�
	root[rooty]=rootx; //��rooty�ϲ�
	relation[rooty]=(relation[x]-relation[y]+3+d)%3;
	return true;
}

int main(){
	cin>>n>>k;
	//��ʼ�����鼯�͹�ϵ���� 
	for(int i=1;i<=n;i++){
		root[i]=i;
		relation[i]=0; 
	} 
	for(int i=0;i<k;i++){
		cin>>d>>x>>y;
		//x��y����x��y��N�� 
		if(x>n||y>n||(d==2&&x==y)){
			sum=sum+1;
			continue; 
		}
		if(unionroot(x,y,d)==false){
			sum=sum+1;
		} 
	}
	cout<<sum<<endl;
	return 0;
} 
