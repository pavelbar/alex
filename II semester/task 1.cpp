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
				if (argv[i][1] == 'p') {
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
	int fileName = 0;
	findCommandLineArguments(argc, argv, fileName);

	if (fileName == 0) {
		cout << endl << "FATALERROR! not fount file Name.";
	}
	else {
		logFile(argv, fileName);
	}

	return 0;
}
