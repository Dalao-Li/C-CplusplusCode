#include<stdio.h>
#include<iostream>
#include<stdlib.h>
typedef char ElemType;
typedef struct Tree {
	ElemType data;
	Tree *leftSon;
	Tree *rightSon;
} Tree,*TreeList;

//���ĳ�ʼ��
TreeList initTree(TreeList root) {
	root->leftSon = NULL;
	root->rightSon = NULL;
	return root;
}

//���Ľ���
//      A
//     / \
//    B   C
//   / \
//  D   E
//������һ����  ABD##E##C##
TreeList creatTree(TreeList &root) {

	ElemType elem;
	scanf("%c",&elem);
	if(elem!='#') {
		root = (TreeList)malloc(sizeof(Tree));
		root->data = elem;
		root->leftSon = creatTree(root->leftSon);
		root->rightSon = creatTree(root->rightSon);
	}
	return root;
}

//LDR        D B E A C
void inOrderTree(TreeList &root) {
	if(root!=NULL) {

		inOrderTree(root->leftSon);
		printf("%c ",root->data);
		inOrderTree(root->rightSon);
	}
}

//ͳ��Ҷ�ӽڵ����
int sumOfLeaves(TreeList &root) {
	if(root==NULL) {
		return 0;
	} else if(root->leftSon==NULL&&root->rightSon==NULL) {
		return 1;
	} else {
		return sumOfLeaves(root->leftSon)+sumOfLeaves(root->rightSon);
	}
}

//ͳ�ƽڵ�ĸ���
int sumOfNode(TreeList &root) {
	if(root==NULL) {
		return 0;
	} else {
		return sumOfNode(root->leftSon)+sumOfNode(root->rightSon)+1;
	}
}

//�����������
int deepOfTree(TreeList &root) {
	return max(deepOfTree(root->leftSon),deepOfTree(root->rightSon))+1;
}


//ͳ�Ƹ���Ҷ�ӵ����ڵ�ľ���
void  distanceFromRoot(TreeList &root,int sum) {
	if(root->leftSon==NULL&&root->rightSon==NULL) {
		std::cout<<sum;
		sum=0;
	} else {
		distanceFromRoot(root->leftSon,sum+1);
		distanceFromRoot(root->rightSon,sum+1);
	}
}


int main() {
	TreeList root;

	creatTree(root);
	inOrderTree(root);
	printf("\n");
	printf("��Ҷ�ܸ���Ϊ��%d\n",sumOfLeaves(root));
	distanceFromRoot(root,0);
	printf("�ڵ��ܸ���Ϊ��%d\n",sumOfNode(root));
	printf("�������Ϊ��%d\n",deepOfTree(root));
	return 0;
}
