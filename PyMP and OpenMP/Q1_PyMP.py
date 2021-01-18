from __future__ import print_function

with pymp.Parallel(4) as p:
    p.print(p.num_threads, p.thread_num)