#include <bits/stdc++.h>
#include <iostream>

#include "dp.h"

using namespace std;


int main() {
	
	DPSchedule Test;
	cerr << "Read it" <<endl;
	Test.PrintData();
	cerr << "After Ordering " << endl;
	Test.OrderJobs();
	Test.PrintData();
	
	cerr << "After DP " << endl;
	Test.RunDPAlgorithm();
	Test.PrintData();
	
	vector<int> order_j = Test.OptimalOrderForJobs();
	Print_vector(order_j);
	
	Test.PrintOptimalOrderValue();
}


/*
Sample Input
4
2 3 2 1
2 1 5 3
1 10 4 8
 
*/


