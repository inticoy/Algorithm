---
emoji: ✍🏻
title: "151. Reverse Words in a String"
date: "2025-02-03 15:00:00"
author: 윤건우
categories: PS
tags: leetcode string two-pointer
---

## Overview
- string에는 space로 구분되는 여러개의 string이 있다. 이를 split하되, 반대 순서로 바꾸어 space 하나로 떨어뜨려 return.

## Approach 1

### stringstream 이용

1. stringstream으로 split하여 vector<string>에 저장

2. vector를 iterate하며 새 stringstream에 띄어쓰기와 저장

3. return ss.str()

## Testcase

1. Input: s = "the    sky is blue" Output: "blue is sky the"

2. Input: s = "  hello world  " Output: "world hello"

## Code

``` c++
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;

        string temp;
        stringstream ss(s);
        stringstream out;

        while (ss >> temp)
            words.push_back(temp);

        for (auto i = 0; i < words.size(); i++)
        {
            out << words[words.size() - i - 1];
            if (i != words.size() - 1)
                out << " ";
        }

        return out.str();
    }
};
```

## Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Approach 2

### O(1) Extra Space 로 구혀


## Code

``` c++

```

## Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Notes
- 
