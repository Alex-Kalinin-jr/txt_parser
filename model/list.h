#ifndef THIS_PROJECT_LIST_H
#define THIS_PROJECT_LIST_H

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

  ~LinkedList() {
    Node<T> *current = head_;
    while (current != nullptr) {
      Node<T> *next_ = current->next_;
      delete current;
      current = next_;
    }
  }

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

  void Display() {
    Node<T> *current = head_;
    while (current != nullptr) {
      std::cout << current->data_ << " ";
      current = current->next_;
    }
    std::cout << std::endl;
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

  void Sort() { QuickSort(head_, tail_); }

private:
  Node<T> *head_;
  Node<T> *tail_;
  int size_;

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
};

#endif // THIS_PROJECT_LIST_H
