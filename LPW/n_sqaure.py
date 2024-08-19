import multiprocessing
from multiprocessing import Pool
import time

def n_squareFunction(args):
    start,end = args
    sum = 0
    for i in range(start,end):
        for j in range(start,end):
            sum = sum + i + j
    return sum

def main():
    cpu_cout = [2, 4, 8]
    input_size = [10000, 50000, 100000]
    for i in cpu_cout:
        for j in input_size:
            if j % i != 0:
                continue
            t1 = time.time()
            p = Pool(processes=i)
            step = j // i
            ranges = []
            for k in range(i):
                ranges.append((k * step + 1, (k + 1) * step))

            result = p.map(n_squareFunction, ranges)
            p.close()
            p.join()
            print("Multiple {} Processor Use for {} Input Size : {}".format(i, j, time.time() - t1))

if __name__ == "__main__":
    main()