#include "io.hpp"
#pragma once

namespace io
{
    class exception 
    {
        //Probably TODO, not sure though
    };

    class runtime_error : public exception
    {
    protected:
        const char * message;
    public:
        runtime_error(const char * msg) : message(msg)
        {
            printerr(message, "\n");
            return;
        }
    };
}