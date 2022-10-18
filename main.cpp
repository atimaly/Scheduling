#include <bits/stdc++.h>
#include <iostream>

#include "dp.h"

using namespace std;


int main(int argc, char** argv) {
	FORO(i,argc) {
		ifstream fin(argv[i]);
		DPSchedule Test(fin);
		Test.OrderJobs();
		Test.RunDPAlgorithm();
		string s = "out";
		ofstream fout(s+std::to_string(i));	
		Test.PrintOptimalOrderValue(fout);
		fin.close(); fout.close();
	}
}


/*
Sample Input
4
2 3 2 1
2 1 5 3
1 10 4 8
 
*/


