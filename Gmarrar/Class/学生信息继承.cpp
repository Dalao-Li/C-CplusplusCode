#include<iostream>
using namespace std;
class Base1
{ 
    public :
        Base1(int i) 
		{ 
		   cout<<"���û���Base1�Ĺ��캯��:"<<i<<endl;
		}
};
class Base2
{ 
    public:
        Base2(int j) 
		{
		   cout<<"���û���Base2�Ĺ��캯��:"<<j<<endl;
	    }
}; 
class A:public Base1,public Base2
{ 
    public :
        A( int a, int b, int c, int d ) : Base1(b), Base2(c), b1(a), b2(d)
        { 
	      cout << "����������A�Ĺ��캯��:"<<a+b+c+d<<endl;
	    }   
    private :
        int b1;
        int b2;
};
 
int main()
{ 
   A obj( 1, 2, 3, 4 ); 
}

