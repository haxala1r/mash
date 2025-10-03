#include <concepts>
#include <value.hpp>


template <typename T>
requires std::convertible_to<T, LispValue>
void value_printer(T t) {
    if constexpr (std::same_as<T, LispValue>) {
        print_val(t);
    } else if constexpr (requires { std::cout << t.value;}) {
        std::cout << t.value;
    } else {
        std::cout << "{UNKNOWN}" << std::endl;
    }
}

template <>
void value_printer(List l) {
    std::cout << "(";
    for (auto i : l.list) {
        value_printer(i);
        std::cout << " ";
    }
    std::cout << ")";
}

template <>
void value_printer(String s) {
    std::cout << '"' << s.value << '"';
}

void print_val(LispValue v) {
    std::visit([](auto arg) {value_printer(arg);}, v);
}

