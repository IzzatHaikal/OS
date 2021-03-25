#include <stdio.h>
#include <stdbool.h>

void FIFO(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]);
void switchFIFO(int pageFrameNum, int pageFrame[], int pageNum, int pageOrder[]);
// void LRU(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[])

int main(){
    int pageFrameNum;
    printf("Enter the number of page frame(s): ");
    scanf("%d", &pageFrameNum);
    int pageFrame [pageFrameNum];
    bool pageFrameAllocate [pageFrameNum];
    int pageNum;
    printf("Enter the number of page(s): ");
    scanf("%d", &pageNum);
    int pageOrder[pageNum];
    for(int i = 0; i<pageNum; i++){
        printf("Enter the %d page: ", i+1);
        scanf("%d", &pageOrder[i]);
    }
    printf("Enter 1 for FIFO and 2 for LRU: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
        FIFO(pageFrameNum, pageFrame, pageFrameAllocate, pageNum, pageOrder);
    // else if (choice == 2)
        // LRU(pageFrameNum, pageFrame, pageFrameAllocate, pageNum, pageOrder);
    // else
    //     printf("Incorrect Input");
    
}

void FIFO(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]){
    int missCount = 0;
    for(int i = 0; i<pageNum; i++){
        bool found = false;
        bool allocate = false;
        for(int j = 0; j<pageFrameNum; j++){
            if(pageFrameAllocate[j] == false){
                pageFrame[j] = pageOrder[i];
                pageFrameAllocate[j] = true;
                allocate = true;
                found = true;
                break;
            }
            else if (pageFrameAllocate[j] == true){
                if(pageFrame[j] == pageOrder[i]){
                    found = true;
                    break;
                }
            }
            
        }
        if(found == false){
            switchFIFO(pageFrameNum, pageFrame, i, pageOrder);
            allocate = true;
        }
        if(allocate == true)
            missCount++;
    }
    printf("%d", missCount);
}

void switchFIFO(int pageFrameNum, int pageFrame[], int pageNum, int pageOrder[]){
    for(int i=0; i<pageFrameNum; i++){
        if(i != pageFrameNum-1){
            pageFrame[i] = pageFrame[i+1];
        }
        else{
            pageFrame[i] = pageOrder[pageNum];
        }
    }
}

// void LRU(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]){

// }