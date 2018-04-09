#pragma once

namespace prog
{
  void new_vector(const int h, const int w, vector<vector<vector<string>>> &vec);
  void print_vec(const size_t id, const vector<vector<vector<string>>> &vec);
  void auto_filling_vector(const size_t id, const int from, const int  to, vector<vector<vector<string>>> &vec);
  void print_list_vec(const vector<vector<vector<string>>> &vec);
  bool user_filling_vector(size_t id, vector<vector<string>> &temp, vector<vector<vector<string>>> &vec);
  void compare_vector(size_t id, vector<vector<string>> &temp, vector<vector<vector<string>>> &vec);
}

