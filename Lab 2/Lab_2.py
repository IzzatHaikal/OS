def FIFO():
    pageFrameNum = int(input("Enter the number of page frame(s): "))
    pageFrame = [None]*pageFrameNum
    pageFrameAllocate = [False]*pageFrameNum
    pageNum = int(input("Enter the number of page(s): "))
    pageOrder = [None]*pageNum
    for x in range(pageNum):
        pageOrder[x] = int(input("Enter the {} page: ".format(x+1)))
    missCount = 0
    for x in range(pageNum):
        found = False
        allocate = False
        for y in range(pageFrameNum):
            if pageFrameAllocate[y] == False:
                pageFrame[y] = pageOrder[x]
                pageFrameAllocate[y] = True
                allocate = True
                break
            elif pageFrameAllocate[y] == True:
                if pageOrder[x] in pageFrame:
                    break
                else:
                    pageFrame.pop(0)
                    pageFrame.append(pageOrder[x])
                    allocate = True
        if allocate == True:
            missCount += 1
    print(missCount)

def LRU():
    pageFrameNum = int(input("Enter the number of page frame(s): "))
    pageFrameBit = [None]*pageFrameNum
    for x in range(pageFrameNum): #to simulate one by one page get into the frame making the first = 1 and last = n
        pageFrameBit[x] = x+1
    pageFrame = [None]*pageFrameNum
    pageFrameAllocate = [False]*pageFrameNum
    pageNum = int(input("Enter the number of page(s): "))
    pageOrder = [None]*pageNum
    for x in range(pageNum):
        pageOrder[x] = int(input("Enter the {} page: ".format(x+1)))
    missCount = 0
    for x in range(pageNum):
        found = False
        allocate = False
        smallest = None
        for y in range(pageFrameNum):
            if pageFrameAllocate[y] == False:
                pageFrame[y] = pageOrder[x]
                pageFrameAllocate[y] = True
                allocate = True
                break
            elif pageFrameAllocate[y] == True:
                if pageOrder[x] in pageFrame:
                    if pageFrame[y] != pageOrder[x]:
                        pageFrameBit[y] -= 1
                    else:
                        break
                else:
                    if y > 0:
                        if pageFrameBit[smallest] > pageFrameBit[y]:
                            smallest = y
                    else:
                        smallest = y
                        

        if smallest != None:
            pageFrame[smallest] = pageOrder[x]
            allocate = True

        if allocate == True:
            missCount += 1

    print(pageFrame)
    print(missCount)


# FIFO()
LRU()