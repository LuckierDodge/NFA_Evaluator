#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//Read from File
	string buffer1;
	string buffer2;
	cin >> buffer1 >> buffer2;
	int nstates = stoi(buffer1, nullptr);
	int naccepting = stoi(buffer2, nullptr);

	buffer1 = "";
	buffer2 = "";

	int accepting[naccepting];

	for (int i = 0; i < naccepting; i++) {
		cin >> buffer1;
		accepting[i] = stoi(buffer1, nullptr);
	}

	buffer1 = "";
	vector<int> transitions[nstates][2];
	for (int j = 0; j < nstates; j++) {
		// For input 'a'
		cin >> buffer1;
		int ntransistions = stoi(buffer1, nullptr);
		for (int k = 0; k < ntransistions; k++) {
			cin >> buffer2;
			transitions[j][0].push_back(stoi(buffer2, nullptr));
			buffer2 = "";
		}
		buffer1 = "";

		// For input 'b'
		cin >> buffer1;
		ntransistions = stoi(buffer1, nullptr);
		for (int k = 0; k < ntransistions; k++) {
			cin >> buffer2;
			transitions[j][1].push_back(stoi(buffer2, nullptr));
			buffer2 = "";
		}
	}

	buffer1 = "";
	int nwords;
	cin >> buffer1;
	nwords = stoi(buffer1, nullptr);

	string words[nwords];

	for (int k = 0; k < nwords; k++) {
		cin >> words[k];
	}

	// Print Table
	cout << "    | a b" << endl;
	cout << "----+------" << endl;

	for (int i = 0; i < nstates; i++) {
		bool accepts = false;

		for (int j = 0; j < naccepting; j++)
			accepts = (accepting[j] == i ? true : accepts);

		cout << (accepts ? "* " : "  ") << i << " | {";
		for(vector<int>::iterator it = transitions[i][0].begin(); it != transitions[i][0].end(); ++it)
			cout << " " << *it;
		cout << "} {";
		for(vector<int>::iterator it = transitions[i][1].begin(); it != transitions[i][1].end(); ++it)
			cout << " " << *it;
		cout << "}" << endl;
	}
}
