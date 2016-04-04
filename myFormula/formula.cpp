#include <iostream>
#include <string>
#include <vector>
using namespace std;

string substr(string s, int begin, int end) {
	string r="\0";
	for(int i=begin;i<end;i++)
		r+=s[i];
	return r;
}

class myFormula {

public:
	myFormula* left;
	myFormula* right;
	char value;
	char op;
	
	myFormula() {
		left = NULL;
		right = NULL;
	}
	
	void appendNode(string expr);		//to create left and right nodes from input string
	virtual void input() {
		return;
	}
	virtual void print() {
		return;
	}
	virtual myFormula* diff() {
		return NULL;
	}			//virtual function has to be used
	virtual myFormula* simplify() {
		return NULL;
	}
	virtual bool isConstExpr() {
		return false;
	}
};
////////////////////////////////////////////////////////////////////////////////////
class PrimitiveExpr : public myFormula {
public:
	PrimitiveExpr(char c='\0') {
		value = c ;
		op = 'p' ;			//primitive (just a symbol : x in "x+y")
	}

	void print() {
		cout<<value;
	}

	myFormula* diff() {
		myFormula* n;
		if(value=='x') {
			n = new PrimitiveExpr('1');
		}
		else
			n = new PrimitiveExpr('0');
		return n;
	}

	myFormula* simplify() {
		return this;
	}

	bool isConstExpr() {
		if(value=='x')
			return false;
		else 
			return true;
	}
};
////////////////////////////////////////////////////////////////////////////////////
class AddExpr : public myFormula {
 public:
	AddExpr(myFormula l, myFormula r) {
	value = '\0';
	op = '+';
	*left = l;
	*right = r;		//defining left and right expressions and joining by + operator 
	}

	AddExpr(myFormula* l, myFormula* r) {
	value = '\0';
	op = '+';
	left = l;
	right = r;		//defining left and right expressions and joining by + operator 
	}

	AddExpr(string expr) {
		value = '\0';
		op = '+';
		appendNode(expr);
	} 

	void print() {
		cout<<"(";
		left->print();
		cout<<"+";
		right->print();
		cout<<")";
	}

	myFormula* diff() {
		myFormula* n;
		n = new AddExpr((left->diff()), (right->diff()));
		return n;
	}

	bool isConstExpr() {
		return left->isConstExpr() and right->isConstExpr();
	}

	/*myFormula* simplify() {
		myFormula *l,*r;
		  left = left->simplify();
		  right = right->simplify();

		  if(left->value=='0' and right->value!='0') {
		  	return right;
		  }
		  else if(right->value=='0' and left->value=='0') {
		  	return left;
		  }
	}
	*/
};
//////////////////////////////////////////////////////
class SubExpr : public myFormula {
public:
	SubExpr(myFormula l, myFormula r) {
		value = '\0';
		op = '-';
		*left = l;
		*right = r;
	}

	SubExpr(myFormula* l, myFormula* r) {
		value = '\0';
		op = '-';
		left = l;
		right = r;
	}

	SubExpr(string expr) {
		value = '\0';
		op = '-';
		appendNode(expr);
	}

	void print() {
		cout<<"(";
		left->print();
		cout<<"-";
		right->print();
		cout<<")";
	}

	myFormula* diff() {
		myFormula* n;
		n = new SubExpr(left->diff(), right->diff());
		return n;
	}

	bool isConstExpr() {
		return left->isConstExpr() and right->isConstExpr();
	}
};

//////////////////////////////////////////////////////////////////////
class MulExpr : public myFormula {
public:
	MulExpr(myFormula l, myFormula r) {
		value = '\0';
		op = '*';
		*left = l;
		*right = r;			//def left, right and join by / operator
	}

	MulExpr(myFormula* l, myFormula* r) {
		value = '\0';
		op = '*';
		left = l;
		right = r;			//def left, right and join by / operator
	}

	MulExpr(string expr) {
		value = '\0';
		op = '*';
		appendNode(expr);
	}

	void print() {
		cout<<"(";
		left->print();
		cout<<"*";
		right->print();
		cout<<")";
	}

	myFormula* diff() {
		myFormula *s1,*s2,*s;
		s1 = new MulExpr(left,right->diff());
		s2 = new MulExpr(right, left->diff());
		s = new AddExpr(s1,s2);
		return s;
	}

	bool isConstExpr() {
		return left->isConstExpr() and right->isConstExpr();
	}
};
///////////////////////////////////////////////////////////////////////////////////////
class DivExpr : public myFormula {
public:
	DivExpr(myFormula l, myFormula r) {
		value = '\0';
		op = '/';
		*left = l;
		*right = r;			//def left, right and join by / operator
	}

	DivExpr(myFormula* l, myFormula* r) {
		value = '\0';
		op = '/';
		left = l;
		right = r;			//def left, right and join by / operator
	}

	DivExpr(string expr) {
		value = '\0';
		op = '/';
		appendNode(expr);
	}

	bool isConstExpr() {
		return left->isConstExpr() and right->isConstExpr();
	}

	void print() {
		cout<<"(";
		left->print();
		cout<<"/";
		right->print();
		cout<<")";
	}

	myFormula* diff() {
		if(isConstExpr()==true) {
			myFormula *p;
			p = new PrimitiveExpr('0');
			return p;
		}
		myFormula *num1,*num2,*num,*den, *final;
		num1 = new MulExpr(left->diff(),right);
		num2 = new MulExpr(left,right->diff());
		num = new SubExpr(num1,num2);
		den = new MulExpr(right,right);
		final = new DivExpr(num,den);
		return final; 
	}

};
////////////////////////////////////////////////////////////////////////
class PowerExpr : public myFormula {
public:
	PowerExpr(myFormula l, myFormula r) {
		value = '\0';
		op = '^';
		*left = l;
		*right = r;			//def left, right and join by / operator
	}

	PowerExpr(myFormula* l, myFormula* r) {
		value = '\0';
		op = '^';
		left = l;
		right = r;			//def left, right and join by / operator
	}

	PowerExpr(string expr) {
		value = '\0';
		op = '^';
		appendNode(expr);
	}

	bool isConstExpr() {
		return left->isConstExpr() and right->isConstExpr();
	}

	void print() {
		cout<<"(";
		left->print();
		cout<<"^";
		right->print();
		cout<<")";
	}

	myFormula* diff() {			//only handles x^a or a^b, returns 1 in all other cases
		myFormula* d;

		// x raised to something
		 if(left->value=='x' and right->isConstExpr()==true) {		
		 	myFormula *exponent,*one,*power;
		 	one = new PrimitiveExpr('1');
		 	exponent = new SubExpr(right,one);
		 	power = new PowerExpr(left,exponent);
		 	d = new MulExpr(right,power);
		 	return d;
		 }
		 else if(isConstExpr()==true)	{	//left value is primitive and not x 
		 	d = new PrimitiveExpr('0');
		 	return d;
		 }
		 else								//dummy to handle rest cases
		 {
		 	d = new PrimitiveExpr('?');
		 	return d;
		 }
	}
};
////////////////////////////////////////////////////////////////////////
struct myExpr {						//formula pointer based on what user wants
	myFormula *expr;
	void input(string expr1);

	myExpr() {
		expr = NULL;
	}

	void print() {
		expr->print();
		cout<<endl;
	}

	myExpr diff() {
		myExpr d;
		(d.expr) = ((*this).expr->diff());
		return d;
	}

	myExpr simplify() {
		myExpr s;
		s.expr = (*this).expr->simplify();
		return s;
	}
};
///////////////////////////////////////// Modify this
void myExpr::input(string expr1) {

	if(expr1[1]!='+' and expr1[1]!='/' and expr1[1]!='-' and expr1[1]!='*' and expr1[1]!='^') {
		expr = new PrimitiveExpr(expr1[1]);			//primitive object
	}
	else {												//non-primitive
		if(expr1[1]=='+') {
			expr = new AddExpr(expr1);
		}
		else if(expr1[1]=='/') {
			expr = new DivExpr(expr1);
		}
		else if(expr1[1]=='-') {
			expr = new SubExpr(expr1);
		}
		else if(expr1[1]=='*') {
			expr = new MulExpr(expr1);
		}
		else if(expr1[1]=='^') {
			expr = new PowerExpr(expr1);
		}
	}
}
///////////////////////////////////////      Modify this
void myFormula::appendNode(string expr) {
	int search = 3;
	int par = 1;

		while(par > 0 and search < expr.length()) {
			if(expr[search] == '(')
				par++;
			else if(expr[search]==')')
				par--;
			search++;
		}

		if(expr[3]!='+' and expr[3]!='/' and expr[3]!='-' and expr[3]!='*' and expr[3]!='^') {		//primitive
			left = new PrimitiveExpr(expr[3]);
		}
		else {	//not primitive
			if(expr[3]=='+') {
				left = new AddExpr(substr(expr,2,search));
			}
			else if(expr[3]=='/') {
				left = new DivExpr(substr(expr,2,search));
			}
			else if(expr[3]=='-') {
				left = new SubExpr(substr(expr,2,search));
			}
			else if(expr[3]=='*') {
				left = new MulExpr(substr(expr,2,search));
			}
			else if(expr[3]=='^') {
				left = new PowerExpr(substr(expr,2,search));
			}
		}

		if(expr[search+1]!='+' and expr[search+1]!='^' and expr[search+1]!='/' and expr[search+1]!='-' and expr[search+1]!='*') {			//primitive
			right = new PrimitiveExpr(expr[search+1]);
		}
		else {										//non primitive
			if(expr[search+1]=='+') {
				right = new AddExpr(substr(expr,search,expr.length()-1));
			}
			else if(expr[search+1]=='/') {
				right = new DivExpr(substr(expr,search,expr.length()-1));
			}
			else if(expr[search+1]=='-') {
				right = new SubExpr(substr(expr,search,expr.length()-1));
			}
			else if(expr[search+1]=='*') {
				right = new MulExpr(substr(expr,search,expr.length()-1));
			}
			else if(expr[search+1]=='^') {
				right = new PowerExpr(substr(expr,search,expr.length()-1));
			}
		}
}
///////////////////////////////////////////////////////////////////////////////////////
int main() {
	myExpr e , ediff;
	string s;
	cout<<"Enter the string in prefix notation with parenthesis.\n";
	cin>>s;
	e.input(s);
	cout<<"Original formula - ";
	e.print();

	ediff = e.diff();
	cout<<"Differentiated formula - ";
	ediff.print();
//	Use prefix with parenthesis, but output will be a 'regular' expression 
//  Some demo inputs - 
// 	(a) 				== a
// 	(+(a)(b))			== (a+b)
// 	(+(/(a)(b))(/(c)(+(d)(e))))   == ((a/b)+(c/(d+e)))
//	check inp and out files for more inputs and corresponding outputs
}