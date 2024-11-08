#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void FCFS(int requests[], int n, int head) {
    int total_movement = 0;
    for (int i = 0; i < n; i++) {
        total_movement += abs(requests[i] - head);
        head = requests[i];
    }
    printf("FCFS Total Head Movement: %d\n", total_movement);
}

void SSTF(int requests[], int n, int head) {
    int total_movement = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        int min_distance = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(requests[j] - head) < min_distance) {
                min_distance = abs(requests[j] - head);
                index = j;
            }
        }
        visited[index] = 1;
        total_movement += min_distance;
        head = requests[index];
    }
    printf("SSTF Total Head Movement: %d\n", total_movement);
}

void SCAN(int requests[], int n, int head, int disk_size, int direction) {
    int total_movement = 0;
    int sorted_requests[n + 2];
    sorted_requests[0] = 0; // Start at 0
    sorted_requests[n + 1] = disk_size - 1; // End at disk size - 1
    for (int i = 0; i < n; i++) sorted_requests[i + 1] = requests[i];

    // Sort requests
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            if (sorted_requests[i] > sorted_requests[j]) {
                int temp = sorted_requests[i];
                sorted_requests[i] = sorted_requests[j];
                sorted_requests[j] = temp;
            }
        }
    }

    int index;
    for (int i = 0; i < n + 2; i++) {
        if (sorted_requests[i] > head) {
            index = i;
            break;
        }
    }

    if (direction == 1) {
        for (int i = index; i < n + 2; i++) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
        for (int i = index - 1; i >= 0; i--) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
        for (int i = index; i < n + 2; i++) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
    }
    printf("SCAN Total Head Movement: %d\n", total_movement);
}

void CSCAN(int requests[], int n, int head, int disk_size) {
    int total_movement = 0;
    int sorted_requests[n + 2];
    sorted_requests[0] = 0;
    sorted_requests[n + 1] = disk_size - 1;
    for (int i = 0; i < n; i++) sorted_requests[i + 1] = requests[i];

    // Sort requests
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            if (sorted_requests[i] > sorted_requests[j]) {
                int temp = sorted_requests[i];
                sorted_requests[i] = sorted_requests[j];
                sorted_requests[j] = temp;
            }
        }
    }

    int index;
    for (int i = 0; i < n + 2; i++) {
        if (sorted_requests[i] > head) {
            index = i;
            break;
        }
    }

    for (int i = index; i < n + 2; i++) {
        total_movement += abs(head - sorted_requests[i]);
        head = sorted_requests[i];
    }
    head = 0;
    for (int i = 0; i < index; i++) {
        total_movement += abs(head - sorted_requests[i]);
        head = sorted_requests[i];
    }

    printf("CSCAN Total Head Movement: %d\n", total_movement);
}

void LOOK(int requests[], int n, int head, int direction) {
    int total_movement = 0;
    int sorted_requests[n];
    for (int i = 0; i < n; i++) sorted_requests[i] = requests[i];

    // Sort requests
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted_requests[i] > sorted_requests[j]) {
                int temp = sorted_requests[i];
                sorted_requests[i] = sorted_requests[j];
                sorted_requests[j] = temp;
            }
        }
    }

    int index;
    for (int i = 0; i < n; i++) {
        if (sorted_requests[i] > head) {
            index = i;
            break;
        }
    }

    if (direction == 1) {
        for (int i = index; i < n; i++) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
        for (int i = index - 1; i >= 0; i--) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
        for (int i = index; i < n; i++) {
            total_movement += abs(head - sorted_requests[i]);
            head = sorted_requests[i];
        }
    }

    printf("LOOK Total Head Movement: %d\n", total_movement);
}

void CLOOK(int requests[], int n, int head) {
    int total_movement = 0;
    int sorted_requests[n];
    for (int i = 0; i < n; i++) sorted_requests[i] = requests[i];

    // Sort requests
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted_requests[i] > sorted_requests[j]) {
                int temp = sorted_requests[i];
                sorted_requests[i] = sorted_requests[j];
                sorted_requests[j] = temp;
            }
        }
    }

    int index;
    for (int i = 0; i < n; i++) {
        if (sorted_requests[i] > head) {
            index = i;
            break;
        }
    }

    for (int i = index; i < n; i++) {
        total_movement += abs(head - sorted_requests[i]);
        head = sorted_requests[i];
    }
    for (int i = 0; i < index; i++) {
        total_movement += abs(head - sorted_requests[i]);
        head = sorted_requests[i];
    }

    printf("CLOOK Total Head Movement: %d\n", total_movement);
}

int main() {
    int n, head, disk_size, direction;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    printf("Enter head movement direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    FCFS(requests, n, head);
    SSTF(requests, n, head);
    SCAN(requests, n, head, disk_size, direction);
    CSCAN(requests, n, head, disk_size);
    LOOK(requests, n, head, direction);
    CLOOK(requests, n, head);

    return 0;
}
