#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void print(vector<vector<int> > &vec) {

    for (int i = 0; i < vec.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

bool isContainSpaceSign(string& s) {
	for (int i = 2; i < s.length(); ++i) {
		if (s[i] == ' ') return true;
	}
	return false;
}

int main() {
    int a, b;
	ifstream infile; 
	infile.open("rgb.txt"); 
	string str;
	vector<string> colorTable(0);
	getline(infile, str);
	vector<int> red(0), green(0), blue(0);
	while (!infile.eof()) {
		int r, b, g;
		 
		getline(infile, str);
		getline(infile, str);
		getline(infile, str);
		
		infile >> r; 
		infile >> g; 
		infile >> b;
		getline(infile, str);
		if (red.size() == 0 || ((r != red[red.size() - 1] || b != blue[blue.size() - 1] || g != green[green.size() - 1] ) && !isContainSpaceSign(str)) ) {
			
			str = str.erase(0, 2);
			colorTable.push_back(str);
			red.push_back(r);
			green.push_back(g);
			blue.push_back(b);
		}
		
	}
	
	// for (int i = 0; i < 10; ++i) cout << colorTable[i] << endl;
 

    vector<int> vertice1(0);
    vector<int> vertice2(0);

    while (cin >> a && cin >> b) {
        // cout << a << " " << b << endl;
        vertice1.push_back(a);
        vertice2.push_back(b);
    }

    int numberOfVertice = 0;
    for (int i = 0; i < vertice1.size(); ++i) {
        if (numberOfVertice < vertice1[i]) numberOfVertice = vertice1[i];
        if (numberOfVertice < vertice2[i]) numberOfVertice = vertice2[i];
    }

    vector<vector<int> > graph(numberOfVertice + 1);
    for (int i = 0; i < vertice1.size(); ++i) {
        int a = vertice1[i];
        int b = vertice2[i];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // print(graph);

    vector<int> color(graph.size());

    for (int i = 0; i < graph.size(); ++i) {
        int c = 1;

        vector<int> colorList(0);
        for (int j = 0; j < graph[i].size(); ++j) {
            colorList.push_back(color[graph[i][j]]);
        }

        sort(colorList.begin(), colorList.end());

        for (int j = 0; j < colorList.size(); ++j) {
            if (c == colorList[j]) c++;
            else if (c < colorList[j]) break;
        }

        color[i] = c;
    }
	ofstream out;
	out.open("graph.dot");

    cout << "graph dothi\n{\n";
	out << "graph dothi\n{\n";
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << " " << "[fillcolor=" << colorTable[(color[i] * 4 + 12) % colorTable.size()] << ", style=filled];" << endl;
		out << i << " " << "[fillcolor=" << colorTable[(color[i] * 4 + 12) % colorTable.size()] << ", style=filled];" << endl;
    }
    for (int i = 0; i < vertice1.size(); ++i) {
        cout << vertice1[i] << "--" << vertice2[i] << endl;
		out << vertice1[i] << "--" << vertice2[i] << endl;
    } 
	cout << "}";
	out << "}";
	out.close();
    return 0;
}
