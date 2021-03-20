# Python3 implementation of First-Fit algorithm 

# Function to allocate memory to 
# blocks as per First fit algorithm 
def firstFit(blockSize, m, processSize, n): 
	
	# Stores block id of the 
	# block allocated to a process 
	allocation = [-1] * n 

	# Initially no block is assigned to any process 

	# pick each process and find suitable blocks 
	# according to its size ad assign to it 
	for i in range(n): 
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				
				# allocate block j to p[i] process 
				allocation[i] = j 

				# Reduce available memory in this block. 
				blockSize[j] -= processSize[i] 

				break

	print(" Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "		 ", processSize[i], 
						"		 ", end = " ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1) 
		else: 
			print("Not Allocated") 
	
# This code is contributed by PranchalK 

# Python3 implementation of Best - Fit algorithm 

# Function to allocate memory to blocks 
# as per Best fit algorithm 
def bestFit(blockSize, m, processSize, n): 
	
	# Stores block id of the block 
	# allocated to a process 
	allocation = [-1] * n 
	
	# pick each process and find suitable 
	# blocks according to its size ad 
	# assign to it 
	for i in range(n): 
		
		# Find the best fit block for 
		# current process 
		bestIdx = -1
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				if bestIdx == -1: 
					bestIdx = j 
				elif blockSize[bestIdx] > blockSize[j]: 
					bestIdx = j 

		# If we could find a block for 
		# current process 
		if bestIdx != -1: 
			
			# allocate block j to p[i] process 
			allocation[i] = bestIdx 

			# Reduce available memory in this block. 
			blockSize[bestIdx] -= processSize[i] 

	print("Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(i + 1, "		 ", processSize[i], 
								end = "		 ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1) 
		else: 
			print("Not Allocated") 
	
# This code is contributed by PranchalK 

def first(blocksize, m, processSize, n):
	allocateLocation = [-1]*n
	freeBusy = [False]*m
	for x in range(n):
		for y in range(m):
			if (blocksize[y] >= processSize[x]) and freeBusy[y] == False:
				allocateLocation[x] = y
				freeBusy[y] = True
				break
	print(" Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "		 ", processSize[i], 
						"		 ", end = " ") 
		if allocateLocation[i] != -1: 
			print(allocateLocation[i] + 1) 
		else: 
			print("Not Allocated")	
 
# Code by Izzat

def best(blockSize, m, processSize, n):
	allocateLocation = [-1]*n
	sizeDiff = [0]*m
	freeBusy = [False]*m
	for x in range(n):
		bestIndex = -1
		for y in range(m):
			if bestIndex == -1 and sizeDiff[y] == 0 and blockSize[y] >= processSize[x] and freeBusy[y] == False:
				freeBusy[y] = True
				sizeDiff[y] = blockSize[y] - processSize[x]
				bestIndex = y 
			elif bestIndex != -1 and (blockSize[y] >= processSize[x]) and (sizeDiff[bestIndex] > blockSize[y] - processSize[x]) and freeBusy[y] == False :
				freeBusy[bestIndex] = False
				freeBusy[y] = True
				sizeDiff[y] = blockSize[y] - processSize[x]
				sizeDiff[bestIndex] = 0
				bestIndex = y
		if bestIndex != -1:
			allocateLocation[x] = bestIndex

	print(" Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "		 ", processSize[i], 
						"		 ", end = " ") 
		if allocateLocation[i] != -1: 
			print(allocateLocation[i] + 1) 
		else: 
			print("Not Allocated")

# Code by Izzat

blockSize = [100, 500, 200, 300, 600] 
processSize = [212, 417, 112, 426] 
# blockSize = [10, 15, 5, 25, 12] 
# processSize = [5, 14, 13, 9, 30 ]
m = len(blockSize) 
n = len(processSize) 
# firstFit(blockSize, m, processSize, n)
# bestFit(blockSize, m, processSize, n)
# first(blockSize, m, processSize, n)
best(blockSize, m, processSize, n)
	 


