//
// Created by oldfrostdragon on 07.08.16.
//

#include "gtest/gtest.h"
#include <gcovbuffer.h>
#include <memory>

using namespace GcovParser;

class GcovBufferTest : public ::testing::Test
{

protected:
    std::shared_ptr< GcovBuffer > buffer;
    virtual void SetUp()
    {
        buffer = std::make_shared< GcovBuffer >();
        buffer->setRawData({'a', 'b', 'c', 'd', 'e'});
    }
};

TEST_F(GcovBufferTest, bufferIsEmptyAtStart)
{
    GcovBuffer localBuffer;
    ASSERT_TRUE(localBuffer.isEmpty());
    ASSERT_EQ(0ull, localBuffer.size());
}

TEST_F(GcovBufferTest, getSlice_returnsEmptyVectorWhenDataAbsent)
{
    GcovBuffer localBuffer;
    ASSERT_TRUE(localBuffer.getSlice(1, 2).empty());
}

TEST_F(GcovBufferTest, getSlice_returnsEmptyVectorWhenSumOfPositionAndSizeGreaterThanDataSize)
{
    ASSERT_TRUE(buffer->getSlice(0, 6).empty());
    ASSERT_TRUE(buffer->getSlice(5, 1).empty());
    ASSERT_TRUE(buffer->getSlice(4, 2).empty());
    ASSERT_TRUE(buffer->getSlice(10, 20).empty());
}

TEST_F(GcovBufferTest, getSlice_returnsEmptyVectorWhenSizeOrPositionIsNegative)
{
    ASSERT_TRUE(buffer->getSlice(-1, 2).empty());
    ASSERT_TRUE(buffer->getSlice(2, -1).empty());
}

TEST_F(GcovBufferTest, getSlice_returnsEmptyVectorWhenSizeIsZero)
{
    ASSERT_TRUE(buffer->getSlice(2, 0).empty());
}

TEST_F(GcovBufferTest, getSlice_returnsBytesForCorrectPositionAndSize)
{
    ASSERT_EQ((std::vector< GcovByte >{'c', 'd'}), buffer->getSlice(2, 2));
}

TEST_F(GcovBufferTest, getSliceRef_returnsInvalidSliceWhenDataAbsent)
{
    GcovBuffer localBuffer;
    ASSERT_FALSE(localBuffer.getSliceRef(1, 2).isValid());
}

TEST_F(GcovBufferTest, getSliceRef_returnsInvalidRefWhenSumOfPositionAndSizeGreaterThanDataSize)
{
    ASSERT_FALSE(buffer->getSliceRef(0, 6).isValid());
    ASSERT_FALSE(buffer->getSliceRef(5, 1).isValid());
    ASSERT_FALSE(buffer->getSliceRef(4, 2).isValid());
    ASSERT_FALSE(buffer->getSliceRef(10, 20).isValid());
}

//======
TEST_F(GcovBufferTest, getSliceRef_returnsInvalidSliceWhenSizeOrPositionIsNegative)
{
    ASSERT_FALSE(buffer->getSliceRef(-1, 2).isValid());
    ASSERT_FALSE(buffer->getSliceRef(2, -1).isValid());
}

TEST_F(GcovBufferTest, getSliceRef_returnsValidEmptyRefWhenSizeIsZero)
{
    auto slice = buffer->getSliceRef(2, 0);
    ASSERT_TRUE(slice.isValid());
    ASSERT_TRUE(slice.toGcovBytes().empty());
}

TEST_F(GcovBufferTest, getSliceRef_returnsValidRefForCorrectPositionAndSize)
{
    auto slice = buffer->getSliceRef(2, 2);
    ASSERT_TRUE(slice.isValid());
    ASSERT_EQ((std::vector< GcovByte >{'c', 'd'}), slice.toGcovBytes());
}