//ЛАБОРАТОРНАЯ РАБОТА №3 ВАРИАНТ 7 Проектирование и использование классов

#include <iostream>
#include <fstream> //LOG
#include <vector> 
#include <string>
#include "TicketOffice.h"

using namespace std;


//struct TicketOffice
//{
//	string ticketNumber;//номер кассы
//	string fullNameCashier;//ФИО кассира
//	string amountSoldTickets;//Кол-во проанных билетов
//	string totalRevenue;//Суммарная выручка
//	string salesDate;//Дата продажи
//
//	const string nameTicketNumber = "Ticket number: ";
//	const string nameFullNameCashier = "Full name cashier: ";
//	const string nameAmountSoldTickets = "Amount sold tickets: ";
//	const string nameTotalRevenue = "Total revenue: ";
//	const string nameSalesDate = "Sales date: ";
//};

void getHelp() {
	cout << endl << "========================HELP=======================";//Правила использования, цель назначения иинформацию о разработчике
	cout << endl << "===================================================";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "= LALAAAAAAAAAAALALLLLLLLLLLLLAAAAAAAAAAAALAAAAAA =";
	cout << endl << "===================================================";
	exit(0);
}

void parserCliArguments(int argc, char** argv, string &fileName, int &N, string &mode) {
	if (argc > 1) {
		vector<string> vAllCliArguments;
		vector<string> vIncorrectCliArguments;
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
					string subject = vAllCliArguments[i + 1];
					if (subject[0] != '-') {
						int len = subject.length();
						if ((subject[len - 1] == 't') && (subject[len - 2] == 'x') && (subject[len - 3] == 't') && (subject[len - 4] == '.')) {
							char delim = ',';
							int countDelim = count(subject.begin(), subject.end(), delim);
							if (countDelim == 1) {
								fileName = subject.substr(1 + subject.find(delim));
								string tmpN = subject.substr(0, subject.find(delim));
								N = atoi(tmpN.c_str());
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
		string input;

		cout << endl << "Serial number " << i + 1 << "(of " << N << ")";

		cout << endl << elt.GetNameTicketNumber();
		cin >> input;
		elt.SetTicketNumber(input);

		cout << elt.GetNameFullNameCashier();
		cin >> input;
		elt.SetFullNameCashier(input);

		cout << elt.GetNameAmountSoldTickets();
		cin >> input;
		elt.SetAmountSoldTickets(input);

		cout << elt.GetNameTotalRevenue();
		cin >> input;
		elt.SetTotalRevenue(input);

		cout << elt.GetNameSalesDate();
		cin >> input;
		elt.SetSalesDate(input);

		vMyTicketOffice.push_back(elt);
	}
	return vMyTicketOffice;
}

void printMode(vector<TicketOffice> vMyTicketOffice) {
	cout << endl << endl << "-> =P=R=I=N=T= =M=O=D=E";

	for (int i = 0; i < vMyTicketOffice.size(); i++) {
		cout << endl << endl << "Serial number " << i + 1 << "(of " << vMyTicketOffice.size() << ")";

		cout << endl << vMyTicketOffice[i].GetNameTicketNumber();
		cout << vMyTicketOffice[i].GetTicketNumber();

		cout << endl << vMyTicketOffice[i].GetNameFullNameCashier();
		cout << vMyTicketOffice[i].GetFullNameCashier();

		cout << endl << vMyTicketOffice[i].GetNameAmountSoldTickets();
		cout << vMyTicketOffice[i].GetAmountSoldTickets();

		cout << endl << vMyTicketOffice[i].GetNameTotalRevenue();
		cout << vMyTicketOffice[i].GetTotalRevenue();

		cout << endl << vMyTicketOffice[i].GetNameSalesDate();
		cout << vMyTicketOffice[i].GetSalesDate();

	}
}

void writeMode(vector<TicketOffice> vMyTicketOffice, string fileName, int N) {
	cout << endl << endl << "-> =W=R=I=T=E= =M=O=D=E" << endl;
	ofstream myOutStream;
	myOutStream.open(fileName);
	myOutStream << N << '\n';
	if (myOutStream.is_open()) {
		for (int i = 0; i < vMyTicketOffice.size(); i++) {
			myOutStream << vMyTicketOffice[i].GetTicketNumber() << '\n';
			myOutStream << vMyTicketOffice[i].GetFullNameCashier() << '\n';
			myOutStream << vMyTicketOffice[i].GetAmountSoldTickets() << '\n';
			myOutStream << vMyTicketOffice[i].GetTotalRevenue() << '\n';
			myOutStream << vMyTicketOffice[i].GetSalesDate() << '\n';
		}
	}
	else {
		cout << endl << "Err open file.";
	}
	myOutStream.close();
	cout << endl << "Job done";
}

vector<TicketOffice> readMode(string fileName, int N) {
	vector<TicketOffice> vMyTicketOffice;
	cout << endl << endl << "-> =R=E=A=D= =M=O=D=E";
	ifstream myInStream;
	myInStream.open(fileName);

	string line;
	getline(myInStream, line);

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
		int realN = atoi(line.c_str());
		cout << endl << "Real N = " << realN;

		if (N > realN) {
			cout << endl << "Err. Wrong N";
		}
		else {
			for (int i = 0; i < N; i++) {
				TicketOffice elt;

				getline(myInStream, line);
				elt.SetTicketNumber(line);

				getline(myInStream, line);
				elt.SetFullNameCashier(line);

				getline(myInStream, line);
				elt.SetAmountSoldTickets(line);

				getline(myInStream, line);
				elt.SetTotalRevenue(line);

				getline(myInStream, line);
				elt.SetSalesDate(line);

				vMyTicketOffice.push_back(elt);
			}
		}

	}
	myInStream.close();
	cout << endl << "Job done";
	return vMyTicketOffice;
}

int main(int argc, char** argv) {
	string fileName;
	int N = -1;
	string mode;
	parserCliArguments(argc, argv, fileName, N, mode);
	cout << endl << "-> file name: " << fileName;
	cout << endl << "-> N: " << N;
	cout << endl << "-> mode: " << mode;

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
