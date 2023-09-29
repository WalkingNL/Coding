
```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& t) {
    return static_cast<typename std::remove_reference<T>::type&&>(t);
}
```
It’s important to note that `std::move` does not actually move anything. It simply casts its argument to an rvalue reference, allowing the argument to be passed to a move constructor or move assignment operator.


#
why using iterator to access the content of a container, what is the main design principle behind it?

    The main design principle behind iterators is to provide a way to access the elements of a container sequentially without exposing its underlying representation.


# smart pointers
shared_ptr, weak_ptr

```cpp
shared_ptr<T> obj = make_shared<T>(x)
```
to allocate the managed object and the control block in a single memory allocation with using make_shared to create a shared_ptr object. `Control block` contains information about the managed object, which includes reference count(strong and weak), deleter, and allocator. The weak reference count keeps track of the number of std::weak_ptr objects that reference the control block.

unique_ptr
```cpp
unique_ptr<T> obj = make_unique<T>(x)
```

how does the `shared_ptr` guarentee the thread-safe?

    use the atomic operation to update the reference count.
