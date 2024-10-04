#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

struct process {
    int pid;            
    int burst_time;     
    int arrival_time;   
    int remaining_time; 
    int priority;       
};

void priority_scheduling(struct process p[], int n) {
    int wait_time[MAX_PROCESSES] = {0}, turnaround_time[MAX_PROCESSES] = {0}, completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_processes = 0, highest_priority = -1;
    printf("\nPriority Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    while (completed_processes < n) {
        int max_priority = INT_MIN;
        highest_priority = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !completed[i] && p[i].priority > max_priority) {
                max_priority = p[i].priority;
                highest_priority = i;
            }
        }

        if (highest_priority == -1) {
            current_time++;
            continue;
        }

        current_time += p[highest_priority].burst_time;
        completed[highest_priority] = 1;
        completed_processes++;

        wait_time[highest_priority] = current_time - p[highest_priority].arrival_time - p[highest_priority].burst_time;
        turnaround_time[highest_priority] = current_time - p[highest_priority].arrival_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[highest_priority].pid, p[highest_priority].arrival_time, p[highest_priority].burst_time, p[highest_priority].priority, wait_time[highest_priority], turnaround_time[highest_priority]);
    }
}

void ljf(struct process p[], int n) {
    int wait_time[MAX_PROCESSES] = {0}, turnaround_time[MAX_PROCESSES] = {0}, completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_processes = 0, longest = -1;
    printf("\nLJF Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed_processes < n) {
        int max_bt = INT_MIN;
        longest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !completed[i] && p[i].burst_time > max_bt) {
                max_bt = p[i].burst_time;
                longest = i;
            }
        }

        if (longest == -1) {
            current_time++;
            continue;
        }

        current_time += p[longest].burst_time;
        completed[longest] = 1;
        completed_processes++;

        wait_time[longest] = current_time - p[longest].arrival_time - p[longest].burst_time;
        turnaround_time[longest] = current_time - p[longest].arrival_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[longest].pid, p[longest].arrival_time, p[longest].burst_time, wait_time[longest], turnaround_time[longest]);
    }
}

void lrtf(struct process p[], int n) {
    int wait_time[MAX_PROCESSES] = {0}, turnaround_time[MAX_PROCESSES] = {0}, completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_processes = 0, longest = -1;
    printf("\nLRTF Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed_processes < n) {
        int max_rem_bt = INT_MIN;
        longest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && p[i].remaining_time > max_rem_bt) {
                max_rem_bt = p[i].remaining_time;
                longest = i;
            }
        }

        if (longest == -1) {
            current_time++;
            continue;
        }

        current_time++;
        p[longest].remaining_time--;

        if (p[longest].remaining_time == 0) {
            completed_processes++;
            wait_time[longest] = current_time - p[longest].arrival_time - p[longest].burst_time;
            turnaround_time[longest] = current_time - p[longest].arrival_time;
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[longest].pid, p[longest].arrival_time, p[longest].burst_time, wait_time[longest], turnaround_time[longest]);
        }
    }
}

int main() {
    struct process p[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].remaining_time = p[i].burst_time;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    priority_scheduling(p, n);
    ljf(p, n);
    lrtf(p, n);

    return 0;
}
