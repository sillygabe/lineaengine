#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include "helper.hpp"
#include <map>

namespace linea
{   
    namespace __private
    {
        typedef func_t<void> listener;
    } 
    
    namespace events
    {
        static std::map<uint32_t, __private::listener> listeners;

        void add_listener(uint32_t, func_t<void>);
        void update(void);
    }
}   

#endif