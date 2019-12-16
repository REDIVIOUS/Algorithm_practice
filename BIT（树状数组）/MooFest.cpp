#include <iostream>
#include <utility>
#include <algorithm>
#define lowbit(x) ((x)&(-x)) 
#define N 20005
using namespace std;

//�ȶ�������������Ȼ��������С��������֤ÿ��ȡ�����������ֵ
//����ÿһ��������ʱ�򣬷�Ϊ����ֵ����С�ĺͱ����ģ�ȡ�����ֵ֮�� 

pair<int,int> x_axis[N]; //�洢ÿ�������Ӧ������
int c[2][N]; //�洢��״����ͣ�2��Ҫ�洢����״̬��ȡ�����0��ţ����1�� 

bool compare(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

//��״�����getsum����������ǰx�������ĺ�
int getsum(int x,int flag){
	int sum=0;
	for(int i=x;i>0;i=i-lowbit(i)){
		sum=sum+c[flag][i]; //����c[i]���ۼ������ 
	}
	return sum; 
} 

//����x����������v������c[i] 
void update(int x,int add, int flag){
	for(int i=x;i<=N;i=i+lowbit(i)){
		c[flag][i]=c[flag][i]+add; //���º�x�������йص�����c[i] 
	}
}

int main(){
	int n;
	cin>>n;
	int x,v,sum=0;
	for(int i=1;i<=n;i++){ //��ȡ 
		cin>>v>>x;
		x_axis[i].first=x;
		x_axis[i].second=v;
	}
	sort(x_axis+1,x_axis+n+1,compare); // ������������
	int left,right,total=0; //�ֱ��¼��ǰ��������ߺ��ұߵľ���֮�� 
	for(int i=1;i<=n;i++){
		int cx=x_axis[i].first; //��ǰ���� 
		int cv=x_axis[i].second; //��ǰ 
		total=total+cx; //��ǰ����֮��
		update(cx,1,1); //��ǰţ������һ 
		update(cx,cx,0); //��ǰ����� 
		int leftnum=getsum(cx,1); //������� 
		int leftsum=getsum(cx,0); //��߾����
		left=leftnum*cx-leftsum; //��߾���� 
		right=total-leftsum-(i-leftnum)*cx; //�ұ߾����
		sum=sum+(left+right)*cv;
	}
	cout<<sum<<endl;
	return 0;
}
