#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

class PThreadLibrary {
public:
    // Function type for threads
    typedef void* (*ThreadFunc)(void*);

    // Create a thread and store its ID
    pthread_t createThread(ThreadFunc func, void* arg = nullptr) {
        pthread_t threadID;
        if (pthread_create(&threadID, nullptr, func, arg) != 0) {
            cerr << "Error: Failed to create thread!" << endl;
            return 0;
        }
        threads.push_back(threadID);
        return threadID;
    }

    // Wait for all threads to finish
    void joinAll() {
        for (pthread_t thread : threads) {
            pthread_join(thread, nullptr);
        }
        threads.clear();
    }

private:
    vector<pthread_t> threads;
};

// Example thread function
void* printMessage(void* arg) {
    cout << "Thread ID: " << pthread_self() << " - " 
         << static_cast<const char*>(arg) << endl;
    return nullptr;
}

int main() {
    PThreadLibrary threadLib;

    // Create multiple threads
    threadLib.createThread(printMessage, (void*)"Hello from Thread 1");
    threadLib.createThread(printMessage, (void*)"Hello from Thread 2");

    // Wait for all threads to finish
    threadLib.joinAll();

    return 0;
}
