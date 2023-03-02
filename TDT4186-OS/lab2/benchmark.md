---
title: TDT4186 Lab 2
geometry: 
- top=15mm
- bottom=15mm
---
\thispagestyle{empty}

## Task 1: Baseline – Measuring Performance

Tick timings for the `Round Robin` scheduler executing the following benchmark:

```bash
time sh load.sh
```

| Run number | Tick timings |
| :--------: | :----------: |
|     1      |      13      |
|     2      |      12      |
|     3      |      12      |
|     4      |      14      |
|     5      |      12      |
|     6      |      12      |
|     7      |      12      |
|     8      |      12      |
|     9      |      14      |
|     10     |      12      |

**Average**: `12.5` ticks

## Task 3: MLFQ – Measuring Performance

Tick timings for the `MLFQ` scheduler executing the following benchmark:

```bash
time sh load.sh
```

| Run number | Tick timings |
| :--------: | :----------: |
|     1      |      10      |
|     2      |      11      |
|     3      |      10      |
|     4      |      11      |
|     5      |      10      |
|     6      |      11      |
|     7      |      12      |
|     8      |      11      |
|     9      |      10      |
|     10     |      11      |

**Average**: `10.7` ticks

### Conclusion

Given the low tick timings the run time of the two schedulers are pretty comparable, but the implementation of the MLFQ scheduler ome times seemed to run a bit better.

An explanation for that behavior can be the fact that I mostly tried to prioritize early exiting, so processes that took longer to exit got prioritized lower.
