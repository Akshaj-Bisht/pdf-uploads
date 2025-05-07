#include <iostream>
#include <climits>

using namespace std;

#define MAX 100  // Maximum size for arrays

// Function for First Fit
void firstFit(int holes[], int numHoles, int processes[], int numProcesses) {
    int allocation[MAX];  // Store allocated hole index for each process
    fill_n(allocation, numProcesses, -1);  // Initialize all allocations to -1

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numHoles; j++) {
            if (holes[j] >= processes[i]) {  // Check if the hole is big enough
                allocation[i] = j;  // Allocate process to hole index j
                holes[j] -= processes[i];  // Reduce hole size
                break;  // Stop searching for this process
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << " (" << processes[i] << " KB) -> ";
        if (allocation[i] != -1)
            cout << "Hole " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

// Function for Best Fit
void bestFit(int holes[], int numHoles, int processes[], int numProcesses) {
    int allocation[MAX];
    fill_n(allocation, numProcesses, -1);

    for (int i = 0; i < numProcesses; i++) {
        int bestIdx = -1;
        for (int j = 0; j < numHoles; j++) {
            if (holes[j] >= processes[i]) {
                if (bestIdx == -1 || holes[j] < holes[bestIdx]) {
                    bestIdx = j;  // Select the smallest suitable hole
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            holes[bestIdx] -= processes[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << " (" << processes[i] << " KB) -> ";
        if (allocation[i] != -1)
            cout << "Hole " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

// Function for Worst Fit
void worstFit(int holes[], int numHoles, int processes[], int numProcesses) {
    int allocation[MAX];
    fill_n(allocation, numProcesses, -1);

    for (int i = 0; i < numProcesses; i++) {
        int worstIdx = -1;
        for (int j = 0; j < numHoles; j++) {
            if (holes[j] >= processes[i]) {
                if (worstIdx == -1 || holes[j] > holes[worstIdx]) {
                    worstIdx = j;  // Select the largest suitable hole
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            holes[worstIdx] -= processes[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << " (" << processes[i] << " KB) -> ";
        if (allocation[i] != -1)
            cout << "Hole " << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

int main() {
    int holes[MAX] = {100, 500, 200, 300, 600};  // Memory holes
    int processes[MAX] = {212, 417, 112, 426};  // Memory requests
    int numHoles = 5, numProcesses = 4;

    firstFit(holes, numHoles, processes, numProcesses);
    
    // Reset holes since they were modified in firstFit
    int holes2[MAX] = {100, 500, 200, 300, 600};  
    bestFit(holes2, numHoles, processes, numProcesses);
    
    int holes3[MAX] = {100, 500, 200, 300, 600};  
    worstFit(holes3, numHoles, processes, numProcesses);

    return 0;
}