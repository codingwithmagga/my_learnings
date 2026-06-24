#include <iostream>

template <typename T>
class Storage;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Storage<T> &v);

template <typename T>
class Storage
{
public:
    Storage(T val) : val_(val)
    {
    }

    void print() const
    {
        std::cout << val_ << "\n";
    }

    friend std::ostream &operator<< <>(std::ostream &os, const Storage &v);

private:
    T val_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Storage<T> &v)
{
    return os << v.val_;
}

template <typename T>
class Storage<T *>;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Storage<T *> &v);

template <typename T>
class Storage<T *>
{
public:
    Storage(T *val) : val_(val)
    {
    }

    void print() const
    {
        std::cout << *val_ << "\n";
    }

    friend std::ostream &operator<< <>(std::ostream &os, const Storage &v);

private:
    T *val_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Storage<T *> &v)
{
    return os << *v.val_;
}

template <>
class Storage<char *>;

std::ostream &operator<<(std::ostream &os, const Storage<char *> &v);

template <>
class Storage<char *>
{
public:
    Storage(char *val) : val_(val)
    {
    }

    void print() const
    {
        std::cout << val_ << "\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Storage &v);

private:
    char *val_;
};

std::ostream &operator<<(std::ostream &os, const Storage<char *> &v)
{
    return os << v.val_;
}

template <>
class Storage<const char *>;

std::ostream &operator<<(std::ostream &os, const Storage<const char *> &v);

template <>
class Storage<const char *>
{
public:
    Storage(const char *val) : val_(val)
    {
    }

    void print() const
    {
        std::cout << val_ << "\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Storage &v);

private:
    const char *val_;
};

std::ostream &operator<<(std::ostream &os, const Storage<const char *> &v)
{
    return os << v.val_;
}

int main()
{
    int i = 5;

    Storage<int> intStor(5);
    Storage<double> doubleStor(5.0);
    Storage<const char *> ccStor("5.0");
    Storage<int *> cintStor(&i);

    intStor.print();
    doubleStor.print();
    ccStor.print();
    cintStor.print();

    std::cout << "Values: " << intStor << " " << doubleStor << " " << ccStor << " " << cintStor << "\n";
}

/*
    Questions:

    1. Why is special handling for `const char*` often useful?
        const char* represents a C-style string. In most situations we want to print the complete string contents rather than
        treating it like a generic pointer. A generic pointer specialization would typically dereference the pointer and only print a single character.

    2. What problems can occur with `Storage<T*>`?
        When dereferencing for T=int you get the int. But in case of const char* you just get the first char not the entire char array.
        Also danlging pointers, nullptr dereference, unclear ownership.

    3. When is the full specialization used, and when is the partial specialization used?
        Full specialization is used when the type fits perfectly. Partial specialization when there is no full specialization like for int*.

    4. What challenges arise with `friend operator<<` in template classes?
        Friend operators in template classes can be tricky because the compiler must know whether the friend refers to an existing function template or declares a new non-template function.
        Without proper forward declarations and the <> syntax, it is easy to accidentally create separate overloaded functions instead of befriending the intended function template.
*/