// graph.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream> // LOG
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Top
{
	int number;
	int size;
	vector<int> neighbors;
	string color;

	bool operator <(const Top &rhs) {
		return size > rhs.size;
	}
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

vector<Top> coloring(vector<Top> igraph) {
	cout << endl << endl << "-> =C=O=L=O=R=I=N=G= =G=R=A=P=H=";
	vector<Top> sgraph = igraph;
	sort(sgraph.begin(), sgraph.end());

	//Red blue green white 

	//RED ZONE
	{
		sgraph[0].color = "Red";
		int index = sgraph[0].number;
		igraph[index].color = "Red";

		for (int i = 0; i < sgraph.size(); i++) {
			bool flag = true;

			for (int j = 0; j < sgraph[i].neighbors.size(); j++) {

				if (sgraph[i].neighbors[j] == index) {
					flag = false;
				}

				if (igraph[sgraph[i].neighbors[j]].color == "Red") {
					flag = false;
				}
			}
			if (flag) {
				sgraph[i].color = "Red";
				igraph[sgraph[i].number].color = "Red";
			}
		}
	}
	//RED ZONE END

	//BLUE ZONE
	{
		int index = -1;
		for (int i = 0; i < sgraph.size(); i++) {
			if (sgraph[i].color == "-1") {
				index = i;
				break;
			}
		}

		if (index == -1) {
			cout << endl << "Job done";
			return igraph;
		}

		sgraph[index].color = "Blue";
		index = sgraph[index].number;
		igraph[index].color = "Blue";


		for (int i = 0; i < sgraph.size(); i++) {
			bool flag = true;
			for (int j = 0; j < sgraph[i].neighbors.size(); j++) {
				if (sgraph[i].neighbors[j] == index) {
					flag = false;
				}
				if (igraph[sgraph[i].neighbors[j]].color == "Blue") {
					flag = false;
				}
			}
			if ((flag) && (sgraph[i].color == "-1")) {
				sgraph[i].color = "Blue";
				igraph[sgraph[i].number].color = "Blue";
			}
		}
	}
	//BLUE ZONE END

	//GREEN ZONE
	{
		int index = -1;
		for (int i = 0; i < sgraph.size(); i++) {
			if (sgraph[i].color == "-1") {
				index = i;
				break;
			}
		}

		if (index == -1) {
			cout << endl << "Job done";
			return igraph;
		}
		sgraph[index].color = "green";
		index = sgraph[index].number;
		igraph[index].color = "green";

		for (int i = 0; i < sgraph.size(); i++) {
			bool flag = true;
			for (int j = 0; j < sgraph[i].neighbors.size(); j++) {
				if (sgraph[i].neighbors[j] == index) {
					flag = false;
				}
				if (igraph[sgraph[i].neighbors[j]].color == "green") {
					flag = false;
				}
			}
			if ((flag) && (sgraph[i].color == "-1")) {
				sgraph[i].color = "green";
				igraph[sgraph[i].number].color = "green";
			}
		}
	}
	//GREEN ZONE END

	//WHITE ZONE
	{
		int index = -1;
		for (int i = 0; i < sgraph.size(); i++) {
			if (sgraph[i].color == "-1") {
				index = i;
				break;
			}
		}

		if (index == -1) {
			cout << endl << "Job done";
			return igraph;
		}
		sgraph[index].color = "white";
		index = sgraph[index].number;
		igraph[index].color = "white";

		for (int i = 0; i < sgraph.size(); i++) {
			bool flag = true;
			for (int j = 0; j < sgraph[i].neighbors.size(); j++) {
				if (sgraph[i].neighbors[j] == index) {
					flag = false;
				}
				if (igraph[sgraph[i].neighbors[j]].color == "white") {
					flag = false;
				}
			}
			if ((flag) && (sgraph[i].color == "-1")) {
				sgraph[i].color = "white";
				igraph[sgraph[i].number].color = "white";
			}
		}
	}
	//WHITE ZONE END

	cout << endl << "Job done";
	return igraph;
}

vector<Top> getGtaph(vector<vector<int>> inputData) {
	vector<Top> graph;
	for (int i = 0; i < inputData.size(); i++) {
		Top tmp;
		tmp.number = i;
		tmp.size = inputData[i].size();
		tmp.color = "-1";
		tmp.neighbors = inputData[i];
		graph.push_back(tmp);
	}
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
	graph = getGtaph(inputData);
	printModeGraph(graph);

	vector<Top> coloringGraph;
	coloringGraph = coloring(graph);
	printModeGraph(coloringGraph);

	return 0;
}

