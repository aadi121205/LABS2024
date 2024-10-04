#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int n, m;
int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES], available[MAX_RESOURCES];
int finished[MAX_PROCESSES], safe_sequence[MAX_PROCESSES];

void calculateNeed() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int checkSafety() {
    int work[MAX_RESOURCES];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    for (int i = 0; i < n; i++) {
        finished[i] = 0;
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}

void requestResources(int process_id, int request[]) {
    for (int i = 0; i < m; i++) {
        if (request[i] > need[process_id][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return;
        }
        if (request[i] > available[i]) {
            printf("Resources not available. Process must wait.\n");
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }

    if (checkSafety()) {
        printf("Resources granted. System is in a safe state.\n");
    } else {
        for (int i = 0; i < m; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        printf("Resources cannot be granted. System would enter an unsafe state.\n");
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    calculateNeed();

    if (checkSafety()) {
        printf("System is in a safe state.\nSafe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
    } else {
        printf("System is not in a safe state.\n");
    }

    int process_id, request[MAX_RESOURCES];
    printf("Enter process ID requesting resources: ");
    scanf("%d", &process_id);
    printf("Enter resource request:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &request[i]);
    }

    requestResources(process_id, request);

    return 0;
}
