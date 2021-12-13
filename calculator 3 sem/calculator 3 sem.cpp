#include <iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#define pi 3.14159265 
#define exp 2.718281
using namespace std;
int check_for_correct_input(string str,bool check_for_bracekts)
{
	check_for_bracekts= 1;
	int posL, posR;
	string str_check_for_brackets=str;
	string Lbracket = "(";
	string Rbracket = ")";
	//cout << "change sting:" << str_check_for_brackets << endl;
	while (check_for_bracekts)
	{
		posL = str_check_for_brackets.find(Lbracket); 
		posR = str_check_for_brackets.find(Rbracket);
		//cout << "change sting:" << str_check_for_brackets << endl;
		
		if ((posL != -1) && (posR != -1) && (posL < posR))
		{	
			str_check_for_brackets.erase(posL, 1);
			check_for_bracekts = 1;		

		str_check_for_brackets.erase(posR-1, 1);
		}
		else
			check_for_bracekts = 0;
	}
	
	if (posL == posR) { check_for_bracekts = 1; }
	return check_for_bracekts;
};
void polish_notation_isntmyorientation(string str) 
{

};
/*
int finding_corners(string str,char arithm,int leftcorner,int rightcorner)
{
		

};*/
void arithmetics(string str)
{

};
void calculation(string str)
{
	string tmp_str,tmp2_str;
	int  left_point, right_point,i,j,pos_ar;//pos_ar- position of artihmetic left/right_point is for borders of double
	double tmp_d1, tmp_d2;
	cout << str << endl;
	while (str.find("exp") != -1)
	{
		i = str.find("exp");//find index of 'e'
		j = str.find("p", i);
		tmp_str = to_string(exp);
		str.replace(i, j - i + 1, tmp_str);
		cout << str << endl;
	}
	while (str.find("pi") != -1)
	{
		i = str.find("pi");//find index of 'p'
		j = str.find("i", i);
		tmp_str = to_string(pi);
		str.replace(i, j - i + 1, tmp_str);
		cout << str << endl;
	}
	while (str.find("cos(")!=-1)
	{
		i = str.find("cos(");//find index of 'c'
		j = str.find(")", i);
		tmp_str.assign(str,i+4, j-(i+4));
		tmp_d1 = std::stod(tmp_str);
		//calculation cos of thi tmp_d1 and then add it 
		tmp_d2 = cos(tmp_d1);
		tmp_str = to_string(tmp_d2);
		str.replace(i, j-i+1, tmp_str);
		cout << str<<endl;
	}
	while (str.find("sin(") != -1)
	{
		i = str.find("sin(");//find index of 's'
		j = str.find(")", i);
		tmp_str.assign(str, i + 4, j - (i + 4));
		tmp_d1 = std::stod(tmp_str);
		//calculation sin of thi tmp_d1 and then add it 
		tmp_d2 = sin(tmp_d1);
		tmp_str = to_string(tmp_d2);
		str.replace(i, j - i+1, tmp_str);
		cout << str << endl;
	}
	while (str.find("sgn(") != -1)
	{
		i = str.find("sgn(");//find index of 's'
		j = str.find(")", i);
		tmp_str.assign(str, i + 4, j - (i + 4));
		tmp_d1 = std::stod(tmp_str);
		//calculation sin of thi tmp_d1 and then add it 
		if (tmp_d1 > 0) tmp_d2 = 1;
		if (tmp_d1 < 0) tmp_d2 = -1;
		if (tmp_d1 == 0) tmp_d2 = 0;
		tmp_str = to_string(tmp_d2);
		str.replace(i, j - i+1, tmp_str);
		cout << str << endl;
	}
	while (str.find("log(") != -1)
	{
		i = str.find("log(");//find index of 's'
		j = str.find(")", i);
		tmp_str.assign(str, i + 4, j - (i + 4));
		tmp_d1 = std::stod(tmp_str);
		//calculation sin of thi tmp_d1 and then add it 
		tmp_d2 = log(tmp_d1);
		tmp_str = to_string(tmp_d2);
		str.replace(i, j - i + 1, tmp_str);
		cout << str << endl;
	}
	//we make our calculation little easer lets find the nearest ) form the beginging bagining beginning 
	//let it be that i is left corner index and j is right corner index

 	while (str.find("^")!=-1|| str.find("*") != -1|| str.find("+") != -1|| str.find("-") != -1|| str.find("/") != -1)
	{
		j = str.find(")");
		i = str.rfind("(", j);
		tmp_str.assign(str,i+1,j-i-1);
		//if (str.find("*", j, i)!=-1&& str.find("/", j, i)==-1)
		if (i != -1 && j != -1)
		{
			while ((tmp_str.find("*") != -1) || (tmp_str.find("+") != -1) || (tmp_str.find("-") != -1) || (tmp_str.find("/") != -1))
				//in brackets 
			{
				pos_ar = tmp_str.find("*");//pos_ar- position of artihmetic left/right_point is for borders of double
				if (pos_ar != -1)
				{//should find in brackets two doubles left and right to multiplate
					for (left_point = pos_ar - 1; left_point > 0; left_point--) {
						if (tmp_str[left_point] == '+' || tmp_str[left_point] == '-' || tmp_str[left_point] == '/') { left_point++; break; }
					}
					tmp2_str.assign(tmp_str, left_point, pos_ar - left_point);
					tmp_d1 = std::stod(tmp2_str);
					for (right_point = pos_ar + 1; right_point < tmp_str.length(); right_point++) {
						if (tmp_str[right_point] == '+' || tmp_str[right_point] == '-' || tmp_str[right_point] == '/' || tmp_str[right_point] == '*') { break; }
					}
					tmp2_str.assign(tmp_str, pos_ar + 1, right_point - pos_ar - 1);
					tmp_d2 = std::stod(tmp2_str);
					tmp_d2 = tmp_d2 * tmp_d1;
					tmp2_str = to_string(tmp_d2);
					tmp_str.replace(left_point, right_point - left_point, tmp2_str);
				}
				else {
					pos_ar = tmp_str.find("/");//pos_ar- position of artihmetic left/right_point is for borders of double
					if (pos_ar != -1)
					{//should find in brackets two doubles left and right to multiplate
						for (left_point = pos_ar - 1; left_point > 0; left_point--) {
							if (tmp_str[left_point] == '+' || tmp_str[left_point] == '-') { left_point++; break; }
						}
						tmp2_str.assign(tmp_str, left_point, pos_ar - left_point);
						tmp_d1 = std::stod(tmp2_str);
						for (right_point = pos_ar + 1; right_point < tmp_str.length(); right_point++) {
							if (tmp_str[right_point] == '+' || tmp_str[right_point] == '-' || tmp_str[right_point] == '/' || tmp_str[right_point] == '*') { break; }
						}
						tmp2_str.assign(tmp_str, pos_ar + 1, right_point - pos_ar - 1);
						tmp_d2 = std::stod(tmp2_str);
						tmp_d2 = tmp_d2 / tmp_d1;
						tmp2_str = to_string(tmp_d2);
						tmp_str.replace(left_point, right_point - left_point, tmp2_str);
					}

					else {
						pos_ar = tmp_str.find("-");//pos_ar- position of artihmetic left/right_point is for borders of double
						if (pos_ar != -1)
						{//should find in brackets two doubles left and right to multiplate
							for (left_point = pos_ar - 1; left_point > 0; left_point--) {
								if (tmp_str[left_point] == '+') { left_point++; break; }
							}
							tmp2_str.assign(tmp_str, left_point, pos_ar - left_point);
							tmp_d1 = std::stod(tmp2_str);
							for (right_point = pos_ar + 1; right_point < tmp_str.length(); right_point++) {
								if (tmp_str[right_point] == '+' || tmp_str[right_point] == '-' || tmp_str[right_point] == '/' || tmp_str[right_point] == '*') { break; }
							}
							tmp2_str.assign(tmp_str, pos_ar + 1, right_point - pos_ar - 1);
							tmp_d2 = std::stod(tmp2_str);
							tmp_d2 = tmp_d2 - tmp_d1;
							tmp2_str = to_string(tmp_d2);
							tmp_str.replace(left_point, right_point - left_point, tmp2_str);
						}
						else {
							pos_ar = tmp_str.find("+");//pos_ar- position of artihmetic left/right_point is for borders of double
							if (pos_ar != -1)
							{//should find in brackets two doubles left and right to multiplate
								for (left_point = pos_ar - 1; left_point > 0; left_point--) {
									if (tmp_str[left_point] == '+' || tmp_str[left_point] == '-') { left_point++; break; }
								}
								tmp2_str.assign(tmp_str, left_point, pos_ar - left_point);
								tmp_d1 = std::stod(tmp2_str);
								for (right_point = pos_ar + 1; right_point < tmp_str.length(); right_point++) {
									if (tmp_str[right_point] == '+' || tmp_str[right_point] == '-' || tmp_str[right_point] == '/' || tmp_str[right_point] == '*') { break; }
								}
								tmp2_str.assign(tmp_str, pos_ar + 1, right_point - pos_ar - 1);
								tmp_d2 = std::stod(tmp2_str);
								tmp_d2 = tmp_d2 + tmp_d1;
								tmp2_str = to_string(tmp_d2);
								tmp_str.replace(left_point, right_point - left_point, tmp2_str);
							}
						}
					}
				}
			}
			str.replace(i, j - i + 1, tmp_str);
		}

	}

}
int main()
 {
	string str="((2.2+1.1*4.4*1.0)*5.5)/6.6+(cos(0.123891298)*2.0+sin(0))^2.0+sgn(-5)+log(exp)+log(1)";
	bool check_for_bracekts=1;
	cout << "our txt is :" << str << endl;
	/*
	find '(' , rembeber it's index and delete, rfind ')' and delete 
	if found then check check_for_bracekts=1
	else =0;
	in the end of whole return

posL = str.find(Lbracket);
cout << posL << endl;
str_check_for_brackets.erase(posL, 1);
cout << str_check_for_brackets;
*/
	check_for_bracekts=check_for_correct_input(str, check_for_bracekts);
	if (check_for_bracekts == 0)
	{
		//	throw out_of_range("wrong number of ( and ) brakets");
		cout << "bruda u make some wrong calculation\n";	
	}
	else
	{
		cout << "everthing is okey\n";
		calculation(str);
	}

}