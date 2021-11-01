// 1115. Print FooBar Alternately
class FooBar {
    private int n;
    private boolean fooTurn = true;
    private Object lock = new Object();

    public FooBar(int n) {
        this.n = n;
        //lock = new Object();
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(lock) {
                if (!fooTurn) lock.wait();
                fooTurn = false;
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                lock.notifyAll();
            }
            
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(lock) {
                if (fooTurn) lock.wait();
                fooTurn = true;
                
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                
                lock.notifyAll();
                
            }
        }
    }
}
