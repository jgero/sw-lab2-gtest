#include <gtest/gtest.h>
#include "istIBANgueltig.h"

TEST(istIBANgueltig, TF1_korrekteSchweizerIBAN) {
  EXPECT_TRUE(istIBANgueltig("CH10 002300A1 02350 2601"));
}
TEST(istIBANgueltig, TF1_korrekteDeutscheIBAN) {
  EXPECT_TRUE(istIBANgueltig("DE68700202700667302269"));
}
TEST(istIBANgueltig, TF2_korrekteSyntax_aber_falscheIBAN) {
  EXPECT_FALSE(istIBANgueltig("DE10123456780123456789"));
}
