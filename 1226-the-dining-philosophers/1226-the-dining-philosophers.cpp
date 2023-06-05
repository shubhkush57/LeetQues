class Semaphore{
    private:
        mutex m;
        int count;
        condition_variable cv;
    public:
        Semaphore(){}
        Semaphore(int c):count(c){}
        void set_count(int a){
            count = a;
        }
        void signal(){
            unique_lock<mutex>lock(m);
            count++;
            if(count<=0){
                cv.notify_one();
            }
            return;
        }
        void wait(){
            unique_lock<mutex>lock(m);
            count--;
            while(count<0){
                cv.wait(lock);
            }
            return;
        }
};
class DiningPhilosophers {
    Semaphore fork[5];
    mutex m;
public:
    DiningPhilosophers() {
        for(int i = 0;i<5;i++){
            fork[i].set_count(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            lock_guard<mutex>lock(m);
            fork[(philosopher+1)%5].wait();
            fork[philosopher].wait();
            
        }
        pickLeftFork();
        pickRightFork();
        eat();
       
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        
        putRightFork();
        fork[philosopher].signal();

        return;
		
    }
};