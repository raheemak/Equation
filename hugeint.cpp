#include "hugeint.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

///////////////helper functions////////////
bool HugeInteger::isZero()const{
	return (sigDigits==0);
}

int HugeInteger::getDigits()const{
	return sigDigits;
}

void HugeInteger::addDigit(int pos, int val){
	digits[pos]=val;
	sigDigits++;
}
		
void HugeInteger::clear(){
	HugeInteger product, temp;
	for (int x=0; x< MAXDIGITS; x++){
		digits[x]=0;
	}
	sigDigits=0;
}

int HugeInteger::getDigit(int x)const{
	return digits[x];
}

///////////////////////////////////////////


//output function 
ostream& operator<< (ostream& output, const HugeInteger  & op1){
	for (int x=op1.MAXDIGITS - op1.sigDigits; x<op1.MAXDIGITS; x++){
		output<<op1.digits[x];
	}
	return output;
}


//input function 
istream& operator>> (istream& input, HugeInteger & op1){
	op1.clear();

        int toInt(char);

        string s;
	input>>s;
	int j=op1.MAXDIGITS-1;
	char tmp;
	int tmp1;
	
	for (int x=s.length()-1; x>=0 && j>=0; x--,j--){
		tmp = s[x];
		tmp1 =toInt(tmp);
     		op1.digits[j]=tmp1;
		op1.sigDigits++;
	}
	return input;
}

///////////////////////////////////////////

HugeInteger::HugeInteger(){
	sigDigits =0;
	for (int x=0; x<MAXDIGITS; x++){
		digits[x]=0;
	}
}


string HugeInteger::asString(){
	string res = "";
	for (int x = MAXDIGITS-sigDigits; x<MAXDIGITS; x++){
		res += std::to_string(digits[x]);
	}
	return res;
}

HugeInteger HugeInteger::operator+ (const HugeInteger & op2)const{
	int toInt(char);

	HugeInteger sum;
	int  tmp=0, carryOver=0;
	string str = "";
	//decide how many times to go based on larger number 
	//(and then go once more in case there is a carry over
	int numIterations = MAXDIGITS - max(sigDigits, op2.getDigits()) - 1;

	//go through both arrays of digits 
	for (int x =MAXDIGITS-1; x>=numIterations && x>=0; x--){	
		tmp = digits[x] + op2.getDigit(x) + carryOver;

 		//reset carryover in case it isnt updated 

		carryOver = tmp/10;
			//cout <<"tmp: " <<tmp <<" str: ." <<str <<  ". str[0]: " << str[0] << " carryover: " <<carryOver <<endl;
			
			//dont carry over if it the last iteraton and it is a 0
			if (!(x==numIterations && tmp==0))
				sum.addDigit(x, tmp%10);
		
		str="";
	}
	//cout <<"sum: " <<sum<<endl;
	return sum;
}

HugeInteger HugeInteger::operator* (const HugeInteger & op2)const{
	HugeInteger product, temp;
	int tmp=0, carryover=0;
	int toInt(char);

	string str;
	if ((*this).isZero() || op2.isZero()){
		return product;
	}

	int numIterations = MAXDIGITS-sigDigits;

	for (int x=MAXDIGITS -1 ; x>=MAXDIGITS-op2.getDigits(); x--){
		for (int y=MAXDIGITS-1;y>=MAXDIGITS-sigDigits; y--){
			tmp = digits[y]* op2.getDigit(x) + carryover;
			carryover=tmp/10;
			//cout << "carryover: " << carryover << "tmp: " <<tmp <<endl;
	
				//dont carry over if it the last iteraton and it is a 0
				//cout << "y: " <<y << "tmp: " <<tmp << " numiterations: " << numIterations <<endl;
				if (!( y==numIterations && tmp==0))
					temp.addDigit(x-(MAXDIGITS-1)+y, tmp%10);
				
		}
		//cout <<"temp: " <<temp <<endl;
		product = product + temp;
		temp.clear();
	}
	return product;
}

bool HugeInteger::operator==(HugeInteger& op2)const{
	bool equal = true;
	
	//check if they are the same length
	if (op2.getDigits()!=sigDigits)
		equal = false;
	//else, go through digits and check to see they are the same
	else{
		for (int x=MAXDIGITS-sigDigits; x<MAXDIGITS; x++){
			if (digits[x]!=op2.getDigit(x)){	
				equal = false;
			}
		}
	}
	return equal;
}	

bool HugeInteger::operator!=( HugeInteger & op2)const{
	return !(*this==op2);
}

bool HugeInteger::operator>=(HugeInteger &op2)const{
	bool greater= false;

	//check to see if this has more digits than op2
	//by default is larger, no check required
	if (sigDigits > op2.getDigits()){
		greater = true;
	}

	else {
		for (int x = MAXDIGITS-sigDigits; x< MAXDIGITS; x++){
			if (digits[x]>=op2.getDigit(x)){
				greater = true;
			}
		}
	}
	return greater;
}

bool HugeInteger::operator<=(HugeInteger &op2)const{
        bool lesser=false;
	
	//check to see if it has less digits than op2
	//by default is less, no check required 
	
	if (sigDigits < op2.getDigits()){
		lesser = false;
	}

	else {
		for (int x = MAXDIGITS-sigDigits; x< MAXDIGITS; x++){
			if (digits[x]<=op2.getDigit(x)){
				lesser=false;
			}
		}
	}

	return lesser;        
}



int toInt (char c){
	int tmp1;
	switch (c){
	case '1':
		tmp1 = 1;
		break;
	case '2':
 		tmp1 = 2;
		break;
	case '3':
                tmp1 = 3;
		break;
	case '4':	
		tmp1=4;
		break;
	case '5':
                tmp1 = 5;
		break;
        case '6':
                tmp1 = 6;
		break;
        case '7':
                tmp1 = 7;
                break; 
	case '8':
		tmp1=8;
		break;
	case '9':
		tmp1 = 9;
		break;                       
 	case '0':
	default:
 		tmp1 = 0;
                break; 
       }
	return tmp1;
}

