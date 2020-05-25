#include<iostream>
#include<string>
#define MAXVERTICES 20
#define MAXWEIGHT 100
using namespace std;

typedef char TypeElement;
typedef struct {
	//ͼ��ʵ���ܶ�����
	int sumVertices;
	//ͼ��ʵ���ܱ���
	int sumEdges;
	//�����
	TypeElement verticesList[MAXVERTICES];
	//�ڽӾ���
	int adjacentMatrix[MAXVERTICES][MAXVERTICES];
	//������ʾ��ĳ�����Ƿ�ѡ��
	bool isExchanged[MAXVERTICES];
} Graph;

//����ĳ���ڶ�����е�λ��,�������򷵻�-1
int getPositionInVerticesList(Graph & G,TypeElement val) {
	for(int i = 0; i<G.sumVertices ; i++) {
		if(G.verticesList[i] == val) {
			return i;
		}
	}
	return -1;
}

//����ĳ������ĵ�һ���ڽӶ���,����Ϊ�����ڶ�����е�λ��
int findFirstNeighborVertex(Graph &G , int vertexPosition) {
	//���λ�úϷ�
	if(vertexPosition != -1) {
		//���������
		for(int j = 0; j<G.sumVertices ; j++) {
			//�ҵ�һ���Ϸ����ڽӵ�
			if(G.adjacentMatrix[vertexPosition][j] > 0 && G.adjacentMatrix[vertexPosition][j] <MAXWEIGHT) {
				//���ظ��ڽӵ��λ��
				return j;
			}
		}
	}
	return -1;
}

//�ҳ�һ�������һ���ڽӶ���֮�����һ���ڽӶ���
int findNextNeighborVertex(Graph &G , int vertexPosition1, int vertexPosition2) {
	if(vertexPosition1 != -1 && vertexPosition2 != -1) {
		//ֱ�Ӵ� vertexPosition2 + 1�ж�, ��ΪvertexPosition2֮ǰ�ĵ�϶��������ڽӵ�
		for(int j = vertexPosition2 + 1 ; j< G.sumVertices ; j++ ) {
			if(G.adjacentMatrix[vertexPosition1][j] >0 && G.adjacentMatrix[vertexPosition1][j] < MAXWEIGHT ) {
				return j;
			}
		}
	}
	return -1;
}

//��ʼ��ͼ����,n,e���������ͱ���
void createGraph(Graph &G,int n,int e) {
	G.sumVertices = n;
	G.sumEdges = e;
	for(int i = 0 ; i<G.sumVertices ; i++) {
		//��Ǹõ�Ϊδѡ״̬
		G.isExchanged[i] == false;
		TypeElement val;
		cout<<"�����붥��ֵ"<<endl;
		//���붥��ֵ
		cin>>val;
		//���¶����
		G.verticesList[i] = val;
		for(int j = 0 ; j< G.sumVertices ; j++) {
			//�Խ���ֵΪ0
			if(i == j) {
				G.adjacentMatrix[i][j] = 0;
			} else {
				G.adjacentMatrix[i][j]= MAXWEIGHT;
			}
		}
	}
	//��ʼ��ÿһ����
	for(int i = 0; i< G.sumEdges ; i++) {
		TypeElement e1,e2;
		int weight;
		//��������ߵ��������Ȩֵ
		cout<<"��������ߵ��������Ȩֵ"<<endl;
		cin>>e1>>e2>>weight;
		//��ȡ���������ڶ�����е�����
		int position1 = getPositionInVerticesList(G,e1);
		int position2 = getPositionInVerticesList(G,e2);
		//�����ڽӾ���
		G.adjacentMatrix[position1][position2] = weight;
		G.adjacentMatrix[position2][position1] = weight;
	}
}

//���ҽڵ�
TypeElement getTypeElement(Graph &G , int vertexPosition) {
	if(vertexPosition != -1) {
		return G.verticesList[vertexPosition];
	}
}

//����ͼ,�β�Ϊ�ʼ�����Ľڵ�λ��
void dfs(Graph &G,int vertexPosition) {
	cout<<"->"<<getTypeElement(G,vertexPosition);
	//��Ǹ�λ��Ϊ��ѡ
	G.isExchanged[vertexPosition] = true;
	// firstNeighborVertex��ʾvertexPosition�ĵ�һ���ڽӵ�
	int neighborPosition = findFirstNeighborVertex(G,vertexPosition);
	//��vertexPosition���ڽӵ����ʱ
	while (neighborPosition != -1 ) {
		//����õ�û�б�ѡ��
		if(G.isExchanged[neighborPosition] == false) {
			//�ݹ���� ��һ���ڽӵ�
			dfs(G,neighborPosition);
		}
		//����ȡ vertexPosition ����һ���ڽӵ� neighborPosition
		neighborPosition =  findNextNeighborVertex(G,vertexPosition,neighborPosition);
	}
}

//��vertexPosition�����·��
void theShortestPath(Graph &G,int vertexPosition,int distance[],int path[]) {
	//���·�����㼯��
	int isGetShortestPath[MAXVERTICES];
	for(int i = 0 ; i<G.sumVertices ; i++) {
		//·�����������ʼ��,��ֵΪvertexPosition������ÿ����ľ���
		distance[i] = G.adjacentMatrix[vertexPosition][i];
		//��ʾ����i�Ƿ�������·��
		isGetShortestPath[i] =0;
		//�����vertexPosition��i�б�,path[i]Ϊ�ñ�ʼ�����vertexPosition
		if(i != vertexPosition && distance[i] < MAXWEIGHT) {
			path[i] = vertexPosition;
		}
		//��û�б���path[i]Ϊ-1
		else {
			path[i] = -1;
		}
	}
	//����vertexPosition���뼯��isGetShortestPath
	isGetShortestPath[vertexPosition] = 1;
	distance [vertexPosition] = 0;
	//������isGetShortestPath��������������·��
	for(int i = 0; i < G.sumVertices -1; i++) {
		int min  = MAXWEIGHT;
		//ѡ���� isGetShortestPath�о������·���Ķ���point
		int point = vertexPosition;
		for(int j = 0 ; j< G.sumVertices ; j++) {
			//����õ�jû�б�ѡ���Ҵ�vertexPosition���õ�ľ���С��min
			if(!isGetShortestPath[j] && distance[j] < min ) {
				//����λ��
				point = j;
				//�������·��
				min = distance[j];
			}
		}
		//������point����isGetShortestPath����
		isGetShortestPath[point] = 1;
		//�޸ľ���point�����������·������
		for(int k = 0 ; k< G.sumVertices ; k++) {
			//weightΪ��point����k�ľ���
			int weight = G.adjacentMatrix[point][k];
			/* �����kδ��ѡ��
			�� ��point����k�б�
			�� vertexPosition����k�ľ����vertexPosition����point����k�ľ��볤*/
			if(!isGetShortestPath[k] && weight < MAXWEIGHT && distance[point] + weight < distance[k]) {
				//vertexPosition����k�ľ���·����������
				distance[k] = distance[point] + weight;
				// vertexPosition����k��ǰһ������Ϊpoint
				path[k] = point;
			}
		}
	}
}

//ͼ�Ĳ���(����һ����)
void insertGraphEdge(Graph &G,int point1,int point2,int weight) {
	if(point1 != -1 && point2 !=- 1) {
		//�ڽӾ�������Ӹñ�
		G.adjacentMatrix[point1][point2] = weight;
		G.adjacentMatrix[point2][point1] = weight;
	}
}

//ͼ�Ĳ���(����һ������)
void insertGraphVertice(Graph &G,TypeElement val) {
	if(G.sumVertices<MAXVERTICES) {
		//�ܽڵ�����1
		G.sumVertices++;
		//���½ڵ�
		G.verticesList[G.sumVertices] = val;
	}

}

//ɾ��һ����
void deleteGraphEdeg(Graph &G,int point1,int point2) {
	//����ߵĹ�ϵ
	if(point1 != -1 && point2 !=- 1) {
		G.adjacentMatrix[point1][point2] = MAXWEIGHT;
		G.adjacentMatrix[point1][point2] = MAXWEIGHT;
	}
}


//ɾ��һ���������Ӧ�ı�
void deleteGraphVetric(Graph &G,TypeElement val) {
	//�ҵ��õ��λ��
	int position = getPositionInVerticesList(G,val);
	//�����������������һλ��ȥ
	int temp = G.verticesList[G.sumVertices];
	G.verticesList[G.sumVertices] = G.verticesList[position];
	G.verticesList[position] = temp;
	//ת���ߵĹ�ϵ
	for(int j = 0 ; j< G.sumVertices ; j++) {
		G.adjacentMatrix[position][j] = MAXWEIGHT;
		G.adjacentMatrix[j][position] = MAXWEIGHT;
	}
	G.adjacentMatrix[position][position] = 0;
	//�ܶ�������1
	G.sumVertices--;
}



int main() {
	Graph G;
	createGraph(G,4,5);
	for(int i = 0 ; i< G.sumVertices ; i++) {
		for(int j = 0 ; j <G.sumVertices ; j++) {
			printf("%4d ",G.adjacentMatrix[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	dfs(G,2);
	cout<<endl;
	for(int i = 0 ; i<G.sumVertices ; i++) {
		G.isExchanged[i] == false;
	}
	int distance[MAXVERTICES],path[MAXVERTICES];
	theShortestPath(G,0,distance,path);
	for(int i = 0; i< G.sumVertices ; i++) {
		cout<<distance[i]<<endl;
	}
}
