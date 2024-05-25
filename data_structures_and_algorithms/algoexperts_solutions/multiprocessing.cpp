/*
in c++ , multiprocessing is achived through various mechanisms and the language provides features and 
libraries to facilitate concurrent and parallel programming. key aspects related to multiprocessing 
1. Standard Library Features:

    C++11 and later standards introduced several features to support multithreading and multiprocessing.
    The <thread> header provides facilities for creating and managing threads.
    The <mutex> and <atomic> headers offer synchronization primitives like mutexes and atomic operations.

    explanation of mutex:
    In C++, a standard mutex (mutual exclusion) is a synchronization primitive provided by the <mutex> 
    header in the C++ Standard Library. Mutexes are used to protect shared data and ensure that only one 
    thread can access the critical section (the code that operates on shared data) at a time. 
    The standard mutex is a simple and flexible mechanism for preventing data races and ensuring thread safety.

    Locking and Unlocking a Mutex:

    Locking: To acquire ownership of the mutex, a thread calls lock() on the mutex. If another thread already 
    owns the mutex, the calling thread will be blocked until the mutex becomes available.

    #include <iostream>
    #include <mutex>
    #include <thread>

    Locking and Unlocking a Mutex:

    Locking: To acquire ownership of the mutex, a thread calls lock() on the mutex. 
    If another thread already owns the mutex,the calling thread will be blocked until 
    the mutex becomes available.

    syntax
    std::lock_guard<std::mutex> lock(myMutex);
    // critical section 
    // access shared data safely

    Unlocking: The lock_guard automatically releases the lock when it goes out of scope.
    Alternatively, you can manually unlock the mutex using unlock().

    std::lock_guard<std::mutex> lock(myMutex);
    // Critical section
    // Access shared data safely
    lock.unlock();  // Manually unlock

    note by that the std::lock_guard is a RAII( Resource Acquisition is Initialization ) wrapper for locking and 
    unlocking the mutex

    when a thread enters the std::lock_guard scope it acquires the lock on the mutex and when it goes out of 
    scope e.g at the end of t function , it releases the lock automatically 


    note by : local static variables are guaranteed to only be initialized once and their destruction occurs when 
    the program exits .
    this is often reffered to as the magic static 

    summary so just note that with the thread safe approach the std::lock_guard only ensures that only one thread 
    has access to the critical section of code at a time 

2. Thread Creation 

    C++ provides a std::thread class for creating and managing threads.
    Example of creating a thread:

    syntax example 
    #include <iostream>
    #include <thread>

    void myFunction() {
        std::cout << "Hello from a thread!" << std::endl;
    }

    int main() {
        std::thread myThread(myFunction);
        myThread.join();  // Wait for the thread to finish

        return 0;
    }
    
3. Thread Syncronization 

    Mutexes can be used for protecting shared data and avoiding data races in multithreaded programs.
    if one thread has the lock on the shared resource through the mutex, then the second thread has to 
    wait for the first thread to first finish 

    #include <iostream>
    #include <thread>
    #include <mutex>

    std::mutex myMutex;

    void myFunction() {
        std::lock_guard<std::mutex> lock(myMutex);
        std::cout << "Hello from a thread!" << std::endl;
    }

    int main() {
        std::thread myThread(myFunction);
        myThread.join();

        return 0;
    }
4. Parallel Algorithms 

    the c++ stl c++ 17 introduces parallel versions of many algorithms in the <algorithm> header, these 
    algorithms take advantage of multiple threads of parallel execution 

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <execution>

    int main() {
        std::vector<int> data = {5, 2, 8, 1, 7, 3};
        std::sort(std::execution::par, data.begin(), data.end());

        for (const auto& element : data) {
            std::cout << element << " ";
        }

        return 0;
    }

5. Parallelism in Standard Library:

    C++17 introduced the <execution> header, which defines execution policies for algorithms. 
    These policies can be used to control the execution of parallel algorithms.

6. Third Party Libraries 

    libraries like intel TBB (threading building blocks ) and OpenMP provide additional tools for 
    parallel programming in C++

7. Atomic Operations 
    The <atomic> header provides support for atomic operations,
    which are essential for avoiding data races in multithreaded environments.

C++ provides a variety of tools for multiprocessing, ranging from low-level thread management to 
high-level parallel algorithms. When working with multithreading and multiprocessing in C++, 
it's crucial to carefully manage synchronization, avoid data races, and ensure thread safety.
*/


// code for atomic operations 
#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Counter value: " << counter.load(std::memory_order_relaxed) << std::endl;

    return 0;
}

