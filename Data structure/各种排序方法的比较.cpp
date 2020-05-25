#include<stdio.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;

int Numberlookups[6] = {0};
int Numbermoves[6] = {0};

//�������飬ÿ��100�������
void generateRandomNumbers(int testData[]) {
	for(int j = 0 ; j < 500 ; j++) {
		testData[j] = rand()%100+1;
	}

}

//ð������
void bubbleSort3(int testData[],int len) {
	//һ����������
	for(int j = 0; j< len-1; j++) {
		//�����ж��Ƿ���������
		bool exchange = false;
		for(int i = 0; i<len-1; i++) {
			if(testData[i] > testData[i+1]) {
				Numberlookups[0] += 1;
				//�������������exchangeΪ true
				exchange = true;
				//������Ԫ��
				swap(testData[i],testData[i+1]);
				Numbermoves[0] += 3;
			}
		}
		//����˴�ɨ��û�з�������������˵�������Ѿ��������
		if(exchange == false) {
			break;
		}
	}
}

//��������
void insertionSorting(int testData[],int len) {
	for(int i = 1,j; i<len; i++) {
		//ǰһ��Ԫ�رȺ�һ��Ԫ�ش�
		if(testData[i-1] > testData[i]) {
			Numberlookups[1] += 1;
			int temp = testData[i];
			//��ǰһ��Ԫ��λ�ÿ�ʼ,��δ����ͷ�ҵ�ǰλ��Ԫ�ش��ڴ�����Ԫ��temp
			for(j = i-1; j >= 0 && temp < testData[j]; j--) {
				//����Ԫ����������ƶ�
				testData[j+1] = testData[j];
				Numbermoves[1] += 1;
			}
			//�˴�����Ϊ���������Ŀ�(�˳�ѭ��ʱj����1)
			testData[j+1] = temp;
		}
	}

}

//ѡ������
void selectionSort (int testData[],int len) {

	for(int i=0; i < len-1; i++) {
		//��ʼ��׼��Ϊ��ͷԪ��λ��
		int index = i;
		//����֮������Ԫ��
		for(int j = i+1; j <= len-1; j++) {
			//���ĳλ��Ԫ��С�ڻ�׼λ��Ԫ��
			if(testData[j] < testData[index]) {
				Numberlookups[2]+=1;
				//���»�׼��
				index = j;
			}
		}
		//�����׼�벻�ǿ�ʼ���Ǹ�,˵����λ�õ�Ԫ����С
		if(index!=i) {
			//����С��Ԫ�ؽ�������ʼλ��
			swap(testData[i],testData[index]);
			Numbermoves[2]+=3;
		}
	}
}

//��������
void quicksort(int testData[],int left,int right) {

	//index��ʾ������Ԫ�ص�λ��
	int index = left;
	//�趨��׼Ԫ��,Ĭ�ϻ�׼λ��Ϊ�����λ��
	int pivotElement = testData[left];
	//������׼λ��֮�������Ԫ��
	for(int i = left+1 ; i<= right ; i++) {
		//�����Ԫ�رȻ�׼Ԫ��С
		if(testData[i]< pivotElement) {
			Numberlookups[3]++;
			//������λ������
			index++;
			//���������λ�����λ�ò��غ�
			if(index != i) {
				swap(testData[i],testData[index]);
				Numbermoves[3]+=3;
			}
		}
	}
	//��׼Ԫ�ؾ�λ,��׼λλindex
	testData[left] = testData[index];
	testData[index] = pivotElement;
	if(left < right) {
		//�����Ԫ��Ҳ����ͬ������
		quicksort(testData,left,index-1);
		//���Ҳ�Ԫ��Ҳ����ͬ������
		quicksort(testData,index+1 ,right);
	}

}

//ϣ������
void shellSort(int testData[],int len) {
	//��������
	for(int gap = len/2; gap > 0; gap /= 2) {
		//���forѭ������ǰ���ֱ�Ӳ�������
		for(int i = gap,j; i < len; i++) {
			Numberlookups[4]++;
			int temp = testData[i];
			//ѭ����ӡ�����ÿ��Ԫ��
			for(j = i-gap; j>=0 && temp<testData[j]; j-=gap) {
				testData[j+gap] = testData[j];
				Numbermoves[4]++;
			}
			testData[j+gap ]= temp;
			Numbermoves[4]++;
		}
	}

}

//����ΪС���Ѻ���
void siftDown(int testData[],int start,int end) {
	int parent = start;
	int child = 2*parent+1;
	//temp�ݴ��������ڵ�
	int temp = testData[parent];
	//�������ӱ��δ���յ�
	while(child < end) {
		//����Ҷ��ӱ������С
		if(child+1 < end && testData[child] < testData[child+1]) {
			//child��Ϊ�Ҷ���
			Numberlookups[5]++;
			++child;
		}
		// ������ڵ�ȶ��ӽڵ�С,����Ҫ����
		if(temp >= testData[child]) {
			Numberlookups[5]++;
			break;
		}
		//������������Ӻ�˫�׵�λ��

		Numberlookups[5]++;
		testData[parent] =  testData[child];
		//�������Ʊ�Ϊ˫��
		parent = child;
		//���������
		child = 2*child+1;
	}
	//����˫�׵�ֵ
	testData[parent] = temp;

}

//��������
void heapSort(int testData[],int len) {
	for(int i =  (len-2)/2; i>=0 ; i-- ) {
		//����һ��С����
		siftDown(testData,i,len);
	}
	for(int i = len-1 ; i>0 ; i--) {
		//�����������һ��Ԫ��,
		swap(testData[0],testData[i]);
		Numbermoves[5]+=3;
		siftDown(testData,0,i);
	}
}


int main() {
	//��������
	int testData[500];
	//����ÿ����������Ԫ��˳��Ļָ����Ա�ѭ��ʹ��
	int testData1[500],testData2[500],testData3[500],testData4[500],testData5[500];
	//�趨���������
	//srand ((unsigned)time(NULL));
	//����5�鹲500�������
	generateRandomNumbers(testData);
	for(int i = 0 ; i < 500 ; i++) {
		testData1[i] = testData[i];
		testData2[i] = testData[i];
		testData3[i] = testData[i];
		testData4[i] = testData[i];
		testData5[i] = testData[i];
	}

	bubbleSort3(testData,500);
	insertionSorting(testData1,500);
	selectionSort(testData2,500);
	quicksort(testData3,0,500);
	shellSort(testData4,500);
	heapSort(testData5,500);

	cout<<"ð�������ѯ����Ϊ"<<Numberlookups[0]<<endl;
	cout<<"ð�������ƶ�����Ϊ"<< Numbermoves[0]<<endl;
	cout<<"���������ѯ����Ϊ"<<Numberlookups[1]<<endl;
	cout<<"���������ƶ�����Ϊ"<< Numbermoves[1]<<endl;
	cout<<"ѡ�������ѯ����Ϊ"<<Numberlookups[2]<<endl;
	cout<<"ѡ�������ƶ�����Ϊ"<< Numbermoves[2]<<endl;
	cout<<"���������ѯ����Ϊ"<<Numberlookups[3]<<endl;
	cout<<"���������ƶ�����Ϊ"<< Numbermoves[3]<<endl;
	cout<<"ϣ�������ѯ����Ϊ"<<Numberlookups[4]<<endl;
	cout<<"ϣ�������ƶ�����Ϊ"<< Numbermoves[4]<<endl;
	cout<<"�������ѯ����Ϊ"<<Numberlookups[5]<<endl;
	cout<<"�������ƶ�����Ϊ"<< Numbermoves[5]<<endl;
	cout<<endl;

}
