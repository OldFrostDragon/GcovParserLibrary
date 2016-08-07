#include <gtest/gtest.h>

#include "gcovfileparser.h"

using namespace GcovParser;

class GcovFileParserTests : public ::testing::Test
{
public:
    GcovFileParserTests() {}

    // Test interface
protected:
    GcovFileParser *parser{nullptr};

    virtual void SetUp() override
    {
        parser = new GcovFileParser();
    }
    virtual void TearDown() override
    {
        delete parser;
    }
};

TEST_F(GcovFileParserTests, gcnoParsingReturnsFalseWhenBufferIsNull)
{
    ASSERT_FALSE(parser->parseGcno(nullptr));
}

TEST_F(GcovFileParserTests, gcnoParsingReturnsTrueWhenBufferIsEmpty)
{
    auto buffer = std::make_shared<GcovBuffer>();
    ASSERT_TRUE(parser->parseGcno(buffer));
}
