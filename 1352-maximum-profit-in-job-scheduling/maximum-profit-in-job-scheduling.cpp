

// A simple structure to hold job details
struct Job {
    int start;
    int end;
    int profit;
};

class Solution {
private:
    int n;
    std::vector<Job> jobs;
    std::vector<int> memo;

    // Helper function for binary search to find the next non-overlapping job
    int findNextJob(int current_job_end_time) {
        int low = 0, high = n - 1;
        int next_index = n; // Default to n if no job is found

        // We need to find the first job whose start time is >= current_job_end_time
        // We can use std::lower_bound for this.
        auto it = std::lower_bound(jobs.begin(), jobs.end(), current_job_end_time, 
            [](const Job& job, int value) {
                return job.start < value;
            });
        
        // If a job is found, calculate its index
        if (it != jobs.end()) {
            next_index = std::distance(jobs.begin(), it);
        }

        return next_index;
    }


    // The recursive DP function with memoization
    int solve(int i) {
        // Base case: If we've run out of jobs to consider, profit is 0
        if (i >= n) {
            return 0;
        }

        // If we have already computed the result for this index, return it
        if (memo[i] != -1) {
            return memo[i];
        }

        // --- Choice 1: Skip the current job ---
        // The profit is the result of solving for the next job
        int profit_if_skipped = solve(i + 1);


        // --- Choice 2: Take the current job ---
        // Find the index of the next job that doesn't overlap
        int next_job_index = findNextJob(jobs[i].end);
        
        // The profit is the current job's profit + the result of solving from the next non-overlapping job
        int profit_if_taken = jobs[i].profit + solve(next_job_index);

        
        // Store the maximum of the two choices in our memo table and return it
        return memo[i] = std::max(profit_if_skipped, profit_if_taken);
    }

public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        this->n = startTime.size();
        
        // 1. Combine the separate arrays into a single vector of Job structs
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // 2. Sort the jobs based on their start times. This is crucial.
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.start < b.start;
        });

        // 3. Initialize memoization table with -1 (to indicate 'not computed')
        memo.assign(n, -1);

        // 4. Start the recursion from the first job (index 0)
        return solve(0);
    }
};