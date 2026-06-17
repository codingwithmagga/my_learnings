# Practice Problems (5 tasks)

## 1) Simple Class Template `Stack<T>`

**Topic:** Class Templates, Implementation of Class Template Stack  
**Duration:** about 10–15 minutes

Write a simple class template `Stack<T>`.

### Requirements

* Internal storage using `std::vector<T>`
* These member functions:
  * `push(const T&)`
  * `pop()`
  * `top()`
  * `empty() const`
  * `size() const`
* Test the class with:
  * `Stack<int>`
  * `Stack<std::string>`

### Additional Questions

1. Why is `Stack<T>` a **class template** and not a normal class?
2. Which member functions should be `const`?
3. What should happen if `pop()` or `top()` is called on an empty stack?

***

## 2) Using a Class Template Stack

**Topic:** Use of Class Template Stack  
**Duration:** about 10 minutes

Assume that a `Stack<T>` has already been implemented.

### Tasks

Write short code examples showing how to use:

* `Stack<int>`
* `Stack<double>`
* `Stack<std::string>`

### Additional Tasks

1. Push at least three values into each stack
2. Print the top element of each stack
3. Remove one element and check `top()` again afterward

### Understanding Questions

1. Why can the same `Stack<T>` implementation be used for different types?
2. What requirements does `Stack<T>` impose on the type `T`?
3. Are there types for which your stack could be problematic?

***

## 3) Default Template Arguments + Type Aliases

**Topic:** Default Class Template Arguments, Type Aliases, Partial Usage of Class Templates  
**Duration:** about 10–15 minutes

Extend your `Stack` template so that the container type can also be configured.

### Target Idea

```cpp
template<typename T, typename Cont = std::vector<T>>
class Stack;
```

### Tasks

1. Write the template declaration with a **default template argument**
2. Add a **type alias** inside the class, for example:
   ```cpp
   using value_type = T;
   using container_type = Cont;
   ```
3. Create the following types:
   ```cpp
   Stack<int> s1;
   Stack<int, std::deque<int>> s2;
   ```

### Understanding Questions

1. What does “partial usage of class templates” mean here?
2. Why can you omit the second template parameter in `Stack<int>`?
3. What are type aliases useful for in template classes?

***

## 4) Friends + CTAD: Analyze Conceptually

**Topic:** Friends, Class Template Argument Deduction  
**Duration:** about 10–15 minutes

Given the following template class:

```cpp
template<typename T>
class Value {
private:
    T val;
public:
    Value(T v) : val(v) {}
};
```

### Tasks

1. Think about how you would declare an `operator<<` for `Value<T>`
2. Decide whether this operator should be:
   * a normal friend
   * a function template friend
   * or implemented outside the class
3. Also consider this usage:
   ```cpp
   Value v(42);
   Value w(std::string("hello"));
   ```

### Understanding Questions

1. Why might this syntax only become convenient starting with C++17?
2. What is the difference between:
   * `Value<int> v(42);`
   * `Value v(42);`
3. Why are friends in template classes often trickier than in ordinary classes?

***

## 5) Full Specialization vs. Partial Specialization

**Topic:** Specializations of Class Templates, Partial Specialization  
**Duration:** about 10–15 minutes

Given this basic outline:

```cpp
template<typename T>
class Printer;
```

### Tasks

1. Design a **general version** of `Printer<T>`
2. Design a **full specialization** for `Printer<int>`
3. Design a **partial specialization** for pointer types:
   ```cpp
   Printer<T*>
   ```

### Understanding Questions

1. What is the difference between full specialization and partial specialization?
2. Which version would be selected for these types?
   * `Printer<double>`
   * `Printer<int>`
   * `Printer<char*>`
3. Why are partial specializations especially important for **class templates**, but not for **function templates**?

***

# Homework Problems (3 tasks)

## Homework 1) Extendable `Stack<T, Cont>`

**Topics:** Class Templates, Implementation of Class Template Stack, Use of Class Template Stack, Default Class Template Arguments, Type Aliases, Partial Usage of Class Templates  
**Duration:** about 30–45 minutes

Implement a complete template class `Stack<T, Cont>`.

### Requirements

1. Use this form:
   ```cpp
   template<typename T, typename Cont = std::vector<T>>
   class Stack;
   ```
2. Implement at least:
   * `push(const T&)`
   * `pop()`
   * `top()`
   * `empty() const`
   * `size() const`
3. Add the following type aliases:
   ```cpp
   using value_type = T;
   using container_type = Cont;
   using size_type = typename Cont::size_type;
   ```
4. Test the class with:
   ```cpp
   Stack<int> a;
   Stack<std::string> b;
   Stack<int, std::deque<int>> c;
   ```

### Additional Task

Add a method:

```cpp
void print() const;
```

that prints all elements of the stack in a sensible order.

### Understanding Questions

1. What are the advantages of the second template parameter `Cont`?
2. Why is `std::vector<T>` a sensible default?
3. What does “partial usage” mean concretely in:
   ```cpp
   Stack<int>
   ```
4. What requirements must `Cont` satisfy so that your stack works?

***

## Homework 2) `Storage<T>` with Specializations

**Topics:** Specializations of Class Templates, Partial Specialization, Friends  
**Duration:** about 30–45 minutes

Implement a class `Storage<T>` that stores a value and can print it.

### Requirements

1. Write a **primary template**:
   ```cpp
   template<typename T>
   class Storage;
   ```
2. Implement a general version for ordinary types
3. Implement a **full specialization** for `char*` or `const char*` so that string contents are handled meaningfully instead of only pointer addresses
4. Implement a **partial specialization** for pointer types:
   ```cpp
   template<typename T>
   class Storage<T*>;
   ```
5. Add output support using `operator<<`
   * either with a friend-based solution
   * or with an external function

### Test Cases

Test at least with:

```cpp
Storage<int>
Storage<double>
Storage<const char*>
Storage<int*>
```

### Understanding Questions

1. Why is special handling for `const char*` often useful?
2. What problems can occur with `Storage<T*>`?
3. When is the full specialization used, and when is the partial specialization used?
4. What challenges arise with `friend operator<<` in template classes?

***

## Homework 3) Templatized Aggregates + CTAD

**Topics:** Templatized Aggregates, Class Template Argument Deduction, Type Aliases  
**Duration:** about 30–45 minutes

Design a simple templatized aggregate, for example `Pair<T1, T2>` or `ValueWithTag<T, Tag>`.

### Example Idea

```cpp
template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;
};
```

### Tasks

1. Implement a **templatized aggregate** with at least two template parameters
2. Add sensible type aliases, for example:
   ```cpp
   using first_type = T1;
   using second_type = T2;
   ```
3. Test direct usage with explicit template arguments:
   ```cpp
   Pair<int, double> p1{1, 2.5};
   ```
4. Also test CTAD:
   ```cpp
   Pair p2{1, 2.5};
   Pair p3{std::string("id"), 42};
   ```

### Additional Task

If CTAD does not work as expected in your compiler / language standard mode:

* investigate why
* document the difference between C++17 and C++20 in your experiment
* optionally add a suitable deduction guide

### Understanding Questions

1. What is a “templatized aggregate”?
2. Why can CTAD for aggregates be interestingly different depending on the standard/compiler?
3. What is the difference between:
   ```cpp
   Pair<int, double> p{1, 2.5};
   ```
   and
   ```cpp
   Pair p{1, 2.5};
   ```
4. When can type aliases be helpful in such a structure?
