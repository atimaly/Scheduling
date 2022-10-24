#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#ifndef SCHEDULE_DP
#define SCHEDULE_DP
class DPSchedule{
		struct Job{
			int id;
			int due_date_;
			int processing_time_;
			int weight_;
			
			bool operator<(const Job &j) {
				return  due_date_ < j.due_date_;
			}
		};
		
		int n_;
		vector<Job> jobs_;
		vector<vector<int>> DP_; //row coordinates are the jobs, the columns are weights
		int optimal_value_;
		
	public:
		
		DPSchedule(std::istream &is = std::cin);
	
		DPSchedule(int n, vector<int> &dues, vector<int> &proc_t, vector<int> &w);
		
		void PrintData(std::ostream &os = std::cerr);
		
		void OrderJobs(); //Order the Jobs according to their due dates
		
		void RunDPAlgorithm(std::ostream &os = std::cerr);
		
		vector<int> OptimalOrderForJobs(std::ostream &os = std::cerr); //Getting the optimal ordering from the DP
		
		void PrintOptimalOrderValue(std::ostream &os = std::cout); //Prints out the optimal order and value
		

};
#endif //SCHEDULE_DP

#ifndef UTILITY_TOOLS
#define UTILITY_TOOLS
using ll = long long int;

const long long int INF = 10000000000;

#define all(x) begin(x), end(x)
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define FORO(i,n) for(int i = 1; i < (n); ++i)

template <class C>
void Print_vector(const C &Original, std::ostream &os = std::cerr) {
	for(const auto &v : Original) {
	    os << v << " ";
	}
	os << endl;
}

template <class C>
void Print_Matrix(const vector<vector<C>> &M, std::ostream &os = std::cerr) {
	for(auto &v : M) {
		for(auto &u : v) {
			os << u; os << " ";            
			}
	    os << endl;
	}
}

template<class T, class C>
void Print_pair(const pair<T,C> &M) {
    cout << "(" << M.first << " , " << M.second << " ) ";
}

template <class C>
void Print_vector_pairs(const C &Original) {
	for(const auto &v : Original) {
	    Print_pair(v);
	}
	cout << endl;
}
#endif //UTILITY_TOOLS
