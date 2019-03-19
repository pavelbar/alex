//Лабораторная работа №4. Наследование, перегрузка операций

#include "pch.h"
#include <iostream>
#include <fstream> //LOG
#include <vector> 
#include "MString.h"
#include "TicketOffice.h"

using  std::endl;
using  std::cout;
using  std::vector;
using  std::cin;
using  std::ofstream;
using  std::ifstream;
using  namespace std;//dell (ios::binary)

const int MAX_SIZE = 15;

void getHelp() {
	cout << endl << "========================HELP=======================";//Правила использования, цель назначения иинформацию о разработчике
	cout << endl << "===================================================";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "===================================================";
	exit(0);
}

void parserCliArguments(int argc, char** argv, MString &fileName, int &N, MString &mode) {
	if (argc > 1) {
		vector<MString> vAllCliArguments;
		vector<MString> vIncorrectCliArguments;
		for (int i = 1; i < argc; i++) {
			vAllCliArguments.push_back(argv[i]);
		}

		for (int i = 0; i < vAllCliArguments.size(); i++) {
			bool otherArgument = true;
			if (vAllCliArguments[i] == "-h") {
				getHelp();
				otherArgument = false;
			}

			if (vAllCliArguments[i] == "-c" || vAllCliArguments[i] == "-r") {
				if (vAllCliArguments.size() - 1 >= i + 1) {
					MString subject = vAllCliArguments[i + 1];
					if (subject[0] != '-') {
						int len = subject.Size();
						if ((subject[len - 1] == 'n') && (subject[len - 2] == 'i') && (subject[len - 3] == 'b') && (subject[len - 4] == '.')) {
							char delim = ',';
							//int countDelim = count(subject.begin(), subject.end(), delim);
							int countDelim = 1;//dell
							if (countDelim == 1) {
								//fileName = subject.substr(1 + subject.find(delim));
								fileName = "aaa.bin";//dell
								//string tmpN = subject.substr(0, subject.find(delim));
								//N = atoi(tmpN.c_str());
								N = 2;//dell
								if (vAllCliArguments[i] == "-c") {
									mode = "create";
								}
								else {
									mode = "read";
								}
								otherArgument = false;
								i++;
							}
							else {
								if (countDelim == 0) {
									cout << endl << "Err. Not found delemiter ',' ";
								}
								if (countDelim > 1) {
									cout << endl << "Err. there can be only one delemiter ";
								}
							}
						}
						else {
							cout << endl << "Err. File type only TXT:";
						}
					}
				}
			}

			if (otherArgument) {
				vIncorrectCliArguments.push_back(vAllCliArguments[i]);
			}
		}

		if (vIncorrectCliArguments.size() != 0) {
			cout << endl << "Err. Incorrect cli args detected:";
			for (auto i = vIncorrectCliArguments.begin(); i != vIncorrectCliArguments.end(); i++) {
				cout << endl << "-> " << *i;
			}
			getHelp();
		}
	}
	else {
		cout << endl << "Err. Empty cli args list. See help";
		getHelp();
	}
}

vector<TicketOffice> inputMode(int N) {
	vector<TicketOffice> vMyTicketOffice;
	cout << endl << endl << "-> =I=N=P=U=T= =M=O=D=E";
	cout << endl << "ENTER FROM KEYBOARD:" << endl;
	for (int i = 0; i < N; i++) {
		TicketOffice elt;
		//string input;
		MString input;

		char word[MAX_SIZE];  //new
		

		cout << endl << "Serial number " << i + 1 << "(of " << N << ")";

		cout << endl << elt.GetNameTicketNumber() ;
		cin >> word;		  //new
		input = word;		  //new
		elt.SetTicketNumber(input);

		cout << elt.GetNameFullNameCashier() ;
		cin >> word;		  //new
		input = word;		  //new
		elt.SetFullNameCashier(input);

		cout << elt.GetNameAmountSoldTickets() ;
		cin >> word;		  //new
		input = word;		  //new
		elt.SetAmountSoldTickets(input);

		cout << elt.GetNameTotalRevenue() ;
		cin >> word;		  //new
		input = word;		  //new
		elt.SetTotalRevenue(input);

		cout << elt.GetNameSalesDate() ;
		cin >> word;		  //new
		input = word;		  //new
		elt.SetSalesDate(input);

		vMyTicketOffice.push_back(elt);
	}
	return vMyTicketOffice;
}

void printMode(vector<TicketOffice> vMyTicketOffice) {
	cout << endl << endl << "-> =P=R=I=N=T= =M=O=D=E";

	for (int i = 0; i < vMyTicketOffice.size(); i++) {
		cout << endl << endl << "Serial number " << i + 1 << "(of " << vMyTicketOffice.size() << ")";

		cout << endl << vMyTicketOffice[i].GetNameTicketNumber() ;
		cout << vMyTicketOffice[i].GetTicketNumber() ;

		cout << endl << vMyTicketOffice[i].GetNameFullNameCashier() ;
		cout << vMyTicketOffice[i].GetFullNameCashier() ;

		cout << endl << vMyTicketOffice[i].GetNameAmountSoldTickets() ;
		cout << vMyTicketOffice[i].GetAmountSoldTickets() ;

		cout << endl << vMyTicketOffice[i].GetNameTotalRevenue() ;
		cout << vMyTicketOffice[i].GetTotalRevenue() ;

		cout << endl << vMyTicketOffice[i].GetNameSalesDate() ;
		cout << vMyTicketOffice[i].GetSalesDate() ;

	}
}

void writeMode(vector<TicketOffice> vMyTicketOffice, MString fileName, int N) {
	cout << endl << endl << "-> =W=R=I=T=E= =M=O=D=E" << endl;
	//ofstream myOutStream(fileName, ios::binary);
	ofstream myOutStream("aaa.bin", ios::binary);//dell
	if (myOutStream.is_open()) {
		myOutStream.write((char*)&N, sizeof(N));

		for (int i = 0; i < vMyTicketOffice.size(); i++) {
			MString str;
			size_t len = -1;

			str = vMyTicketOffice[i].GetTicketNumber();
			len = str.Size();
			myOutStream.write((char*)&len, sizeof(len));
			myOutStream.write((char*)str.GetCharArray() , len);

			str = vMyTicketOffice[i].GetFullNameCashier();
			len = str.Size();
			myOutStream.write((char*)&len, sizeof(len));
			myOutStream.write((char*)str.GetCharArray(), len);

			str = vMyTicketOffice[i].GetAmountSoldTickets();
			len = str.Size();
			myOutStream.write((char*)&len, sizeof(len));
			myOutStream.write((char*)str.GetCharArray(), len);

			str = vMyTicketOffice[i].GetTotalRevenue();
			len = str.Size();
			myOutStream.write((char*)&len, sizeof(len));
			myOutStream.write((char*)str.GetCharArray(), len);

			str = vMyTicketOffice[i].GetSalesDate();
			len = str.Size();
			myOutStream.write((char*)&len, sizeof(len));
			myOutStream.write((char*)str.GetCharArray(), len);
		}
	}
	else {
		cout << endl << "Err open file.";
	}
	myOutStream.close();
	cout << endl << "Job done";
}

vector<TicketOffice> readMode(MString fileName, int N) {
	vector<TicketOffice> vMyTicketOffice;
	cout << endl << endl << "-> =R=E=A=D= =M=O=D=E";
	//ifstream myInStream(fileName, ios::binary);
	ifstream myInStream("aaa.bin", ios::binary);

	if (!myInStream)
	{
		if (myInStream.eof()) {
			cout << endl << "Err. Empty file";
		}
		else {
			cout << endl << "File not found or other failure";
		}
	}

	if (myInStream.is_open()) {
		int realN = -1;
		myInStream.read((char*)&realN, sizeof(realN));
		cout << endl << "Real N = " << realN;

		if (N > realN) {
			cout << endl << "Err. Wrong N";
		}
		else {
			for (int i = 0; i < N; i++) {
				TicketOffice elt;
				size_t len;
				char * buf;

				myInStream.read((char*)&len, sizeof(len));
				buf = new char[len];
				myInStream.read(buf, len);
				elt.SetTicketNumber(buf);
				delete[]buf;

				myInStream.read((char*)&len, sizeof(len));
				buf = new char[len];
				myInStream.read(buf, len);
				elt.SetFullNameCashier(buf);
				delete[]buf;

				myInStream.read((char*)&len, sizeof(len));
				buf = new char[len];
				myInStream.read(buf, len);
				elt.SetAmountSoldTickets(buf);
				delete[]buf;

				myInStream.read((char*)&len, sizeof(len));
				buf = new char[len];
				myInStream.read(buf, len);
				elt.SetTotalRevenue(buf);
				delete[]buf;

				myInStream.read((char*)&len, sizeof(len));
				buf = new char[len];
				myInStream.read(buf, len);
				elt.SetSalesDate(buf);
				delete[]buf;

				vMyTicketOffice.push_back(elt);
			}
		}

	}
	myInStream.close();
	cout << endl << "Job done";
	return vMyTicketOffice;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");//dell
	MString fileName;
	int N = -1;
	MString mode;
	parserCliArguments(argc, argv, fileName, N, mode);
	cout << endl << "-> file name: " << fileName ;
	cout << endl << "-> N: " << N;
	cout << endl << "-> mode: " << mode ;

	vector <TicketOffice> vMyTicketOffice;

	if (mode == "create") {
		vMyTicketOffice = inputMode(N);
		printMode(vMyTicketOffice);
		writeMode(vMyTicketOffice, fileName, N);
	}
	if (mode == "read") {
		vMyTicketOffice = readMode(fileName, N);
		printMode(vMyTicketOffice);
	}

	return 0;
}
