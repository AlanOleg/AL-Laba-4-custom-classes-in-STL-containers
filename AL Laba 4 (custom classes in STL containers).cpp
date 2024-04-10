#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
using namespace std;

class Credit {
	friend ostream& operator<<(ostream& os, Credit& Credit);
	friend istream& operator>>(istream& is, Credit& Credit);
	friend bool operator<(const Credit&, const Credit&);
private:
	string name;
	int sum;
	string currency;
	int annual_rate;
public:
	Credit();
	Credit(string name, int sum, string currency, int annual_rate);
	Credit(const Credit& Credit_copied);
};

Credit::Credit() {
	this->name = "";
	this->sum = 0;
	this->currency = "";
	this->annual_rate = 0;
};

Credit::Credit(string name, int sum, string currency, int annual_rate) {
	this->name = name;
	this->sum = sum;
	this->currency = currency;
	this->annual_rate = annual_rate;
};

Credit::Credit(const Credit& Credit_copied) {
	this->name = Credit_copied.name;
	this->sum = Credit_copied.sum;
	this->currency = Credit_copied.currency;
	this->annual_rate = Credit_copied.annual_rate;
};

ostream& operator<<(ostream& os, Credit& Credit) {
	fstream file("output.txt", fstream::app);
	if (file.is_open()) {
		file << Credit.name << ' ' << Credit.sum << ' ' << Credit.currency << ' ' << Credit.annual_rate << endl;
	}
	else {
		cout << "Output file didn't open." << endl;
	}
	os << Credit.name << ' ' << Credit.sum << ' ' << Credit.currency << ' ' << Credit.annual_rate << '%' << endl;
	return os;
};

istream& operator>>(istream& is, Credit& Credit) {
	is >> Credit.name;
	is >> Credit.sum;
	is >> Credit.currency;
	is >> Credit.annual_rate;
	return is;
};

bool operator<(const Credit& Credit1, const Credit& Credit2) {
	return Credit1.annual_rate < Credit2.annual_rate;
};

int main() {
	ofstream file_output("output.txt");
	file_output.close();
	ifstream file_input("input.txt");

	vector<Credit> Credits_vector;
	string line;
	while (getline(file_input, line)) {
		istringstream ss(line);
		Credit to_vector;
		ss >> to_vector;
		Credits_vector.push_back(to_vector);
	}

	cout << "Vector before sorting: " << endl;
	for (int i = 0; i < Credits_vector.size(); ++i) {
		cout << Credits_vector[i];
	}cout << endl;

	sort(Credits_vector.begin(), Credits_vector.end());
	cout << "Vector after sorting: " << endl;
	for (int i = 0; i < Credits_vector.size(); ++i) {
		cout << Credits_vector[i];
	}cout << endl;

	deque<Credit> Credits_deque;
	copy(Credits_vector.begin(), Credits_vector.end(), back_inserter(Credits_deque));
	cout << "Deque copied from vector: " << endl;
	for (int i = 0; i < Credits_deque.size(); ++i) {
		cout << Credits_deque[i];
	}cout << endl;
}