#include <iostream>
#include "numbers.dat"
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

const int MAX_N = 1e5 + 1;

// O(NloglogN)
void
counting_prime_numbers(int * prime_numbers, int size_prime_numbers)
{
    prime_numbers[1] = 1;
    prime_numbers[0] = 1;
    for (int i = 2; i * i < size_prime_numbers; ++i) {
        if (!prime_numbers[i]) {
            for (int j = i * i; j < size_prime_numbers; j += i) {
                prime_numbers[j] = 1;
            }
        }
    }
}

// O(N)
void
counting_prefix_ans(int * prefix_ans, int size_prefix_ans, int * prime_numbers)
{
    for (int i = 0; i < size_prefix_ans; ++i) {
        if (i == 0 && !prime_numbers[Data[i]]) {
            prefix_ans[i] = 1;
        } else if (!prime_numbers[Data[i]]) {
            prefix_ans[i] = prefix_ans[i - 1] + 1;
        } else {
            prefix_ans[i] = prefix_ans[i - 1];
        }
    }
}

//O(1)
int
counting_ans(int position_first, int position_second, int * prefix_ans, int size_prefix_ans, int first_value, int second_value)
{
    if (position_first < 0 || position_first >= size_prefix_ans
        || position_second < 0 || position_second >= size_prefix_ans) {
        return 0;
    }
    if (position_first <= position_second
        && Data[position_first] == first_value && Data[position_second] == second_value) {
        if (position_first > 0) {
            return prefix_ans[position_second] - prefix_ans[position_first - 1];
        } else {
            return prefix_ans[position_second];
        }
    } else {
        return 0;
    }
}

//O(NloglogN) + C * O(logN)
int main(int argc, const char * argv[]) {
    if (argc % 2 != 1 || argc == 1) {
        return -1;
    }
    
    
    int *prime_numbers = new int[MAX_N]();
    counting_prime_numbers(prime_numbers, MAX_N);
    
    int *prefix_ans = new int[Size]();
    counting_prefix_ans(prefix_ans, Size, prime_numbers);
    
    for (int i = 1; i < argc; i += 2) {
        int first_value = std::atoi(argv[i]);
        int second_value = std::atoi(argv[i + 1]);
        //O(logN)
        int position_first = std::lower_bound(Data, Data + Size, first_value) - Data;
        int position_second = std::upper_bound(Data, Data + Size, second_value) - Data - 1;
        int ans = counting_ans(position_first, position_second, prefix_ans, Size, first_value, second_value);
        printf("%d\n", ans);
    }
    delete[] prime_numbers;
    delete[] prefix_ans;
    return 0;
}
