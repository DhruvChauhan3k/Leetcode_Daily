class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int fooo;

public:
    FooBar(int n) {
        this->n = n;
        fooo=1;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex>lck(mtx); 
        for (int i = 0; i < n; i++) {

            
        	// printFoo() outputs "foo". Do not change or remove this line.
            cv.wait(lck,[this](){return fooo == 1;});
        	printFoo();
            fooo=!fooo;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex>lck(mtx);
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            cv.wait(lck,[this](){return fooo != 1;});
        	printBar();
            fooo=!fooo;
            cv.notify_all();
        }
    }
};