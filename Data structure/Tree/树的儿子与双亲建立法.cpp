#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define MAX 5
using namespace std;
typedef int ElemType;
typedef struct Tree {
	ElemType data;
	int parent;
	int leftSon;
	int rightSon;
} Tree,*TreeList;

//���ĳ�ʼ��
TreeList initTree(TreeList root) {
	root->leftSon = -1;
	root->rightSon = -1;
	return root;
}

//���Ľ���
//      12
//     / \
//    7   5
//   / \
//  1   4
//������һ����
TreeList creatTree(TreeList &root) {
	root = new Tree[MAX+1];
	for(int i = 0; i<MAX; i++) {
		root[i].leftSon = -1;
		root[i].rightSon = -1;
	}
	
	for(int i = 0; i<MAX; i++) {
		cin>>root[i].data;
		cout<<"�ڵ�ֵ:"<<root[i].data<<endl;
		//cin>>root[i].parent;
		cin>>root[i].leftSon;
		cout<<"����ӱ��:"<<root[i].leftSon<<endl;
		cin>>root[i].rightSon;	
		cout<<"�Ҷ��ӱ��:"<<root[i].rightSon<<endl;

	}
	
	for(int i = 0;i<MAX;i++){
		cout<<"�ڵ�ֵ:"<<root[i].data<<endl;
		cout<<"����ӱ��:"<<root[i].leftSon<<endl;
		cout<<"�Ҷ��ӱ��:"<<root[i].rightSon<<endl;
		
	}
	return root;
}

//LDR        D B E A C
void inOrderTree(TreeList &root,int n) {
	if(root[n].leftSon==-1&&root[n].rightSon==-1){
		return; 
	}
	else{
		inOrderTree(root,root[n].leftSon);
		cout<<root[n].data<<" ";
		inOrderTree(root,root[n].rightSon);
	}
}

int main(){
	TreeList root;
	root = creatTree( root);
	inOrderTree(root,4);
}
