#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int compare(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos; // descending by position
}

int carFleet(int target, int pos[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = pos[i];
        cars[i].time = (double)(target - pos[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int pos[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, pos, speed, n));

    return 0;
}
