#include "kernel/types.h"
#include "user.h"
#define LIB_PREFIX "[UTHREAD]: "
#define ulog() printf("%s%s\n", LIB_PREFIX, __FUNCTION__)

#define FREE        0x0
#define RUNNING     0x1
#define RUNNABLE    0x2
#define STACK_SIZE  8192
#define MAX_THREAD  4

struct thread  current_thread;
struct thread  next_thread;

void tsched()
{
    // TODO: Implement a userspace round robin scheduler that switches to the next thread
    struct thread t;
    next_thread = t;

    for (int i = 0; i < MAX_THREAD; i++) {
      if (next_thread.state == RUNNABLE) {
        current_thread = next_thread;
        current_thread.state = RUNNING;
        break;
      }
    }

    if (current_thread.state == RUNNING) {
      next_thread = current_thread;
    }

    if (next_thread.state == FREE) {
      printf(1, "no thread to run\n");
      exit(0);
    }

    if (current_thread.tid != next_thread.tid) {
      next_thread.state = RUNNING;
      tswtch(&current_thread, &next_thread);
    }

}

void tcreate(struct thread **thread, struct thread_attr *attr, void *(*func)(void *arg), void *arg)
{
    // TODO: Create a new process and add it as runnable, such that it starts running
    // once the scheduler schedules it the next time
    struct thread t;

    for (int i = 0; i < MAX_THREAD; i++) {
      if (t.state == FREE) {
        t.state = RUNNABLE;
        t.tid = i;
        t.func = func;
        t.arg = arg;
        break;
      }
    }
}

int tjoin(int tid, void *status, uint size)
{
    // TODO: Wait for the thread with TID to finish. If status and size are non-zero,
    // copy the result of the thread to the memory, status points to. Copy size bytes.
    if (status == 0 || size == 0) {
      return 0;
    } else {
      for (int i = 0; i < MAX_THREAD; i++) {
        if (next_thread.tid == tid) {
          memmove(status, next_thread.func, size);
          break;
        }
      }
    }

    return 0;
}

void tyield()
{
    // TODO: Implement the yielding behaviour of the thread
    current_thread.state = RUNNABLE;
    tsched();
}

uint8 twhoami()
{
    // TODO: Returns the thread id of the current thread
    for (int i = 0; i < 100; i++) {
      printf(1, "my thread 0x%x\n", current_thread.tid);
      thread_yield();
    }
    return 0;
}
