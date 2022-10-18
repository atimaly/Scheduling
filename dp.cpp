#include <bits/stdc++.h>
#include <iostream>

#include "dp.h"

using namespace std;


DPSchedule::DPSchedule(std::istream &is) : optimal_value_{0} {
	cout << "Give me the number of jobs!" << endl;
	is >> n_;
	jobs_.resize(n_);
	cout << "Give me the due dates (positive int) for the jobs!" << endl;
	FOR(i,n_) is >> jobs_[i].due_date_;
	
	cout << "Give me the processing times (positive int) for the jobs!" << endl;
	FOR(i,n_) is >> jobs_[i].processing_time_;
	
	cout << "Give me the weights (positive int) for the jobs!" << endl;
	FOR(i,n_) is >> jobs_[i].weight_;
	
	int weight_sum = std::accumulate(all(jobs_), 0, [&](int s, Job c){return s+c.weight_;});
	DP_.resize(n_+1);
	for(auto &v : DP_) v.resize(weight_sum+1, INF);	
}

DPSchedule::DPSchedule(int n, vector<int> &dues, vector<int> &proc_t, vector<int> &w) : n_{n}, optimal_value_{0} {
	assert(n_ == (int)dues.size()); assert(n_ ==  (int)proc_t.size()); assert(n_ == (int)w.size());
	
	jobs_.resize(n_);
	FOR(i,n_) {
		jobs_[i].due_date_ = dues[i];
		jobs_[i].processing_time_ = proc_t[i];
		jobs_[i].weight_ = w[i];
	}
	
	int weight_sum = std::accumulate(all(jobs_), 0, [&](int s, Job c){return s+c.weight_;});
	DP_.resize(n_+1);
	for(auto &v : DP_) v.resize(weight_sum+1, INF);
}

void DPSchedule::PrintData(std::ostream &os) {
	os << "The number of Jobs: "<< n_ << endl;
	os << "Jobs:" << endl;
	for(auto v : jobs_) {
		os << "Due date: "<< v.due_date_ << " Processing Time: " << v.processing_time_ << " Weight: " << v.weight_ << endl;
	}
	os << "DP:\n";
	Print_Matrix(DP_);
}

void DPSchedule::OrderJobs() {
	std::sort(all(jobs_));
}


void DPSchedule::RunDPAlgorithm(std::ostream &os) {
	if(!std::is_sorted(all(jobs_)))
		OrderJobs();
	
	//intialize the weight=0 column to 0
	FOR(i,(int)DP_.size()) {
		DP_[i][0] = 0;
	}
	
	
	FORO(i,(int)DP_.size()) {
		FORO(j,(int)DP_[0].size()) {
			//os << "i: " << i << " j: " << j << endl;
			//os << "j - jobs_[i].weight_: " << j - jobs_[i-1].weight_ << endl;
			if(j - jobs_[i-1].weight_ >= 0)
				if(DP_[i-1][j - jobs_[i-1].weight_] + jobs_[i-1].processing_time_ <= jobs_[i-1].due_date_)
					DP_[i][j] = std::min(DP_[i-1][j], DP_[i-1][j - jobs_[i-1].weight_] + jobs_[i-1].processing_time_);
				else DP_[i][j] = DP_[i-1][j];
			else DP_[i][j] = DP_[i-1][j];
		}
	}
}


vector<int> DPSchedule::OptimalOrderForJobs(std::ostream &os) {
	optimal_value_ = 0;
	
	vector<int> can_jobs_order;
	vector<int> can_not_jobs;
	
	auto first_non_inf = std::find_if_not(DP_[n_].rbegin(), DP_[n_].rend(), [](int i){return i == (int)INF;});
	
	//os << "Size: " << int(DP_[n_].size()) << endl;
	int index_w = int(DP_[n_].size()) -1 - std::distance(DP_[n_].rbegin(), first_non_inf);
	for(int i = n_; i > 0; --i) {
		//os << "i: " << i << " index_w: " << index_w << endl;
		//os << "curr: " << DP_[i][index_w] << " lower: " << DP_[i-1][index_w] << endl;
		if(DP_[i][index_w] != DP_[i-1][index_w]) {
			can_jobs_order.push_back(i-1);
			index_w -= jobs_[i-1].weight_;
		}
		else{
			can_not_jobs.push_back(i-1);
			optimal_value_ += jobs_[i-1].weight_;
		}
	}
	
	std::reverse(all(can_jobs_order));
	can_jobs_order.insert(can_jobs_order.end(), all(can_not_jobs));
	return can_jobs_order;
}

void DPSchedule::PrintOptimalOrderValue(std::ostream &os) {
	optimal_value_ = 0;
	os << "Optimal Order: ";
	Print_vector(OptimalOrderForJobs(), os);
	os << "Optimal Value: " << optimal_value_ << endl;
	
}
