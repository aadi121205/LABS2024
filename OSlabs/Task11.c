#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROGRAMS 10

void first_fit(int memory_blocks[], int n, int required_memory, int process_id)
{
    for (int i = 0; i < n; i++)
    {
        if (memory_blocks[i] >= required_memory)
        {
            memory_blocks[i] -= required_memory;
            printf("Process %d allocated %d memory using First Fit.\n", process_id, required_memory);
            return;
        }
    }
    printf("Process %d could not be allocated memory using First Fit.\n", process_id);
}

void best_fit(int memory_blocks[], int n, int required_memory, int process_id)
{
    int best_index = -1;
    int best_size = 10000;
    for (int i = 0; i < n; i++)
    {
        if (memory_blocks[i] >= required_memory && memory_blocks[i] < best_size)
        {
            best_size = memory_blocks[i];
            best_index = i;
        }
    }

    if (best_index != -1)
    {
        memory_blocks[best_index] -= required_memory;
        printf("Process %d allocated %d memory using Best Fit.\n", process_id, required_memory);
    }
    else
    {
        printf("Process %d could not be allocated memory using Best Fit.\n", process_id);
    }
}

void worst_fit(int memory_blocks[], int n, int required_memory, int process_id)
{
    int worst_index = -1;
    int worst_size = -1;

    for (int i = 0; i < n; i++)
    {
        if (memory_blocks[i] >= required_memory && memory_blocks[i] > worst_size)
        {
            worst_size = memory_blocks[i];
            worst_index = i;
        }
    }

    if (worst_index != -1)
    {
        memory_blocks[worst_index] -= required_memory;
        printf("Process %d allocated %d memory using Worst Fit.\n", process_id, required_memory);
    }
    else
    {
        printf("Process %d could not be allocated memory using Worst Fit.\n", process_id);
    }
}

void show_memory_state(int memory_blocks[], int n)
{
    printf("\nCurrent Memory Blocks:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Block %d: %d memory left\n", i, memory_blocks[i]);
    }
}

void show_memory_matrix(int memory_blocks[], int n)
{
    printf("\nMemory Blocks Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", memory_blocks[i]);
    }
    printf("\n");
}

int main()
{
    int memory_blocks[MAX_BLOCKS] = {100, 500, 200, 300, 600};
    int n = 5; // Number of memory blocks

    show_memory_matrix(memory_blocks, n);

    printf("Selecting memory allocation algorithms:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");

    int m;
    scanf("%d", &m);

    int num_programs;
    printf("Enter number of programs: ");
    scanf("%d", &num_programs);

    int program_sizes[MAX_PROGRAMS];
    for (int i = 0; i < num_programs; i++)
    {
        printf("Enter size of program %d: ", i + 1);
        scanf("%d", &program_sizes[i]);
    }

    for (int i = 0; i < num_programs; i++)
    {
        switch (m)
        {
        case 1:
            first_fit(memory_blocks, n, program_sizes[i], i + 1);
            break;
        case 2:
            best_fit(memory_blocks, n, program_sizes[i], i + 1);
            break;
        case 3:
            worst_fit(memory_blocks, n, program_sizes[i], i + 1);
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
        }
        show_memory_matrix(memory_blocks, n);
    }

    show_memory_state(memory_blocks, n);
    return 0;
}
