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

void recordingMode(string fileName) {
	cout << endl << "=R=E=C=O=R=D=I=N=G= =M=O=D=E" << endl;

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

void parserCliArguments(int argc, char** argv) {
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

			if (vAllCliArguments[i] == "-r") {
				if (vAllCliArguments.size() - 1 >= i + 1) {
					string subject = vAllCliArguments[i + 1];
					if (subject[0] != '-') {
						int len = subject.length();
						if ((subject[len - 1] == 't') && (subject[len - 2] == 'x') && (subject[len - 3] == 't') && (subject[len - 4] == '.')) {
							char delim = ',';
							int countDelim = count(subject.begin(), subject.end(), delim);
							if (countDelim == 1) {
								string fileName = subject.substr(1 + subject.find(delim));
								cout << endl << "-> file name: " << fileName;
								cout << endl << "-> N: " << fileName;
								//recordingMode(fileName);
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
			cout << endl << "Incorrect cli args detected:";
			for (auto i = vIncorrectCliArguments.begin(); i != vIncorrectCliArguments.end(); i++) {
				cout << endl << "-> " << *i;
			}
			cout << endl << "Read Help to avoid mistakes.";
			getHelp();
		}
	}
	else {
		cout << endl << "Err. Empty cli args list. See help";
		getHelp();
	}


}

int main(int argc, char** argv) {
	parserCliArguments(argc, argv);
	return 0;
}
