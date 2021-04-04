def SJN():
    jobNum = int(input("Enter the number of job(s): "))
    job = [None]*jobNum
    for x in range(jobNum):
        aUnicode = ord("A")+x
        job[x] = int(input("Enter job {} CPU cycle: ".format(chr(aUnicode))))
        aUnicode += 1
    job.sort()
    total = totalSJN(job, jobNum)
    print("Average turnaround time: {}".format(total))

def totalSJN(job, jobNum):
    total = 0
    for x in range(jobNum):
        total += totalRecurse(job, x)
    avgTotal = total/jobNum
    return avgTotal

def totalRecurse(job, x):
    if x > 0:
        total = job[x] + totalRecurse(job, x-1)
    else:
        total = job[0]
    return total

def RR():
    jobNum = int(input("Enter the number of job(s): "))
    job = [None]*jobNum
    for x in range(jobNum):
        aUnicode = ord("A")+x
        job[x] = int(input("Enter job {} CPU cycle: ".format(chr(aUnicode))))
        aUnicode += 1
    jobArrive = [None]*jobNum
    for x in range(jobNum):
        aUnicode = ord("A")+x
        jobArrive[x] = int(input("Enter job {} arrival time: ".format(chr(aUnicode))))
        aUnicode += 1
    timeQuantum = int(input("Enter time quantum: "))
    jobFinish = [0]*jobNum
    jobCheck = [False]*jobNum
    loopCheck = True
    timeQuantumAccumulate = 0
    while not all(jobCheck):
        for x in range(jobNum):
            if job[x] >= timeQuantum and jobCheck[x] == False:
                job[x] -= timeQuantum
                timeQuantumAccumulate += timeQuantum
                hold = timeQuantumAccumulate
                jobFinish[x] = hold
            elif job[x] < timeQuantum and jobCheck[x] == False:
                timeQuantumAccumulate += job[x]
                job[x] = 0
                hold = timeQuantumAccumulate
                jobFinish[x] = hold
            if job[x] == 0 and jobCheck[x] == False:
                    jobCheck[x] = True
    total = 0
    for x in range(jobNum):
        total += jobFinish[x] - jobArrive[x]
    print("Average turnaround time: {}".format(total/jobNum))
    
choice = int(input("Enter 1 for SJN or 2 for Round Robin: "))
if choice == 1:
    SJN()
elif choice == 2:
    RR()
else:
    print("Invalid Input")