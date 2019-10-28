#include <iostream>
using namespace std;

class Operation{
protected:
	double num1;
	double num2;
public:
	virtual double getResult(){ return 0; }
	void NumBer1(int val){ num1 = val; }
	void NumBer2(int val){ num2 = val; }
};

class Add :public Operation{
public:
	virtual double getResult(){
		return num1 + num2;
	}
};

class Sub :public Operation{
public:
	virtual double getResult(){
		return num1 - num2;
	}
};

class Mul :public Operation{
public:
	virtual double getResult(){
		return num1 * num2;
	}
};

class Div :public Operation{
public:
	virtual double getResult(){
		if (num2 == 0){
			throw string("除数不能为0！！！");
		}
		else{
			return num1 / num2;
		}
	}
};

class Factory{
public:
	static Operation* createObj(char c){
		Operation* p = nullptr;
		switch (c){
		case '+':
			p = new Add;
			break;
		case '-':
			p = new Sub;
			break;
		case '*':
			p = new Mul;
			break;
		case '/':
			p = new Div;
			break;
		}
		return p;
	}
};

int main()
{
	Operation* oper = Factory::createObj('/');
	oper->NumBer1(1);
	oper->NumBer2(0);
	double ret = 0;
	try{
		ret = oper->getResult();
	}
	catch (string s){
		cout << s.c_str() << endl;
		return 0;
	}
	cout << ret << endl;
	return 0;
}