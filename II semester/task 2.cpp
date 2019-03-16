//ЛАБОРАТОРНАЯ РАБОТА №2 ВАРИАНТ 7 Использование структур

#include <iostream>
#include <fstream> //LOG
#include <vector> 
#include <string>


using namespace std;

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
								string tmpN = subject.substr(0, subject.find(delim) );
								N = atoi(tmpN.c_str());
								if(vAllCliArguments[i] == "-c"){
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

void createMode(string fileName) {
	cout << endl << "=C=R=E=A=T=E= =M=O=D=E" << endl;

	std::ofstream myStream;
	myStream.open(fileName);
	if (myStream.is_open()) {
		cout << endl << "ENTER FROM KEYBOARD:" << endl;
		while (1) {
			char symbol = getchar();            // Get one character from the input
			if (symbol == EOF) {
				break;
			}  // Exit the loop if we receive EOF ("end of file")
			myStream << symbol;
		}
	}
	myStream.close();
}

void readMode(string fileName) {
	cout << endl << "=R=E=A=D= =M=O=D=E" << endl;

	std::ofstream myStream;
	myStream.open(fileName);
	if (myStream.is_open()) {
		cout << endl << "ENTER FROM KEYBOARD:" << endl;
		while (1) {
			char symbol = getchar();            // Get one character from the input
			if (symbol == EOF) {
				break;
			}  // Exit the loop if we receive EOF ("end of file")
			myStream << symbol;
		}
	}
	myStream.close();
}

int main(int argc, char** argv) {
	string fileName;
	int N = -1;
	string mode;
	parserCliArguments(argc, argv, fileName, N, mode);
	cout << endl << "-> file name: " << fileName;
	cout << endl << "-> N: " << N;
	cout << endl << "-> mode: " << mode;

	if (mode == "create") {
		createMode(fileName);
	}
	if (mode == "read") {
		readMode(fileName);
	}

	return 0;
}
