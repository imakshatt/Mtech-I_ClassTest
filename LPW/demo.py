from multiprocessing import Pool
import time

def singleFunction(args):
    start, end = args
    sum = 0
    for i in range(start, end+1):
        sum += i
    return sum

def squareFunction(args):
    start, end = args
    sum = 0
    for i in range(start, end):
        for j in range(start, end):
            sum +=  i+j
    return sum

def lognFunction(args):
    start, end = args
    sum = 0
    for i in range(start, end+1):
        for j in range(start+i, end+1):
            sum += i+j
    return sum

def main():
    proc = [2,4,8]
    input = [10000, 50000, 100000]
    for i in proc:
        for j in input:
            if j%i != 0:
                continue
            t1 = time.time()
            p = Pool(processes=i)
            step = j // i
            ranges = []
            for k in range(i):
                ranges.append((k*step+1, (k+1)*step))
            result = p.map(squareFunction, ranges)
            p.close()
            p.join()
            
            print("Multiple {} processes is used for the input size {} and takes: {}".format(i,j,time.time()-t1))

if __name__ == "__main__":
    main()