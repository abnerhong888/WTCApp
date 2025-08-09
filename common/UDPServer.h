#ifndef __UDPSERVER_H__
#define __UDPSERVER_H__

#include "au_utils.h"
#include "Messages.h"

namespace wtc{
    using namespace au;

    class UDPServer : public protoco::Server {
    public:
        UDPServer() : protoco::Server("UDPServer"){
            hd.backend = protoco::eBackendType::UDP;
            hd.ip = "localhost";
            hd.port = 8080;
            int ret = protoco::Server::Initialize(hd);
            AU_ASSERT(ret == 0, "UDPServer init failed.");

            cppThread::Start();
        }
        virtual void Parser(uint8_t* buffer, int len, struct sockaddr_in& client_addr){
            std::string ip = inet_ntoa(client_addr.sin_addr);
            int port = ntohs(client_addr.sin_port);
            
            log::console::Debug("[[UDP Server]] ip {}:{}, Recv: {}\n", ip.c_str(), port, recv_msg.get_message().c_str());
        }

        void Run() override{
            auto backend = Server::GetBackend();
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
           
            int len = backend->recvfrom(recv_msg.get_data_ptr(), recv_msg.get_total_data_length(), 0, (struct sockaddr*)&client_addr, &client_len);

            if(len > 0){
                recv_msg.decode();
                Parser(recv_msg.get_message_ptr(), recv_msg.get_message_length(), client_addr);
                send_msg.encode(eUdpMessageType::Join,  "this message is from UDPServer.");
                backend->sendto(send_msg.get_data_ptr(), send_msg.get_total_length(), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
            }
        }
    private:
        protoco::handle hd;
        Message recv_msg;
        Message send_msg;
    }; // class UDPServer
    
} // namespace wtc


#endif //__UDPSERVER_H__
