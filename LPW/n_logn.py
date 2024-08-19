from multiprocessing import Pool
import time

def lognFunction(args):
    start, end = args
    sum = 0
    for i in range(start, end+1):
        for j in range(start+i, end+1):
            sum += i+j
    return sum


def main():
    procc = [2,4,8]
    input = [10000,50000,100000]
    for i in procc:
        for j in input:
            if j%i != 0:
                continue
            t1 = time.time()
            p = Pool(processes=i)
            step = j//i
            ranges = []
            for k in ranges:
                ranges.append((k*step+1, (k+1)*step))
            result = p.map(lognFunction, ranges)
            p.close()
            p.join()
            
            print("Multiple {} processes used for the input sixe {} and takes: {}".format(i,j,time.time() -t1))

if __name__ == "__main__":
    main()