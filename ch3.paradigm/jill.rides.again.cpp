//
// Created by Touhid Alam on 3/26/20.
//

#include <cstdio>
#include <cstring>
#include <string>
//The input file contains information on several bus routes. The first line of the file is a single integer b
// representing the number of route descriptions in the file. The identifier for each route (r) is the sequence number
// within the data file, 1 ≤ r ≤ b. Each route description begins with the number of stops on the route: an integer s,
// 2 ≤ s ≤ 20000 on a line by itself. The number of stops is followed by s − 1 lines, each line i (1 ≤ i < s) is an
// integer ni representing Jill’s assessment of the niceness of the road between the two stops i and i + 1

int stops[20000];

/*
3
3 -1 6
10 4 -5 4 -3 4 4 -4 4 -5
4 -2 -3 -4

 */
void plan_trip(int trip){
    int sum(0), best(0), l(0), r(0), max_diff(0);
    for (int i = 0; stops[i] != 0; ++i) {
        sum += stops[i];
        if (sum < 0) {
            sum = 0;
            l = r = i;
        }
        if (sum >= best) {
            if (sum == best && r - l < max_diff) continue;
            best = sum; r = i;
        }
        max_diff = std::max(max_diff, r - l);
    }

    if (r == l) printf("Route %d has no nice parts\n", trip);
    else printf("The nicest part of route %d is between stops %d and %d\n", trip, l + 2, r + 2);

}
int main() {
    int b, trip = 0;
    scanf("%d", &b);
    while (b--) {
        int s;
        scanf("%d", &s);

        std::memset(stops, 0, sizeof(stops));
        for(int i = 0; i < s - 1; ++i) {
            scanf("%d", &stops[i]);
        }
        plan_trip(++trip);
    }
    return 0;
}

/*
3
3
    -1
    6
10
    4
    -5
    4
    -3
    4
    4
    -4
    4
    -5
4
    -2
    -3
    -4

 */