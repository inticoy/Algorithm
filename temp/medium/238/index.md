---
emoji: ✍🏻
title: "238. Product of Array Except Self"
date: "2025-02-03 15:00:00"
author: 윤건우
categories: PS
tags: leetcode tag
---

## Overview
-  int array nums가 주어질 때, 각 nums[i]에 대해서 본인을 제외한 다른 값들을 곱한 결과들을 int array로 return.

## Approach

```
       1  2  3  4
front: 1  1  2  6
back: 24 12  4  1
```

- [a,b,c,d,e] 에서 c가 선택되면 (a * b) * (d * e)

- 각 item 이전까지의 곱와 각 item 이후까지의 곱(역순)을 저장해놓은 뒤 front * back을 하면 되는 것에서 착안


## Testcase

1. Input: nums = [1,2,3,4] Output: [24,12,8,6]

2. Input: nums = [-1,1,0,-3,3] Output: [0,0,9,0,0]
## Code

``` c++
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();

        vector<int> front(len);
        vector<int> back(len);
        vector<int> answer(len);

        front[0] = 1;
        back[len - 1] = 1;

        for (auto i = 1; i < nums.size(); i++)
            front[i] = front[i - 1] * nums[i - 1];

        for (auto i = len - 2; i >= 0; i--)
            back[i] = back[i + 1] * nums[i + 1];

        for (auto i = 0; i < nums.size(); i++)
            answer[i] = front[i] * back[i];

        return answer;
    }
};
```

## Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Notes

- answer vector 하나만 선언하고도 문제를 해결할 수 있다. 
