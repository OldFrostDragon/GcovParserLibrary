#ifndef GCOVFILEPARSER_H
#define GCOVFILEPARSER_H

#include "gcovfileparser_global.h"

#include <memory>

#include "gcovbuffer.h"

class GCOVFILEPARSERSHARED_EXPORT GcovFileParser
{
public:
    GcovFileParser() = default;
    bool parseGcno(const std::shared_ptr< GcovBuffer > &gcnoBuffer);
};

#endif  // GCOVFILEPARSER_H
