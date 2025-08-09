#ifndef __UDP_CLIENT_H__
#define __UDP_CLIENT_H__

#include "au_utils.h"
#include "Messages.h"

namespace wtc{
    using namespace au;

    class UDPClient : public protoco::Client{
		public:
			UDPClient(): protoco::Client("UDPClient"){
				hd.backend = protoco::eBackendType::UDP;
				hd.ip = "localhost";
				hd.port = 8080;
				int ret = protoco::Client::Initialize(hd);
				AU_ASSERT(ret == 0, "UDPClient init failed.");

				cppThread::Start();
			}
			void send(int cnt){
				auto backend = Client::GetBackend();
				struct sockaddr_in server_addr = backend->get_sockaddr(hd);
                
				std::string str = "this message is from UDPClient." + std::to_string(cnt);
                send_msg.encode(eUdpMessageType::Join,  str);

				backend->sendto(send_msg.get_data_ptr(), send_msg.get_total_length(), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
			}
			void Run() override{
				auto backend = Client::GetBackend();

				struct sockaddr_in addr;
    			socklen_t addr_len = sizeof(addr);

				int len = backend->recvfrom(recv_msg.get_data_ptr(), recv_msg.get_total_data_length(), 0, (struct sockaddr*)&addr, &addr_len);

				if(len > 0){
					std::string ip = inet_ntoa(addr.sin_addr);
					int port = ntohs(addr.sin_port);
					recv_msg.decode();
					log::console::Debug("[[UDP Client]] ip {}:{}, Recv: {}\n", ip.c_str(), port, recv_msg.get_message().c_str());
				}
            };
		private:
			protoco::handle hd;
            Message recv_msg;
            Message send_msg;
    }; // class UDPClient
    
} // namespace wtc

#endif //__UDP_CLIENT_H__
