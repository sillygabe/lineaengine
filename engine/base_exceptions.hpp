#include "../scrap/exception.hpp"

//Throw when couldn't initialize the libraries
class no_init : public io::runtime_error
{
public:
    no_init() : runtime_error("Couldn't initialize SDL")
    {}
};