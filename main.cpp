#include <bits/stdc++.h>
#include <iostream>

#include "dp.h"

using namespace std;


int main() {
	
	DPSchedule Test;
	Test.OrderJobs();
	Test.RunDPAlgorithm();	
	Test.PrintOptimalOrderValue();
}


/*
Sample Input
4
2 3 2 1
2 1 5 3
1 10 4 8
 
*/


