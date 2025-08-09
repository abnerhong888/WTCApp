#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <cstdint>
#include <string>
#include <cstring>

namespace wtc{

// message length = 1024
// header length = 16
// check sum length = 1
#define MESSAGE_DATA_LENGTH ((1024) + 16 + 1)

    enum class eUdpMessageType : uint32_t {
        Join,
        Leave,
    };

    class Message{
    private:
        union {
            uint8_t data[MESSAGE_DATA_LENGTH];
            struct{
                eUdpMessageType type;
                uint32_t total_length;
                uint32_t message_length;
                uint32_t random_seed;
                uint8_t message[MESSAGE_DATA_LENGTH - 16];
            };
        };
    public:    
        void encode(eUdpMessageType _type, uint8_t* _data, uint32_t _length){
            this->type = _type;
            this->message_length = _length;
            this->total_length = this->message_length + 16 + 1;
            this->random_seed = rand() % this->message_length;
            ::memcpy(this->message, _data, this->message_length);
            // one byte check sum
            this->data[this->total_length - 1] = calculate_check_sum();
            this->_encode();
        }

        void encode(eUdpMessageType _type, std::string message){
            this->encode(_type, (uint8_t*)message.c_str(), message.length());
        }

        void decode(){
            this->_decode();
        }

        eUdpMessageType get_type(){
            return this->type;
        }

        uint32_t get_total_length(){
            return this->total_length;
        }
        
        uint32_t get_total_data_length(){
            return MESSAGE_DATA_LENGTH;
        }

        uint32_t get_message_length(){
            return this->message_length;
        }

        uint8_t* get_data_ptr(){
            return this->data;
        }

        uint8_t* get_message_ptr(){
            return this->message;
        }

        std::string get_message(){
            return std::string((char*)this->message, this->message_length);
        }

    private:
        uint8_t calculate_check_sum(){
            uint8_t sum = 0;
            for(uint32_t i = 0; i < this->total_length - 1; ++i){
                sum += this->data[i];
            }
            sum = ~sum + 1;
            return sum;
        }
        
        void rearrange(){
            uint32_t start = 16;
            uint32_t seed = start + this->random_seed;
            uint32_t end = start + this->message_length;

            uint32_t n = seed - start;
            for(uint32_t i = start; i < n / 2; ++i){
                std::swap(this->data[i], this->data[n - i - 1]);
            }

            n = end - seed;
            for(uint32_t i = seed; i < n / 2; ++i){
                std::swap(this->data[i], this->data[n - i - 1]);
            }
        }

        void _encode(){
            rearrange();
            
            for(uint32_t i = 0; i < this->message_length; ++i){
                if(std::isalpha(this->data[i])){
                    this->data[i] = this->data[i] + 3;
                }
            }
        }

        void _decode(){
            rearrange();
            for(uint32_t i = 0; i < this->message_length; ++i){
                if(std::isalpha(this->data[i])){
                    this->data[i] = this->data[i] - 3;
                }
            }
        }
    };
    
} // namespace wtc

#endif //__MESSAGES_H__
