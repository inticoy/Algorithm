---
emoji: ✍🏻
title: "443. String Compression"
date: "2025-02-05 14:30:00"
author: 윤건우
categories: PS
tags: leetcode string two-pointer
---

## Overview
-  chars라는 char array에서 연속해서 반복되는 문자를 압축하고, 압축된 결과의 길이를 리턴하는 함수를 만들자.

## Approach

1. chars 를 iterate하면서 직전 character와 동일한지 비교한다.

	1.a. 같다면, 해당 letter의 개수 1 증가.

	1.b. 다르다면, 적어야할 자리에 문자를 적고, 개수가 1보다 크다면 string으로 바꿔 저장.

2. 적어야할 자리는 idx로 chars의 iterater와는 달리 저장.

## Testcase

1. "aaabbbccc" => "a3b3c3", 6

2. "abbbbbbbbbb" => "ab10", 4

## Code

``` c++
class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0');
        
        int idx = 0;
        int num = 1;

        for (auto i = 1; i < chars.size(); i++)
        {
            if (chars[i-1] == chars[i])
                ++num;
            else
            {
                chars[idx++] = chars[i-1];
                if (num > 1)
                {
                    for (char c : to_string(num))
                        chars[idx++] = c;
                }
                num = 1;
            }
        }

        return idx;
    }
};
```

## Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Notes
- 이 문제와 같이 string을 특별히 formatting 할 필요가 없을 경우에는 stringstream 대신에 to_string을 사용하자.
