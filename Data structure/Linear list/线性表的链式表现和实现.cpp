#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
} Lnode,*Linklist;

//��ʼ��
Lnode *initList(Linklist head) {
	head=(Linklist)malloc(sizeof(Lnode));
	head->next=NULL;
	return head;
}

//��巨��������
Lnode *inputList(Linklist &head,int n) {
	head->next=NULL;
	Linklist p,r;
	r=head;
	for(int i=0; i<n; i++) {
		p=(Lnode *)malloc(sizeof(Lnode));
		scanf("%d",&p->data);
		p->next=NULL;
		r->next=p;
		r=p;
	}
	return head;
}

//����
void getList(Linklist head,int index) {
	Linklist p;
	p=head->next;
	//jΪ�����������Լ�¼��ǰ��λ��
	int j=1;
	//��P��Ϊ����δ��ָ��λ��ʱ,ָ������ƶ�,����������
	while(p&&j<index) {
		p=p->next;
		++j;
	}
	if(!p||j>index) {
		return;
	}
	printf("%d\n",p->data);
}

//����
void insertList(Linklist &head,int index,int e) {
	Linklist p;
	p=head;
	//��������ʼֵΪ0�ǿ��ǵ��˿ձ�����
	int j=0;
	while(p&&j<index-1) {
		p=p->next;
		++j;
	}
	if(!p||j>index-1) {
		return;
	}
	Linklist s;
	s=(Linklist)malloc(sizeof(Lnode));;
	s->data=e;
	s->next=p->next;
	p->next=s;
}

//ɾ��
void insertList(Linklist &head,int index) {
	Linklist p;
	p=head;
	int j=0;
	while((p->next)&&j<index-1) {
		p=p->next;
		j++;
	}
	if(!p||j>index-1) {
		return;
	}
	Linklist q;
	q=p->next;
	p->next=q->next;
	free(q);
}

//
void ouputList(Linklist &head) {
	Linklist p;
	p=head->next;
	while(p) {
		printf("%d ",p->data);
		p=p->next;
	}
}

int main() {
	Linklist head;
	head=initList(head);
	int n;
	scanf("%d",&n);
	head=inputList(head,n);
	/*int index,e;
	scanf("%d%d",&index,&e);
	insertList(head,index,e);*/
	ouputList(head);
	return 0;
}
