#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Enter no of process: ";
    int totalProcesses;
    cin >> totalProcesses;

    vector<int> pid(totalProcesses);
    vector<int> arrivalTime(totalProcesses);
    vector<int> burstTime(totalProcesses);
    vector<int> completionTime(totalProcesses, 0);
    vector<int> turnaroundTime(totalProcesses);
    vector<int> waitingTime(totalProcesses);
    vector<int> flag(totalProcesses, 0);
    vector<int> TempBurst(totalProcesses);
    int executedTime = 0;
    int executedProcesses = 0;
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;

    for (int i = 0; i < totalProcesses; i++) {
        pid[i] = i + 1;
        cout << "Enter process " << (i + 1) << " arrival time: ";
        cin >> arrivalTime[i];
        cout << "Enter process " << (i + 1) << " burst time: ";
        cin >> burstTime[i];
        TempBurst[i] = burstTime[i];
        flag[i] = 0;
    }

    while (true) {
        int min = 99, c = totalProcesses;
        if (executedProcesses == totalProcesses)
            break;

        for (int i = 0; i < totalProcesses; i++) {
            if ((arrivalTime[i] <= executedTime) && (flag[i] == 0) && (burstTime[i] < min)) {
                min = burstTime[i];
                c = i;
            }
        }

        if (c == totalProcesses)
            executedTime++;
        else {
            burstTime[c]--;
            executedTime++;
            if (burstTime[c] == 0) {
                completionTime[c] = executedTime;
                flag[c] = 1;
                executedProcesses++;
            }
        }
    }

    for (int i = 0; i < totalProcesses; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - TempBurst[i];
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
    }

    cout << "pid  arrival  burst  complete turn waiting" << endl;
    for (int i = 0; i < totalProcesses; i++) {
        cout << pid[i] << "\t" << arrivalTime[i] << "\t" << TempBurst[i] << "\t" << completionTime[i] << "\t" << turnaroundTime[i] << "\t" << waitingTime[i] << endl;
    }

    cout << "\nAverage Turnaround Time is " << (averageTurnaroundTime / totalProcesses) << endl;
    cout << "Average Waiting Time is " << (averageWaitingTime / totalProcesses) << endl;

    return 0;
}
