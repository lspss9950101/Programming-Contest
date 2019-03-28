#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<sstream>

#define DIGIT 9
#define DIGIT_EXP 1000000000
#define ABS(x) ((x)<0 ? -(x) : (x))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
using namespace std;

class BigInteger{
	private:
		long long int* magnitude;
		long long int length;
		
	public:
		BigInteger(string s){
			if(s == "")s = "0";
			length = (s.length() + DIGIT - 1) / DIGIT;
			magnitude = new long long int[length];
			int t = DIGIT * length - s.length();
			for(int i = 0; i < t; i++)s = "0" + s;
			for(long long int i = length-1; i >= 0; i--){
				string t = s.substr(i*DIGIT, DIGIT);
				magnitude[length - i - 1] = atoll(t.c_str());
			}
		}

		~BigInteger(){
			delete [] magnitude;
		}

		void updateMagnitude(long long int* magnitude){
			delete [] this->magnitude;
			this->magnitude = magnitude;	
		}

		friend void operator+=(BigInteger&, BigInteger&);
		friend void operator*=(BigInteger&, BigInteger&);
		friend BigInteger& operator<<(BigInteger&, long long int);
		friend ostream& operator<<(ostream& ,const BigInteger&);

};

void operator+=(BigInteger& bi1, BigInteger& bi2){
	long long int length = MAX(bi1.length, bi2.length)+1;
	long long int* magnitude = new long long int[length];
	int carry = 0;
	for(long long int i = 0; i < length; i++){
		long long int a = (i < bi1.length ? bi1.magnitude[i] : 0);
		long long int b = (i < bi2.length ? bi2.magnitude[i] : 0);
		magnitude[i] = a + b + carry;
		carry = magnitude[i] / DIGIT_EXP;
		magnitude[i] %= DIGIT_EXP;
	}
	if(magnitude[length-1])bi1.length = length;
	else bi1.length = length -1;
	bi1.updateMagnitude(magnitude);
}

void operator*=(BigInteger& bi1, BigInteger& bi2){
	long long int length = bi1.length + 1;
	BigInteger t("0");
	for(long long int i = 0; i < bi2.length; i++){
		long long int* magnitude = new long long int[length];
		long long int b = bi2.magnitude[i];
		long long int carry = 0;
		for(long long int j = 0; j < length; j++){
			long long int a = (j < bi1.length ? bi1.magnitude[j] : 0);
			magnitude[j] = a * b + carry;
			carry = magnitude[j] / DIGIT_EXP;
			magnitude[j] %= DIGIT_EXP;
		}

		BigInteger m("0");
		long long int j;
		for(j = length-1; j >= 0; j--)if(magnitude[j])break;
		m.updateMagnitude(magnitude);
		m.length = j+1;
		t += (m << i);
	}
	bi1.updateMagnitude(t.magnitude);
	t.magnitude = new long long int [1];
	bi1.length = t.length;
}

BigInteger& operator<<(BigInteger& bi, long long int displacement){
	if(!displacement)return bi;
	bi.length += displacement;
	long long int* magnitude = new long long int [bi.length];
	for(int i = 0; i < bi.length; i++){
		if(i < displacement)magnitude[i] = 0;
		else magnitude[i] = bi.magnitude[i-displacement];
	}
	bi.updateMagnitude(magnitude);
	return bi;
}

ostream& operator<<(ostream& os, const BigInteger& bi){
	bool zero = false;
	for(long long int i = bi.length-1; i >= 0; i--){
		if(bi.magnitude[i])zero = true;
		if(zero){
		 	os << bi.magnitude[i];
			os << setfill('0') << setw(DIGIT);
		}
	}
	os << setw(0);
	if(!zero)cout << 0;
	return os;
}

int main(){
	string s;
	while(getline(cin, s)){
		s += "+";
		stringstream ss(s);
		char t, op = '+';
		string number;
		BigInteger a("0");
		while(ss >> t){
			if(t == '+' || t == '*'){
				if(op == '+'){
					BigInteger b(number);
					number = "";
					a += b;
				}else if(op == '*'){
					BigInteger b(number);
					number = "";
					a *= b;
				}
				op = t;
			}else{
				number += t;
			}
		}
		cout << a << endl;
	}
}
