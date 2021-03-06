// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/traits_bag.h"

#include "testing/gmock/include/gmock/gmock.h"

namespace base {
namespace trait_helpers {
namespace {

struct ExampleTrait {};

enum class EnumTraitA { A, B, C };

enum class EnumTraitB { ONE, TWO };

struct TestTraits {
  // List of traits that are valid inputs for the constructor below.
  struct ValidTrait {
    ValidTrait(ExampleTrait);
    ValidTrait(EnumTraitA);
    ValidTrait(EnumTraitB);
  };

  template <class... ArgTypes,
            class CheckArgumentsAreValid = std::enable_if_t<
                trait_helpers::AreValidTraits<ValidTrait, ArgTypes...>::value>>
  constexpr TestTraits(ArgTypes... args)
      : has_example_trait(trait_helpers::HasTrait<ExampleTrait>(args...)),
        enum_trait_a(
            trait_helpers::GetEnum<EnumTraitA, EnumTraitA::A>(args...)),
        enum_trait_b(
            trait_helpers::GetEnum<EnumTraitB, EnumTraitB::ONE>(args...)) {}

  const bool has_example_trait;
  const EnumTraitA enum_trait_a;
  const EnumTraitB enum_trait_b;
};

struct RequiredEnumTestTraits {
  // List of traits that are required inputs for the constructor below.
  struct ValidTrait {
    ValidTrait(EnumTraitA);
  };

  // We require EnumTraitA to be specified.
  template <class... ArgTypes,
            class CheckArgumentsAreValid = std::enable_if_t<
                trait_helpers::AreValidTraits<ValidTrait, ArgTypes...>::value>>
  constexpr RequiredEnumTestTraits(ArgTypes... args)
      : enum_trait_a(trait_helpers::GetEnum<EnumTraitA>(args...)) {}

  const EnumTraitA enum_trait_a;
};

}  // namespace

TEST(TraitsBagTest, DefaultConstructor) {
  constexpr TestTraits trait_test_class;

  EXPECT_FALSE(trait_test_class.has_example_trait);
}

TEST(TraitsBagTest, HasTrait) {
  constexpr TestTraits with_trait(ExampleTrait{});
  constexpr TestTraits without_trait;

  EXPECT_TRUE(with_trait.has_example_trait);
  EXPECT_FALSE(without_trait.has_example_trait);
}

TEST(TraitsBagTest, GetEnumWithDefault) {
  constexpr TestTraits defaults;

  EXPECT_EQ(defaults.enum_trait_a, EnumTraitA::A);
  EXPECT_EQ(defaults.enum_trait_b, EnumTraitB::ONE);

  constexpr TestTraits a(EnumTraitA::A);
  constexpr TestTraits b(EnumTraitA::B);
  constexpr TestTraits c(EnumTraitA::C);

  EXPECT_EQ(a.enum_trait_a, EnumTraitA::A);
  EXPECT_EQ(a.enum_trait_b, EnumTraitB::ONE);

  EXPECT_EQ(b.enum_trait_a, EnumTraitA::B);
  EXPECT_EQ(b.enum_trait_b, EnumTraitB::ONE);

  EXPECT_EQ(c.enum_trait_a, EnumTraitA::C);
  EXPECT_EQ(c.enum_trait_b, EnumTraitB::ONE);

  constexpr TestTraits a_one(EnumTraitA::A, EnumTraitB::ONE);
  constexpr TestTraits b_one(EnumTraitA::B, EnumTraitB::ONE);
  constexpr TestTraits c_one(EnumTraitA::C, EnumTraitB::ONE);

  EXPECT_EQ(a_one.enum_trait_a, EnumTraitA::A);
  EXPECT_EQ(a_one.enum_trait_b, EnumTraitB::ONE);

  EXPECT_EQ(b_one.enum_trait_a, EnumTraitA::B);
  EXPECT_EQ(b_one.enum_trait_b, EnumTraitB::ONE);

  EXPECT_EQ(c_one.enum_trait_a, EnumTraitA::C);
  EXPECT_EQ(c_one.enum_trait_b, EnumTraitB::ONE);

  constexpr TestTraits a_two(EnumTraitA::A, EnumTraitB::TWO);
  constexpr TestTraits b_two(EnumTraitA::B, EnumTraitB::TWO);
  constexpr TestTraits c_two(EnumTraitA::C, EnumTraitB::TWO);

  EXPECT_EQ(a_two.enum_trait_a, EnumTraitA::A);
  EXPECT_EQ(a_two.enum_trait_b, EnumTraitB::TWO);

  EXPECT_EQ(b_two.enum_trait_a, EnumTraitA::B);
  EXPECT_EQ(b_two.enum_trait_b, EnumTraitB::TWO);

  EXPECT_EQ(c_two.enum_trait_a, EnumTraitA::C);
  EXPECT_EQ(c_two.enum_trait_b, EnumTraitB::TWO);
}

TEST(TraitsBagTest, RequiredEnum) {
  constexpr RequiredEnumTestTraits a(EnumTraitA::A);
  constexpr RequiredEnumTestTraits b(EnumTraitA::B);
  constexpr RequiredEnumTestTraits c(EnumTraitA::C);

  EXPECT_EQ(a.enum_trait_a, EnumTraitA::A);
  EXPECT_EQ(b.enum_trait_a, EnumTraitA::B);
  EXPECT_EQ(c.enum_trait_a, EnumTraitA::C);
}

TEST(TraitsBagTest, ValidTraitInheritance) {
  struct ValidTraitsA {
    ValidTraitsA(EnumTraitA);
  };

  struct ValidTraitsB {
    ValidTraitsB(ValidTraitsA);
    ValidTraitsB(EnumTraitB);
  };

  static_assert(AreValidTraits<ValidTraitsA, EnumTraitA>(), "");
  static_assert(AreValidTraits<ValidTraitsB, EnumTraitA, EnumTraitB>(), "");
}

}  // namespace trait_helpers
}  // namespace base
