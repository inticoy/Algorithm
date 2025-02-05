---
emoji: ✍🏻
title: "334. Increasing Triplet Subsequence"
date: "2025-02-03 00:00:00"
author: 윤건우
categories: PS
tags: leetcode greedy
---

## Overview
-  int array nums가 주어질 때, 0 <= i, j, k < nums.size()인 i, j, k에 대해서 nums[i] < nums[j] < nums[k] 인 i, j, k의 존재 여부를 return.

## Approach

-  i, j, k의 여부만 체크하면 되는 것이므로 nums[i], nums[j]를 각각 small, big에 저장.

- 이전의 nums[i], nums[j] 쌍보다 nums[j]가 작은 쌍이 존재한다면 small과 big을 업데이트 해주어야 하므로 temp에 nums[i] 후보를 저장

1. small, big, temp에 nums[0] 저장

2. nums[1]부터 small, big, temp를 업데이트.

	2.a. small < big < curr 라면 i, j, k 존재. (return true)

	2.b. small < curr < big 이라면 기존 big보다 더 나은 j 후보 it으로 big을 업데이트

	2.c. temp < curr 이라면 small, big을 각각 temp, curr로 업데이트

	2.d. curr < small 이라면 i 후보 curr을 temp 에 저장

x. temp 를 새로운 i 후보로 지정하는데, 2.c 에서 (temp, curr)이 (small, big)과 비교했을 때, temp는 상관없지만 curr < big을 만족해야 새로 저장해야 한다. (curr <= big이어도 새로 저장해도 되긴 하지만 중요하지 않음.) 이 비교는 조건문에서 나타나 있지는 않지만, 만약 curr > big이라면 위의 조건문에서 return true가 될 것이므로 고려하지 않아도 된다.

## Testcase

1. [2,1,5,0,4,6] => true

2. [1,2,3,4,5] => true

## Code

``` c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = nums[0];
        int big = nums[0];
        int temp = nums[0];

        for (auto i = 0; i < nums.size(); i++)
        {
            if (small < big && big < nums[i])
                return true;
            
            if (small < nums[i] && nums[i] < big)
                big = nums[i];
            
            if (temp < nums[i])
            {
                small = temp;
                big = nums[i];
            }

            if (nums[i] < small)
                temp = nums[i];
            
        }
        
        return false;
    }
};
```

## Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Notes
- 나의 코드는 small, big, temp에 대해서 조건문이 4개나 있어서 구조적으로 파악하기가 굉장히 힘들었다. 하지만 `Alexander Korobeynikov` 의 코드를 보면 내 코드에서 small을 덜어낼 수 있다는 것을 알아낼 수 있다. 

``` c++
bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           
        } else if (x <= c2) { 
            c2 = x;           
        } else {              
            return true;      
        }
    }
    return false;
}
```

- c1 는 temp과 c2 는 big과 비슷한 역할을 한다.

- 문제에서는 i, j, k를 알아낼 필요가 없기 때문에, (small, big)의 순서쌍을 저장해둘 필요가 없다.

- 첫번째 조건에 의해 curr <= c1 이면 i 후보가 curr이 된다.

- 두번째 조건에 c1 < curr <= c2에 의해 curr이 최적의 j 후보라면 저장한다.

- 마지막 조건에 의해 curr은 c2보다 크므로 조건을 만족한다.
