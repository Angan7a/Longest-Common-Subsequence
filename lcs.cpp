#include<iostream>
#include<vector>
using namespace std;


struct Field {
	int number;
	vector<char> letter;
	Field() : number(0) { }
};


void lcs(string X, string Y) {
	int s_X = X.size(), s_Y = Y.size();
	Field C[s_Y + 1][s_X + 1];
	for(int i = 1; i < X.size(); ++i) {
		for(int j = 1; j < Y.size(); ++j) {
			if(Y[j] == X[i]) {
				C[j][i].number = C[j-1][i-1].number + 1;
				C[j][i].letter = C[j-1][i-1].letter;
				C[j][i].letter.push_back(X[i]);
			} else if(C[j-1][i].number > C[j][i-1].number) {
				C[j][i].number = C[j-1][i].number;
				C[j][i].letter = C[j-1][i].letter;
			} else {
				C[j][i].number = C[j][i-1].number;
				C[j][i].letter = C[j][i-1].letter;
			}
		}
	}
//print outcom
	cout << C[s_Y - 1][s_X - 1].letter.size() << endl;
	for(unsigned w = 0; w < C[Y.size()-1][X.size()-1].letter.size(); ++w) {
		cout << C[s_Y - 1][s_X - 1].letter[w] << endl;
	}

	for(unsigned w = 0; w < s_X; ++w) {
		for(unsigned v = 0; v < s_Y; ++v) {
			cout << C[v][w].number << " ";
			for(unsigned h=0; h < C[v][w].letter.size(); ++h) {
				cout << C[v][w].letter[h];
			}
			cout << endl;
		}
		cout << "=======" << endl;
	}
	
	
}


int main() {
	string X = " ACCG"; //to simplify notation, first char will be ignored
	string Y = " CCAGCA";

	lcs(X, Y);
return 0;
}
