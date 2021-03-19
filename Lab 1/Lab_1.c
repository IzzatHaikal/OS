#include <stdio.h>
#include <stdbool.h>

void first(int blockNum, int block[], int processNum, int process[]);
void best(int blockNum, int block[], int processNum, int process[]);

int main() {
    printf("Enter number of block: ");
    int blockNum;
    scanf("%d", &blockNum);
    int block [blockNum];
    for(int i = 0; i<blockNum; i++){
        printf("Enter the block size for block number %d: ", i+1);
        scanf("%d", &block[i]);
    }
    printf("Enter number of processes: ");
    int processNum;
    scanf("%d", &processNum);
    int process [processNum];
    for(int i = 0; i<processNum; i++){
        printf("Enter the block size for block number %d: ", i+1);
        scanf("%d", &process[i]);
    }
    //first( blockNum, block, processNum, process);
    best(blockNum, block, processNum, process);
}

void first(int blockNum, int block[], int processNum, int process[]){
    bool allocateBlock[blockNum];
    bool allocateProcess[processNum];
    int allocateLocation[processNum];
    for(int i = 0; i<processNum; i++){
        for(int j = 0; j<blockNum; j++){
            if((block[j] >= process[i]) && allocateBlock[j] == false){
                allocateBlock[j] = true;
                allocateProcess[i] = true;
                allocateLocation[i] = j;
                break;
            }
        }
    }
    printf(" Process No. Process Size	Block no.\n");
    for(int i = 0; i<processNum; i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocateProcess[i] == true){
            printf(" %d\n", allocateLocation[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }
}

void best(int blockNum, int block[], int processNum, int process[]){
    bool allocateBlock[blockNum];
    bool allocateProcess[processNum];
    int allocateLocation[processNum];
    for(int i = 0; i<processNum; i++){
        //int blockProcess[blockNum];
        int smallest = -1;
        for(int j = 0; j<blockNum; j++){
            if((block[j] >= process[i]) && smallest == -1 && allocateBlock[j] == false){
                //blockProcess[j] = block[j] - process[i];
                allocateLocation[i] = j;
                allocateBlock[j] = true;
                smallest = j;
                allocateProcess[i] = true;
            }
            else if((block[smallest] - process[i] > block[j] - process[i]) && allocateBlock[j] == false && smallest != -1 && (block[j] > process[i])){
                allocateLocation[i] = j;
                //blockProcess[j] = block[j] - process[i];
                allocateBlock[smallest] = false;
                allocateBlock[j] = true;
                allocateProcess [i] = true;
                smallest = j;
            }
        }
    }
    printf(" Process No. Process Size	Block no.\n");
    for(int i = 0; i<processNum; i++){
        printf(" %d\t\t%d\t\t",i+1,process[i]);
        if(allocateProcess[i] == true){
            printf("%d\n", allocateLocation[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }
}