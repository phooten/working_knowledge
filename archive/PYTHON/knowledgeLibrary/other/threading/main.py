# https://www.youtube.com/watch?v=IEEhzQoKtQU
# left off: 12:

import threading
import time

start = time.perf_counter()


def do_something(seconds):                      # Figure out how to make 'seconds' default
    print(f'sleeping {seconds} second(s)...')
    time.sleep(seconds)
    print('done sleeping.')

#  Note 2:
# t1 = threading.Thread(target=do_something)
# t2 = threading.Thread(target=do_something)

# # note 1: 
# # without the .join(), the threads will run here, then finish the script while these two threads are still waiting
# t1.start()
# t2.start()

# t1.join()
# t2.join()

threads = []
for _ in range (10):                            # _ is a throw away variable
    t = threading.Thread(target=do_something, args=[1.5])
    t.start()
    threads.append(t)

for thread in threads:
    thread.join()

finish = time.perf_counter()

print(f'finished in {round(finish - start, 2)} second(s)')