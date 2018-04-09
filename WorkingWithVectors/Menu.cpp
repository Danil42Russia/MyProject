#include "stdafx.h"
#include "Menu.h"
#include "Prog.h"

using namespace prog;

namespace menu
{
  void add_vecor_menu(vector<vector<vector<string>>> &vec);
  void list_vetor_menu(vector<vector<vector<string>>> &vec);
  void filling_vector_menu(vector<vector<vector<string>>> &vec);

  void search_vector_menu(vector<vector<vector<string>>> &vec);
  void search_MIN_vector_menu(size_t id, vector<vector<vector<string>>> &vec);
  void search_MAX_vector_menu(size_t choose_id_vector, vector<vector<vector<string>>> &vec);

  void sort_vector_menu(vector<vector<vector<string>>> &vec);

  void special_print_vector_menu(vector<vector<vector<string>>> &vec);

  //

  void main_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    int paragraph = 0;

    cout << "<--������� ����-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)�������� ������" << endl
      << "\t2)������ ��������" << endl
      << "\t3)��������� ������" << endl
      << "\t4)��������/������ ������� (� ���������)" << endl
      << "\t5)����������" << endl
      << "\t6)���������� MIN/MAX" << endl
      << "\t7)��������� �����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;

    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      add_vecor_menu(vec);
      break;

    case 2:
      list_vetor_menu(vec);
      break;

    case 3:
      filling_vector_menu(vec);
      break;

    case 4:
      break;

    case 5:
      sort_vector_menu(vec);
      break;

    case 6:
      search_vector_menu(vec);
      break;

    case 7:
      special_print_vector_menu(vec);
      break;

    default:
      break;
    }

    cin.clear();
  }

  void add_vecor_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    int length = 0;
    int width = 0;
    int paragraph = 0;

    cout << "<--���� ���������� �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)�������� ������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      system("CLS");

      cout << "������� ������ �������" << endl;
      cin >> length;

      cout << "������� ������ �������" << endl;
      cin >> width;

      if (!(length == 0 || width == 0 || isalpha(length) || isalpha(width))) {
        try
        {
          new_vector(length, width, vec);

          cout << "������ " << length << " x " << width << " ������� ��������!" << endl;
        }
        catch (exception &ex)
        {
          cout << "������ ��� ���������� �������";
          cout << ex.what();
        }
      }
      else
        cout << "������ ��� ���������� ������� ������� �� ������ ������" << endl;

      system("PAUSE");
      break;

    case 9:
      main_menu(vec);
      break;

    default:
      add_vecor_menu(vec);
      break;
    }

    cin.clear();
  }

  void list_vetor_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    size_t choose_id_vector = 0;
    int paragraph = 0;

    cout << "<--���� ������� ��������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)�������� �������" << endl
      << "\t2)������� ������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");

        print_list_vec(vec);
      }

      system("PAUSE");
      break;

    case 2:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ����������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;
        system("CLS");

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
        {
          cout << "������ " << choose_id_vector << endl << endl;

          print_vec(choose_id_vector, vec);
          system("PAUSE");
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      break;

    case 9:
      main_menu(vec);
      break;

    default:
      list_vetor_menu(vec);
      break;
    }

    cin.clear();
  }

  void filling_vector_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    size_t choose_id_vector = 0;
    int paragraph = 0;
    int from = 0;
    int to = 0;
    string str;
    string tempstr;
    size_t index_vector = 0;
    vector<vector<string>> temp;

    cout << "<--���� ���������� ��������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)�������������� ���������� ��������" << endl
      << "\t2)������ ���������� ��������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ����������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;

        cout << "������� �������� ��������" << endl;

        cout << "������� ����������� �����" << endl;
        cin >> from;

        cout << "������� ����������� �����" << endl;
        cin >> to;

        if (!(choose_id_vector > vec.size() - 1 || isalpha(static_cast<int>(choose_id_vector)) || isalpha(from) || isalpha(to) || choose_id_vector > 0) || from != to)
        {
          auto_filling_vector(choose_id_vector, from, to, vec);

          cout << "������ ������� ��������!" << endl;
        }
        else
          cout << "������ ��� ���������� �������" << endl;
      }
      system("PAUSE");
      break;

    case 2:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ����������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;
        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0) {

          temp = vec[choose_id_vector];

          cin.ignore(INT_MAX, '\n');

          for (size_t i = 0; i < vec[choose_id_vector].size(); ++i)
          {
            for (size_t k = 0; k < vec[choose_id_vector][i].size(); ++k)
              cout << "x ";
            cout << endl;

            getline(cin, str);

            for (size_t index = 0; index < str.length() + 1; ++index)
            {
              if (str[index] != ' ' && str[index] != '\0')
                tempstr += str[index];
              else
              {
                temp[i].resize(index_vector);
                temp[i].push_back(tempstr);
                index_vector++;
                tempstr.clear();
              }
            }
            index_vector = 0;
            str.clear();
          }

          if (user_filling_vector(choose_id_vector, temp, vec))
            vec[choose_id_vector] = temp;
          else
            cout << "������ ��� ����������� ��������" << endl;
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
        temp.clear();
        system("PAUSE");
        break;

    case 9:
      main_menu(vec);
      break;

    default:
      filling_vector_menu(vec);
      break;
      }

      cin.clear();
    }
  }

  //Search

  void search_vector_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    int paragraph = 0;
    size_t choose_id_vector = 0;

    cout << "<--���� ���������� MIN/NAX � �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)����� MAX" << endl
      << "\t2)����� MIN" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
          search_MAX_vector_menu(choose_id_vector, vec);
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      break;

    case 2:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
          search_MIN_vector_menu(choose_id_vector, vec);
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      break;

    case 9:
      main_menu(vec);
      break;

    default:
      search_vector_menu(vec);
      break;
    }

    cin.clear();
  }

  void search_MAX_vector_menu(size_t id, vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    vector<string>::iterator it;
    int paragraph = 0;
    size_t where = 0;
    vector<string> temp;

    cout << "<--���� ���������� MAX � �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)����� MAX � ������" << endl
      << "\t2)����� MAX � �������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      system("CLS");

      print_vec(id, vec);
      cout << endl;

      cout << "������� ID ������ (������� � 0)" << endl;
      cin >> where;

      system("CLS");
      print_vec(id, vec);
      cout << endl;

      if ((where <= vec[id].size() - 1 && where > 0) || where == 0) {
        it = max_element(vec[id][where].begin(), vec[id][where].end());

        cout << "� ������ " << where << " ������������ �������: " << *it << " � ������� " << distance(vec[id][where].begin(), it) << endl;
      }
      else
        cout << "�� ����� �� ������ ID" << endl;

      system("PAUSE");
      break;
    case 2:
      system("CLS");

      print_vec(id, vec);
      cout << endl;

      cout << "������� ID ������� (������� � 0)" << endl;
      cin >> where;

      system("CLS");
      print_vec(id, vec);
      cout << endl;

      if ((where <= vec[id][0].size() - 1 && where > 0) || where == 0) {

        temp.resize(vec[id].size());

        for (size_t i = 0; i < vec[id].size(); ++i)
          temp[i] = vec[id][i][where];

        it = max_element(temp.begin(), temp.end());

        cout << "� ������� " << where << " ������������ ������� " << *it << " � ������� " << distance(temp.begin(), it) << endl;

      }
      else
        cout << "�� ����� �� ������ ID" << endl;

      system("PAUSE");
      temp.clear();
      break;

    case 9:
      search_vector_menu(vec);
      break;

    default:
      search_MAX_vector_menu(id, vec);
      break;
    }

    cin.clear();
  }
  void search_MIN_vector_menu(size_t id, vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    vector<string>::iterator it;
    int paragraph = 0;
    size_t where = 0;
    vector<string> temp;

    cout << "<--���� ���������� MIN � �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)����� MIN � ������" << endl
      << "\t2)����� MIN � �������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      system("CLS");

      print_vec(id, vec);
      cout << endl;

      cout << "������� ID ������ (������� � 0)" << endl;
      cin >> where;

      system("CLS");
      print_vec(id, vec);
      cout << endl;

      if ((where <= vec[id].size() - 1 && where > 0) || where == 0) {
        it = min_element(vec[id][where].begin(), vec[id][where].end());

        cout << "� ������ " << where << " ����������� �������: " << *it << " � ������� " << distance(vec[id][where].begin(), it) << endl;
      }
      else
        cout << "�� ����� �� ������ ID" << endl;

      system("PAUSE");
      break;
    case 2:
      system("CLS");

      print_vec(id, vec);
      cout << endl;

      cout << "������� ID ������� (������� � 0)" << endl;
      cin >> where;

      system("CLS");
      print_vec(id, vec);
      cout << endl;

      if ((where <= vec[id][0].size() - 1 && where > 0) || where == 0) {

        temp.resize(vec[id].size());

        for (size_t i = 0; i < vec[id].size(); ++i)
          temp[i] = vec[id][i][where];

        it = min_element(temp.begin(), temp.end());

        cout << "� ������� " << where << " ����������� ������� " << *it << " � ������� " << distance(temp.begin(), it) << endl;

      }
      else
        cout << "�� ����� �� ������ ID" << endl;

      system("PAUSE");
      temp.clear();
      break;

    case 9:
      search_vector_menu(vec);
      break;

    default:
      search_MIN_vector_menu(id, vec);
      break;
    }

    cin.clear();
  }

  //Sorting

  void sort_vector_menu(vector<vector<vector<string>>> &vec) {
    system("CLS");

    vector<vector<string>> temp;
    int paragraph = 0;
    size_t choose_id_vector = 0;

    cout << "<--���� ���������� �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)���������� �� MAX � MIN" << endl
      << "\t2)���������� �� MIN � MAX" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ����������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;
        system("CLS");

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
        {
          temp = vec[choose_id_vector];

          for (size_t i = 0; i < temp.size(); ++i)
            sort(temp[i].begin(), temp[i].end());

          compare_vector(choose_id_vector, temp, vec);

          system("PAUSE");
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      temp.clear();
      break;

    case 2:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ����������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;
        system("CLS");

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
        {
          temp = vec[choose_id_vector];

          for (size_t i = 0; i < temp.size(); ++i)
            sort(temp[i].rbegin(), temp[i].rend());

          cout << "���������� ������� " << choose_id_vector << endl << endl;

          compare_vector(choose_id_vector, temp, vec);

          system("PAUSE");
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      temp.clear();
      break;

    case 9:
      main_menu(vec);
      break;

    default:
      sort_vector_menu(vec);
      break;
    }

    cin.clear();
  }

  void special_print_vector_menu(vector<vector<vector<string>>> &vec)
  {
    system("CLS");

    int paragraph = 0;
    size_t choose_id_vector = 0;
    size_t where = 0;

    cout << "<--���� ��� ������ ������/������� � �������-->" << endl;
    cout << "�������� �����:" << endl
      << "\t1)����� ������" << endl
      << "\t2)����� �������" << endl
      << "\t9)�����" << endl
      << "\t0)��������� ������" << endl;

    cin >> paragraph;
    switch (paragraph)
    {
    case 0:
      exit(0);

    case 1:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ������ ������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
        {
          system("CLS");

          print_vec(choose_id_vector, vec);
          cout << endl;


          cout << "������� ID ������ (������� � 0)" << endl;
          cin >> where;
          if ((where <= vec[choose_id_vector].size() - 1 && where > 0) || where == 0) {
            system("CLS");
            print_vec(choose_id_vector, vec);
            cout << endl;


            for (size_t i = 0; i < vec[choose_id_vector][where].size(); ++i)
              cout << vec[choose_id_vector][where][i] << " ";
            cout << endl;
          }
          else
            cout << "�� ����� �� ������ ID" << endl;
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      system("PAUSE");
      break;

    case 2:
      if (vec.empty())
        cout << "������ �������� ������" << endl;
      else
      {
        system("CLS");
        cout << "�������� ������ ��� ������ �������" << endl;

        print_list_vec(vec);

        cin >> choose_id_vector;

        if ((choose_id_vector <= vec.size() - 1 && choose_id_vector > 0) || choose_id_vector == 0)
        {
          system("CLS");

          print_vec(choose_id_vector, vec);
          cout << endl;

          cout << "������� ID ������� (������� � 0)" << endl;
          cin >> where;
          if ((where <= vec[choose_id_vector][0].size() - 1 && where > 0) || where == 0) {//���-�� ��������� � 0...
            system("CLS");
            print_vec(choose_id_vector, vec);
            cout << endl;

            for (size_t i = 0; i < vec[choose_id_vector].size(); ++i)
              cout << vec[choose_id_vector][i][where] << endl;
          }
          else
            cout << "�� ����� �� ������ ID" << endl;
        }
        else
          cout << "�� ����� �� ������ ������" << endl;
      }
      system("PAUSE");
      break;

    case 9:
      main_menu(vec);
      break;

    default:
      special_print_vector_menu(vec);
      break;
    }

    cin.clear();
  }
}