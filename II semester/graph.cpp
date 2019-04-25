// graph.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream> // LOG
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Top
{
	int number;
	int size;
	vector<int> neighbors;
	int color;
};

vector<vector<int>> readMode(string fileName) {
	cout << endl << endl << "-> =R=E=A=D= =M=O=D=E";

	vector<vector<int>> inputData;
	ifstream myInStream;
	myInStream.open(fileName);

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
		string line;
		while (getline(myInStream, line)) {
			stringstream ss(line);
			vector<int> nums;
			int ti;
			while (ss >> ti) {
				nums.push_back(ti);
			}
			inputData.push_back(nums);
		}
	}
	myInStream.close();
	cout << endl << "Job done";
	return inputData;
}

void printMode(vector<vector<int>> inputData) {
	cout << endl << endl << "-> =P=R=I=N=T= =M=O=D=E";

	cout << endl;
	for (int i = 0; i < inputData.size(); i++) {
		cout << endl;
		for (int j = 0; j < inputData[i].size(); j++) {
			cout << " " << inputData[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void printModeGraph(vector<Top> graph) {
	cout << endl << endl << "-> =P=R=I=N=T= =M=O=D=E =G=R=A=P=H=";

	cout << endl;
	for (int i = 0; i < graph.size(); i++) {
		cout << endl;
		cout << endl << "number = " << graph[i].number;
		cout << endl << "size = " << graph[i].size;
		cout << endl << "color = " << graph[i].color;
		cout << endl << "neighbors:" << endl;
		for (int j = 0; j < graph[i].neighbors.size(); j++) {
			cout << " " << graph[i].neighbors[j];
		}
		cout << endl;
	}
	cout << endl;
}

vector<Top> coloring(vector<Top> graph) {
	cout << endl << endl << "-> =C=O=L=O=R=I=N=G= =G=R=A=P=H=";

	//Is empty

	cout << endl << "Job done";
	return graph;
}

int main()
{
	string fileName = "in.txt";
	cout << endl << "-> file name: " << fileName;
	vector<vector<int>> inputData;

	inputData = readMode(fileName);
	printMode(inputData);

	vector<Top> graph;

	for (int i = 0; i < inputData.size(); i++) {
		Top tmp;
		tmp.number = i;
		tmp.size = inputData[i].size();
		tmp.color = -1;
		tmp.neighbors = inputData[i];
		graph.push_back(tmp);
	}

	printModeGraph(graph);

	vector<Top> coloringGraph;
	coloringGraph = coloring(graph);
	printModeGraph(coloringGraph);

    return 0;
}

