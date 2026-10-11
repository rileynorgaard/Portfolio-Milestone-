#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void countUp()
{
    for (int counter = 1; counter <= 20; ++counter)
    {
        cout << "Thread 1 - Count up: "
             << counter << '\n';

        this_thread::sleep_for(100ms);
    }
}

void countDown()
{
    for (int counter = 20; counter >= 0; --counter)
    {
        cout << "Thread 2 - Count down: "
             << counter << '\n';

        this_thread::sleep_for(100ms);
    }
}

int main()
{
    cout << "Starting the counter application."
         << '\n';

    thread thread1(countUp);

    thread1.join();

    cout << "Thread 1 completed. Starting thread 2."
         << '\n';

    thread thread2(countDown);

    thread2.join();

    cout << "Both threads completed successfully."
         << '\n';

    return 0;
}