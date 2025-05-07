#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> memory = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};

    vector<int> temp_memory = memory;

    cout << "First Fit Allocation:\n";
    for (int i = 0; i < process.size(); i++) {
        bool allocated = false;
        for (int j = 0; j < temp_memory.size(); j++) {
            if (temp_memory[j] >= process[i]) {
                cout << "Process " << i + 1 << " of size " << process[i]
                     << " allocated to block " << j + 1
                     << ", remaining: " << temp_memory[j] - process[i] << " KB\n";
                temp_memory[j] -= process[i];
                allocated = true;
                break;
            }
        }
        if (!allocated)
            cout << "Process " << i + 1 << " of size " << process[i] << " not allocated\n";
    }
    return 0;
}
