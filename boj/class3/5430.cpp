/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5430.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:57:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 00:06:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);  // use cpp buffer only
  std::cin.tie(NULL);                     // untie std::cin && std::cout

  int test_case = 0;
  std::cin >> test_case;

  std::string cmds = "";
  std::string str_arr = "";
  int arr_len = 0;
  bool is_reversed;
  bool is_valid;

  for (int test = 0; test < test_case; test++) {
    std::cin >> cmds >> arr_len >> str_arr;
    is_reversed = false;
    is_valid = true;

    std::deque<int> dq;
    int idx = 0;
    while (idx < str_arr.length()) {
      if (str_arr[idx] == '[' || str_arr[idx] == ']' || str_arr[idx] == ',') {
        idx++;
        continue;
      } else {
        dq.push_back(atoi(str_arr.c_str() + idx));
        while (idx < str_arr.length() &&
               (str_arr[idx] != '[' && str_arr[idx] != ']' &&
                str_arr[idx] != ',')) {
          idx++;
        }
      }
    }

    for (int cmd = 0; cmd < cmds.length(); cmd++) {
      if (cmds[cmd] == 'R') {
        is_reversed = !is_reversed;
      } else if (cmds[cmd] == 'D') {
        if (dq.size() == 0) {
          is_valid = false;
          break;
        }

        if (is_reversed) {
          dq.pop_back();
        } else {
          dq.pop_front();
        }
      }
    }

    if (is_valid) {
      std::cout << "[";
      for (int i = 0; i < dq.size(); i++) {
        if (is_reversed) {
          std::cout << dq[dq.size() - i - 1];
        } else {
          std::cout << dq[i];
        }

        if (dq.size() - i > 1) {
          std::cout << ",";
        }
      }
      std::cout << "]\n";
    } else {
      std::cout << "error\n";
    }
  }
  return 0;
}

// 4 RDD 4 [1, 2, 3, 4] DD 1 [42] RRD 6 [1, 1, 2, 3, 5, 8] D 0 []