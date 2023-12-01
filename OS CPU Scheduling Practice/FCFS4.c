#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    vector<int> p(n);//process id
    vector<int> ArrivalTime(n);
    vector<int> BurstTime(n);
    vector<int> CompletionTime(n);
    vector<int> WaitingTime(n);
    vector<int> TurnaroundTime(n);
    
    float avgWaitingTime = 0, avgTurnaroundTime = 0;//initializing to zero  
    
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << (i + 1) << ": ";// 'i+1' is process no
        cin >> ArrivalTime[i];
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> BurstTime[i];
        p[i] = i + 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (ArrivalTime[j] > ArrivalTime[j + 1]) {
                swap(ArrivalTime[j], ArrivalTime[j + 1]);//swapping arrival time
                swap(BurstTime[j], BurstTime[j + 1]);//arrival burst time
                swap(p[j], p[j + 1]);// swap process ids
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            CompletionTime[i] = ArrivalTime[i] + BurstTime[i];
        } else {
            if (ArrivalTime[i] > CompletionTime[i - 1]) {
                CompletionTime[i] = ArrivalTime[i] + BurstTime[i];
            } else {
                CompletionTime[i] = CompletionTime[i - 1] + BurstTime[i];
            }
        }
        TurnaroundTime[i] = CompletionTime[i] - ArrivalTime[i];
        WaitingTime[i] = TurnaroundTime[i] - BurstTime[i];
        avgWaitingTime += static_cast<float>(WaitingTime[i]);//converting int waitingTime into float
        avgTurnaroundTime += static_cast<float>(TurnaroundTime[i]);//
    }
    
    cout << "\npid  arrivalT  burstT  completeT turnT waitingT" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << "  \t " << ArrivalTime[i] << "\t" << BurstTime[i] << "\t" << CompletionTime[i] << "\t"
             << TurnaroundTime[i] << "\t" << WaitingTime[i] << endl;
    }
    
    cout << "\naverage waiting time: " << (avgWaitingTime / n) << endl;
    cout << "average turnaround time: " << (avgTurnaroundTime / n) << endl;
    
    return 0;
}
