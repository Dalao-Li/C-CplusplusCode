#include<iostream>
#define NULL 0
using namespace std;
struct Student {
	long num;
	string name;
	Student *next;
};
int main() {
	Student *head,*p,*p1,*p2;
	int n=0;
	cout<<"������ѧ����Ϣ (��������Ϣ����'0'��Ϊ����) "<<endl;
	p1=p2=new Student;
	cin>>p1->num>>p1->name;
	head=NULL;
	while(p1->num!=0) {
		n=n+1;
		if(n==1) {
			head=p1;
		} else {
			p2->next=p1;
		}
		p2=p1;
		p1=new Student;
		cin>>p1->num>>p1->name;
	}
	p2->next=NULL;
	//���ѧ����Ϣ
	cout<<"ѧ������ϢΪ��"<<endl;
	p=head;
	if(head!=NULL) {
		do {
			cout<<p->num<<" "<<p->name<<endl;
			p=p->next;
		} while(p!=NULL);
	}
	return 0;
}
