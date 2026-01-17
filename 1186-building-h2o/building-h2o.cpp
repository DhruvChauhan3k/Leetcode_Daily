class H2O {
private:
    mutex mtx;
    condition_variable cv;
    int hydrogen_count = 0;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);

        cv.wait(lck,[this](){return hydrogen_count<2;});

        hydrogen_count++;
        releaseHydrogen();
        
        // If two hydrogen atoms are ready, wake up oxygen
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);

        // Wait until exactly 2 hydrogens are available
        cv.wait(lck,[this](){return hydrogen_count==2;});

        releaseOxygen();

        // Reset for the next water molecule
        hydrogen_count = 0;
        // Notify waiting hydrogen threads
        cv.notify_all(); 
    }
};