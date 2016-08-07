#include "gcovbuffer.h"

using namespace GcovParser;

GcovBuffer::GcovBuffer() {}

void GcovBuffer::setRawData(const std::vector< GcovByte > &rawData) { _rawData = rawData; }

GcovBuffer::GcovBuffer(const std::vector< GcovByte > &rawData) : _rawData(rawData) {}

std::vector< GcovByte > GcovBuffer::getSlice(const int position, const int size) const
{
    if (!canReadFrom(position, size))
        return std::vector< GcovByte >();

    std::vector< GcovByte > data;
    for (int i = 0; i < size; ++i)
        data.push_back(_rawData.at(position + i));
    return data;
}

SliceRef GcovBuffer::getSliceRef(const int position, const int size)
{
    if (!canReadFrom(position, size))
        return SliceRef();
    else
        return SliceRef(_rawData.data() + position, size);
}

bool GcovBuffer::canReadFrom(const int position, const int size) const
{
    if (position < 0 || size < 0)
        return false;
    else return std::size_t(position + size) < _rawData.size();
}

SliceRef::SliceRef(GcovByte *dataOffset, const int size) : _dataOffset(dataOffset), _size(size) {}

std::vector< GcovByte > SliceRef::toGcovBytes() const
{
    if (!isValid() || _size == 0)
        return std::vector< GcovByte >();

    std::vector< GcovByte > data;
    data.reserve(_size);
    for (int i = 0; i < _size; ++i)
        data.push_back(*(_dataOffset + i));
    return data;
}
