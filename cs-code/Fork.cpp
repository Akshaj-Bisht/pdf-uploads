#include <iostream>
#include <unistd.h>   // For fork(), getpid(), getppid()
#include <sys/types.h> // For pid_t

using namespace std;

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        cout << "Child Process: PID = " << getpid() 
             << ", Parent PID = " << getppid() << endl;
    } 
    else {
        // Parent process
        cout << "Parent Process: PID = " << getpid() 
             << ", Child PID = " << pid << endl;
    }

    return 0;
}
