#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SJN();
int cmpfunc(const void * a, const void * b);
float totalSJN(int job[], int jobNum);
int totalRecurse(int job[], int x);
void RR();
bool loopCheck(bool jobCheck[], int jobNum);

int main(){
    printf("Enter 1 for SJN or 2 for Round Robin: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
        SJN();
    else if(choice == 2)
        RR();
    else
     printf("Invalid Input");
}


void SJN(){
    printf("Enter the number of job(s): ");
    int jobNum;
    scanf("%d", &jobNum);
    int job[jobNum];
    for(int i=0; i<jobNum; i++){
        printf("Enter job %c CPU cycle: ",i+65);
        scanf("%d", &job[i]);
    }
    qsort(job, jobNum, sizeof(int), cmpfunc);
    float total = totalSJN(job, jobNum);
    printf("Average turnaround time: %f", total);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

float totalSJN(int job[], int jobNum){
    int total = 0;
    for(int i=0; i<jobNum; i++){
        total += totalRecurse(job, i);
    }
    float avgtotal = total/(float)jobNum;
    return avgtotal;
}

int totalRecurse(int job[], int x){
    int total = 0;
    if(x > 0)
        total = job[x] + totalRecurse(job, x-1);
    else
        total = job[0];
    return total;
}

void RR(){
    printf("Enter the number of job(s): ");
    int jobNum;
    scanf("%d", &jobNum);
    int job[jobNum];
    for(int i=0; i<jobNum; i++){
        printf("Enter job %c CPU cycle: ",i+65);
        scanf("%d", &job[i]);
    }
    int jobArrive[jobNum];
    for(int i=0; i<jobNum; i++){
        printf("Enter job %c arrival time: ",i+65);
        scanf("%d", &jobArrive[i]);
    }
    int timeQuantum;
    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);
    int jobFinish[jobNum];
    bool jobCheck[jobNum];
    for(int i=0; i<jobNum; i++)
        jobCheck[i] = false;
    int timeQuantumAccumulate = 0;
    while (loopCheck(jobCheck, jobNum)){
        for(int i=0; i<jobNum; i++){
            if((job[i] >= timeQuantum) && (jobCheck[i] == false)){
                job[i] -= timeQuantum;
                timeQuantumAccumulate += timeQuantum;
                int hold = timeQuantumAccumulate;
                jobFinish[i] = hold;
            }
            else if((job[i] < timeQuantum) && (jobCheck[i] == false)){
                timeQuantumAccumulate += job[i];
                job[i] = 0;
                int hold = timeQuantumAccumulate;
                jobFinish[i] = hold;
            }
            if((job[i] == 0) && (jobCheck[i] == false))
                jobCheck[i] = true;
        }
    }
    int total = 0;
    for(int i=0; i<jobNum; i++)
        total += jobFinish[i] - jobArrive[i];
    float avg;
    avg = total/(float)jobNum;
    printf("Average turnaround time: %f", avg);
}

bool loopCheck(bool jobCheck[], int jobNum){
    int check = 0;
    for(int i=0; i<jobNum; i++){
        if(jobCheck[i] == true)
            check++;
    }
    if(check == jobNum)
        return false;
    else
        return true;
}