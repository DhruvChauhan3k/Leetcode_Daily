#include <semaphore>
#include <barrier>

class H2O {
private:
    std::counting_semaphore<2> collect_hydro;
    std::counting_semaphore<1> collect_oxy;
    std::barrier<> assembler;
public:
    H2O() : collect_hydro(2), collect_oxy(1), assembler(3)
    {
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        collect_hydro.acquire();
		assembler.arrive_and_wait();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        collect_hydro.release();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        collect_oxy.acquire();
		assembler.arrive_and_wait();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        collect_oxy.release();
    }
};