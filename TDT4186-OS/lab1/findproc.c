#include <stdarg.h>

#include "types.h"
#include "param.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"
#include "proc.h"

// add to defs.h:
// // findproc.c
// void            find_proc(struct proc*);

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