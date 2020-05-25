#include<iostream>
#include<string.h>
#define MAX_SIZE 26
#define LENGTH 6
using namespace std;

//���Խ��й���������
int code[20];

string huffman[LENGTH];

typedef struct logSheet {
	char character[MAX_SIZE];
	int occurrenceNumber[MAX_SIZE];
    
} logSheet;



typedef struct Tree {
	int data;  //���������нڵ��Ȩֵ
	Tree * leftChild;
	Tree * rightChild;
} Tree,*TreeList;

TreeList createTree(logSheet sheet) {
	//����һ��ָ��������������ڵ���Ϣ
	TreeList leaves[LENGTH];
	TreeList leaf;
	//����һ���ڵ���Ϊ���������ĸ��ڵ�
	TreeList root = NULL;
	for (int i = 0; i < LENGTH; i++) { //��ʼ���ṹ��ָ������,������ÿһ��Ԫ��Ϊһ���ṹ��ָ������
		leaf = new Tree;

		leaf->data = sheet.occurrenceNumber[i];
		leaf->leftChild = leaf->rightChild = NULL;
		leaves[i] = leaf;
	}
	//���� n-1 ��ѭ��������������
	for(int i = 1; i < LENGTH; i++) {
		//min1��ʾɭ���о�����СȨֵ�����������±�,min2Ϊ����С���±�
		int min1 = -1, min2;
		for(int j = 0; j < LENGTH; j++) {
			if (leaves[j] != NULL && min1 == -1) {
				min1 = j;
				continue;
			}
			if (leaves[j] != NULL) {
				min2 = j;
				break;
			}
		}
		//��ָ�������е�ָ��ָ�����Сֵ��ֵ��������Ϊmin1��,��Сֵ��ֵ��������Ϊmin2��
		for (int j = min2; j < LENGTH; j++) {
			if(leaves[j] != NULL) {
				if(leaves[j]->data < leaves[min1]->data) {
					min2 = min1;
					min1 = j;
				} else if(leaves[j]->data < leaves[min2]->data) {
					min2 = j;
				}
			}
		}
		//����СȨֵ���ʹ���СȨֵ������һ������,rootָ���������
		root = new Tree;
		//�����½ڵ�Ȩֵ
		root->data = leaves[min1]->data + leaves[min2]->data;
		root->leftChild = leaves[min1];
		root->rightChild = leaves[min2];
		//��ָ��������ָ�븳��leavesָ��������min1λ��,��Լ�ռ�
		leaves[min1] = root;
		//min2λ��Ϊ��
		leaves[min2] = NULL;
	}
	return root;
}

//�ݹ���й����������뺯��
void huffmanCoding(TreeList &root,int len,logSheet sheet) {
	//������ڵ㲻Ϊ��
	if(root != NULL) {
		//����Ҷ�ӽڵ�
		if(root->leftChild == NULL && root->rightChild == NULL) {
			//ȷ��������һ���ַ��Ĺ�������
			int index;
			for(int i = 0; i<LENGTH; i++) {
				//����Ȩֵȷ���ַ�
				if(root->data == sheet.occurrenceNumber[i]) {
					index = i;
					break;
				}
			}
			for(int i = 0; i < len; i++) {
				//�������������
				huffman[index].push_back(code[i]+'0');
			}
		}
		//����������й���������Ĳ���
		else {
			//��߷�֧����Ϊ��
			code[len] = 0;
			huffmanCoding(root->leftChild,len+1,sheet);
			//�Ҳ��֧����Ϊ1
			code[len] = 1;
			huffmanCoding(root->rightChild,len+1,sheet);
		}
	}
}


//A3B9C5D12E6F15
int main() {
	int arr[LENGTH] = {3,9,5,12,6,15};
	char alph[LENGTH] = {'A','B','C','D','E','F'};
	
	logSheet sheet;
	
	for(int i = 0; i<LENGTH; i++) {
		sheet.character[i] = alph[i];
		sheet.occurrenceNumber[i] = arr[i];
	}
	
	//����ָ������������ڵ��ָ��
	TreeList root = createTree(sheet);
	
	//���й���������
	huffmanCoding(root,0,sheet);
	for(int i = 0; i<LENGTH; i++) {
		cout<<sheet.character[i]<<"�Ĺ�����������"<<huffman[i]<<endl;
	}
	return 0;
}
