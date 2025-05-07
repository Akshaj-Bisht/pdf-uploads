#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], bt[n], wt[n], tat[n];
    float avgWT = 0, avgTAT = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter burst time for Process " << pid[i] << ": ";
        cin >> bt[i];
    }

    // Sort processes by burst time (simple selection sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // First process has 0 waiting time
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time and averages
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Display results
    cout << "\nPID\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << avgWT;
    cout << "\nAverage Turnaround Time: " << avgTAT << "\n";

    return 0;
}
