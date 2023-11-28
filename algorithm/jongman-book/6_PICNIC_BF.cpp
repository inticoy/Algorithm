/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_PICNIC_BF.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:11:17 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/28 17:14:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * id:			PICNIC
 * link:		https://algospot.com/judge/problem/read/PICNIC
 * algorithm:	brute-force
 */

#include <iostream>

int getSingleIdx(bool haveFriend[], int n)
{
    for (int i = 0; i < n; i++)
        if (!haveFriend[i])
            return i;
    return n;
}

int getFriendPair(int n, bool haveFriend[], bool friendTable[][10])
{
    if (getSingleIdx(haveFriend, n) == n)
        return 1;

    int idx = getSingleIdx(haveFriend, n);
    int pairs = 0;

    for (int i = idx + 1; i < n; i++)
    {
        if (!haveFriend[i] && friendTable[idx][i])
        {
            haveFriend[idx] = true;
            haveFriend[i] = true;
            pairs += getFriendPair(n, haveFriend, friendTable);
            haveFriend[idx] = false;
            haveFriend[i] = false;
        }
    }
    return pairs;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testcase;
    bool friendTable[10][10];
    bool haveFriend[10];
    int n, m, f1, f2;

    std::cin >> testcase;

    for (int test = 0; test < testcase; test++)
    {
        // reset arrays
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                friendTable[i][j] = false;
        for (int i = 0; i < 10; i++)
            haveFriend[i] = false;

        std::cin >> n >> m;

        for (int i = 0; i < m; i++)
        {
            std::cin >> f1 >> f2;
            if (f1 < f2)
                friendTable[f1][f2] = true;
            else
                friendTable[f2][f1] = true;
        }

        std::cout << getFriendPair(n, haveFriend, friendTable) << std::endl;
    }
    return 0;
}