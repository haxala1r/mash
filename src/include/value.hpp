#pragma once

#include <concepts>
#include <deque>
#include <cstdint>
#include <string>
#include <variant>
#include <iostream>

// we're using a pure variant as our value type.
struct Integer {int64_t value;};
struct Double {double value;};
struct String {std::string value;}; // might be a good idea to intern strings
struct Symbol {std::string value;};
struct List;
struct Nil {};


using LispValue = std::variant<Integer, Double, String, Symbol, List>;
struct List {std::deque<LispValue> list;};
// during compilation, we don't really care for cyclical lists etc.
// during compilation we'll mostly be dealing with regular, flat lists
// that form function calls.
// We will have a different set of values during runtime
// as the runtime will be a bytecode interpreter anyhow.



void print_val(LispValue);

String make_string(std::string);
Symbol make_symbol(std::string);

