#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip>
#include <climits>
using std::cout, std::ifstream;

//Process structure
struct Processes{
    int pid, arrivalTime, burstTime, remainingTime; //[process id, arrival time, burst time, remaining time]
    double completionTime, waitingTime, turnAroundTime; //[completion time, waiting time, turnaround time]
};

//Read Process Data from file
void readFromFile(std::vector<Processes> &proc) {
    std::vector<std::string> files = {
        "Data1.txt",
        "Data2.txt",
        "Data3.txt",
        "Data4.txt",
        "Data5.txt"
    };
    int pid_counter = 1;
    for(const auto &file : files){
        ifstream inFile(file);
        if(!inFile.is_open()){
            std::cerr << "Error opening file: " << file << "\n";
            exit(1);
        }
        int at, bt;
        while(inFile >> at >> bt){
            Processes p;
            p.pid = pid_counter++;
            p.arrivalTime = at;
            p.burstTime = bt;
            p.remainingTime = bt; // Initially remaining = burst
            proc.push_back(p);
        }
        inFile.close();
    }
}

// Round Robin Time Quantum Reading
void readQuantums(std::vector<int> &quantums,  const std::string &fileName){
    ifstream inFile(fileName);
    if(!inFile.is_open()){
        std::cerr << "Error opening file: " << fileName << "\n";
        exit(1);
    }
    int quantum;
    while(inFile >> quantum){
        quantums.push_back(quantum);
    }
    inFile.close();
}


void RRCalculation(std::vector<Processes> proc, int timeQuantum){
    int n = proc.size(); // Get the size of the process vector(number of processes)
    std::queue<int> q; //Queue for ready processes
    std::vector<bool> inQueue(n, false); // To avoid duplicate enqueues
    int time = 0, completed = 0; //[current time, number of processes completed]
    double totalTAT = 0, totalWT = 0; //for calculating averages

    // Gantt chart storage
    std::vector<std::pair<int,int>> gantt; 
    int lastProc = -1;

    //Start with the first process that arrives
    int firstArrival = INT_MAX;
    for (int i = 0; i < n; i++) firstArrival = std::min(firstArrival, proc[i].arrivalTime);
    time = firstArrival;

    // Run until all processes complete
    while(completed < n){
        // Enqueue all processes that have arrived by current time
        for(int i = 0 ; i < n; i++){
            if(proc[i].arrivalTime <= time && proc[i].remainingTime > 0 && !inQueue[i]){
                q.push(i);
                inQueue[i] = true;
            }
        }
        // If no process is ready → advance time
        if(q.empty()){time++; continue;}
        // Pick the next process from the queue
        int idx = q.front(); q.pop();
        inQueue[idx] = false;

        // Log Gantt chart when process changes
        if (lastProc != proc[idx].pid) {
            gantt.push_back({proc[idx].pid, time});
            lastProc = proc[idx].pid;
        }

        // Execute it for "quantum" time or until completion
        int exec = std::min(timeQuantum, proc[idx].remainingTime);
        proc[idx].remainingTime -= exec;
        time += exec;

        // Add new arrivals during this execution
        for(int i = 0; i < n; i++){
            if(proc[i].arrivalTime <= time && proc[i].remainingTime > 0 && !inQueue[i]){
                q.push(i);
                inQueue[i] = true;
            }
        }

        if(proc[idx].remainingTime == 0){
            // Process finished
            completed++;
            proc[idx].completionTime = time;
            proc[idx].turnAroundTime = proc[idx].completionTime - proc[idx].arrivalTime;
            proc[idx].waitingTime = proc[idx].turnAroundTime - proc[idx].burstTime;
            totalTAT += proc[idx].turnAroundTime;
            totalWT += proc[idx].waitingTime;
        } else {
            //Re-enqueue the process if not finished
            q.push(idx);
            inQueue[idx] = true;
        }
    }
    // Show results
    cout << std::fixed << std::setprecision(2);
    cout << "\n--- Round Robin (Time Quantum = " << timeQuantum << ") ---";
    gantt.push_back({-1, time});
    cout << "\n--- Round Robin (Time Quantum = " << timeQuantum << ") Gantt Chart ---\n";
    for (size_t i = 0; i < gantt.size()-1; i++) {
        cout << "\t| P" << gantt[i].first << "   ";
    }
    cout << "|\n";
    for (size_t i = 0; i < gantt.size(); i++) {
        cout << gantt[i].second << "    ";
    }
    cout << "\n";
    cout << "Average Turnaround Time = " << totalTAT / n << "\n";
    cout << "Average Waiting Time    = " << totalWT / n << "\n";
}

int main(){
    std::vector<Processes> proc;
    std::vector<int> quantums;

    //Load Process Data from file
    readFromFile(proc);
    //Load Time Quantums from file
    readQuantums(quantums, "TimeQuantum.txt");

    // Run RR with 3 different quantums
    for (int q : quantums) {
        std::vector<Processes> tmp = proc; // fresh copy each time
        for (auto &p : tmp) p.remainingTime = p.burstTime;
        RRCalculation(tmp, q);
    }
    return 0;
}