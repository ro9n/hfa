#include <bits/stdc++.h>

using namespace std;

bool solution(vector<int> &A) {
    int sum = 0;
    for (int n : A)
        sum += n;
    int l = 0, r = A.size() - 1, sumL = A[l], sumR = A[r];
    while (l < r) {
        if (sumL == sumR) {
            if (sumL == sum - sumL * 2 - A[l + 1] - A[r - 1] && r - l > 1)
                return true;
            else {
                l++;
                r--;
                sumL += A[l];
                sumR += A[r];
            }
        } else if (sumL > sumR) {
            r--;
            sumR += A[r];
        } else {
            l++;
            sumL += A[l];
        }
    }
    return false;
}

int main() {
    int[] nums1 = {1, 3, 4, 2, 2, 2, 1, 1, 2}, nums2 = {1, 1, 1, 1, 1, 1};
     solve(nums1);
}