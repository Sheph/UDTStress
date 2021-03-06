#ifndef _DTUN_UDTHANDLE_H_
#define _DTUN_UDTHANDLE_H_

#include "DTun/SHandle.h"
#include <boost/enable_shared_from_this.hpp>
#include <udt.h>

namespace DTun
{
    class UDTReactor;

    class DTUN_API UDTHandle : public SHandle,
        public boost::enable_shared_from_this<UDTHandle>
    {
    public:
        UDTHandle(UDTReactor& reactor, UDTSOCKET sock);
        ~UDTHandle();

        inline UDTSOCKET sock() const { return sock_; }

        virtual void ping(UInt32 ip, UInt16 port);

        virtual bool bind(SYSSOCKET s);

        virtual bool bind(const struct sockaddr* name, int namelen);

        virtual bool getSockName(UInt32& ip, UInt16& port) const;

        virtual bool getPeerName(UInt32& ip, UInt16& port) const;

        virtual SYSSOCKET duplicate();

        virtual int getTTL() const;

        virtual bool setTTL(int ttl);

        virtual void close(bool immediate = false);

        virtual bool canReuse() const;

        virtual boost::shared_ptr<SConnector> createConnector();

        virtual boost::shared_ptr<SAcceptor> createAcceptor();

        virtual boost::shared_ptr<SConnection> createConnection();

    private:
        UDTReactor& reactor_;
        UDTSOCKET sock_;
        UDTSOCKET checkReuseSock_;
    };
}

#endif
