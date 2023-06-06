class H2O {
    mutex m;
    condition_variable cv;
    int h;
public:
    H2O() {
        h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
            unique_lock<mutex>lock(m);
            while(h == 2){
                cv.wait(lock);
            }
            h++;
            releaseHydrogen();
            cv.notify_all();
        
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(h<2){
            cv.wait(lock);
        }
        releaseOxygen();
        h = 0;
        cv.notify_all();
        return;
    }
};