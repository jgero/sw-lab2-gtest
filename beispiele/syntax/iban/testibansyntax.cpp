#include <gtest/gtest.h>
#include "istIBANsyntaxgueltig.h"

TEST(IBAN_Syntax, TF1) {
  EXPECT_TRUE(istIBANsyntaxGueltig("DE10123456780123456789"));
}

TEST(IBAN_Syntax, TF2_Leerzeichen) {
  EXPECT_TRUE(istIBANsyntaxGueltig("DE10 12345678  0123456789"));
}

TEST(IBAN_Syntax, TF3_Schweizer_IBAN) {  
  EXPECT_FALSE(istIBANsyntaxGueltig("CH10 002300A1 02350 2601"));
}

TEST(IBAN_Syntax, TF4_Ziffer_zu_viel) {
  EXPECT_FALSE(istIBANsyntaxGueltig("DE10 192345678  0123456789"));
}

TEST(IBAN_Syntax, TF5_Ziffer_zu_wenig) {
  EXPECT_FALSE(istIBANsyntaxGueltig("DE10 12345678  01256789"));
}

TEST(IBAN_Syntax, TF6_enthaelt_Buchstabe) {
  EXPECT_FALSE(istIBANsyntaxGueltig("DE10 192345678  01A3456789"));
}
