def FIFO():
    pageFrameNum = int(input("Enter the number of page frame(s): "))
    pageFrame = [None]*pageFrameNum
    pageFrameAllocate = [False]*pageFrameNum
    pageNum = int(input("Enter the number of page(s): "))
    pageOrder = [None]*pageNum
    for x in range(pageNum):
        pageOrder[x] = int(input("Enter the {} page: ".format(x+1)))
    missCount = 0
    firstEntry = False
    for x in range(pageNum):
        found = False
        allocate = False
        for y in range(pageFrameNum):
            if pageFrameAllocate[y] == False and firstEntry == False:
                pageFrame[y] = pageOrder[x]
                pageFrameAllocate[y] = True
                allocate = True
                if x == pageFrameNum-1:
                    firstEntry = True
                    break
                break
            elif pageFrameAllocate[y] == True and firstEntry == True:
                if pageOrder[x] in pageFrame:
                    break
                else:
                    pageFrame.pop(0)
                    pageFrame.append(pageOrder[x])
                    allocate = True
        if allocate == True:
            missCount += 1
    print("Total Page Fault = {}".format(missCount))

def LRU():
    pageFrameNum = int(input("Enter the number of page frame(s): "))
    pageFrameBit = [None]*pageFrameNum
    pageFrame = [None]*pageFrameNum
    pageFrameAllocate = [False]*pageFrameNum
    pageNum = int(input("Enter the number of page(s): "))
    pageOrder = [None]*pageNum
    for x in range(pageNum):
        pageOrder[x] = int(input("Enter the {} page: ".format(x+1)))
    missCount = 0
    firstEntry = False
    for x in range(pageNum):
        found = False
        allocate = False
        smallest = None
        for y in range(pageFrameNum):
            if pageFrameAllocate[y] == False and firstEntry == False:
                pageFrameAllocate[y] = True
                pageFrame[y] = pageOrder[x]
                pageFrameBit[y] = x
                allocate = True
                if x == pageFrameNum-1:
                    firstEntry = True
                    break
                break
            elif pageFrameAllocate[y] == True and firstEntry == True:
                if smallest == None:
                    smallest = y
                elif pageFrameBit[smallest] > pageFrameBit[y]:
                    smallest = y

        if smallest != None:
            if pageOrder[x] in pageFrame:
                pageFrameBit[pageFrame.index(pageOrder[x])] = x
            else:
                pageFrame[smallest] = pageOrder[x]
                pageFrameBit[smallest] = x
                allocate = True

        if allocate == True:
            missCount += 1


    print("Total Page Fault = {}".format(missCount))


choice = int(input("Enter 1 for FIFO and 2 for LRU : "))
if choice == 1:
    FIFO()
elif choice == 2:
    LRU()
else:
    print("Invalid Input")