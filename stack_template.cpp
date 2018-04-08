#include<iostream>
#include<typeinfo>
using namespace std;
template<class T,class V> void stack_functionality(T,V);
template<class T,class V> void stack_functionality_for_str(T,V);
class complex{
	float img, real;
public:
	complex(){
//		cout<<"Defaut constr is called\n";
		img= 0;
		real= 0;
	}
	complex(float a, float b){
		img= a;
		real= b;
	}

	complex(complex &c1){
		img= c1.img;
		real= c1.real;
	}

	template<class T> friend class stack1;
	friend istream & operator >>(istream &in, complex &c1);
	friend ostream & operator <<(ostream &out, const complex &c1);

};
istream & operator >> (istream &in,complex &c1)
	{
		cout << "Enter real=";
		in >> c1.real;
		cout << "Enter img=";
		in >> c1.img;
		return in;
	}
ostream & operator <<(ostream &out, const complex &c1)
	{

		cout << "\nreal=" << c1.real<<" | ";
		cout << "img=" << c1.img<<"\n";
		return out;
	}




template<class T>
class stack1{
	T *s;
     int size, top;
public:
	stack1()
	{
		s=NULL;
		size=0;
		top= -1;
//		cout<<"\n defult cont";
	}
	stack1(int a)
	{
		s= new T[a];
		size=a;
		top= -1;
//		cout<<"\n parameterised cont";
	}

	~stack1()
	{
		delete s;
		size=0;
		top= -1;
	}

	void get_size(int n)
	{
		s= new T[n];
		size= n;
	}
	void push(T);
	T pop();
	T peap();
	bool isFull();
	bool isEmpty();
	void display();
};

template<class T> void stack1<T>::push(T element){
	if(!isFull()){
		s[++top]= element;
		cout<<"\nElement pushed in stack : "<<s[top]<<endl;
	}else{
		cout<<" =================== stack is full =================== \n";
	}
}


template<class T> T stack1<T>::pop(){
	T x;
	x= -99;
	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"=================== Satck is empty =================== ";
	}
	return (x);
}


template<class T> T stack1<T>::peap(){
	T x = -99;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"=================== Satck is empty =================== ";
	}
	return (x);
}

template<class T> bool stack1<T>::isFull(){
	return(size-1 == top);
}
template<class T> bool stack1<T>::isEmpty(){
	return(top==-1);
}
template<class T> void stack1<T>::display()
{
	int i;
	if (top == -1) {
		cout<<"=================== Satck is empty =================== ";
	}else{
		cout << "\n Stack elements: ";
		for(i=0;i<=top;i++){
			cout<<" | "<<s[i];
		}
	}

}

//============================================================================
// explicit specilization for complex
//============================================================================
template<> void stack1<complex>::display(){
		int i;
		if (top == -1) {
			cout<<"=================== Satck is empty =================== ";
		}else{
			cout << "\n Stack elements: " ;
			for(i=0;i<=top;i++){
				cout<<"\nreal :"<<s[i].real;
				cout<<" | img :"<<s[i].img;
			}
		}
}

template<> void stack1<complex>::push(complex element){
	if(!isFull()){
		s[++top]= element;
		cout<<"\nElement pushed in stack : "<< element<<endl;
	}else{
		cout<<"========================= stack is full =========================\n";
	}
}

template<>	complex stack1<complex>::pop()
	{
		complex x;
	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
template<> complex stack1<complex>::peap(){
	complex x;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
//============================================================================
// explicit specilization for char*
//============================================================================
template<> void stack1<char *>::display(){
		int i;
		if (top == -1) {
			cout<<"=================== Satck is empty =================== ";
		}
		else{
			cout << "\n Stack elements: " ;
			for(i=0;i<=top;i++){
				cout<<"\n | "<<s[i];
			}
		}
}

template<> void stack1<char *>::push(char* ele){
	if(!isFull()){
		s[++top]= ele;
		cout<<"\nElement pushed in stack : "<<ele <<endl;
	}else{
		cout<<" stack is full\n";
	}
}

template<>	char* stack1<char*>::pop()
	{
		char* x;
		x = NULL;
	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}

template<> char* stack1<char*>::peap(){
	char* x;
	x = NULL;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}


int main(){
	complex c2(5,6), c1;
	stack1<int> s1;
	stack1<float> s2;
	stack1<complex> s3;
	stack1<char*> s4;
	char *ch;
	int i,sw;
	float f;
	cout << "\n================================================================== " << '\n';
	cout << "\nPlease select your choice" << '\n';
	cout << "\n 1: Stack implementation for int type " << '\n';
	cout << " 2: Stack implementation for float type " << '\n';
	cout << " 3: Stack implementation for complex type " << '\n';
	cout << " 4: Stack implementation for char* type " << '\n';
	cout << " 5: Exit " << '\n';
	cin>>sw;
	switch(sw){
		case 1:
					stack_functionality(s1,i);
					break;
		case 2:
					stack_functionality(s2,f);
					break;
		case 3:
					stack_functionality(s3,c1);
					break;
		case 4:
					stack_functionality_for_str(s4,ch);
					break;
		case 5:
					break;
		default:
					break;
	}

	return(0);
}

template<class V> V get(V a, int i){
	char* tmp;
	cout<<"Enter String : ";
	if(typeid(V).name() == typeid(char*).name()){
		V t1;
		char a[100];
		cin>>a;
		t1 = a;
		return t1;
	}else{
		return a;
	}
}



template<class T,class V> void stack_functionality_for_str(T s1,V tmp) {
			int n,sw;
			int flag =0 ;
			cout<<"Enter the stack size : ";
			cin>>n;
			s1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: For push element in stack " << '\n';
			cout << " 2: For pop element in stack " << '\n';
			cout << " 3: For peap element in stack " << '\n';
			cout << " 4: For print elements of stack " << '\n';
			cout << " 5: Exit " << '\n';
			cin>>sw;
			switch(sw){
				case 1:
								cout<<"Enter String : ";
								tmp = new char[50];
								cin>> tmp;
								s1.push(tmp);
							break;
				case 2:
								if(!s1.isEmpty()){
									tmp = s1.pop();
									cout<<"Poped element : "<<tmp;
								}else{
									cout<<"=================== Satck is empty =================== ";
								}
							break;
				case 3:
								if(!s1.isEmpty()){
									tmp = s1.peap();
									cout<<"Peaped element : "<<tmp;
								}else{
									cout<<"=================== Satck is empty =================== ";
								}
							break;
				case 4:
							s1.display();
							break;
				case 5:
							flag = 1;
							break;
				default:
							break;
			}
		}
}



																										// stack<float> s1, float tmp
template<class T,class V> void stack_functionality(T s1,V tmp) {
			int n,sw;
			int flag =0 ;
			cout<<"Enter the stack size : ";
			cin>>n;
			s1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: For push element in stack " << '\n';
			cout << " 2: For pop element in stack " << '\n';
			cout << " 3: For peap element in stack " << '\n';
			cout << " 4: For print elements of stack " << '\n';
			cout << " 5: Exit " << '\n';
			cin>>sw;
			switch(sw){
				case 1:
							cout<<"Enter element : ";
							cin>> tmp;
							s1.push(tmp);
							break;
				case 2:
							if(!s1.isEmpty()){
								tmp = s1.pop();
								cout<<"Poped element : "<<tmp;
							}else{
								cout<<"=================== Satck is empty =================== ";
							}
							break;
				case 3:
							if(!s1.isEmpty()){
								tmp = s1.peap();
								cout<<"Peaped element : "<<tmp;
							}else{
								cout<<"=================== Satck is empty =================== ";
							}
							break;
				case 4:
							s1.display();
							break;
				case 5:
							flag = 1;
							break;
				default:
							break;
			}
		}
}
