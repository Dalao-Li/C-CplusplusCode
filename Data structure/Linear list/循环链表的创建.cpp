
#include<stdio.h>
#include<stdlib.h>

//����һ���ṹ��,���ݳ�ԱΪ�Լ�������
typedef struct List {
	int num;
	int possward;
	struct List *next;
} Lnode,*Linklist;



//����������
Lnode *creatJosephList(const int n) {
	//������һ���ڵ�
	Linklist pFirst;
	pFirst=(Linklist)malloc(sizeof(Lnode));
	//����ýڵ������
	scanf("%d",&pFirst->possward);
	pFirst->num=1;
	pFirst->next=NULL;
	//tail����β�ڵ�
	Linklist p,tail;
	//������β�ڵ�ָ���׽ڵ�
	tail=pFirst;
	for(int i=1; i<n; i++) {
		p=(Linklist)malloc(sizeof(Lnode));
		p->num=i+1;
		//����ýڵ������
		scanf("%d",&p->possward);
		//���ӵ�ǰһ�ڵ�
		p->next=NULL;
		tail->next=p;
		tail=p;
	}
	tail->next=pFirst;
	return pFirst;
}

void ouputList(Linklist &pFirst,int n) {
	Linklist p;
	p=pFirst;
	for(int i=0; i<3; i++) {
		for(int j=0; j<n; i++) {
			printf("%d->",p->possward);
			p=p->next;
		}
	}
}

int main() {
	Linklist pFirst;
	int n;
	scanf("%d",&n);
	pFirst=creatJosephList(n);
	/*int index,e;
	scanf("%d%d",&index,&e);
	insertList(head,index,e);*/
	ouputList(pFirst,n);
	return 0;
}
