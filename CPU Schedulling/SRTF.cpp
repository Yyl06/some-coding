#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <fstream>
using std::cout, std::ifstream;

//Process structure
struct Processes{
    int pid, arrivalTime, burstTime, remainingTime; //[process id, arrival time, burst time, remaining time]
    double completionTime, waitingTime, turnaroundTime;//[completion time, waiting time, turnaround time]
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

void SRTFCalculation(std::vector<Processes> proc){
    int n = proc.size(); // Get the size of the process vector(number of processes)
    int time = 0, completed = 0;//[current time, number of processes completed]
    double totalTAT = 0, totalWT = 0; //for calculating average turnaround time and waiting time
    
    // To build Gantt chart
    std::vector<std::pair<int,int>> gantt; // (processID, startTime)
    int lastProc = -1;

    // while all processes are not completed
    while(completed < n){
        int idx = -1; //Index of process with minimum remaining time
        int mn = INT_MAX; // Minimum remaining time found

        // Find process with shortest remaining time that has already arrived
        for(int i = 0 ; i < n; i++){
            if(proc[i].arrivalTime <= time && proc[i].remainingTime > 0){
                if(proc[i].remainingTime < mn){
                    mn = proc[i].remainingTime;
                    idx = i;
                }
            }
        }

        if(idx != -1){
            //Log the Gantt chart entry when switching processes
            if (lastProc != proc[idx].pid) {
                gantt.push_back({proc[idx].pid, time});
                lastProc = proc[idx].pid;
            }


            // Execute process for 1 unit of time(preemptive, which can be interrupted)
            proc[idx].remainingTime--;
            time++;

            //If process finished execution, run this
            if(proc[idx].remainingTime == 0){
                completed++; //Completed process +1
                proc[idx].completionTime = time; // Set completion time
                proc[idx].turnaroundTime = proc[idx].completionTime - proc[idx].arrivalTime; //Turnaround time = completion time - arrival time
                proc[idx].waitingTime = proc[idx].turnaroundTime - proc[idx].burstTime;// Waiting time = turnaround time - burst time
                totalTAT += proc[idx].turnaroundTime;//Accumulate total turnaround time
                totalWT += proc[idx].waitingTime;//Accumulate total waiting time
            }
        }else{
            // If no process is ready -> CPU Idling
            time++;
        }
    }

    //Display
    cout << std::fixed << std::setprecision(2);
    cout << "\nShortest Remaining Time First (SRTF)";
    // Close Gantt chart with final time
    gantt.push_back({-1, time});
    cout << "\n--- SRTF Gantt Chart ---\n";
    for (size_t i = 0; i < gantt.size()-1; i++) {
        cout << "| P" << gantt[i].first << "  ";
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
    readFromFile(proc);
    SRTFCalculation(proc);
    return 0;
}
