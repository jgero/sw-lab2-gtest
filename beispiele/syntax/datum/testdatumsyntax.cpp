#include <gtest/gtest.h>
#include "istDatumSyntaxGueltig.h"

TEST(Datumsyntax, TF1_korrekterWert) {
  EXPECT_TRUE(istDatumSyntaxGueltig("11.11.2016"));
}

TEST(Datumsyntax, TF2_SyntaxOK_falscherWert) {
  EXPECT_TRUE(istDatumSyntaxGueltig("30.2.2017"));
}

TEST(Datumsyntax, TF3) {
  EXPECT_TRUE(istDatumSyntaxGueltig("0.0.1111"));
}

TEST(Datumsyntax, TF4) {
  EXPECT_TRUE(istDatumSyntaxGueltig("99.99.9999"));
}

TEST(Datumsyntax, TF5) {
  EXPECT_TRUE(istDatumSyntaxGueltig("00.88.0000"));
}

TEST(Datumsyntax, TF6_Buchstabe) {
  EXPECT_FALSE(istDatumSyntaxGueltig("x0.2.2016"));
}

TEST(Datumsyntax, TF7_Jahr_zu_kurz) {  
  EXPECT_FALSE(istDatumSyntaxGueltig("1.1.123"));
}

TEST(Datumsyntax, TF7_Jahr_zu_lang) {  
  EXPECT_FALSE(istDatumSyntaxGueltig("1.1.12345"));
}

TEST(Datumsyntax, TF8_Tag_fehlt) {  
  EXPECT_FALSE(istDatumSyntaxGueltig(".12.2001"));
}

TEST(Datumsyntax, TF9_Monat_fehlt) {  
  EXPECT_FALSE(istDatumSyntaxGueltig("1..2001"));
}

TEST(Datumsyntax, TF10_Komma_statt_Punkt) {  
  EXPECT_FALSE(istDatumSyntaxGueltig("23,12,1995"));
}
