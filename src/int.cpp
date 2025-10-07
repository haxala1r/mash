#include <cmath>
#include <cstdlib>
#include <gmp.h>
#include <int.hpp>
#include <string>
#include <utility>

Int::Int() { mpz_init(this->inner); };
Int::Int(const Int &big) { mpz_init_set(this->inner, big.inner); };
Int::Int(unsigned long ul) { mpz_init_set_ui(this->inner, ul); };
Int::Int(long l) { mpz_init_set_si(this->inner, l); };
Int::Int(double d) { mpz_init_set_d(this->inner, d); };
Int::Int(const std::string &str, base b) {
  int result = mpz_init_set_str(this->inner, str.data(), static_cast<int>(b));
  if (result == 1)
    throw std::exception();
};

base print_base_to_base(print_base p_base) {
  switch (p_base) {
  case print_base::lc_2:
  case print_base::uc_2:
    return base::base_2;
  case print_base::lc_3:
  case print_base::uc_3:
    return base::base_3;
  case print_base::lc_4:
  case print_base::uc_4:
    return base::base_4;
  case print_base::lc_5:
  case print_base::uc_5:
    return base::base_5;
  case print_base::lc_6:
  case print_base::uc_6:
    return base::base_6;
  case print_base::lc_7:
  case print_base::uc_7:
    return base::base_7;
  case print_base::lc_8:
  case print_base::uc_8:
    return base::base_8;
  case print_base::lc_9:
  case print_base::uc_9:
    return base::base_9;
  case print_base::lc_10:
  case print_base::uc_10:
    return base::ci_10;
  case print_base::lc_11:
  case print_base::uc_11:
    return base::ci_11;
  case print_base::lc_12:
  case print_base::uc_12:
    return base::ci_12;
  case print_base::lc_13:
  case print_base::uc_13:
    return base::ci_13;
  case print_base::lc_14:
  case print_base::uc_14:
    return base::ci_14;
  case print_base::lc_15:
  case print_base::uc_15:
    return base::ci_15;
  case print_base::lc_16:
  case print_base::uc_16:
    return base::ci_16;
  case print_base::lc_17:
  case print_base::uc_17:
    return base::ci_17;
  case print_base::lc_18:
  case print_base::uc_18:
    return base::ci_18;
  case print_base::lc_19:
  case print_base::uc_19:
    return base::ci_19;
  case print_base::lc_20:
  case print_base::uc_20:
    return base::ci_20;
  case print_base::lc_21:
  case print_base::uc_21:
    return base::ci_21;
  case print_base::lc_22:
  case print_base::uc_22:
    return base::ci_22;
  case print_base::lc_23:
  case print_base::uc_23:
    return base::ci_23;
  case print_base::lc_24:
  case print_base::uc_24:
    return base::ci_24;
  case print_base::lc_25:
  case print_base::uc_25:
    return base::ci_25;
  case print_base::lc_26:
  case print_base::uc_26:
    return base::ci_26;
  case print_base::lc_27:
  case print_base::uc_27:
    return base::ci_27;
  case print_base::lc_28:
  case print_base::uc_28:
    return base::ci_28;
  case print_base::lc_29:
  case print_base::uc_29:
    return base::ci_29;
  case print_base::lc_30:
  case print_base::uc_30:
    return base::ci_30;
  case print_base::lc_31:
  case print_base::uc_31:
    return base::ci_31;
  case print_base::lc_32:
  case print_base::uc_32:
    return base::ci_32;
  case print_base::lc_33:
  case print_base::uc_33:
    return base::ci_33;
  case print_base::lc_34:
  case print_base::uc_34:
    return base::ci_34;
  case print_base::lc_35:
  case print_base::uc_35:
    return base::ci_35;
  case print_base::lc_36:
  case print_base::uc_36:
    return base::ci_36;
  case print_base::base_37:
    return base::cs_37;
  case print_base::base_38:
    return base::cs_38;
  case print_base::base_39:
    return base::cs_39;
  case print_base::base_40:
    return base::cs_40;
  case print_base::base_41:
    return base::cs_41;
  case print_base::base_42:
    return base::cs_42;
  case print_base::base_43:
    return base::cs_43;
  case print_base::base_44:
    return base::cs_44;
  case print_base::base_45:
    return base::cs_45;
  case print_base::base_46:
    return base::cs_46;
  case print_base::base_47:
    return base::cs_47;
  case print_base::base_48:
    return base::cs_48;
  case print_base::base_49:
    return base::cs_49;
  case print_base::base_50:
    return base::cs_50;
  case print_base::base_51:
    return base::cs_51;
  case print_base::base_52:
    return base::cs_52;
  case print_base::base_53:
    return base::cs_53;
  case print_base::base_54:
    return base::cs_54;
  case print_base::base_55:
    return base::cs_55;
  case print_base::base_56:
    return base::cs_56;
  case print_base::base_57:
    return base::cs_57;
  case print_base::base_58:
    return base::cs_58;
  case print_base::base_59:
    return base::cs_59;
  case print_base::base_60:
    return base::cs_60;
  case print_base::base_61:
    return base::cs_61;
  case print_base::base_62:
    return base::cs_62;
  }

  std::unreachable();
}

unsigned long Int::to_ul() { return mpz_get_ui(this->inner); };
long Int::to_l() { return mpz_get_si(this->inner); };
double Int::to_d() { return mpz_get_d(this->inner); };
std::string Int::to_string(print_base base) {
  int print_base_int = static_cast<int>(base);

  char *str = mpz_get_str(NULL, print_base_int, this->inner);

  std::string res(str);

  free(str);

  return res;
};

void Int::swap(Int &rhs) { mpz_swap(this->inner, rhs.inner); }

void Int::operator+(const Int &rhs) {
  mpz_add(this->inner, this->inner, rhs.inner);
};

void Int::operator+(unsigned long rhs) {
  mpz_add_ui(this->inner, this->inner, rhs);
};

void Int::operator+(long rhs) {
  if (rhs < 0)
    mpz_sub_ui(this->inner, this->inner, std::abs(rhs));
  else
    mpz_add_ui(this->inner, this->inner, rhs);
};

void Int::operator-(const Int &rhs) {
  mpz_sub(this->inner, this->inner, rhs.inner);
};

void Int::operator-(unsigned long rhs) {
  mpz_sub_ui(this->inner, this->inner, rhs);
};

void Int::operator-(long rhs) {
  if (rhs < 0)
    mpz_add_ui(this->inner, this->inner, std::abs(rhs));
  else
    mpz_sub_ui(this->inner, this->inner, rhs);
};

void Int::operator*(const Int &rhs) {
  mpz_mul(this->inner, this->inner, rhs.inner);
};

void Int::operator*(unsigned long rhs) {
  mpz_mul_ui(this->inner, this->inner, rhs);
};

void Int::operator*(long rhs) {
  if (rhs < 0) {
    mpz_mul_ui(this->inner, this->inner, std::abs(rhs));
    this->operator~();
  } else
    mpz_mul_ui(this->inner, this->inner, rhs);
};

void Int::operator/(const Int &rhs) {
  mpz_tdiv_q(this->inner, this->inner, rhs.inner);
};

void Int::operator/(unsigned long rhs) {
  mpz_tdiv_q_ui(this->inner, this->inner, rhs);
};

void Int::operator/(long rhs) {
  if (rhs < 0) {
    mpz_tdiv_q_ui(this->inner, this->inner, std::abs(rhs));
    this->operator~();
  } else
    mpz_tdiv_q_ui(this->inner, this->inner, rhs);
};

void Int::operator%(const Int &rhs) {
  mpz_mod(this->inner, this->inner, rhs.inner);
};

void Int::operator%(unsigned long rhs) {
  mpz_mod_ui(this->inner, this->inner, rhs);
};

void add_mul(Int &);
void add_mul(unsigned long);
void add_mul(long);

void sub_mul(Int &);
void sub_mul(unsigned long);
void sub_mul(long);

void mul_2exp(unsigned long);

void Int::operator~() { mpz_neg(this->inner, this->inner); };

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
