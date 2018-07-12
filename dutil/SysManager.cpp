#include "DTun/SysManager.h"
#include "DTun/SysHandle.h"
#include "Logger.h"
#include <boost/make_shared.hpp>

namespace DTun
{
    SysManager::SysManager(SysReactor& reactor)
    : reactor_(reactor)
    {
    }

    SysManager::~SysManager()
    {
    }

    boost::shared_ptr<SHandle> SysManager::createStreamSocket()
    {
        SYSSOCKET sock = ::socket(AF_INET, SOCK_STREAM, 0);
        if (sock == SYS_INVALID_SOCKET) {
            LOG4CPLUS_ERROR(logger(), "Cannot create TCP socket: " << strerror(errno));
            return boost::shared_ptr<SHandle>();
        }
        return boost::make_shared<SysHandle>(boost::ref(reactor_), sock);
    }

    boost::shared_ptr<SHandle> SysManager::createDatagramSocket()
    {
        assert(false);
        return boost::shared_ptr<SHandle>();
    }
}
