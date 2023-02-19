#include <vector>

using namespace std;

class CQueue
{
  vector<int> _in = {};
  vector<int> _out = {};
  // _flag = 1: push
  // _flag = 0: pop
  bool _flag = 1;
public:
  CQueue() = default;

  void appendTail(int value)
  {
    if (_flag)
    {
      _in.push_back(value);
    }
    else
    {
      int size = _out.size();
      for (int i = 0; i < size; ++i)
      {
        _in.push_back(_out.back());
        _out.pop_back();
      }
      _in.push_back(value);
      _flag = 1;
    }
    return;
  }

  int deleteHead()
  {
    if (_in.empty() && _out.empty())
    {
      return -1;
    }
    if (_flag)
    {
      int size = _in.size();
      for (int i = 0; i < size; ++i)
      {
        _out.push_back(_in.back());
        _in.pop_back();
      }
      int num = _out.back();
      _out.pop_back();
      _flag = 0;
      return num;
    }
    else
    {
      int num = _out.back();
      _out.pop_back();
      return num;
    }
  }
};