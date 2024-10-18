#include <fmt/chrono.h>
#include <fmt/format.h>

static int foo;

void doSomething(int value) {
    value += 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomething2(int* ref) {
    *ref += 1;
    fmt::print("doSomething, value {}\n", *ref);
}

int* doSomething3() {
    int value = 4711;
    fmt::print("doSomething, value {}\n", value);
    return &value;
}

void doSomething4() {
    static int value = 56;
    value += 1;
    fmt::print("doSomething, value {}\n", value);
}


auto main(int argc, char **argv) -> int
{
  
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));

    doSomething(42);
    int bar = 42;
    doSomething(bar);
    fmt::print("The value of bar is: {}\n", bar);
    doSomething2(&bar);
    fmt::print("The value of bar is: {}\n", bar);

    int* returnedPtr = doSomething3();
    fmt::print("Pointer: {}\n", *returnedPtr);
    doSomething(bar);
    fmt::print("Pointer: {}\n", *returnedPtr);

    for (int i = 0; i < 5; i++)
    {
        doSomething4();
    }
    
    fmt::println("Value of foo: {}, adress of foo: {}", foo, fmt::ptr(&foo));
    int var;
    fmt::println("Value of var: {}, adress of var: {}", var, fmt::ptr(&var));

    return 0; /* exit gracefully*/
}
