#ifndef GCOVBUFFER_H
#define GCOVBUFFER_H

#include <vector>

namespace GcovParser
{
using GcovByte = unsigned char;

/*!
 * @brief \c SliceRef provides fast access to piece of data, that stored in \c GcovBuffer. It store
 * pointer to start of data chunk and its size and can extract byte array from it if required.
 * Because of direct pointer to \c GcovBuffer data it will became invalid, when \c GcovBuffer data
 * updated.
 */
class SliceRef
{
public:
    SliceRef() = default;

    SliceRef(GcovByte *dataOffset, const int size);

    bool isValid() const { return _dataOffset != nullptr; }

    std::vector< GcovByte > toGcovBytes() const;

private:
    GcovByte *_dataOffset{nullptr};
    int _size{0};
};

/*!
 * @brief store raw bytes read from gcno or gcda file and provide interface for different data types
 * (e.g. integers, strings, blocks, functions, etc.)
 */
class GcovBuffer
{
public:
    GcovBuffer();

    GcovBuffer(const std::vector< GcovByte > &rawData);

    bool isEmpty() const { return _rawData.empty(); }

    std::size_t size() const { return _rawData.size(); }

    void setRawData(const std::vector< GcovByte > &rawData);

    std::vector< GcovByte > getSlice(const int position, const int size) const;

    SliceRef getSliceRef(const int position, const int size);

    bool canReadFrom(const int position, const int size) const;

private:
    std::vector< GcovByte > _rawData;
};
}

#endif  // GCOVBUFFER_H