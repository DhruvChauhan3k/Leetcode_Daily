class DiningPhilosophers {
private:
    mutex mtxFork[5];
    // mutex mtxTable;
    
public:
    DiningPhilosophers() { }
    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork, function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int leftFork = philosopher;
        int rightFork = (philosopher + 1) % 5;
        
        // 2. Determine Locking Order
        // To prevent deadlock, always lock the smaller index first.
        int first = std::min(leftFork, rightFork);
        int second = std::max(leftFork, rightFork);

        // 3. Acquire Locks
        // We use lock_guard to ensure exceptions (unlikely here) 
        // or returns don't leave mutexes locked.
        // Note: lock_guard locks immediately upon construction.
        
        // Lock the first (smaller ID) fork
        lock_guard<std::mutex> lock1(mtxFork[first]);
        // Lock the second (larger ID) fork
        lock_guard<std::mutex> lock2(mtxFork[second]);

        // 4. Perform Actions
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        putRightFork();
    }
};