#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <map>


using namespace std;

int hex_to_dec(const char *st)
{
    int i,s,k,p;
    s=0;
    p=strlen(st)-1;
    for (i=0; st[i]!='\0'; i++)
    {
        switch (toupper(st[i]))
        {
			case 'A': k=10; break;
			case 'B': k=11; break;
			case 'C': k=12; break;
			case 'D': k=13; break;
			case 'E': k=14; break;
			case 'F': k=15; break;
			case '1': k=1; break;
			case '2': k=2; break;
			case '3': k=3; break;
			case '4': k=4; break;
			case '5': k=5; break;
			case '6': k=6; break;
			case '7': k=7; break;
			case '8': k=8; break;
			case '9': k=9; break;
			case '0': k=0; break;
        }
        s=s+k * pow(16, p);
        p--;
    }
    return (s);
}

unsigned BinToDec(unsigned Value) {
    unsigned result = 0;
    for (unsigned i = 1; Value; Value/=10, i*=2){
        result += i*(Value%10);
    }
    return result;
}
 
int main()
{

    string s, result;  //s - начальная строка, result - конечная
    char prev;   // последний неповторяющийся символ, который мы встретили
    s = "dogieofebghcffebdiecfgcifabfagfgfdeafbbeoeabiobhceagoaaddedghoohbideegichafbi";
	std::map<char, int> n;
	n['a'] = 1;
	n['b'] = 2;
	n['c'] = 3;
	n['d'] = 4;
	n['e'] = 5;
	n['f'] = 6;
	n['g'] = 7;
	n['h'] = 8;
	n['i'] = 9;
	n['o'] = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
	
		result += to_string(n[s[i]]);
	}
    cout << result << std::endl;
	for (std::map<char, int>::iterator it = n.begin(); it != n.end(); it++)
	{
		std::cout << it->first << it->second << " ";
	}
	cout << endl;
    return 0;
}
// Z10N{dwdgdw3p_i1a3_w3uf3v_wv0p_3kw}
// JQ8GNm4CdY8
// fr3qu3ncy
// dogieofebghcffebdiecfgcifabfagfgfdeafbbeoeabiobhceagoaaddedghoohbideegichafbi
// d7 o7 g8 i7 e11 f10 b9 h5 c5 a8
// a8c5h5f10e11i7g8b9o7d7
//Z10N{4 15 7 9 5 6 2 8 3 1}
//Z10N{3968451720}

// hiegkjhegg
