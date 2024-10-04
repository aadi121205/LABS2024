#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

// Structure to store process details
struct process {
    int pid; // Process ID
    int burst_time; // Burst time of the process
    int arrival_time; // Arrival time of the process
    int remaining_time; // Remaining time of the process
};

// Function to implement FCFS
void fcfs(struct process p[], int n) {
    int wait_time = 0, turnaround_time = 0, current_time = 0;
    printf("\nFCFS Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time; // CPU idle till process arrives
        }
        wait_time = current_time - p[i].arrival_time;
        turnaround_time = wait_time + p[i].burst_time;
        current_time += p[i].burst_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, wait_time, turnaround_time);
    }
}

// Function to implement SJF
void sjf(struct process p[], int n) {
    int wait_time[MAX_PROCESSES] = {0}, turnaround_time[MAX_PROCESSES] = {0}, completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_processes = 0, shortest = -1;
    printf("\nSJF Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed_processes < n) {
        int min_bt = INT_MAX;
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !completed[i] && p[i].burst_time < min_bt) {
                min_bt = p[i].burst_time;
                shortest = i;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        current_time += p[shortest].burst_time;
        completed[shortest] = 1;
        completed_processes++;

        wait_time[shortest] = current_time - p[shortest].arrival_time - p[shortest].burst_time;
        turnaround_time[shortest] = current_time - p[shortest].arrival_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[shortest].pid, p[shortest].arrival_time, p[shortest].burst_time, wait_time[shortest], turnaround_time[shortest]);
    }
}

// Function to implement SRTF
void srtf(struct process p[], int n) {
    int wait_time[MAX_PROCESSES] = {0}, turnaround_time[MAX_PROCESSES] = {0}, completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_processes = 0, shortest = -1;
    printf("\nSRTF Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    while (completed_processes < n) {
        int min_rem_bt = INT_MAX;
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && p[i].remaining_time < min_rem_bt) {
                min_rem_bt = p[i].remaining_time;
                shortest = i;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        current_time++;
        p[shortest].remaining_time--;

        if (p[shortest].remaining_time == 0) {
            completed_processes++;
            wait_time[shortest] = current_time - p[shortest].arrival_time - p[shortest].burst_time;
            turnaround_time[shortest] = current_time - p[shortest].arrival_time;
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[shortest].pid, p[shortest].arrival_time, p[shortest].burst_time, wait_time[shortest], turnaround_time[shortest]);
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
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time; // For SRTF
    }

    // Sorting processes by arrival time (required for all algorithms)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Run the scheduling algorithms
    fcfs(p, n);
    sjf(p, n);
    srtf(p, n);

    return 0;
}
