# ft_printf — Minimal `printf` Reimplementation in C

## Overview

`ft_printf` is a compact reimplementation of the standard C `printf` function, developed as part of the **42 Bangkok** curriculum.
The project focuses on **low-level correctness**, **explicit type handling**, and **predictable behavior** rather than feature completeness.

The implementation demonstrates careful use of variadic arguments, integer representation awareness, and controlled stack usage, while avoiding unnecessary abstractions or dynamic allocation.

---

## Project Structure

```text
.
├── ft_printf.c
├── ft_printf_utils.c
├── ft_printf.h
├── Makefile
└── objs/
```

* `ft_printf.c`
  Core formatting logic, format parsing, and output byte counting.

* `ft_printf_utils.c`
  Numeric, hexadecimal, and pointer conversion routines.

* `ft_printf.h`
  Public interface and function prototypes.

* `objs/`
  Contains object files generated during compilation, separated from source files for build hygiene.

---

## Implemented Features

Supported format specifiers:

* `%c` — character
* `%s` — string (with explicit null handling)
* `%p` — pointer address
* `%d`, `%i` — signed decimal integer
* `%u` — unsigned decimal integer
* `%x` — hexadecimal (lowercase)
* `%X` — hexadecimal (uppercase)
* `%%` — literal percent character

All output is written directly using `write(2)`.

---

## Design Decisions

### Explicit Variadic Type Handling

Each format specifier maps to a **precise `va_arg` type**, respecting default argument promotions and avoiding undefined behavior:

* `%c` → `int`
* `%d`, `%i` → `int`
* `%u` → `unsigned int`
* `%x`, `%X` → `unsigned int`
* `%p` → `void *`, cast to `unsigned long long`

This ensures correct signedness and prevents accidental sign extension or misinterpretation of values.

---

### Fixed-Size Stack Buffers for Number Conversion

Numeric conversions use **fixed-size local arrays**:

* Decimal conversion: `int arr[10]`
* Hexadecimal conversion: `int arr[8]`
* Pointer conversion: `int arr[16]`

Characteristics:

* Stack-only allocation
* No heap usage
* Bounded and predictable memory usage
* Digits are generated via modulo/division and emitted in reverse order

This design avoids recursion, dynamic memory, and intermediate string buffers.

---

### Integer and Unsigned Conversion Strategy

#### Decimal Conversion (`pf_putnbr`)

```c
void pf_putnbr(long long num);
```

* Accepts `long long` to safely handle promoted signed values
* Negative values are handled explicitly:

  * Sign emitted first
  * Absolute value converted afterward
* Digits are extracted using modulo/division and stored in a **fixed-size local array**

```c
int arr[10];
```

* Stack-allocated, bounded, no heap usage
* Reverse-digit storage ensures correct output order without recursion

---

#### Unsigned Decimal (`%u`)

* `%u` is extracted as `unsigned int`
* Passed through the same numeric pipeline without sign handling
* Prevents negative reinterpretation or sign-extension bugs

This separation ensures semantic correctness between signed and unsigned formatting.

---

#### Hexadecimal Conversion (`%x`, `%X`)

```c
void pf_puthex(unsigned int num, int flag);
```

* Operates strictly on `unsigned int`
* Uses a **fixed-size integer buffer**:

```c
int arr[8];
```

* Size chosen to match 32-bit unsigned integer hex width
* No dynamic memory or string manipulation
* Uppercase vs lowercase is selected via explicit lookup tables

This avoids:

* Accidental signed conversion
* Width ambiguity
* Platform-dependent behavior

---

### Pointer Width Correctness

Pointer values:

* Are emitted with a fixed `"0x"` prefix

* Are explicitly checked for null and printed as `(nil)`

```c
void pf_putpointer(void *ptr);
```

* Are cast to `unsigned long long` before conversion

```c
unsigned long long
```

* Supports full pointer-width representation without truncation

```c
int arr[16];
```


This ensures correct representation across architectures

---

## Usage

The project is compiled as a static library using the provided `Makefile`.

```bash
make			#generate libftprintf.a

make fclean		#remove all files

make clean		#remove .o files

make re			#recompilation
```

### Example

```c
ft_printf("Char: %c\n", 'A');			//Char: A
ft_printf("String: %s\n", NULL);		//String: (null)
ft_printf("Pointer: %p\n", NULL);		//Pointer: (nil)
ft_printf("Signed: %d\n", -42);			//Signed: -42
ft_printf("Unsigned: %u\n", -42);		//Unsigned: 4294967254
ft_printf("Hex: %x %X\n", 255, 255);	//Hex: ff FF
```

## Key Technical Skills

* Variadic function handling (`stdarg.h`)
* Integer signedness and promotion rules
* Manual base conversion (decimal / hexadecimal)
* Pointer representation and width awareness
* Stack memory discipline with fixed-size buffers
* ELF symbol visibility and storage duration understanding
* Clean separation of source code and build artifacts

---