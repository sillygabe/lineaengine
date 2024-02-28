#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include "helper.hpp"
#include <map>
#include <vector>

namespace linea
{   
    namespace __private
    {
        typedef func_t<void> listener;
    } 
    
    namespace events
    {
        static std::map<uint32_t, __private::listener> listeners;
        static std::vector<uint32_t> event_query;

        void add_listener(uint32_t, func_t<void>);
        void update(void);
        void throw_event(uint32_t);
    }
}   

#endif