/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6064.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:21:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 15:34:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

inline int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return a <= b ? gcd(b % a, a) : gcd(b, a);
  }
}

inline int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int test_case = 0;
  std::cin >> test_case;

  int M, N, x, y, max;
  for (int test = 0; test < test_case; test++) {
    std::cin >> M >> N >> x >> y;

    max = lcm(M, N);
    int i;
    for (i = x; i <= max; i += M) {
      if ((i - 1) % N + 1 == y) {
        break;
      }
    }

    if (i > max) {
      std::cout << "-1"
                << "\n";
    } else {
      std::cout << i << "\n";
    }
  }
  return 0;
}