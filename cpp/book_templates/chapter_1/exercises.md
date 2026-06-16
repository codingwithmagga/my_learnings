# Practice Problems (5 tasks)

**Goal:** 5–15 minutes per task  
**Format:** short reasoning / mini coding / fill‑in / prediction

***

## 1) Write a Simple Function Template

**Topic:** Function Templates, Argument Deduction  
**Duration:** \~10 minutes

Write a function `mymax()` that returns the larger of two values.

### Requirements

* Implement it as a **function template**
* It should work with `int`, `double`, and `std::string`
* Use it with the following calls:

```cpp
mymax(3, 7);
mymax(4.5, 2.1);
mymax(std::string("abc"), std::string("xyz"));
```

### Additional Questions

1. Do you need to explicitly specify the template parameter for these calls?
2. What happens with `mymax(3, 4.5)`?
3. Why?

***

## 2) What Gets Deduced – and What Doesn’t?

**Topic:** Template Argument Deduction  
**Duration:** \~10–15 minutes

Given these templates:

```cpp
template<typename T>
void f1(T a);

template<typename T>
void f2(T& a);

template<typename T>
void f3(const T& a);

template<typename T>
void f4(T* a);
```

And these variables:

```cpp
int x = 0;
const int cx = 0;
int* px = &x;
const int* pcx = &cx;
```

### Tasks

For each call:

* Determine whether the call is valid
* Determine the deduced type of `T`

Calls:

```cpp
f1(x);
f1(cx);

f2(x);
f2(cx);

f3(x);
f3(cx);

f4(px);
f4(pcx);
```

### Additional

Explain the difference between:

* `T`
* `T&`
* `const T&`

with respect to deduction.

***

## 3) Multiple Template Parameters

**Topic:** Multiple Template Parameters  
**Duration:** \~10 minutes

Write a function template `is_same_value()` that can compare two values of **different types**.

### Requirements

* Use two template parameters
* The following calls should compile:

```cpp
is_same_value(42, 42);
is_same_value(42, 42.0);
is_same_value('a', 97);
```

### Questions

1. How many template parameters do you need?
2. What return type would you choose?
3. What might be problematic or surprising when comparing different types?

### Additional

Consider whether `is_same_value("hi", "hi")` behaves as expected.

***

## 4) Using Default Template Arguments

**Topic:** Default Template Arguments  
**Duration:** \~10 minutes

Write a function template `convert<TargetType>()` that converts a value into a target type.

### Target Example

```cpp
auto a = convert<int>(4.7);
auto b = convert<double>(3);
auto c = convert<>(5);   // with a meaningful default
```

### Requirements

* Use **at least one default template argument**
* Define a reasonable default for `TargetType`

### Questions

1. Which template parameter should have a default?
2. Which types are deduced automatically and which are not?
3. Why can `<>` sometimes be omitted and sometimes not?

***

## 5) Overloading + Parameter Passing

**Topic:** Overloading Function Templates, Pass by value / reference  
**Duration:** \~15 minutes

Given these three overloads:

```cpp
template<typename T>
void logValue(T x);

template<typename T>
void logValue(T& x);

template<typename T>
void logValue(const T& x);
```

### Tasks

1. Evaluate whether this overload set is reasonable
2. Identify cases where calls are ambiguous or problematic
3. Analyze these calls:

```cpp
int a = 1;
const int b = 2;

logValue(a);
logValue(b);
logValue(42);
```

### Additional Questions

* Which version would you typically prefer in practice?
* For which types is `pass by value` acceptable?
* When is `const T&` the better choice?

***

# Homework Problems (3 tasks)

**Goal:** 30–45 minutes per task  
**Format:** programming task + understanding questions

***

## Homework 1) Generic `max` Utility with Special Case for C-Strings

**Topics:** Function Templates, Overloading, Deduction  
**Duration:** \~30–45 minutes

Implement a small module (`max_utils.cpp` or `.hpp`) with multiple versions of `mymax`.

### Requirements

1. Implement a generic version:
   ```cpp
   template<typename T>
   T mymax(T a, T b);
   ```

2. Ensure these calls work:
   ```cpp
   mymax(3, 5);
   mymax(2.5, 7.1);
   mymax(std::string("aa"), std::string("zz"));
   ```

3. Add a **special overload** for C-strings (`const char*`) so that comparison is **lexicographical**, not pointer-based

4. Provide a small `main()` with test cases

### Understanding Questions

1. Why is a special handling for `const char*` necessary?
2. Which version is selected for `mymax("abc", "xyz")`?
3. What happens for `mymax(4, 4.2)` with the generic version?
4. How could you support mixed types without forcing explicit casts?

***

## Homework 2) `add()` for Mixed Types with Default Return Type

**Topics:** Multiple Template Parameters, Default Template Arguments, Deduction  
**Duration:** \~30–45 minutes

Implement a function `add()` that allows adding values of different types.

### Target Usage

```cpp
auto x = add(3, 4);
auto y = add(3, 4.5);
auto z = add<double>(3, 4);
```

### Requirements

1. Use **at least two template parameters**
2. Allow an **explicit return type**
3. Define a **reasonable default** return type
4. Write a test program with at least 6 test cases

### Guiding Questions

* Which template parameters should be deduced?
* Which may need to be specified explicitly?
* How should the function signature be designed to support both use cases?

### Understanding Questions

1. Why is `template<typename T>` not sufficient here?
2. When are default template arguments useful?
3. What differences arise between:
   * automatic return type
   * explicitly specified return type?

***

## Homework 3) `debugPrint()` – Exploring Value vs Reference

**Topics:** Pass by value/reference, Overloading, Deduction  
**Duration:** \~30–45 minutes

Design a generic debug function `debugPrint()` and carefully analyze parameter passing.

### Task

Implement these three variants:

```cpp
template<typename T>
void debugPrint(T x);

template<typename T>
void debugPrintByRef(T& x);

template<typename T>
void debugPrintConstRef(const T& x);
```

Use them with:

* `int`
* `const int`
* `std::string`
* a larger object:

```cpp
struct BigObject {
    std::string name;
    std::vector<int> data;
};
```

### Requirements

1. Create a test program calling all variants
2. Document for each call:
   * whether it compiles
   * what `T` is deduced to
   * whether unnecessary copies occur
3. Provide a short recommendation:
   * when to use `T`
   * when to use `T&`
   * when to use `const T&`

### Additional Task

Extend your analysis to:

* temporary objects
* string literals
* `const` objects

Example:

```cpp
debugPrint(42);
debugPrintConstRef(std::string("tmp"));
```

### Understanding Questions

1. Why can `T&` not accept everything?
2. Why is `const T&` often the “safe default”?
3. When is `pass by value` still the better choice?

***

# Study Tip

For this chapter, apply this checklist to **every task**:

1. **Which template parameters are involved?**
2. **Which of them are deduced automatically?**
3. **Which must be specified explicitly?**
4. **How does the parameter form affect deduction?**  
   (`T`, `T&`, `const T&`, `T*`)
5. **Are there mixed types, ambiguities, or implicit conversions?**
