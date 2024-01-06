#include "list.hpp"
#pragma once

//FIX ME!!!
namespace data
{
    class string
    {
    private:
        list<char> arr;
    public:
        string() = default;

        string(const char * src)
        {
            char buff = *(src++);
            for (; buff != '\0'; buff = *src++)
            {
                arr.append(buff);
            }
        }

        string(char * src)
        {
            auto b = (const char *) src;
            char buff = *(src++);
            for (; buff != '\0'; buff = *b++)
            {
                arr.append(buff);
            }
        }

        string(const char src)
        {
            arr.append(src);
        }

        const char &operator[](size_t pos)
        {
            return this->arr[pos];
        }

        string operator+(string other)
        {
            string ret = *this;
            for (char b : other) ret.arr.append(b);
            return ret;
        }

        void operator+=(string other)
        {
            for (char b : other) this->arr.append(b);
        }

        const char * get_cstring()
        {
            return (const char *) (this->arr.arr);
        }

        char *begin()
        {
            return this->arr.begin();
        }

        char *end()
        {
            return this->arr.end();
        }

        friend class outstream;
        friend class instream;
    };
}