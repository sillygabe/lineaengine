#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.hpp"
#pragma once

namespace io
{   
    class outstream
    {
    protected:
        FILE * file;

    public:
        outstream(FILE * f) {this->file = f;}
        outstream(const char * filename)
        {
            this->file = fopen(filename, "w");
        }
        ~outstream(){fclose(file);}

        void operator()(int to_print)
        {
            fprintf(file, "%d", to_print);
        }
        void operator()(char * to_print)
        {
            fprintf(file, "%s", to_print);
        }
        void operator()(const char * to_print)
        {
            fprintf(file, "%s", to_print);
        }
        void operator()(data::string str)
        {
            for (auto c : str) this->operator()(c);
        }
        void operator()(double to_print)
        {
            fprintf(file, "%lf", to_print);
        }
        void operator()(float to_print)
        {
            fprintf(file, "%f", to_print);
        }
        void operator()(long to_print)
        {
            fprintf(file, "%ld", to_print);
        }
        void operator()(char to_print)
        {
            fprintf(file, "%c", to_print);
        }
        template <class First, class ...Other>
        void operator()(First elem, Other ...args)
        {
            this->operator()(elem);
            this->operator()(args...);
        }
        void close()
        {
            fclose(this->file);
        }
    };
    class instream
    {
    private:
        FILE * f;

        const char * readstr()
        {
            size_t size = 0; char * str = NULL;
            char temp; bool running = true;

            while ((temp = getc(this->f)) && running)
            {
                switch (temp)
                {
                case ' ': running = false; break;
                case '\n': running = false; break;
                case '\t': running = false; break;
                default:
                    str = (char *) realloc(str, ++size);
                    str[size - 1] = temp;
                    break;
                }
            }
            return (const char *) (str);
        }
    public:
        instream(FILE * file) : f(file) {}
        instream(const char * path)
        {
            this->f = fopen(path, "r");
        }
        ~instream(){fclose(this->f);}

        void operator()(int &num)
        {
            fscanf(this->f, "%d", &num);
        }
        void operator()(double &num)
        {
            fscanf(this->f, "%lf", &num);
        }
        void operator()(char *&str)
        {
            str = (char *) this->readstr();
        }
        void operator()(data::string &str)
        {
            str = this->readstr();
        }
        void operator()(char &symb)
        {
            fscanf(this->f, "%c", &symb);
        }

        template <typename First, typename ...Other>
        void operator()(First &elem, Other &...elems)
        {
            this->operator()(elem);
            this->operator()(elems...);
        }
        
        void close()
        {
            fclose(this->f);
        }
    };  

    outstream print = stdout;
    outstream printerr = stderr;
    instream input = stdin;
}