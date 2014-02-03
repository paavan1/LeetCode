#include<string>
#include<vector>
#include<fstream>
#include <stdlib.h>
#include<iostream>
#include <sstream>
#include<algorithm>

using namespace std;

struct event{
	long long id;
	long long start;
	long long end;
	long long score;
};

void importData(string filename1, string filename2,  vector<event> &data, vector<event> &scoring)
{
	ifstream inFile, outFile;

	inFile.open(filename1.c_str());
	outFile.open(filename2.c_str());

	string line;

	//get total Number
	getline(inFile, line);

	int row = atoi(line.c_str());

	for(int i = 0; i < row; i++)
	{
		event temp;

		getline(inFile,line);

		istringstream stm(line);

		string word;

		stm >> word; temp.id = atoll(word.c_str());

		stm >> word; temp.start = atoll(word.c_str());

		stm >> word; temp.end = atoll(word.c_str());

		//cout<<temp.id<<" "<<temp.start<<" "<<temp.end<<endl;

		data.push_back(temp);

		line.clear();

		getline(outFile,line);

		istringstream stm2(line);

		stm2 >> word; temp.id = atoll(word.c_str());

		stm2 >> word; temp.score = atoll(word.c_str());

		scoring.push_back(temp);

	}

	inFile.close();
	outFile.close();
}

bool myComp1(const event &e1, const event &e2)
{
	if( e1.start < e2.start ) return true;

	if( e1.start == e2.start ) return e1.id < e2.id;

	return false;
}

bool myComp2(const event &e1, const event &e2)
{
	if( e1.score < e2.score ) return true;

	if( e1.score == e2.score ) return e1.id < e2.id;

	return false;
}

void raceRater()
{
	string filename1("C:/COMPUTER_SCIENCE/Coding Test/RacerRater_testcases/input004.txt");
	string filename2("C:/COMPUTER_SCIENCE/Coding Test/RacerRater_testcases/output004.txt");

	vector<event> data;
	vector<event> scoring;

	importData(filename1, filename2, data, scoring);

	sort(data.begin(), data.end(), myComp1);

	unsigned i = 0, j = 0;
	for(i = 0; i < data.size(); i++)
	{
		int cnt = 0;
		for(j = i + 1; j < data.size() && data[j].start <= data[i].end; j++)
		{
			if(data[j].end <= data[i].end) cnt++;
		}

		data[i].score = cnt;
	}

	sort(data.begin(), data.end(), myComp2);


	for(i = 0; i < data.size(); i++)
	{
		cout<<data[i].id<<" "<<data[i].score<<endl;
		cout<<scoring[i].id<<" "<<scoring[i].score<<endl;
		cout<<"----------------------"<<endl;
		if(data[i].id != scoring[i].id || data[i].score != scoring[i].score)
		{
			cout<<"error!"<<endl; break;
		}
	}

	if(i == data.size()) cout<<"pass the test!"<<endl;
}

int main()
{
	raceRater();
}
