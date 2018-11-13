#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;

const char readPath[] = "D:\\input.txt";
const char writePath[] = "D:\\out.txt";

void printLogo(int task) {
	printf("************************************************************\n"
		"* Nizhniy Novgorod Technical University                    *\n");
	printf("* Study work number 2. Task number %d.                      *\n", task);
	printf("* Performed student 18 - IVT - 2. Kornilov Alexey          *\n"
		"************************************************************\n");
}

void sleep() {
	system("pause");
	cout << endl;
}

void myCls(int task) {
	system("cls");
	printLogo(task);
}

void clearStdIn() {
	while (getc(stdin) != '\n');// clear stdin
}

void jobDone() {
	cout << endl;
	puts("\nJob done.");
	cout << endl;
	clearStdIn();
	sleep();
}

vector<char> read() {
	vector<char> vLineText;
	char symbol;
	ifstream f(readPath);
	while (!f.eof())
	{
		f.get(symbol);
		vLineText.push_back(symbol);
	}
	f.close();
	return vLineText;
}

void print(vector<char> vLineText) {
	for (char symbol : vLineText) {
		cout << symbol;
	}
}

void write(vector<char> vLineText) {
	ofstream  fout(writePath);
	for (char symbol : vLineText) {
		fout << symbol;
	}
	fout.close();
}

vector<char> input() {
	char symbol;
	vector<char> vResult;

	do
	{
		cin.get(symbol);

		vResult.push_back(symbol);
	} while (symbol != '\n');
	return vResult;
}

int find(vector<char> vec, vector<char> find) {
	size_t findSize = find.size() - 1;
	size_t ind = -1;
	bool done = false;

	for (size_t i = 0; i < vec.size() - findSize + 1; i++) {
		done = false;
		if (vec[i] == find[0]) {
			ind = i;
			done = true;
			size_t k = 0;
			for (size_t j = ind; j < ind + findSize; j++) {
				if (vec[j] != find[k]) {
					done = false;
					break;
				}
				k++;
			}
			if (done) break;
		}
	}

	if (done) {
		return ind;
	}
	else {
		return -1;
	}
}

void add(vector<char>& oldV, vector<char> addPart, size_t pos) {
	for (size_t i = 0; i < addPart.size() - 1; i++) {
		oldV.insert(oldV.begin() + pos + i, addPart[i]);
	}
}

int main() {
	setlocale(LC_ALL, ".866");

	while (true)
	{
		int task = 0;

		myCls(task);
		cout
			<< "Tasks.The source of the data and the result of the program is textual." << endl
			<< "file.For coding tex, the DOS code table (CP866) is used." << endl
			<< "Create a program that processes the file according to the specified the algorithm" << endl << endl;

		vector<char> vLineText = read();

		cout << endl << "============================" << endl;
		print(vLineText);
		cout << endl << "============================";

		cout << endl << endl << " MODE: Add word" << endl;
		cout << endl << " Insert a word about which" << endl << "-> ";

		vector<char>  vFind = input();
		if (find(vLineText, vFind) == -1) {
			cout << endl << "error. not found";
		}
		else {
			int select = 0;
			cout << endl << " 1. (posle) After ";
			cout << endl << " 2. (do) Before ";
			cout << endl << "Select mode. Mode = " << endl << "-> ";
			cin >> select;
			if ((select < 1) || (select > 2)) {
				cout << endl << "error. not found";
			}
			else {
				size_t findIndex = find(vLineText, vFind);
				size_t index = 0;
				if (select == 1) {
					index = findIndex + vFind.size() - 1;
				}
				if (select == 2) {
					if (findIndex == 0) {
						index = 0;
					}
					else {
						index = findIndex - 1;
					}
				}
				cout << endl << "Pos for add: " << index;
				clearStdIn();// clear stdin
				cout << endl << " Insert a word for add" << endl << "-> ";
				vector<char>  vNew = input();
				add(vLineText, vNew, index);
			}

		}

		cout << endl << "============================" << endl;
		print(vLineText);
		cout << endl << "============================";

		write(vLineText);
		vLineText.clear();

		jobDone();
	}
}
