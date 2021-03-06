//ЛАБОРАТОРНАЯ РАБОТА №1 ВАРИАНТ 7 Передача аргументов программе из командной строки. Переменные среды
//POSIX: https://habr.com/ru/post/55665/

#include <iostream>
#include <fstream> // LOG
using namespace std;

void getHelp() {
	cout << endl << "HELP";//Правила использования, цель назначения иинформацию о разработчике
}

void setFileName(int argc, char** argv, int &fileName, int i) {
	if (argc > i + 1) {
		if (argv[i + 1][0] != '-') {
			fileName = i + 1;
		}
	}
}

void findCommandLineArguments(int argc, char** argv, int &fileName) {
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				if (argv[i][1] == 'h') {
					getHelp();
				}
				if (argv[i][1] == 'n') {
					setFileName(argc, argv, fileName, i);
				}
			}
		}
	}
}

void logFile(char** argv, int fileName) {
	std::ofstream myStream;
	myStream.open(argv[fileName]);
	if (myStream.is_open()) {
		cout << endl << "ENTER FROM KEYBOARD:" << endl;
		while (1) {
			char symbol = getchar();           
			if (symbol == EOF) {
				break;
			}  
			myStream << symbol;
		}
	}
	myStream.close();
}

int main(int argc, char** argv) {
	int fileName = 0;
	findCommandLineArguments(argc, argv, fileName);

	if (fileName == 0) {
		cout << endl << "FATALERROR! not found file Name.";
	}
	else {
		logFile(argv, fileName);
	}

	return 0;
}
