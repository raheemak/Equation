#include "hugeint.cpp"


class Equation{

	friend ostream& operator<< (ostream&, const Equation &);
	friend istream& operator>>(istream&, Equation &);

	public:
		static void reports();
		void applyOperation();
	
	private:
   		static string results [][2]; //[row][columns]
		HugeInteger op1, op2, result;
		char op;
		static int pos;
		
		void addToResults();
};
