#include "stdafx.h"
#include "Prog.h"

namespace prog
{
  void new_vector(const int h, const int w, vector<vector<vector<string>>> &vec)
  {
    const size_t vecor_id = vec.size();

    const auto vector_length = static_cast<size_t>(h);
    const auto vector_width = static_cast<size_t>(w);

    vec.resize(vecor_id + 1);

    vec[vecor_id].resize(vector_length);

    for (size_t i = 0; i < vector_length; ++i)
      vec[vecor_id][i].resize(vector_width);

  }

  void print_vec(const size_t id, const vector<vector<vector<string>>> &vec)
  {
    for (const auto v_el : vec[id])
    {
      for (const auto el : v_el)
        cout << el << " ";
      cout << endl;
    }
  }

  void auto_filling_vector(const size_t id, const int from, const int  to, vector<vector<vector<string>>> &vec)
  {
    for (size_t i = 0; i < vec[id].size(); ++i)
      for (size_t j = 0; j < vec[id][i].size(); ++j)
        vec[id][i][j] = to_string(from + rand() % (to - from));
  }

  void print_list_vec(const vector<vector<vector<string>>> &vec)
  {
    cout << "Список векторов: " << endl;

    for (size_t i = 0; i < vec.size(); ++i)
    {
      try
      {
        cout << "Вектор " << i << " | " << vec[i].size() << " x " << vec[i][0].size() << endl;
      }
      catch (exception &ex)
      {
        cout << "Ошибка при показании списка векторов";
        cout << ex.what();
      }
    }
  }

  bool user_filling_vector(size_t id, vector<vector<string>> &temp, vector<vector<vector<string>>> &vec)
  {
    bool tf = true;
    if (temp.size() == vec[id].size())
      for (size_t i = 0; i < temp.size(); ++i)
        if (temp[i].size() == vec[id][i].size())
        {
          tf *= true;
        }
        else
          tf *= false;
    else
      return false;

    return tf;
  }

  void compare_vector(size_t id, vector<vector<string>> &temp, vector<vector<vector<string>>> &vec)
  {
    if (vec[id].size() == temp.size())
    {
      for (size_t i = 0; i < vec[id].size(); ++i)
      {
        for (size_t j = 0; j < vec[id][i].size(); ++j)
          cout << vec[id][i][j] << " ";
        cout << "| ";
        for (size_t j = 0; j < temp[i].size(); ++j)
          cout << temp[i][j] << " ";
        cout << endl;
      }
      vec[id] = temp;
    }
    else
      cout << "Размер не совпадает" << endl;
  }
}