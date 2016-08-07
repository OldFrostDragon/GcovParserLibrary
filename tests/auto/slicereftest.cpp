//
// Created by oldfrostdragon on 07.08.16.
//

#include "gtest/gtest.h"

#include <gcovbuffer.h>

using namespace GcovParser;

TEST(SliceRefTest, isInvalidByDefault) { ASSERT_FALSE(SliceRef().isValid()); }

TEST(SliceRefTest, becameValidIfPointerIsInitialized)
{
    std::vector< GcovByte > bytes(2);
    SliceRef myRef(bytes.data(), 0);
    ASSERT_TRUE(myRef.isValid());
}

TEST(SliceRefTest, getGcovBytes_retunsEmptyVectorWhenSizeIsZero)
{
    std::vector< GcovByte > bytes(2);
    SliceRef myRef(bytes.data(), 0);
    ASSERT_EQ(std::vector< GcovByte >(), myRef.toGcovBytes());
}

TEST(SliceRefTest, getGcovBytes_retunsEmptyVectorWhenSliceIsInvalid)
{
    ASSERT_EQ(std::vector< GcovByte >(), SliceRef().toGcovBytes());
}

TEST(SliceRefTest, getGcovBytes_returnsSlicedBytes)
{
    std::vector< GcovByte > bytes{'a', 'b', 'c', 'd', 'e'};
    SliceRef myRef(bytes.data() + 1, 2);
    ASSERT_EQ((std::vector< GcovByte >{'b', 'c'}), myRef.toGcovBytes());
}