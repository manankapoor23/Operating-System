# Operating System

Lab practice / coursework programs written for a university Operating Systems
course. These are small, standalone C programs written while learning core
OS concepts — not a production project or a library. Each file is
self-contained and meant to be compiled and run individually.

## What's implemented

- **`bankers.c`** — Banker's algorithm for deadlock avoidance (computes a
  safe sequence, or reports that the system is not in a safe state, from
  max-need/allocation matrices).
- **`fcfs.c`** — First-Come-First-Served CPU scheduling (waiting time and
  turnaround time from arrival/burst times).
- **`sjf.c`** — Shortest-Job-First (non-preemptive) CPU scheduling.
- **`round_robin.c`** — Round-Robin CPU scheduling with a user-supplied time
  quantum.
- **`fork_demo.c`** — Process creation with `fork()`, printing parent/child
  PIDs.
- **`multithreads/multithreading.c`** — Basic POSIX threads example
  (`pthread_create` / `pthread_join`).
- **`multithreads/race.c`** — Demonstrates a race condition: two threads
  incrementing a shared, unsynchronized counter.
- **`writer.c`** / **`reader.c`** — Inter-process communication via POSIX
  shared memory (`shm_open` + `mmap`); `writer` creates and writes a shared
  memory segment, `reader` reads and unlinks it.

### Incomplete / not functional

A few files in this repo are leftovers from experimenting and don't do
anything useful — listed here for honesty rather than silently dropped:

- **`4.c`**, **`IPCP.C`** — empty files.
- **`ps.c`** — only variable declarations, no logic; never finished.
- **`tempCodeRunnerFile.c`** — an auto-generated duplicate of `reader.c`
  left behind by VS Code's "Code Runner" extension, not intentional source.

## How to compile and run

Each program is compiled individually with `gcc`. No build system/Makefile
is provided.

```sh
# Scheduling algorithms
gcc bankers.c -o bankers && ./bankers
gcc fcfs.c -o fcfs && ./fcfs
gcc sjf.c -o sjf && ./sjf
gcc round_robin.c -o round_robin && ./round_robin

# Process creation
gcc fork_demo.c -o fork_demo && ./fork_demo

# Threads (link pthreads)
gcc multithreads/multithreading.c -o multithreading -lpthread && ./multithreading
gcc multithreads/race.c -o race -lpthread && ./race

# Shared memory IPC — run the writer first, then the reader
gcc writer.c -o writer -lrt && ./writer
gcc reader.c -o reader -lrt && ./reader
```

(`-lrt` is needed on Linux for the shared-memory calls; it's a no-op/unneeded
on macOS.)

## File structure

```
.
├── 4.c                        # empty
├── IPCP.C                     # empty
├── bankers.c                  # Banker's algorithm (deadlock avoidance)
├── fcfs.c                     # FCFS CPU scheduling
├── fork_demo.c                # fork() demo
├── ps.c                       # unfinished stub
├── reader.c                   # shared-memory IPC (reader)
├── round_robin.c              # Round Robin CPU scheduling
├── sjf.c                      # SJF CPU scheduling
├── tempCodeRunnerFile.c       # editor artifact, duplicate of reader.c
├── writer.c                   # shared-memory IPC (writer)
└── multithreads/
    ├── multithreading.c       # pthread create/join demo
    └── race.c                 # race condition demo
```
