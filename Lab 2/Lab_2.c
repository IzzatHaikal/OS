#include <stdio.h>
#include <stdbool.h>

void FIFO(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]);
int switchFIFO(int pageFrameNum, int pageFrame[], int pageNum, int pageOrder[], int changePlace);
void LRU(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]);
bool findLRU(int pageFrameNum, int pageFrame[], int pageOrder[], int find);
int indexLRU(int pageFrameNum, int pageFrame[], int pageOrder[], int find);
void output(int pageFrameNum, int pageFrame[], int frame, int pageOrder[]);

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
    else if (choice == 2)
        LRU(pageFrameNum, pageFrame, pageFrameAllocate, pageNum, pageOrder);
    else
        printf("Incorrect Input");
    
}

void output(int pageFrameNum, int pageFrame[], int page, int pageOrder[]){
    printf("%d |",pageOrder[page]);
    for(int i=0; i<pageFrameNum; i++){
        if(i <= page)
            printf("%d|",pageFrame[i]);
        else
            printf(" |");
    }
    printf("\n");
}

void FIFO(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]){
    int missCount = 0, changePlace = 0;
    printf("FIFO :\n");
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
            changePlace = switchFIFO(pageFrameNum, pageFrame, i, pageOrder,changePlace);
            allocate = true;
        }
        if(allocate == true)
            missCount++;
        output(pageFrameNum,pageFrame,i,pageOrder);
    }
    printf("Total Page Fault = %d", missCount);
}

int switchFIFO(int pageFrameNum, int pageFrame[], int swap, int pageOrder[], int changePlace){
    pageFrame[changePlace] = pageOrder[swap];
    if(changePlace < pageFrameNum-1)
        changePlace++;
    else if(changePlace == pageFrameNum-1)
        changePlace = 0;
    return changePlace;
}

void LRU(int pageFrameNum, int pageFrame[], bool pageFrameAllocate[], int pageNum, int pageOrder[]){
    int pageFrameBit[pageFrameNum];
    int missCount = 0;
    bool firstEntry = false;
    printf("LRU :\n");
    for(int i=0; i<pageNum; i++){
        bool allocate = false;
        int smallest = -1;
        for(int j=0; j<pageFrameNum; j++){
            if(pageFrameAllocate[j] == false && firstEntry == false){
                pageFrameAllocate[j] = true;
                pageFrame[j] = pageOrder[i];
                pageFrameBit[j] = i;
                allocate = true;
                if (i == pageFrameNum-1)
                    firstEntry = true;
                break;
            }
            else if(pageFrameAllocate[j] == true && firstEntry == true){
                if(smallest == -1)
                    smallest = j;
                else if(pageFrameBit[smallest] > pageFrameBit[j])
                    smallest = j;
            }
        }
        if (smallest != -1){
            if (findLRU(pageFrameNum, pageFrame, pageOrder, i)){
                pageFrameBit[indexLRU(pageFrameNum,pageFrame,pageOrder,i)] = i;
            }
            else{
                pageFrame[smallest] = pageOrder[i];
                pageFrameBit[smallest] = i;
                allocate = true;
            }
        }
        if(allocate == true)
            missCount++;
        output(pageFrameNum,pageFrame,i,pageOrder);
    }
    printf("Total Page Fault = %d", missCount);
}

bool findLRU(int pageFrameNum, int pageFrame[], int pageOrder[], int find){
    bool found = false;
    for(int i=0; i<pageFrameNum; i++){
        if(pageFrame[i] == pageOrder[find]){
            found = true;
            break;
        }
    }
    return found;
}

int indexLRU(int pageFrameNum, int pageFrame[], int pageOrder[], int find){
    int index;
    for(int i=0; i<pageFrameNum; i++){
        if(pageFrame[i] == pageOrder[find]){
            index = i;
            break;
        }
    }
    return index;
}