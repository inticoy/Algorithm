/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1074.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:08:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 17:14:12 by inticoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

static int num = 0;
static int r, c = 0;
static int answer = -1;

void solve_z(int y, int x, int size) {
  if (size == 1) {
	  if (y == r && x == c) {
		  answer = num;
	  }
  } else {
	  if (r < y + size / 2 && c < x+ size / 2) {
		solve_z(y, x, size / 2);
	  } else if (r < y + size / 2 && c >= x + size / 2) {
		num += size * size / 4;
		solve_z(y, x + size / 2, size / 2);
	  } else if (r >= y + size / 2 && c < x + size / 2) {
		num += size * size / 4 * 2;
		solve_z(y + size / 2, x, size / 2);
	  } else if (r >= y + size / 2 && c >= x + size / 2) {
		num +=size * size / 4 * 3;
		solve_z(y + size / 2, x + size / 2, size / 2);
	  }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);  // use cpp buffer only
  std::cin.tie(NULL);                     // untie std::cin && std::cout

  int N;
  std::cin >> N >> r >> c;

  int len = pow(2, N);

  solve_z(0, 0, len);
  std::cout << answer << "\n";

  return 0;
}
