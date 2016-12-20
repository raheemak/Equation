/*Raheema Kadwa
 * Data Structures
 * Review Lab 1 
 *
 *HugeInteher.h
 *Class that represents a positive integer up to 40 digits long.
 *Includes overloaded operators. 
 *Add and multiply hugeintegers
*
*/

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::max;
class HugeInteger{

	friend ostream& operator<< (ostream&, const HugeInteger &);
	friend istream&operator>> (istream&, HugeInteger &);

	private: 
		int sigDigits; 
		static const int MAXDIGITS=40;
		int digits[MAXDIGITS];

                //helper functions	
		bool isZero()const;	
		int getDigits()const;
		int getDigit(int)const;
		void addDigit(int, int);

	public:
		
		void clear();

		HugeInteger();
		string asString();	
	
		HugeInteger operator+ (const HugeInteger &)const;
		HugeInteger operator* (const HugeInteger &)const;

		bool operator== (HugeInteger &)const;
		bool operator!= (HugeInteger &)const;
		bool operator>= (HugeInteger &)const;
		bool operator<= (HugeInteger &)const;

};

