## Mash

### Base design:

#### Paradigm: 

Dynamically typed, functional-first.

#### Syntax: 

A clean subset of Lisp. It's the simplest to parse and will get us to a working state fastest.

- Atoms: 123, 4.56, "hello", my-var, true
- Lists: (func arg1 arg2)
- Almost everything else is syntax sugar that can be added as macros in the standard library. That is also probably easier to implement, and more modular.

#### Data Types: 

Integer, Float, String, Boolean, List, Symbol, Function. That's it.

#### Memory: 

Garbage Collected. Let's forget custom allocators for now, and just use Boehm or
something.

#### Standard Library: 

Basic math ops (+, -, *, /), comparison (=, <, >), cons, car, cdr, list, some form of arrays, and I/O functions. Keep it small, at least for the beginning.

## Basic operations

### Defining functions and variables

Let's just copy Scheme here, it has a very simple special form:

```
(define x 5)
(define (addTwo x y) (+ x y))
```

This simple syntax is fairly readable and math-like.

It's a dynamic language, no type inference or funny business,
no PhDs required.

Every form ("expression") evaluates to something. Variable definitions
evaluate to the value assigned to the variable, or nil if it's
an empty definition. 

Function definitions evaluate to the value of their function.

Nil is the empty list, (). Common Lisp treats
it as the canonical falsy value, scheme has #t and #f, and treats
nil as truthy. We can go with either choice but I lean towards
Common Lisp here.

### Macros

We use CL-style macros, a macro is a function that receives its parameters
unevaluated and runs completely at compile time, producing lisp code that
will be compiled. Of course, it will produce a list.

I.e. using a macro `(foo (1 2 3) arg2)` is equivalent to doing
`(eval (bar '(1 2 3) 'arg2))` assuming the function bar does the
same transformations that foo would have done, except that the
macro foo is evaluated at compile time.

## Special syntax

Let's NOT add too much syntax to the core.

The idea is, if we make a small core that has access to lisp macros,
we can effectively add *any* syntax sugar we want by simply defining
it as part of the standard library.

That's usually what Common Lisp does actually, most language constructs
are actually functions or macros defined in the standard library.

The greatest power of a Lisp is its ability to extend syntax.
Adding too much syntax too early defeats the purpose.
Let's keep it small.


#### Dollar sign

```
(define x $(1/3 + 2^60))
(define y (map (lambda (n) $(n * n)) (range 0 10)))
```

This can be implemented later as a reader macro,
e.g. $(1/3 + 2^60) expands to (math-syntax (1/3 + 2^60))
math-syntax is a macro that expands this further to
(+ (/ 1 3) (^ 2 60)).

So at the start, we don't need much syntax at all.

#### SQL sub-language

This can trivially be done as a library of functions,
and macros can add whatever syntax sugar is desired.

## Evaluation strategy

In order for macros to be possible, the compiler must be able to execute
code during compilation time. This is fine, we can simply keep a running
"image" of all lisp forms compiled so far, and run code there.

We need a byte code VM for this. Lua bytecode is perfectly acceptable.
