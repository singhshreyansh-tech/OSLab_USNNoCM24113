#include <stdio.h>
#include <limits.h>

int main() {
    int n = 3;
    int arrival[3] = {0, 2, 6};
    int burst[3] = {10, 20, 30};
    int remaining[3];
    int complete = 0, time = 0, min, shortest = 0;
    int finish_time;
    int waiting[3];
    int context_switch = -1;  
    int prev = -1;

    for(int i = 0; i < n; i++)
        remaining[i] = burst[i];

    while (complete != n) {
        min = INT_MAX;

        for (int j = 0; j < n; j++) {
            if ((arrival[j] <= time) &&
                (remaining[j] < min) &&
                remaining[j] > 0) {
                min = remaining[j];
                shortest = j;
            }
        }

        if (min == INT_MAX) {
            time++;
            continue;
        }

        if (prev != shortest) {
            context_switch++;
            prev = shortest;
        }

        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0) {
            complete++;
            finish_time = time;
            waiting[shortest] =
                finish_time - burst[shortest] - arrival[shortest];
            if (waiting[shortest] < 0)
                waiting[shortest] = 0;
        }
    }

    float avg = 0;
    for(int i = 0; i < n; i++) {
        avg += waiting[i];
        printf("Waiting Time of P%d = %d\n", i+1, waiting[i]);
    }

    printf("Average Waiting Time = %.2f\n", avg/n);
    printf("Total Context Switches = %d\n", context_switch);

    return 0;
}

