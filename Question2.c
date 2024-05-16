#include <stdio.h>
int maxConDays(int workload[], int N);

int main() {
    int N;
    printf("Enter the number of working days: ");
    scanf("%d", &N);

    int workload[N];
    printf("Enter the workload for each day (separated by space): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &workload[i]);
    }

    int rate = maxConDays(workload, N);
    printf("Employee rating: %d\n", rate);

    return 0;
}

int maxConDays(int workload[], int N) {
    int maxCon = 0;
    int con = 0;

    for (int i = 0; i < N; i++) {
        if (workload[i] > 6) {
            con++;
            if (con > maxCon) {
                maxCon = con;
            }
        } else {
            con = 0;
        }
    }

    return maxCon;
}
