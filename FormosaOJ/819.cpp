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
		bool sign;
		long long int* magnitude;
		long long int length;
		
	public:
		BigInteger(string s){
			if(s[0] == '-'){
				sign = false;
				s = s.substr(1, s.length()-1);
			}else sign = true;
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
		friend void operator-=(BigInteger&, BigInteger&);
		friend bool operator>(const BigInteger&, const BigInteger&);
		friend bool operator==(const BigInteger&, const BigInteger&);
		friend bool operator<(const BigInteger&, const BigInteger&);
		friend ostream& operator<<(ostream& ,const BigInteger&);

};

void operator+=(BigInteger& bi1, BigInteger& bi2){
	if(bi1.sign == bi2.sign){
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
	}else{
		bi2.sign = !bi2.sign;	
		bi1 -= bi2;
	}
}

void operator-=(BigInteger& bi1, BigInteger& bi2){
	if(bi1.sign != bi2.sign){
		bi2.sign = !bi2.sign;
		bi1 += bi2;
	}else{
		if(bi1 == bi2){
			long long int* magnitude = new long long int[1];
			bi1.updateMagnitude(magnitude);
			bi1.length = 1;
		}else if(bi1 > bi2){
			long long int length = MAX(bi1.length, bi2.length);
			long long int* magnitude = new long long int [length];
			int carry = 0;
			for(long long int i = 0; i < length; i++){
				long long int a = (i < bi1.length ? bi1.magnitude[i] : 0);
				long long int b = (i < bi2.length ? bi2.magnitude[i] : 0);
				magnitude[i] = a - b + carry;
				carry = 0;
				if(magnitude[i] < 0){
					magnitude[i] += DIGIT_EXP;
					carry = -1;
				}
			}
			bi1.updateMagnitude(magnitude);
			long long int i;
			for(i = length-1; i >= 0; i--)if(bi1.magnitude[i])break;
			bi1.length = i+1;
		}else{	
			bi1.sign = !bi1.sign;
			long long int length = MAX(bi1.length, bi2.length);
			long long int* magnitude = new long long int [length];
			int carry = 0;
			for(long long int i = 0; i < length; i++){
				long long int a = (i < bi1.length ? bi1.magnitude[i] : 0);
				long long int b = (i < bi2.length ? bi2.magnitude[i] : 0);
				magnitude[i] = b - a + carry;
				carry = 0;
				if(magnitude[i] < 0){
					magnitude[i] += DIGIT_EXP;
					carry = -1;
				}
			}
			bi1.updateMagnitude(magnitude);
			long long int i;
			for(i = length-1; i >= 0; i--)if(bi1.magnitude[i])break;
			bi1.length = i+1;
		}
	}
}


bool operator>(const BigInteger& bi1, const BigInteger& bi2){
	if(bi1.length > bi2.length)return true;
	else if(bi1.length < bi2.length)return false;
	else{
		for(long long int i = bi1.length-1; i >= 0; i++){
			if(bi1.magnitude[i] > bi2.magnitude[i])return true;
			else if(bi1.magnitude[i] < bi2.magnitude[i])return false;
		}
	}
	return false;
}
bool operator==(const BigInteger& bi1, const BigInteger& bi2){
	if(bi1.length != bi2.length)return false;
	bool zero = false;
	for(long long int i = 0; i < bi1.length; i++){
		if(bi1.magnitude[i] != bi2.magnitude[i])return false;
		if(bi1.magnitude[i])zero = true;
	}
	if(zero && (bi1.sign != bi2.sign))return false;
	return true;
}
bool operator<(const BigInteger& bi1, const BigInteger& bi2){
	return bi2 > bi1;
}

ostream& operator<<(ostream& os, const BigInteger& bi){
	if(!bi.sign)os << setw(0) << "-";
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
		stringstream ss(s);
		string t;
		ss >> t;
		BigInteger a(t);
		while(ss >> t){
			BigInteger b(t);
			a += b;
		}
		cout << a << endl;
	}
}
