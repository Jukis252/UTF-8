#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

struct Duomenys
{
    int desimtainis = 0;
    vector<char> dvejaitaine;
    string Unicode, UTFas;
};

void DesimtainisToDvejetaini(int desimtainis, vector<char>& dvejetainis)
{
	for (int i = 0; 0 < desimtainis; i++)
	{
		char laikinas = desimtainis % 2 + '0';
		dvejetainis.push_back(laikinas);
		desimtainis /= 2;
	}
	if (dvejetainis.size() % 4 != 0) 
	{
		int laikinas = 4 - dvejetainis.size() % 4;
		for (int i = 0; i < laikinas; i++)
		{
			dvejetainis.push_back('0');
		}
	}
	reverse(dvejetainis.begin(), dvejetainis.end());
	//for (auto it : dvejetainis) cout << it;
}

void DvejatainisToSesioliktainis(vector<char> dvejetainis, string& sesioliktainis)
{
	ifstream fd("dvejetainiai_sesioliktainiai.txt");
	map<string, char> dvejetainiai_sesioliktainiai;
	map<string, char>::iterator it;
	string sesiolik;
	char dvej;
	while (fd >> sesiolik >> dvej)
	{
		dvejetainiai_sesioliktainiai[sesiolik] = dvej;
	}
	fd.close();
	string rinkinys;
	for (int i = 0; i != dvejetainis.size(); i++)
	{
		rinkinys.push_back(dvejetainis[i]);
		if ((i + 1) % 4 == 0)
		{
			it = dvejetainiai_sesioliktainiai.find(rinkinys);
			if (it != dvejetainiai_sesioliktainiai.end())
			{
				sesioliktainis.push_back(it->second);
			}
			rinkinys = "";
		}
	}
}

void UnicodasToUTFas(vector<char> dvejetainis, int desimtainis, string& UTFas)
{
	vector<char> DvejetainiISesioliktaini;
	UTFas = {};
	if (desimtainis < 128)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 7)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else {
				if (dvejetainis.size() != 0) 
				{
					DvejetainiISesioliktaini.push_back(dvejetainis.back());
					dvejetainis.pop_back();
				}
				else
				{
					DvejetainiISesioliktaini.push_back('0');
				}
			}
		}
	}
	else if (desimtainis < 2048) 
	{
		for (int i = 0; i < 16; i++)
		{
			if (i == 6)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 7)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 13)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 14)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 15)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else 
			{
				if (dvejetainis.size() != 0) 
				{
					DvejetainiISesioliktaini.push_back(dvejetainis.back());
					dvejetainis.pop_back();
				}
				else
				{
					DvejetainiISesioliktaini.push_back('0');
				}
			}
		}
	}
	else if (desimtainis < 65536) 
	{
		for (int i = 0; i < 24; i++)
		{
			if (i == 6)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 7)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 14)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 15)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 20)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 21)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 22)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 23)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else
			{
				if (dvejetainis.size() != 0) 
				{
					DvejetainiISesioliktaini.push_back(dvejetainis.back());
					dvejetainis.pop_back();
				}
				else
				{
					DvejetainiISesioliktaini.push_back('0');
				}
			}
		}
	}
	else if (desimtainis < 1114112) 
	{
		for (int i = 0; i < 32; i++)
		{
			if (i == 6)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 7)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 14)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 15)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 22)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 23)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 27)
			{
				DvejetainiISesioliktaini.push_back('0');
			}
			else if (i == 28)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 29)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 30)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else if (i == 31)
			{
				DvejetainiISesioliktaini.push_back('1');
			}
			else 
			{
				if (dvejetainis.size() != 0) 
				{
					DvejetainiISesioliktaini.push_back(dvejetainis.back());
					dvejetainis.pop_back();
				}
				else
				{
					DvejetainiISesioliktaini.push_back('0');
				}
			}
		}
	}
	reverse(DvejetainiISesioliktaini.begin(), DvejetainiISesioliktaini.end());
	//for (auto it : UTFas) cout << it;
	DvejatainisToSesioliktainis(DvejetainiISesioliktaini, UTFas);
}

void SesioliktainisToDvejetainis(vector<char>& dvejetainis, string sesioliktainis)
{
	ifstream fd("dvejetainiai_sesioliktainiai.txt");
	map<char, string> dvejetainiai_sesioliktainiai;
	map<char, string>::iterator it;
	char sesiolik;
	string dvej;
	while (fd >> dvej >> sesiolik)
	{
		dvejetainiai_sesioliktainiai[sesiolik] = dvej;
	}
	fd.close();
	dvejetainis = {};
	for (int i = 0; i != sesioliktainis.size(); i++)
	{
		it = dvejetainiai_sesioliktainiai.find(sesioliktainis[i]);
		if (it != dvejetainiai_sesioliktainiai.end())
		{
			for (int i = 0; i != it->second.size(); i++)
				dvejetainis.push_back(it->second[i]);
		}	
	}
	/*for (auto it : dvejetainiai_sesioliktainiai)
	{
		cout << it.first << " " << it.second << endl;
	}
	cout << endl;*/
}

int DvejetainisToDesimtainis(vector<char> dvejetainis)
{
	int desimtainis = 0, j = 0;

	for (int i = dvejetainis.size() - 1; i >= 0; i--)
	{
		int Ldvejetainis = dvejetainis[i] - '0';
		int Kvadratas;
		Kvadratas = (int)pow(2, j);
		desimtainis += (Ldvejetainis * Kvadratas);
		j++;
	}

	return desimtainis;
}

vector<char> hex_to_bytes(const string& hex)                                     
{
	vector<char> bytes;

	for (unsigned int i = 0; i < hex.length(); i += 2) 
	{
		string byteString = hex.substr(i, 2);
		char byte = (char)strtol(byteString.c_str(), NULL, 16);
		bytes.push_back(byte);
	}

	return bytes;
}

int main()
{
	bool veikia = true;
	while (veikia)
	{
		system("CLS");
		int ats;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "1. Convert Dec To UTF8" << endl;
		cout << "2. Convert 386intel.txt file to UTF8 using CP437 encoding (outputs to file)" << endl;
		cout << "3. Exit!" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Answer: ";
		cin >> ats;
		if(ats==1)
		{
			int taipne;
			system("CLS");
			Duomenys struktura;
			cin >> struktura.desimtainis;
			DesimtainisToDvejetaini(struktura.desimtainis, struktura.dvejaitaine);
			DvejatainisToSesioliktainis(struktura.dvejaitaine, struktura.Unicode);
			UnicodasToUTFas(struktura.dvejaitaine, struktura.desimtainis, struktura.UTFas);
			ofstream fr("output.txt");
			cout << "UNICODE: U+";
			for (int i = struktura.Unicode.size(); i < 4; i++)
			{
				cout << "0";
			}
			cout << struktura.Unicode << endl;
			cout << "UTF-8: ";
			for (int i = 0; i != struktura.UTFas.size(); i++) {
				cout << struktura.UTFas[i];
				if ((i + 1) % 2 == 0 && i + 1 != struktura.UTFas.size())
				{ 
					cout << " ";
				}
			}
			cout << endl; fr << endl;
			cout << "CHAR: " << char(struktura.desimtainis) << endl;
			fr.close();
			cout << "Do you want to continue?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";
			cin >> taipne;
			if (taipne != 1)
			{
				veikia = false;
			}
		}
		else if(ats==2)
		{
			int taipne;
			ifstream fd("386intel.txt");
			ofstream fr("output.txt");
			Duomenys struktura;
			char currentSym;
			map<int, string> CP437;
			map<int, string>::iterator it;
			int cpDec; string cpHex;
			ifstream cp("CP437.txt");
			while (cp >> cpHex >> cpDec)
			{
				CP437[cpDec] = cpHex;
			}
			cp.close();
			while (fd.get(currentSym))
			{
				struktura.desimtainis = currentSym;
				if (struktura.desimtainis < 0)
				{
					struktura.desimtainis += 256;
					it = CP437.find(struktura.desimtainis);
					if (it != CP437.end())
					{
						struktura.Unicode = it->second;
					}
					//cout << struktura.Unicode << endl;
					SesioliktainisToDvejetainis(struktura.dvejaitaine, struktura.Unicode);
					struktura.desimtainis = DvejetainisToDesimtainis(struktura.dvejaitaine);
					UnicodasToUTFas(struktura.dvejaitaine, struktura.desimtainis, struktura.UTFas);
					vector<char> bytes = hex_to_bytes(struktura.UTFas);
					//cout << struktura.Unicode << " " << struktura.UTFas << " " <<struktura.desimtainis<< " " <<currentSym<< endl;
					for (auto it : bytes)
					{
						fr << it;
					}
				}
				else
				{
					fr << currentSym;
				}
			}
			fd.close();
			fr.close();
			//system("CLS");
			cout << "File created" << endl;
			cout << "Do you want to continue?" << endl;
			cout << "1. Yes "<< endl;
			cout << "2. No "<< endl;
			cin >> taipne;
			if (taipne != 1)
			{
				veikia = false;
			}
		}
	}
}