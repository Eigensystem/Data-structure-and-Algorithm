#include <set>

using namespace std;

class MedianFinder {
  multiset<int> numbers{};
  multiset<int>::const_iterator _first, _second;
public:
  MedianFinder() : _first(numbers.begin()), _second(numbers.begin()) {}
    
  void addNum(int num) {
    numbers.emplace(num);
    if (numbers.size() == 1) {
      _first = _second = numbers.begin();
    }
    else if (_first == _second) {
      if (num >= *_first) _second++;
      else _first--;
    }
    else {
      if (*_first <= num && num < *_second) {
        _first++;
        _second--;
      }
      else if (num < *_first) _second = _first;
      else _first = _second;
    }
  }
    
  double findMedian() {
    return (*_first + *_second) / 2.0f;
  }
};