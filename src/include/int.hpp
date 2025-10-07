#include <gmp.h>
#include <gmpxx.h>
#include <string>

/**
 * @brief Options for `base` parameter used in GMP's `mpz_set_str` and
 * `mpz_sizeinbase`.
 * @see https://gmplib.org/manual/Assigning-Integers
 *
 * `base_N`: no characters, no case sensitivity.
 * `ci_N`: case-insensitive (`A`=`10`, `a`=`10`)
 * `cs_N`: case-sensitive (`A`=`10`, `a`=`36`)
 */
enum class base {
  base_2 = 2,
  base_3 = 3,
  base_4 = 4,
  base_5 = 5,
  base_6 = 6,
  base_7 = 7,
  base_8 = 8,
  base_9 = 9,
  ci_10 = 10,
  ci_11 = 11,
  ci_12 = 12,
  ci_13 = 13,
  ci_14 = 14,
  ci_15 = 15,
  ci_16 = 16,
  ci_17 = 17,
  ci_18 = 18,
  ci_19 = 19,
  ci_20 = 20,
  ci_21 = 21,
  ci_22 = 22,
  ci_23 = 23,
  ci_24 = 24,
  ci_25 = 25,
  ci_26 = 26,
  ci_27 = 27,
  ci_28 = 28,
  ci_29 = 29,
  ci_30 = 30,
  ci_31 = 31,
  ci_32 = 32,
  ci_33 = 33,
  ci_34 = 34,
  ci_35 = 35,
  ci_36 = 36,
  cs_37 = 37,
  cs_38 = 38,
  cs_39 = 39,
  cs_40 = 40,
  cs_41 = 41,
  cs_42 = 42,
  cs_43 = 43,
  cs_44 = 44,
  cs_45 = 45,
  cs_46 = 46,
  cs_47 = 47,
  cs_48 = 48,
  cs_49 = 49,
  cs_50 = 50,
  cs_51 = 51,
  cs_52 = 52,
  cs_53 = 53,
  cs_54 = 54,
  cs_55 = 55,
  cs_56 = 56,
  cs_57 = 57,
  cs_58 = 58,
  cs_59 = 59,
  cs_60 = 60,
  cs_61 = 61,
  cs_62 = 62,
  binary = base_2,
  octal = base_8,
  decimal = ci_10,
  hexadecimal = ci_16,
};

/**
 * @brief Options for `base` parameter used in GMP's `mpz_get_str`.
 * @see https://gmplib.org/manual/Converting-Integers
 *
 * `base_N`: case sensitive. It doesn't have its upper and lower case versions.
 *
 * `lc_N`: lower-case, base N. All letters are lower case.
 *
 * `uc_N`: upper-case, base N. All letters are upper case.
 */
enum class print_base {
  lc_2 = 2,
  lc_3 = 3,
  lc_4 = 4,
  lc_5 = 5,
  lc_6 = 6,
  lc_7 = 7,
  lc_8 = 8,
  lc_9 = 9,
  lc_10 = 10,
  lc_11 = 11,
  lc_12 = 12,
  lc_13 = 13,
  lc_14 = 14,
  lc_15 = 15,
  lc_16 = 16,
  lc_17 = 17,
  lc_18 = 18,
  lc_19 = 19,
  lc_20 = 20,
  lc_21 = 21,
  lc_22 = 22,
  lc_23 = 23,
  lc_24 = 24,
  lc_25 = 25,
  lc_26 = 26,
  lc_27 = 27,
  lc_28 = 28,
  lc_29 = 29,
  lc_30 = 30,
  lc_31 = 31,
  lc_32 = 32,
  lc_33 = 33,
  lc_34 = 34,
  lc_35 = 35,
  lc_36 = 36,
  uc_2 = -2,
  uc_3 = -3,
  uc_4 = -4,
  uc_5 = -5,
  uc_6 = -6,
  uc_7 = -7,
  uc_8 = -8,
  uc_9 = -9,
  uc_10 = -10,
  uc_11 = -11,
  uc_12 = -12,
  uc_13 = -13,
  uc_14 = -14,
  uc_15 = -15,
  uc_16 = -16,
  uc_17 = -17,
  uc_18 = -18,
  uc_19 = -19,
  uc_20 = -20,
  uc_21 = -21,
  uc_22 = -22,
  uc_23 = -23,
  uc_24 = -24,
  uc_25 = -25,
  uc_26 = -26,
  uc_27 = -27,
  uc_28 = -28,
  uc_29 = -29,
  uc_30 = -30,
  uc_31 = -31,
  uc_32 = -32,
  uc_33 = -33,
  uc_34 = -34,
  uc_35 = -35,
  uc_36 = -36,
  base_37 = 37,
  base_38 = 38,
  base_39 = 39,
  base_40 = 40,
  base_41 = 41,
  base_42 = 42,
  base_43 = 43,
  base_44 = 44,
  base_45 = 45,
  base_46 = 46,
  base_47 = 47,
  base_48 = 48,
  base_49 = 49,
  base_50 = 50,
  base_51 = 51,
  base_52 = 52,
  base_53 = 53,
  base_54 = 54,
  base_55 = 55,
  base_56 = 56,
  base_57 = 57,
  base_58 = 58,
  base_59 = 59,
  base_60 = 60,
  base_61 = 61,
  base_62 = 62,
  octal_lower_case = lc_8,
  hex_lower_case = lc_16,
  decimal = lc_10,
  binary = lc_2,
  octal_upper_case = uc_8,
  hex_upper_case = uc_16,
};

base print_base_to_base(print_base);

/**
 * @brief  is an high-performance, arbitrary precision Integer class for mash
 */
class Int {
private:
  mpz_t inner;

public:
  Int();
  Int(const Int &);
  Int(unsigned long);
  Int(long);
  Int(double);
  Int(const std::string &, base);

  unsigned long to_ul();
  long to_l();
  double to_d();
  std::string to_string(print_base);

  void swap(Int &);
  void operator+(const Int &);
  void operator+(unsigned long);
  void operator+(long);

  void operator-(const Int &);
  void operator-(unsigned long);
  void operator-(long);

  void operator*(const Int &);
  void operator*(unsigned long);
  void operator*(long);

  void operator/(const Int &);
  void operator/(unsigned long);
  void operator/(long);

  void operator%(const Int &);
  void operator%(unsigned long);

  void add_mul(Int &);
  void add_mul(unsigned long);
  void add_mul(long);

  void sub_mul(Int &);
  void sub_mul(unsigned long);
  void sub_mul(long);

  void mul_2exp(unsigned long);

  void operator~();

  void abs();

  void ceil_div_quotient(Int &);
  void ceil_div_remainder(Int &);
  void ceil_div_both(Int &);
  void ceil_div(unsigned long);
  void ceil_div_both(unsigned long);
  void ceil_div_quotient(unsigned long);
  void ceil_div_remainder(unsigned long);
  void ceil_div(long);
  void ceil_div_both(long);
  void ceil_div_quotient(long);
  void ceil_div_remainder(long);
  void ceil_div_quotient_2exp(unsigned long);
  void ceil_div_remainder_2exp(unsigned long);

  void floor_div_quotient(Int &);
  void floor_div_remainder(Int &);
  void floor_div_both(Int &);
  void floor_div(unsigned long);
  void floor_div_both(unsigned long);
  void floor_div_quotient(unsigned long);
  void floor_div_remainder(unsigned long);
  void floor_div(long);
  void floor_div_both(long);
  void floor_div_quotient(long);
  void floor_div_remainder(long);
  void floor_div_quotient_2exp(unsigned long);
  void floor_div_remainder_2exp(unsigned long);

  void truncate_div_quotient(Int &);
  void truncate_div_remainder(Int &);
  void truncate_div_both(Int &);
  void truncate_div(unsigned long);
  void truncate_div_both(unsigned long);
  void truncate_div_quotient(unsigned long);
  void truncate_div_remainder(unsigned long);
  void truncate_div(long);
  void truncate_div_both(long);
  void truncate_div_quotient(long);
  void truncate_div_remainder(long);
  void truncate_div_quotient_2exp(unsigned long);
  void truncate_div_remainder_2exp(unsigned long);

  void mod(Int &);
  void mod(unsigned long);
  void mod(long);

  void div_exact(Int &);
  void div_exact(unsigned long);
  void div_exact(long);

  int divisible(Int &);
  int divisible(unsigned long);
  int divisible(long);
  int divisible_2exp(unsigned long);

  int congruent(Int &);
  int congruent(unsigned long);
  int congruent(long);
  int congruent_2exp(unsigned long);

  void mod_pow(Int &);
  void mod_pow(unsigned long);
  void mod_pow(long);

  void powm_sec(Int &);

  void pow(Int &);
  void pow(unsigned long, unsigned long);
  void pow(long, unsigned long);

  ~Int() { mpz_clear(inner); };
};

/*
///
/// Enum for the number's sign.
///
/// `Zero` is for when number is zero.
///
pub const Sign = enum(i8) {
    Negative = -1,
    Positive = 1,
    Zero = 0,

    pub fn toChar(self: @This()) u8 {
        return switch (self) {
            .Negative => '-',
            .Positive => '+',
            .Zero => '0',
        };
    }

    pub fn toString(self: @This()) []const u8 {
        return switch (self) {
            .Negative => "negative",
            .Positive => "positive",
            .Zero => "zero",
        };
    }
};

///
/// Enum for the comparison of two numbers.
///
pub const Ordering = enum(i8) {
    Less = -1,
    Greater = 1,
    Equals = 0,

    const Self = @This();

    pub fn toChar(self: Self) u8 {
        return switch (self) {
            .Less => '<',
            .Greater => '>',
            .Equals => '=',
        };
    }

    pub fn toString(self: Self) []const u8 {
        return switch (self) {
            .Less => "less",
            .Greater => "greater",
            .Equals => "equals",
        };
    }

    pub fn fromC(num: c_int) Self {
        if (num < 0) return .Less;
        if (num > 0) return .Greater;
        return .Equals;
    }
};

/// Enum for the number's parity.
pub const Parity = enum(i8) {
    Even = 0,
    Odd = 1,

    pub fn toString(self: @This()) []const u8 {
        return switch (self) {
            .Even => "even",
            .Odd => "odd",
        };
    }
};

////
/// Rounding methods for division.
///
/// `Truncate` rounds the integer towards 0.
/// `Ceil` rounds the integer towards positive infinity.
/// `Floor` rounds the integer towrds positiv infinity.
///
/// |`Number`|`Truncate`|`Ceil`|`Floor`|
/// |--------|----------|------|-------|
/// |`4.5`   |`4`       |`5`   |`4`    |
/// |`-4.5`  |`-4`      |`-4`  |`-5`   |
///
pub const RoundingMethod = enum(i8) {
    Truncate = 0,
    Ceil = 1,
    Floor = -1,
};

///
/// Option for which result will be written to the integer.
///
pub const Output = enum(i8) {
    Quotient = 0,
    Remainder = 1,
};
*/