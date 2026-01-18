#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;
    int cnt;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->cnt = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            // Wait until it's time for Fizz OR we are done (cnt > n)
            cv.wait(lck, [this] { 
                return cnt > n || (cnt % 3 == 0 && cnt % 5 != 0); 
            });
            
            if (cnt > n) break; // Exit loop if we've reached the limit
            
            printFizz();
            cnt++;
            cv.notify_all(); // Wake up all other threads to check the new cnt
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { 
                return cnt > n || (cnt % 5 == 0 && cnt % 3 != 0); 
            });
            
            if (cnt > n) break;
            
            printBuzz();
            cnt++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { 
                return cnt > n || (cnt % 3 == 0 && cnt % 5 == 0); 
            });
            
            if (cnt > n) break;
            
            printFizzBuzz();
            cnt++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [this] { 
                return cnt > n || (cnt % 3 != 0 && cnt % 5 != 0); 
            });
            
            if (cnt > n) break;
            
            printNumber(cnt);
            cnt++;
            cv.notify_all();
        }
    }
};