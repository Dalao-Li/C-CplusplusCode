/*
	Name:ͨѶ¼
	Copyright:
	Author:
	Date: 15/04/18 09:09
	Description:
*/
#include<iostream>
#include<string>
#define N 1
using namespace std;
struct Message {
	string student_num_school;
	string student_name;
	string student_sex;
	string student_adress_home;
	string student_num_phone;
	string student_e_mail;
	float score[4];                                          /*score[0]��score[3]�ֱ�ָ����ѧ��Ӣ����Ρ�רҵ�εĳɼ�,sum_score��ʾ�ܳɼ�*/
	float sum_score=0;
	struct Message *next;
} mes[N];                                                    /*�����ṹ������mes[N]*/

int main() {
	void input_Information_Value(struct Message mes[]);
	void ouput_Information_Value(struct Message mes[]);
	void query_Information_Value(struct Message mes[]);
	void modify_Information_Value();
	struct Message mes[N],*head,*p=mes;
	while(1) {
		int first_colon;
		cout<<"                                            ���˵�                                          "<<endl;
		cout<<"============================================================================================"<<endl;
		cout<<"                *һ��Ŀ¼:1.������Ϣ  2.��ʾ��Ϣ  3.��ѯ��Ϣ  4.�޸���Ϣ  5.�˳�  *"<<endl;
		cout<<"============================================================================================"<<endl;
		cout<<"-------------------------------------һ����"<<N<<"λͬѧ����Ϣ------------------------------------"<<endl;
		cin>>first_colon;
		switch(first_colon) {
			case 1:
				input_Information_Value(p);
				break;
			case 2:
				ouput_Information_Value(p);
				break;
			case 3:
				query_Information_Value(p);
				break;
			case 4:
				modify_Information_Value();
				break;
			case 5:
				exit(0);                            /*��ֹ����*/
			default:
				cout<<"����������󣡣���"<<endl;
		}
	}
	return 0;
}

/*���뺯��*/
void input_Information_Value(struct Message mes[]) {
	int i,j;
	struct Message *p;
	for(i=0,p=mes; p<mes+N; p++,i++) {
		cout<<"��"<<i+1<<"λ��Ա��"<<endl;
		cout<<"�������"<<i+1<<"λ��Ա��ѧ�ţ�";
		cin>>p->student_num_school;
		cout<<"�������"<<i+1<<"λ��Ա��������";
		cin>>p->student_name;
		cout<<"�������"<<i+1<<"λ��Ա���Ա�";
		cin>>p->student_sex;
		cout<<"�������"<<i+1<<"λ��Ա�ļ�ͥסַ��";
		cin>>p->student_adress_home;
		cout<<"�������"<<i+1<<"λ��Ա�ĵ绰���룺";
		cin>>p->student_num_phone;
		cout<<"�������"<<i+1<<"λ��Ա�ĵ������䣺";
		cin>>p->student_e_mail;
		cout<<"�������"<<i+1<<"��ѧ������ѧ�ɼ���";
		cin>>p->score[0];
		cout<<"�������"<<i+1<<"��ѧ����Ӣ��ɼ���";
		cin>>p->score[1];
		cout<<"�������"<<i+1<<"��ѧ�������γɼ���";
		cin>>p->score[2];
		cout<<"�������"<<i+1<<"��ѧ����רҵ�γɼ���";
		cin>>p->score[3];
		for(j=0; j<4; j++) {
			p->sum_score=p->sum_score+p->score[j];
		}
	}
}

/*��ʾ����*/
void ouput_Information_Value(struct Message mes[]) {
	int i,number,third_colon,forth_colon,sign=1,wign=1;
	struct Message *head,*p;
	p=mes;
	/*��������*/
	head=p;                                                      /*����һ��Ԫ�صĵ�ַ����ͷָ����*/
	for(i=0; i<N-1; i++) {                                       /*���ν���һ��Ԫ�صĵ�ַ����ǰһ��Ԫ�ص�next��Ա��*/
		(p+i)->next=(p+i+1);
	}
	(p+N-1)->next=NULL;                                         /*���һ��Ԫ�ص�next�з���NULL*/
	cout<<"                                                          "<<endl;
	while(sign) {
		cout<<"---------------------------------------------------------------------------------------------------"<<endl;
		cout<<"       **����Ŀ¼����ʾ������  1.������Ϣ��ʾ  2.ȫ����Ϣ��ʾ  3.��ʾ�ɼ�  4.�˳���ʾ"<<endl;
		cout<<"---------------------------------------------------------------------------------------------------"<<endl;
		cin>>third_colon;
		switch(third_colon) {
			case 1:
				cout<<"����������ʾ����Ա����ţ�";
				cin>>number;
				if(number>N) {
					cout<<"���޴��ˣ����󣡣�����"<<endl;
				}
				break;
				if(number<=N) {
					cout<<"��"<<number<<"λ��Ա��ѧ��Ϊ��    "<<(p+number-1)->student_num_school<<endl;
					cout<<"��"<<number<<"λ��Ա������Ϊ��    "<<(p+number-1)->student_name<<endl;
					cout<<"��"<<number<<"λ��Ա���Ա�Ϊ��    "<<(p+number-1)->student_sex<<endl;
					cout<<"��"<<number<<"λ��Ա�ļ�ͥסַΪ��"<<(p+number-1)->student_adress_home<<endl;
					cout<<"��"<<number<<"λ��Ա�ĵ绰����Ϊ��"<<(p+number-1)->student_num_phone<<endl;
					cout<<"��"<<number<<"λ��Ա�ĵ�������Ϊ��"<<(p+number-1)->student_e_mail<<endl;
					cout<<"��"<<number<<"λ��Ա����ѧ�ɼ�Ϊ��"<<(p+number-1)->score[0]<<"��"<<endl;
					cout<<"��"<<number<<"λԱ��Ӣ��ɼ�Ϊ��"<<(p+number-1)->score[1]<<"��"<<endl;
					cout<<"��"<<number<<"λ��Ա�����γɼ�Ϊ��"<<(p+number-1)->score[2]<<"��"<<endl;
					cout<<"��"<<number<<"λ��Ա��רҵ�ɼ�Ϊ��"<<(p+number-1)->score[3]<<"��"<<endl;
					cout<<"��"<<number<<"λ��Ա���ܳɼ�Ϊ��  "<<(p+number-1)->sum_score<<"��"<<endl;
					cout<<"��"<<number<<"λ��Ա��ƽ���ɼ�Ϊ��"<<(p+number-1)->sum_score/4<<"��"<<endl;
					cout<<"                                                          "<<endl;
				}
				break;
			case 2:
				for(i=0; head!=NULL; i++) {
					cout<<"��"<<i+1<<"λ��Ա��ѧ��Ϊ��    "<<head->student_num_school<<endl;
					cout<<"��"<<i+1<<"λ��Ա������Ϊ��    "<<head->student_name<<endl;
					cout<<"��"<<i+1<<"λ��Ա���Ա�Ϊ��    "<<head->student_sex<<endl;
					cout<<"��"<<i+1<<"λ��Ա�ļ�ͥסַΪ��"<<head->student_adress_home<<endl;
					cout<<"��"<<i+1<<"λ��Ա�ĵ绰����Ϊ��"<<head->student_num_phone<<endl;
					cout<<"��"<<i+1<<"λ��Ա�ĵ�������Ϊ��"<<head->student_e_mail<<endl;
					cout<<"��"<<i+1<<"λ��Ա����ѧ�ɼ�Ϊ��"<<head->score[0]<<"��"<<endl;
					cout<<"��"<<i+1<<"λ��Ա��Ӣ��ɼ�Ϊ��"<<head->score[1]<<"��"<<endl;
					cout<<"��"<<i+1<<"λ��Ա�����γɼ�Ϊ��"<<head->score[2]<<"��"<<endl;
					cout<<"��"<<i+1<<"λ��Ա��רҵ�ɼ�Ϊ��"<<head->score[3]<<"��"<<endl;
					cout<<"��"<<i+1<<"λ��Ա���ܳɼ�Ϊ��  "<<head->sum_score<<"��"<<endl;
					cout<<"��"<<i+1<<"λ��Ա��ƽ���ɼ�Ϊ��"<<head->sum_score/4<<"��"<<endl;
					cout<<"                               "<<endl;
					head=head->next;                                      	/*headָ����һ�ڵ�*/
				}
				break;
			case 3:
				while(wign) {
					cout<<"      ***����Ŀ¼���鿴ȫ���˵ĵ��Ƴɼ�  1.��ѧ 2.Ӣ�� 3.���� 4.רҵ�ɼ� 5.�ܳɼ� 6.�˳�"<<endl;
					cout<<"      ----------------------------------------------------------------------------------"<<endl;
					cin>>forth_colon;
					switch(forth_colon) {
						case 1:
							for(i=0,p=mes; p<mes+N; p++,i++) {
								cout<<"��"<<i+1<<"λ��Ա����ѧ�ɼ�Ϊ��"<<p->score[0]<<"��"<<endl;
								cout<<"                                                  "<<endl;
							}
							break;
						case 2:
							for(i=0,p=mes; p<mes+N; p++,i++) {
								cout<<"��"<<i+1<<"λ��Ա��Ӣ��ɼ�Ϊ��"<<p->score[1]<<"��"<<endl;
								cout<<"                                                  "<<endl;
							}
							break;
						case 3:
							for(i=0,p=mes; p<mes+N; p++,i++) {
								cout<<"��"<<i+1<<"λ��Ա�����γɼ�Ϊ��"<<p->score[2]<<"��"<<endl;
								cout<<"                                                  "<<endl;
							}
							break;
						case 4:
							for(i=0,p=mes; p<mes+N; p++,i++) {
								cout<<"��"<<i+1<<"λ��Ա��רҵ�ɼ�Ϊ��"<<p->score[3]<<"��"<<endl;
								cout<<"                                                  "<<endl;
							}
							break;
						case 5:
							for(i=0,p=mes; p<mes+N; p++,i++) {
								cout<<"��"<<i+1<<"λ��Ա���ܳɼ�Ϊ��"<<p->score[4]<<"��"<<endl;
								cout<<"                                                "<<endl;
							}
							break;
						case 6:
							wign=0;
							break;
						default:
							cout<<"����������󣡣���"<<endl;
					}
				}
				break;
			case 4:
				sign=0;
				break;
			default:
				cout<<"����������󣡣���"<<endl;
		}
	}
}


/*��Ϣ��ѯ����*/
void query_Information_Value(struct Message mes[]) {
	struct Message *p=mes;
	string num_or_name;
	int colon,second_colon,third_colon,forth_colon,sign=1,i,k,max_score[4],max_sum;
	while(sign) {
		cout<<"����Ŀ¼  1.��ѧ�Ż��������� 2.��ѯ���ɼ�  3.������  4.�˳�"<<endl;
		cin>>third_colon;
		switch(third_colon) {
			case 1:
				cout<<"������������ѧ�ſ�ʼ����"<<" ";
				cin>>num_or_name;
				for(i=0; p<mes+N; p++,i++) {
					if((p->student_name==num_or_name)||(p->student_name==num_or_name)) {
						cout<<"��Ϊ��Ա�����Ϊ��"<<i+1<<endl;
						cout<<"��λ��Ա��ѧ��Ϊ��    "<<p->student_num_school<<endl;
						cout<<"��λ��Ա������Ϊ��    "<<p->student_name<<endl;
						cout<<"��λ��Ա���Ա�Ϊ��    "<<p->student_sex<<endl;
						cout<<"��λ��Ա�ļ�ͥסַΪ��"<<p->student_adress_home<<endl;
						cout<<"��λ��Ա�ĵ绰����Ϊ��"<<p->student_num_phone<<endl;
						cout<<"��λ��Ա�ĵ�������Ϊ��"<<p->student_e_mail<<endl;
						cout<<"��λ��Ա����ѧ�ɼ�Ϊ��"<<p->score[0]<<"��"<<endl;
						cout<<"��λ��Ա��Ӣ��ɼ�Ϊ��"<<p->score[1]<<"��"<<endl;
						cout<<"��λ��Ա�����γɼ�Ϊ��"<<p->score[2]<<"��"<<endl;
						cout<<"��λ��Ա��רҵ�ɼ�Ϊ��"<<p->score[3]<<"��"<<endl;
						cout<<"��λ��Ա���ܳɼ�Ϊ��  "<<p->sum_score<<"��"<<endl;
						cout<<"��λ��Ա��ƽ���ɼ�Ϊ��"<<p->sum_score/4<<"��"<<endl;
						cout<<"                                            "<<endl;
					} else if(i==N) {
						cout<<"δ��ѯ��ƥ��ļ�¼��"<<endl;
						break;
					}
				};
				break;
			case 2:
				max_sum=p->sum_score;
				for(i=0; i<5; i++) {
					max_score[i]=p->score[i];
				}
				while(sign) {
					cout<<"-------------------------------------------------------------------------------------------"<<endl;
					cout<<"        **����Ŀ¼:����������ֲ������ɼ��� 1.��ѧ 2.Ӣ�� 3.���� 4.רҵ�� 5.�ܳɼ� 6.�˳�"<<endl;
					cout<<"-------------------------------------------------------------------------------------------"<<endl;
					cin>>second_colon;
					switch(second_colon) {
						case 1:
							for(k=0,i=1; i<N; i++) {                  /*�ҳ���ѧ�����ɼ�*/
								if((p+i)->score[0]>=p->score[0]) {
									max_score[0]=(p+i)->score[0];
									k=i;
								}
							}
							cout<<"��ѧ��߳ɼ�Ϊ��"<<(p+k)->score[0]<<"��"<<endl;
							cout<<"����ѧ���ǣ�"<<(p+k)->student_name<<endl;
							cout<<"                                 "<<endl;
							break;
						case 2:
							for(k=0,i=1; i<N; i++) {                 /*�ҳ�Ӣ������ɼ�*/
								if((p+i)->score[1]>=max_score[1]) {
									max_score[1]=(p+i)->score[1];
									k=i;
								}
							}
							cout<<"Ӣ����߳ɼ�Ϊ��"<<(p+k)->score[1]<<"��"<<endl;
							cout<<"����ѧ���ǣ�"<<(p+k)->student_name<<endl;
							cout<<"                                 "<<endl;
							break;
						case 3:
							for(k=0,i=1; i<N; i++) {                   /*�ҳ����ε����ɼ�*/
								if((p+i)->score[2]>=max_score[2]) {
									max_score[2]=(p+i)->score[2];
									k=i;
								}
							}
							cout<<"������߳ɼ�Ϊ��"<<(p+k)->score[2]<<"��"<<endl;
							cout<<"����ѧ���ǣ�"<<(p+k)->student_name<<endl;
							cout<<"                                 "<<endl;
							break;
						case 4:
							for(k=0,i=1; i<N; i++) {                              /*�ҳ�רҵ�ε����ɼ�*/
								if((p+i)->score[3]>=max_score[3]) {
									max_score[3]=(p+i)->score[3];
									k=i;
								}
							}
							cout<<"רҵ����߳ɼ�Ϊ��"<<(p+k)->score[3]<<"��"<<endl;
							cout<<"����ѧ���ǣ�"<<(p+k)->student_name<<endl;
							cout<<"                                 "<<endl;
							break;
						case 5:
							for(k=0,i=1; i<N; i++) {                             /*�ҳ��ܳɼ�������*/
								if((p+i)->sum_score>=max_sum) {
									max_sum=(p+i)->sum_score;
									k=i;
								}
							}
							cout<<"�ܳɼ����Ϊ��"<<(p+k)->score[4]<<"��"<<endl;
							cout<<"����ѧ���ǣ�"<<(p+k)->student_name<<endl;
							cout<<"                                 "<<endl;
							break;
						case 6:
							sign=0;
							break;
						default:
							cout<<"����������󣡣���"<<endl;
					}
				}
				break;
			case 3:
				for(i=0,p=mes; p<mes+N; i++,p++) {
					cout<< "��"<<i+1<<"λ��Ա��"<<p->student_name<<endl;
				}
				break;
			case 4:
				sign=0;
				break;
			default:
				cout<<"����������󣡣���"<<endl;
		}
	}
}

/*�޸���Ϣ����*/
void modify_Information_Value() {
	string key1,key="123456";                            //�����޸�����
	struct Message *p;
	p=mes;
	int number,j,sign=1,k=3;
	cout<<"                                              "<<endl;
	while(sign) {                                        //�����޸�����,���δ���ֱ�ӽ�������
		cout<<"�������޸�����"<<" ";
		cin>>key1;
		if(key1==key) break;
		else {
			cout<<"��������㻹��������"<<k-1<<"��";
			k--;
			if(k==0) exit(0);
		}
	}
	cout<<"��������Ҫ�޸���Ϣ�ĳ�Ա��ţ�";              /*ȷ����������Χ*/
	while(sign) {
		cin>>number;
		if(number>N) {
			cout<<"��ѧ����Ϣ�����ڣ���������������"<<endl;
		} else break;
	}
	cout<<"�޸���Ϣ�ĳ�ԱΪ�ڣ�"<<number<<"λ"<<endl;
	cout<<"�����������λ��Ա��ѧ��: ("<<"ԭ����Ϊ��"<<(p+number-1)->student_num_school<<")"<<endl;
	cin>>(p+number-1)->student_num_school;
	cout<<"�����������λ��Ա��������("<<"ԭ����Ϊ��"<<(p+number-1)->student_name<<")"<<endl;
	cin>>(p+number-1)->student_name;
	cout<<"�����������λ��Ա���Ա�("<<"ԭ����Ϊ��"<<(p+number-1)->student_sex<<")"<<endl;
	cin>>(p+number-1)->student_sex;
	cout<<"�����������λ��Ա�ļ�ͥסַ��("<<"ԭ����Ϊ��"<<(p+number-1)->student_adress_home<<")"<<endl;
	cin>>(p+number-1)->student_adress_home;
	cout<<"�����������λ��Ա�ĵ绰���룺("<<"ԭ����Ϊ��"<<(p+number-1)->student_num_phone<<")"<<endl;
	cin>>(p+number-1)->student_num_phone;
	cout<<"�����������λ��Ա�ĵ������䣺("<<"ԭ����Ϊ��"<<(p+number-1)->student_e_mail<<")"<<endl;
	cin>>(p+number-1)->student_e_mail;
	cout<<"�����������λѧ������ѧ�ɼ���"<<"ԭ����Ϊ��"<<(p+number-1)->score[0]<<")"<<endl;
	cin>>(p+number-1)->score[0];
	cout<<"�����������λѧ����Ӣ��ɼ���("<<"ԭ����Ϊ��"<<(p+number-1)->score[1]<<")"<<endl;
	cin>>(p+number-1)->score[1];
	cout<<"�����������λѧ�������γɼ���("<<"ԭ����Ϊ��"<<(p+number-1)->score[2]<<")"<<endl;
	cin>>(p+number-1)->score[2];
	cout<<"�����������λѧ����רҵ�γɼ���("<<"ԭ����Ϊ��"<<(p+number-1)->score[3]<<")"<<endl;
	cin>>(p+number-1)->score[3];
	p->sum_score=0;
	for(j=0; j<4; j++) {
		(p+number-1)->sum_score=p->sum_score+(p+number-1)->score[j];
	}
}
