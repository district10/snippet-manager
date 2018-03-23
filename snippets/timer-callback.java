Timer timer = new Timer(true);
// public void scheduleAtFixedRate(TimerTask task, long delay, long period)
timer.scheduleAtFixedRate(task, UPDATE_TIME_RATE, UPDATE_TIME_RATE);

public abstract class TimerTask implements Runnable {
    ...
    /**
     * This object is used to control access to the TimerTask internals.
     */
    final Object lock = new Object();
    /**
     * The action to be performed by this timer task.
     */
    public abstract void run();

    public boolean cancel() {
        synchronized(lock) {
            boolean result = (state == SCHEDULED);
            state = CANCELLED;
            return result;
        }
    }

    ...
}
