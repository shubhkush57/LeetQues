class Foo {
    mutex m;
    condition_variable cv;
    int turn;
public:
    Foo() {
        turn = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1; // first is trun on..
        cv.notify_all();
        return;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        // applying the lock...
        while(turn != 1){
            cv.wait(lock); // while trun is not 1 it's wait.....
        }
        printSecond();
        turn = 2;
        cv.notify_all();
        return;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(turn != 2){
            cv.wait(lock);
        }
        turn = 0;
        printThird();
        cv.notify_all();
        return;
    }
};