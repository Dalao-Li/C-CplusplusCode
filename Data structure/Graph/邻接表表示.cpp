#include<stdio.h>
#include<iostream>
#define MAXVERTICES 20
#define MAXWEIGHT 100
using namespace std; 

typedef char TypeElement;
typedef struct Enode{
	int dest; //�ߵ���һ����λ�� 
	int weight;
	struct Enode *link; //��һ������ָ��
}EdgeNode;

typedef struct {
	TypeElement  data;  //��������� 
	struct Eonde *adj;  //�������ͷָ�� 
}VertexNode; 

typedef struct {
	VertexNode VerticesList[MAXVERTICES];
	//ͼ��ʵ���ܶ�����
	int sumVertices;
	//ͼ��ʵ���ܱ���
	int sumEdges;
}Algraph;

void creatAlgraph(Algraph &G,int n,int e){
	G.sumVertices = n;
	G.sumEdges = e;
	TypeElemen val,e1,e2;
	//��ʼ������� 
	for(int i = 0 ; i< G.sumVertices ; i++){
		cin>>val;
		G.VerticesList[i].data = val; //���¶������� 
		G.VerticesList.adj = NULL; 
	}
	for(int i = 0 ; i < G.sumEdges ;i++){
		
	}
}

