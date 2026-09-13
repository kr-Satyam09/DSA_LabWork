#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Clist {
    int pt;             
    char pn[10];        
    struct Clist *next; 
} c1;

void create(c1 **f1, c1 **r1) {
    c1 *p = (c1*)malloc(sizeof(c1));
    
    if (p != NULL) {
        printf("Enter process name: ");
        // Leading space in scanf safely ignores leftover newline characters
        scanf(" %s", p->pn);       
        printf("Enter process time: ");
        scanf("%d", &p->pt);        
        p->next = NULL;
        // If list is empty
        if (*f1 == NULL && *r1 == NULL) {
            *f1 = p;
            *r1 = p;
        } else {
            // Append to the end
            (*r1)->next = p;
            *r1 = p;
        }// Maintain circular link: Rear's next points to Front
        (*r1)->next = *f1; 
    }
}

void disp(c1 *f1) {
    if (f1 == NULL) {
        printf("Process queue is empty.\n");
        return;
    }
    c1 *temp = f1;
    printf("\nCurrent Process Queue: ");
    do {
        printf("[%s|%d] -> ", temp->pn, temp->pt);
        temp = temp->next;
    } while (temp != f1);
    printf(" loops back to %s \n", f1->pn);
}

void produce(c1 **f1, c1 **r1) {
    if (*f1 == NULL) {
        printf("No processes to execute.\n");
        return;
    }

    // Ask for the CPU time directly inside the function
    int time_quantum;
    printf("\nEnter time sharing/slicing environment: \n ");
    scanf("%d", &time_quantum);

    c1 *curr = *f1;
    c1 *prev = *r1; // prev initially points to rear for easy deletion
    int total_elapsed_time = 0;

    printf("Starting Execution(Round Robin Scheduling)\n");

    // Continue until the circular list is completely empty
    while (*f1 != NULL) {
        // Case 1: Process needs more time than the given time slice
        if (curr->pt > time_quantum) {
            curr->pt -= time_quantum;
            total_elapsed_time += time_quantum;
            printf("Time %4d: Process %s executed for %d units. (Remaining: %d)\n", 
                   total_elapsed_time, curr->pn, time_quantum, curr->pt);
            
            // Move to the next process
            prev = curr;
            curr = curr->next;
        } 
        // Case 2: Process will finish within or exactly at the given time slice
        else {
            total_elapsed_time += curr->pt;
            printf("Time %4d: Process %s executed for %d units and COMPLETED. -> Total system time: %d\n", 
                   total_elapsed_time, curr->pn, curr->pt, total_elapsed_time);            
            if (curr == curr->next) { 
                // one node left in the list
                free(curr);
                *f1 = NULL;
                *r1 = NULL;
                break;
            } else {
                prev->next = curr->next;
                // deleting the front node & update the front pointer
                if (curr == *f1) {
                    *f1 = curr->next;
                }
                // deleting the rear node & update the rear pointer
                if (curr == *r1) {
                    *r1 = prev;
                }
                
                c1 *node_to_delete = curr;
                curr = curr->next; // Move to next process
                free(node_to_delete);
            }
        }
    }
}

int main() {
    c1 *front = NULL; // f1 in notes
    c1 *rear = NULL;  // r1 in notes
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    // Create the process list
    for (int i = 0; i < num_processes; i++) {
        printf("Details for Process %d \n", i + 1);
        create(&front, &rear);
    }
    // Display the initial state
    disp(front);
    // Run the scheduler
    produce(&front, &rear);
    return 0;
}