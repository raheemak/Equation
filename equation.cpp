#include "equation.h"
#include <string>

ostream& operator<< (ostream& output, const Equation & equation){
	output << equation.op1 << " " << equation.op << " " << equation.op2 << "=" << equation.result << endl;
	return output;
}

istream& operator>> (istream& input, Equation & equation){
	cout << "Enter equation in the form xx +/* xx: ";
	equation.op = ' ' ;
	equation.op1.clear();
	equation.op2.clear();
	equation.result.clear();

	while (equation.op != '+' &&  equation.op != '*')
		input >> equation.op1 >> equation.op >> equation.op2;	
 	
	return input;
}

int Equation::pos = 0;
string Equation::results[100][2];

void Equation::reports(){
	string addition = "", multiplication="";
	int add = 1, mul = 1;
        cout << "All Equations Entered: " <<endl;
	for (int x = 0 ; x< pos; x++){
		if (results[x][1]=="+"){
			addition+= std::to_string(add) + ". " + results[x][0]+"\n";
			add++;
		}
		else{ 	
			multiplication += std::to_string(mul)+ ". " + results[x][0]+"\n";
			mul++;
		}
		cout << x+1 <<". " << results[x][0] <<endl;
	}

	cout <<  endl << "ALL ADDITION EQUATIONS ENTERED\n" << addition <<endl;
	cout << "ALL MULTIPLICATON EQUATIONS ENTERED\n" << multiplication <<endl;
}

void Equation::applyOperation(){
	result.clear();
	switch (op){
		case '+':
			result = op1 + op2;
			break;
		case '*':
			result = op1 * op2;
			break;
	}
       
	// cout << "results: " << results <<endl;
	
	addToResults();

}

////private functions//////////////////////////////////////

void Equation::addToResults(){

	string opS =  &op;
	results[pos][0]=op1.asString() + " " + opS + " " + op2.asString() + " = " + result.asString();
	switch (op){
		case '+':
			results[pos][1]="+";
			break;
		 case '*':
                        results[pos][1]="*";
                        break;
                
	}

	pos++;	
	//cout <<endl << "POS: " << pos << endl;
}

main(){
	
	bool cont = true;
	int times = 0;
	char ans = ' ';
	Equation eq;
	
	while (cont){
		cin >> eq;
		eq.applyOperation();

		//cout << "answ!: " <<ans <<endl;	
		
		while (ans!= 'n' &&  ans!='N' &&  ans != 'Y' &&  ans!='y'){
			cout <<"Would you like to continue?(y/n): " ;
			cin >> ans;
		}
	
		if (ans=='n' || ans == 'N'|| times == 99)
			cont = false;
		
		ans = ' ';
		times++;
	}

	cout <<"Thank you!\nQuitting......\n\n";
	eq.reports();
}
