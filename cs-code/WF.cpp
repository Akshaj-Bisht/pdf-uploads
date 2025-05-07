#include <iostream>
#include <vector>
using namespace std;

void sortInsertDescending(vector<int>& a, vector<int>& index) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i], idx = index[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            index[j + 1] = index[j];
            j--;
        }
        a[j + 1] = key;
        index[j + 1] = idx;
    }
}

int main() {
    vector<int> memory = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};

    vector<int> temp_memory = memory;
    vector<int> index(memory.size());
    for (int i = 0; i < index.size(); i++) index[i] = i;

    sortInsertDescending(temp_memory, index);
    vector<bool> used(memory.size(), false);

    cout << "Worst Fit Allocation:\n";
    for (int i = 0; i < process.size(); i++) {
        int pos = -1;
        for (int j = 0; j < temp_memory.size(); j++) {
            if (!used[j] && temp_memory[j] >= process[i]) {
                pos = j;
                break;
            }
        }
        if (pos != -1) {
            cout << "Process " << i + 1 << " of size " << process[i]
                 << " allocated to block " << index[pos] + 1
                 << ", remaining: " << temp_memory[pos] - process[i] << " KB\n";
            temp_memory[pos] -= process[i];
            used[pos] = true;
        } else {
            cout << "Process " << i + 1 << " of size " << process[i] << " not allocated\n";
        }
    }
    return 0;
}
