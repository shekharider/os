        #include <iostream>
        using namespace std;

        int main() {
            int n, i, qt, count = 0, temp, sq = 0;
            int burstTime[10], waitingTime[10], turnaroundTime[10], remainingBurstTime[10];
            float averageWaitingTime = 0, averageTurnaroundTime = 0;

            cout << "Enter the number of processes (maximum 10) = ";
            cin >> n;

            cout << "Enter the burst time of the processes" << endl;
            for (i = 0; i < n; i++) {
                cout << "P" << i << " = ";
                cin >> burstTime[i];
                remainingBurstTime[i] = burstTime[i];
            }

            cout << "Enter the quantum time: ";
            cin >> qt;

            while (true) {
                for (i = 0, count = 0; i < n; i++) {
                    temp = qt;
                    if (remainingBurstTime[i] == 0) {
                        count++;
                        continue;
                    }
                    if (remainingBurstTime[i] > qt)
                        remainingBurstTime[i] -= qt;
                    else if (remainingBurstTime[i] >= 0) {
                        temp = remainingBurstTime[i];
                        remainingBurstTime[i] = 0;
                    }
                    sq += temp;
                    turnaroundTime[i] = sq;
                }
                if (n == count)
                    break;
            }

            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "Process\t      Burst Time\t       Turnaround Time\t          Waiting Time" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;

            for (i = 0; i < n; i++) {
                waitingTime[i] = turnaroundTime[i] - burstTime[i];
                averageWaitingTime += waitingTime[i];
                averageTurnaroundTime += turnaroundTime[i];
                cout << " " << (i + 1) << "\t\t " << burstTime[i] << "\t\t\t " << turnaroundTime[i] << "\t\t\t\t " << waitingTime[i] << endl;
            }

            averageWaitingTime /= n;
            averageTurnaroundTime /= n;
            cout << "\nAverage waiting Time = " << averageWaitingTime << "\n";
            cout << "Average turnaround time = " << averageTurnaroundTime << endl;

            return 0;
        }
