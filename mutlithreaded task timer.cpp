#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

// Function that simulates a timer for a given task
void taskTimer(string taskName, int seconds) {
    while (seconds > 0) {
        cout << taskName << ": " << seconds << " seconds remaining\n";
        this_thread::sleep_for(chrono::seconds(1));
        --seconds;//as time is decreasing
    }
    cout << " Task " << taskName << " completed.\n";
}

int main() {
    int numTasks;
    cout << "Enter number of tasks: ";
    cin >> numTasks;

    vector<thread> taskThreads;

    for (int i = 0; i < numTasks; ++i) {
        string name;
        int timeSec;

        cout << "Enter name for task " << (i + 1) << ": ";//because i starts from 0
        cin >> name;
        

        cout << "Enter duration in seconds for task \"" << name << "\": ";
        cin >> timeSec;

        // Start a thread for each task
        taskThreads.emplace_back(taskTimer, name, timeSec);//emplace_back efficiency is better than push_back as it constructs an object in place inside the container
    }

    // Join all threads
  for (auto& t : taskThreads) {// For each thread t in the vector taskThreads, wait (join) until it's finished before continuing. This ensures that the main function waits for all tasks to complete before printing the final message,we used by reference because thread objects
        t.join();
    }

    cout << "All tasks completed.\n";
    return 0;
}


