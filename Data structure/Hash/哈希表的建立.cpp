#include<stdio.h>
#include<iostream>
#include<malloc.h>
//��ϣ���
#define HASH_TABLE_LENGTH 50
//����������
#define NAME_MAX_TOTAL 30
//����
#define M 47
using namespace std;
typedef struct {
	//�û�������
	string name;
	//����������Ӧ�Ĺؼ���
	int keyword;
} NameList ;
 

typedef struct {
	NameList nameUnit;
	//���Ҵ���
	int LookupsNumber;
} HashTable ;

void initializeNameList(NameList nameUnit[]) {
	nameUnit[0].name = "Addison";
	nameUnit[1].name = "Albert";
	nameUnit[2].name = "Alfred";
	nameUnit[3].name = "Barton";
	nameUnit[4].name = "August";
	nameUnit[5].name = "Charles";
	nameUnit[6].name = "Paul";
	nameUnit[7].name = "Georg";
	nameUnit[8].name = "Michael";
	nameUnit[9].name = "Elizabeth";
	nameUnit[10].name = "Kate";
	nameUnit[11].name = "Sarah";
	nameUnit[12].name = "Tiffany";
	nameUnit[13].name = "Nancy";
	nameUnit[14].name = "Thomas";
	nameUnit[15].name = "Jack";
	nameUnit[16].name = "Clark";
	nameUnit[17].name = "Johnson";
	nameUnit[18].name = "Tayler";
	nameUnit[19].name = "Hugo";
	nameUnit[20].name = "Gino";
	nameUnit[21].name = "Gavin";
	nameUnit[22].name = "Garfield";
	nameUnit[23].name = "Frank";
	nameUnit[24].name = "Bob";
	nameUnit[25].name = "Anthony";
	nameUnit[26].name = "Alva";
	nameUnit[27].name = "Jesse";
	nameUnit[28].name = "Isaac";
	nameUnit[29].name = "Harrison";
	for(int i = 0 ; i<NAME_MAX_TOTAL ; i++) {
		//sum����������ָ��ַ���ASCLL��ֵ֮��
		int sum = 0;
		for(int j = 0 ; j< nameUnit[i].name.size() ; j++) {
			sum += nameUnit[i].name[j];
		}
		//���¹ؼ���
		nameUnit[i].keyword = sum;
	}
}

//������ϣ�� , mΪɢ�к����еı�����
void creatHashTable(HashTable hashUnit[], NameList nameUnit[]) {
	//��ϣ���ʼ��
	for(int i = 0 ; i < HASH_TABLE_LENGTH ; i++) {
		hashUnit[i].nameUnit.name = "";
		hashUnit[i].nameUnit.keyword = 0;
		hashUnit[i].LookupsNumber = 0;
	}

	//������ϣ��
	//����ÿһ��������Ԫ,�����ǲ��뵽��ϣ����ȥ
	for(int  i = 0 ; i<NAME_MAX_TOTAL ; i++) {
		//initialAddress�����������Ԫ��������ַ,��ֵΪ������Ԫ�Ĺؼ���keyword % m
		int initialAddress = nameUnit[i].keyword % M;
		//ultimaAddress���������մ����ַ,��ʼʱ����ַ���
		int ultimaAddress =  initialAddress;
		//�����ϣ���ϸ������ַ�ϵĲ��Ҵ���Ϊ0,˵����λ�ò�δ����ؼ���
		if(hashUnit[initialAddress].LookupsNumber == 0) {
			//����������Ԫ�Ĺؼ�������ϣ��
			hashUnit[initialAddress].nameUnit.keyword = nameUnit[i].keyword;
			//���¹�ϣ���ϸ�λ�õ�����
			hashUnit[initialAddress].nameUnit.name = nameUnit[i].name;
			//�ùؼ���Ĳ��Ҵ���Ϊ1
			hashUnit[initialAddress].LookupsNumber = 1;
		}
		//����˵��������"��ͻ"
		else {
			////����̽�ⷨ�����ͻ,sum�����ܲ��Ҵ���
			int sum = 0;
			//������λ���ϵĹؼ��벻Ϊ��ʱ����̽��
			do {
				ultimaAddress = (ultimaAddress + 1) % HASH_TABLE_LENGTH;
				sum++;
			} while(hashUnit[ultimaAddress].nameUnit.keyword != 0);
			//�ҵ�����λ��֮��,���¹�ϣ���ϵĹؼ�������
			hashUnit[ultimaAddress].nameUnit.keyword = nameUnit[i].keyword;
			hashUnit[ultimaAddress].nameUnit.name =  nameUnit[i].name;
			//���²��Ҵ���
			hashUnit[ultimaAddress].LookupsNumber = sum + 1;
		}
	}
}

//����ASLֵ
double averageSearchLength(HashTable hashUnit[]) {
	double sum = 0;
	for(int i = 0 ; i<HASH_TABLE_LENGTH ; i++) {
		//�ۼӲ��Ҵ�����Ϊ0����
		if(hashUnit[i].LookupsNumber != 0) {
			sum += hashUnit[i].LookupsNumber;
		}
	}
	return sum/NAME_MAX_TOTAL;
}

void disPlay(HashTable hashUnit[]) {
	cout << "���" << "\t" << "�ؼ���" << "\t\t" <<
	     "��������" << "\t" << "H(key)" << "\t\t" << "����" << endl;
	for (int i = 0; i<HASH_TABLE_LENGTH; i++) {
		cout << i << "\t" << hashUnit[i].nameUnit.keyword << "\t\t" << hashUnit[i].LookupsNumber << "\t\t"
		     << (hashUnit[i].nameUnit.keyword) % M << "\t\t" << hashUnit[i].nameUnit.name << endl;
	}
}


int main() {
	
	HashTable hashUnit[HASH_TABLE_LENGTH];
	NameList nameUnit[30]; 
	initializeNameList(nameUnit);
	creatHashTable(hashUnit,nameUnit);
	disPlay(hashUnit);
	cout<<averageSearchLength(hashUnit)<<endl;
}
