class Foo {
    private Object lock;
    private boolean oneDone;
    private boolean twoDone;

    public Foo() {
        lock = new Object();
        oneDone = false;
        twoDone = false;
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        synchronized(lock) {
        // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            oneDone = true;
            lock.notifyAll();
        }
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
        synchronized(lock) {
            while (!oneDone) {
                lock.wait();
            }
        // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            twoDone = true;
            lock.notifyAll();
        }
        
    }

    public void third(Runnable printThird) throws InterruptedException {
        synchronized(lock) {
            while (!twoDone) {
                lock.wait();
            }
            
        // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        }
        
    }
}

// 这道题没怎么看懂，第二个样例是什么意思?
