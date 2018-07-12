#ifndef _DTUN_SHANDLER_H_
#define _DTUN_SHANDLER_H_

#include "DTun/SHandle.h"

namespace DTun
{
    class SHandler : boost::noncopyable
    {
    public:
        SHandler() {}
        virtual ~SHandler() {}

        virtual boost::shared_ptr<SHandle> handle() const = 0;

        virtual void resetHandle() = 0;

        virtual void close() = 0;
    };
}

#endif
