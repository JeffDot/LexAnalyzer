#include <iostream>
#include <string>

using namespace std;
const string ICL = "#include<";//9
const string NS = "usingnamespace";//14
const string INT = "int";//3<1,>
const string FLOAT = "float";//5<2,>
const string CHAR = "char";//4<3,>
const string STRING = "string";//6<4,>
const string IF = "if";//2<5,>
const string ELSE = "else";//4<6,>
const string BREAK = "break";//5<7,>
const string COUT = "cout";//4<8,>
const string ENDL = "endl";//4<9,>
const string WHILE = "while";//5<10,>
const string RETURN = "return";//6<11,>
string int2string(int num);


int main()
{
	int line = 0;
	const string test_str = "#include <iostream>\nusing namespace std;\n/*this is a explain*/\nint main()\n	{\nint i = 0;\nif(a == 1)\nelse{}\ncout << \"helloworld\" << endl;\ncout << i << endl;\nreturn 0;\n}";
	cout << test_str << endl;
	string temp_str = "";
	string out_str = "L0: ";
	char readch;
	int i = 0;
	int i_temp = 0;
	int str_len = test_str.length();
	//去掉空白和换行并且计算行数
	while(i <= str_len - 1)
	{			
		readch = test_str[i];
		switch(readch)
		{
			//when read blank then pass it
		case ' ':
			i++;
			break;
		case '\t':
			i++;
			break; 		
			//if read \n let line_counter add 1
		case '\n':
			i++;
			line ++;
			temp_str += '$';		
			break;	
			//when read '/' then have a judgemen : is this a explain?
		case '/':			
			readch = test_str[i+1];			
			if(readch == '*')
			{
				i += 2;
				readch = test_str[i];
				while(1)
				{
					if(readch == '*')
					{
						readch = test_str[i+1];
						//*/ is the end flag of a explain
						if(readch == '/')
						{
							i += 2;
							break;
						}
					}
					i++;
					readch = test_str[i];
				}
			}
			else
			{
				temp_str += test_str[i];
				i++;				
			}
			break;		
		default:			
			temp_str += readch;
			i++;		
		}
	}
	//头文件和名空间的以及解释的处理	
	i = 0;
	int line_temp = 1;
	int pre_over_num = 0;
	str_len = temp_str.length();
	while(i <= str_len - 1)
	{
		readch = temp_str[i];
		string temp = "";
		switch(readch)
		{
			//pre-process make \n be $
		case '$':					
			out_str += "\nL";
			if(line_temp <= 9)
			{
				out_str += line_temp + '0';
			}
			else
			{
				out_str += int2string(line_temp);
			}
			out_str += ": ";
			line_temp ++;
			i++;
			break;
		case '#':		
			cout << "Here#" << endl;
			temp = temp_str.substr(i,9);
			if(temp == ICL)
			{
				out_str += "include the head file : ";
				i = 9;
				while((readch = temp_str[i]) != '>')
				{
					cout << "Here#loop" << endl;
					i++;
				}				
				temp = temp_str.substr(9,i - 9);
				out_str += temp;
			}
			i++;//jump '>'
			break;
		case 'u':		
			cout << "Hereu" << endl;
			temp = temp_str.substr(i,14);
			if(temp == NS)
			{
				int i_temp = i + 14;
				while((readch = temp_str[i]) != ';')
				{
					cout << "Hereuloop" << endl;
					i++;
				}
				temp = temp_str.substr(i_temp,i - i_temp);
				out_str += temp;
				out_str += " namespace";				
				pre_over_num = i;
			}
			i++;
			break;
		case 'i':
			if((temp = temp_str.substr(i,2)) == IF)
			{
				out_str += " <5,IF> ";
				i += 2;
			}
			else if((temp = temp_str.substr(i,3)) == INT)			
			{
				out_str += " <1,INT> ";
				i += 3;
			}
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";				
			}			
			break;
		case 'f':
			if((temp = temp_str.substr(i,5)) == FLOAT)
			{
				out_str += " <2,FLOAT> ";
				i += 5;
			}
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}
			break;
		case 'c':
			if((temp = temp_str.substr(i,4)) == CHAR)
			{
				out_str += " <3,CHAR> ";
				i += 4;
			}
			else if((temp = temp_str.substr(i,4)) == COUT)			
			{
				out_str += " <8,COUT> ";
				i += 4;
			}
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}	
			break;
		case 's':
			if((temp = temp_str.substr(i,6)) == STRING)
			{
				out_str += " <4,STRING> ";
				i += 6;
			}			
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}			
			break;
		case 'e':
			if((temp = temp_str.substr(i,4)) == ELSE)
			{
				out_str += " <6,ELSE> ";
				i += 4;
			}
			else if((temp = temp_str.substr(i,4)) == ENDL)			
			{
				out_str += " <9,ENDL> ";
				i += 4;
			}
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}			
			break;
		case 'w':
			if((temp = temp_str.substr(i,5)) == WHILE)
			{
				out_str += " <10,WHILE> ";
				i += 5;
			}			
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}			
			break;
		case 'b':
			if((temp = temp_str.substr(i,5)) == BREAK)
			{
				out_str += " <7,BREAK> ";
				i += 2;
			}			
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}			
			break;
		case 'r':
			if((temp = temp_str.substr(i,6)) == RETURN)
			{
				out_str += " <11,RETURN> ";
				i += 6;
			}		
			else
			{
				cout << "Here" << endl;
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					cout << "Here_loop" << endl;
					i++;
					readch = temp_str[i];
				}
				out_str += "<49,var-";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += ">";
			}			
			break;
		case '=':
			if((readch = temp_str[i+1]) == '=')
			{
				i+=2;
				out_str += " <13,==> ";
			}
			else
			{
				out_str += " <12,=> ";
				i++;
			}
			break;
		case '!':
			if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <14,!=> ";
			}
			else
			{
				i++;
			}
			break;
		case '+':
			if((readch = temp_str[i+1]) == '+')
			{
				i += 2;
				out_str += " <16,++> ";
			}
			else if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <17,+=> ";
			}
			else
			{
				out_str += " <15,+> ";
				i++;
			}
			break;
		case '-':
			if((readch = temp_str[i+1]) == '-')
			{
				i += 2;
				out_str += " <19,++> ";
			}
			else if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <20,+=> ";
			}
			else
			{
				out_str += " <18,+> ";
				i++;
			}
			break;
		case '*':
			if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <22,*=> ";
			}			
			else
			{
				out_str += " <21,*> ";
				i++;
			}
			break;
		case '/':
			if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <24,/=> ";
			}			
			else
			{
				out_str += " <21,/> ";
				i++;
			}
			break;
		case '%':
			out_str += " <25,%> ";
			i++;
		case '>':
			if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <27,>=> ";
			}			
			else if((readch = temp_str[i+1]) == '>')
			{
				out_str += " <31,>>> ";
				i++;
			}
			else
			{
				out_str += " <26,>> ";
				i++;
			}
			break;
		case '<':
			if((readch = temp_str[i+1]) == '=')
			{
				i += 2;
				out_str += " <29,<=> ";
			}			
			else if((readch = temp_str[i+1]) == '<')
			{
				i += 2;
				out_str += " <30,<<> ";			
			}
			else
			{
				out_str += " <28,<> ";
				i++;
			}
			break;
		case '&':
			if((readch = temp_str[i+1]) == '&')
			{
				i += 2;
				out_str += " <39,&&> ";
			}					
			else
			{
				out_str += " <38,&> ";
				i++;
			}
			break;
		case '|':
			if((readch = temp_str[i+1]) == '|')
			{
				i += 2;
				out_str += " <41,||> ";
			}					
			else
			{
				out_str += " <40,|> ";
				i++;
			}
			break;
		case '{':
			out_str += " <32,{> ";
			i ++;
			break;
		case '}':
			out_str += " <33,}> ";
			i ++;
			break;
		case '(':
			out_str += " <34,(> ";
			i ++;
			break;
		case ')':
			out_str += " <35,)> ";
			i ++;
			break;
		case '[':
			out_str += " <36,[> ";
			i ++;
			break;
		case ']':
			out_str += " <37,]> ";
			i ++;
			break;
		case ';':
			out_str += " <42 , ;> ";
			i ++;
			break;
		default:
			if((readch >= 'A' && readch <= 'Z') || (readch >= 'a' && readch <= 'z'))
			{
				i_temp = i;
				i++;
				readch = temp_str[i];
				while((readch >= 'A' && readch <= 'Z')
						|| (readch >= 'a' && readch <= 'z')
						|| (readch >= '0' && readch <= '9'))
				{
					i++;
					readch = temp_str[i];
				}
				out_str += " <49,var- ";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += "> ";
				i--;
			}
			if(readch >= '0' && readch <= '9')
			{
				i_temp = i;
				i++;
				readch = temp_str[i];
				while(readch >= '0' && readch <= '9')
				{
					i++;
					readch = temp_str[i];
				}
				out_str += " <50,const- ";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += "> ";
				i--;
			}
			if(readch == '"')
			{
				i_temp = i;
				i ++;
				readch = temp_str[i];
				while(readch != '"')
				{
					i ++;
					readch = temp_str[i];
				}
				i++;
				out_str += " <50,const- ";
				out_str += temp_str.substr(i_temp,i - i_temp);
				out_str += "> ";
				i--;
			}
			i++;
			break;
		}
	}
	//cout << pre_over_num;
	//temp_str = temp_str.substr(pre_over_num , str_len - pre_over_num - 1);
	cout << temp_str << endl;
	cout << out_str << endl;
	return 0;
}
string int2string(int num)
{
	string out = "";
	bool is_stop = true;
	while(is_stop)
	{
		if(num / 10 == 0)
		{
			is_stop = false;			
		}		
		string tmp;
		tmp = (num % 10) + '0';
		tmp += out;
		out = tmp;

		num = num/10;
	}
	return out;
}

	