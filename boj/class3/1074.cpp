/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1074.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:08:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 00:36:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

static int num = 0;

void fill_z(int **arr, int level, int y, int x, int total) {
  if (level == total) {
    arr[y + 0][x + 0] = num++;
    arr[y + 0][x + 1] = num++;
    arr[y + 1][x + 0] = num++;
    arr[y + 1][x + 1] = num++;
  } else {
    int half = pow(2, total - level);
    fill_z(arr, level + 1, y, x, total);
    fill_z(arr, level + 1, y, x + half, total);
    fill_z(arr, level + 1, y + half, x, total);
    fill_z(arr, level + 1, y + half, x + half, total);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);  // use cpp buffer only
  std::cin.tie(NULL);                     // untie std::cin && std::cout

  int N, r, c;
  std::cin >> N >> r >> c;

  int len = pow(2, N);
  int **arr = new int *[len];
  for (int i = 0; i < len; i++) {
    arr[i] = new int[len];
  }

  fill_z(arr, 1, 0, 0, N);
  std::cout << arr[r][c] << "\n";

  for (int i = 0; i < len; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}