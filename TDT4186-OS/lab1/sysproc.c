#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

struct proc* proc_arr[5];
struct proc** ptr_arr = proc_arr;
int tally = 0;
void
find_proc(struct proc* p)
{

  if (!strncmp(p->name, "init", 3)){ 
    *ptr_arr = p;
    for (int i = tally; i >= 0; i--)
    {
      printf("%s (%d): %d\n", proc_arr[i]->name, proc_arr[i]->pid, proc_arr[i]->state);
    }
    ptr_arr = proc_arr;
    tally = 0;
    }
  else {
    *ptr_arr = p;
    ptr_arr++;
    tally++;
    find_proc(p->parent);
  }
}

uint64
sys_getproc(void)
{
  struct proc* p = myproc();
  find_proc(p);
  return 0;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// print hello world
// just for testing
uint64
sys_hello(void)
{
  printf("Hello, World!\n");
  return 0;
}
