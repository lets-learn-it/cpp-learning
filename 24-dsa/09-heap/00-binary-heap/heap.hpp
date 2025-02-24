#include <vector>
#include <iostream>

template <typename T>
class Heap {
private:
  std::vector<T> arr;
  void bubbleUp(int pos) {
    while (pos > 0) {
      int parent = (pos-1)/2;
      if (arr[parent] < arr[pos]) {
        std::swap(arr[(pos-1)/2], arr[pos]);
        pos = parent;
      } else {
        break;
      }
    }
  }

  void bubbleDown(int pos) {
    int size = arr.size();

    while(true) {
      int left = (pos*2)+1;
      int right = (pos*2)+2;
      if (left < size && arr[pos] < arr[left]) {
        std::swap(arr[pos], arr[(pos*2)+1]);
        pos = left;
      } else if (right < size && arr[pos] < arr[right]) {
        std::swap(arr[pos], arr[(pos*2)+2]);
        pos = right;
      } else {
        break;
      }
    }
  }
public:
  void push(T n) {
    arr.push_back(n);
    bubbleUp(arr.size()-1);
  }

  T top() {
    return arr[0];
  }

  bool empty() {
    return arr.size() == 0;
  }

  void pop() {
    arr[0] = arr[arr.size()-1];
    arr.pop_back();
    bubbleDown(0);
  }
};
