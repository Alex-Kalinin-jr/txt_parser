#ifndef THIS_PROJECT_LIST_H
#define THIS_PROJECT_LIST_H

#include <fstream>
#include <iostream>

template <typename T> class Node {
public:
  T data_;
  Node *next_;
  Node *prev_;

  Node(T value) : data_(value), next_(nullptr), prev_(nullptr) {}
};

template <typename T> class LinkedList {

public:
  LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

  ~LinkedList() { Clear(); }

  LinkedList(const LinkedList &other)
      : head_(nullptr), tail_(nullptr), size_(0) {
    Node<T> *current = other.head_;
    while (current != nullptr) {
      PushBack(current->data_);
      current = current->next_;
    }
  }

  LinkedList(LinkedList &&other) noexcept
      : head_(other.head_), tail_(other.tail_), size_(other.size_) {
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }

  LinkedList &operator=(const LinkedList &other) {
    if (this != &other) {
      LinkedList temp(other);
      std::swap(head_, temp.head_);
      std::swap(tail_, temp.tail_);
      std::swap(size_, temp.size_);
    }
    return *this;
  }

  LinkedList &operator=(LinkedList &&other) noexcept {
    if (this != &other) {
      Clear();
      head_ = other.head_;
      tail_ = other.tail_;
      size_ = other.size_;
      other.head_ = nullptr;
      other.tail_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  void Display(std::ofstream &file) const {
    Node<T> *current = head_;

    if constexpr (std::is_same_v<T, std::pair<std::string, int>>) {
      while (current != nullptr) {
        file << current->data_.first << "-" << current->data_.second
             << std::endl;
        current = current->next_;
      }
    } else {
      while (current != nullptr) {
        file << current->data_ << std::endl;
        current = current->next_;
      }
    }

    file << std::endl;
  }

  int get_size() const { return size_; }

  void PushBack(T value) {
    Node<T> *new_node = new Node<T>(value);

    if (head_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      tail_->next_ = new_node;
      new_node->prev_ = tail_;
      tail_ = new_node;
    }

    ++size_;
  }

  LinkedList<std::pair<T, int>> DoubleCriteriaSort() {
    Sort();
    LinkedList<std::pair<T, int>> buff = Accumulate(*this);
    buff.SortPairs();
    return buff;
  }

  void Sort() { QuickSort(head_, tail_); }

private:
  Node<T> *head_;
  Node<T> *tail_;
  int size_;

  void Clear() {
    Node<T> *current = head_;
    while (current != nullptr) {
      Node<T> *next_ = current->next_;
      delete current;
      current = next_;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  void QuickSort(Node<T> *low, Node<T> *high) {
    if (high != nullptr && low != high && low != high->next_) {
      Node<T> *pivot = Partition(low, high);
      QuickSort(low, pivot->prev_);
      QuickSort(pivot->next_, high);
    }
  }

  Node<T> *Partition(Node<T> *low, Node<T> *high) {
    T pivot = high->data_;
    Node<T> *i = low->prev_;

    for (Node<T> *j = low; j != high; j = j->next_) {
      if (j->data_ <= pivot) {
        i = (i == nullptr) ? low : i->next_;
        std::swap(i->data_, j->data_);
      }
    }

    i = (i == nullptr) ? low : i->next_;
    std::swap(i->data_, high->data_);
    return i;
  }

  void QuickSortDescending(Node<T> *low, Node<T> *high) {
    if (high != nullptr && low != high && low != high->next_) {
      Node<T> *pivot = PartitionDescending(low, high);
      QuickSortDescending(low, pivot->prev_);
      QuickSortDescending(pivot->next_, high);
    }
  }

  Node<T> *PartitionDescending(Node<T> *low, Node<T> *high) {
    T pivot = high->data_;
    Node<T> *i = low->prev_;

    for (Node<T> *j = low; j != high; j = j->next_) {
      if (j->data_.second > pivot.second ||
          (j->data_.second == pivot.second && j->data_.first < pivot.first)) {
        i = (i == nullptr) ? low : i->next_;
        std::swap(i->data_, j->data_);
      }
    }

    i = (i == nullptr) ? low : i->next_;
    std::swap(i->data_, high->data_);
    return i;
  }

  // for second iteration sorting. sorts pairs by count descending and within
  // the same count - by alphabet ascending
  void SortPairs() {
    if constexpr (std::is_same_v<T, std::pair<std::string, int>>) {
      QuickSortDescending(head_, tail_);
    }
  }

  // be careful: for right work of this function there should be SORTED list as
  // input.(there is not UB, but result would be wrong otherwise)
  LinkedList<std::pair<std::string, int>>
  Accumulate(const LinkedList<std::string> &sorted_list) {
    LinkedList<std::pair<std::string, int>> word_counts;

    Node<std::string> *current = sorted_list.head_;
    std::string current_word = "";
    int count = 0;

    while (current != nullptr) {
      if (current_word != current->data_) {
        if (!current_word.empty()) {
          word_counts.PushBack(std::make_pair(current_word, count));
        }
        current_word = current->data_;
        count = 1;
      } else {
        ++count;
      }

      current = current->next_;
    }

    if (!current_word.empty()) {
      word_counts.PushBack(std::make_pair(current_word, count));
    }

    return word_counts;
  }
};

#endif // THIS_PROJECT_LIST_H

//+---------------------------------+
//    |            Node<T>              |
//    +---------------------------------+
//    | - data_: T                      |
//             | - next_: Node<T>*               |
//             | - prev_: Node<T>*               |
//             +---------------------------------+
//             | + Node(T)                       |
//             +---------------------------------+

//                                                               +---------------------------------------+
//             |           LinkedList<T>                |
//             +---------------------------------------+
//             | - head_: Node<T>*                      |
//             | - tail_: Node<T>*                      |
//             | - size_: int                           |
//             +---------------------------------------+
//             | + LinkedList()                         |
//             | + ~LinkedList()                        |
//             | + LinkedList(const LinkedList&)        |
//             | + LinkedList(LinkedList&&) noexcept    |
//             | + operator=(const LinkedList&)         |
//             | + operator=(LinkedList&&) noexcept     |
//             | + Display(std::ofstream&) const        |
//             | + get_size() const                     |
//             | + PushBack(T)                          |
//             | + DoubleCriteriaSort()                 |
//             | + Sort()                               |
//             - - - - - - - - - - - - - - - - - - - - -
//             | - Clear()                              |
//             | - QuickSort(Node<T>*, Node<T>*)        |
//             | - Partition(Node<T>*, Node<T>*)        |
//             | - QuickSortDescending(Node<T>*, Node<T>*) |
//             | - PartitionDescending(Node<T>*, Node<T>*) |
//             | - SortPairs()                          |
//             | - Accumulate(const LinkedList<std::string>&) |
//             +---------------------------------------+
