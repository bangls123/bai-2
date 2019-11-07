#include <bits/stdc++.h>
#include <stdlib.h>
#include<vector>

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

int main() {
    int a, b;

    vector<int> vertice1(0);
    vector<int> vertice2(0);

    while (cin >> a && cin >> b) {
        cout << a << " " << b << endl;
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

    print(graph);

    vector<int> color(graph.size());

    for (int i = 0; i < graph.size(); ++i) {
        int c = 1;

        vector<int> colorList(0);
        for (int j = 0; j < graph[i].size(); ++j) {
            colorList.push_back(graph[i][j]);
        }

        sort(colorList.begin(), colorList.end());

        for (int j = 0; j < colorList.size(); ++j) {
            if (c == colorList[j]) c++;
            else if (c < colorList[j]) break;
        }

        color[i] = c;
    }

    cout << "graph dothi\n{";
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << " " << "[fillcolor=" << color[i] << ", style=filled];" << endl;
    }
    for (int i = 0; i < vertice1.size(); ++i) {
        cout << vertice1[i] << "--" << vertice2[i] << endl;
    }

    return 0;
}
