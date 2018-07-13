#ifndef _DTUN_LTUDPHANDLEIMPL_H_
#define _DTUN_LTUDPHANDLEIMPL_H_

#include "DTun/Types.h"
#include "DTun/SConnection.h"
#include <boost/noncopyable.hpp>
#include <lwip/tcp.h>

namespace DTun
{
    class LTUDPManager;

    class DTUN_API LTUDPHandleImpl : boost::noncopyable
    {
    public:
        typedef boost::function<bool (const boost::shared_ptr<SHandle>&)> ListenCallback;

        explicit LTUDPHandleImpl(LTUDPManager& mgr);
        ~LTUDPHandleImpl();

        void kill();

        inline LTUDPManager& mgr() { return mgr_; }

        bool bind(const struct sockaddr* name, int namelen);

        void listen(int backlog, const ListenCallback& callback);

    private:
        static err_t listenerAcceptFunc(void* arg, struct tcp_pcb* newpcb, err_t err);

        LTUDPManager& mgr_;
        boost::shared_ptr<SConnection> conn_;
        struct tcp_pcb* pcb_;
        ListenCallback listenCallback_;
    };
}

#endif
