#include <stdio.h>
#include <stdlib.h>
struct student {
	long num; /*ѧ��*/
	int score; /*�ɼ�*/
	struct student *next;
};

//����������ɴ�����������Ҫ�󲹳����ʵ�ֽ��ڶ�������ϲ�����һ������δβ�ĺ�����
struct student *merge(struct student *head, struct student *head1) {
	struct student *g_St;
	g_St=head;
	g_St->next=head1;
	head1->next=NULL;
	return g_St;

}

int main() {
	struct student *head=(struct student *)malloc(sizeof(struct student));
	struct student *head2=(struct student*)malloc(sizeof(struct student));
	scanf("%ld %d",&head->num,&head->score);
	scanf("%ld %d",&head2->num,&head2->score);
	merge(head,head2);
	printf("%ld %d\n",head->num,head->score);
	printf("%ld %d",head->next->num,head->next->score);
	return 0;
}
