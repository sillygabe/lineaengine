#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.hpp"
#pragma once

//TODO: Fix this function
//Like it is so bad :(
char * __readinput(FILE * _readfrom)
{
    #define CHUNK 200
    char* input = NULL;
    char tempbuf[CHUNK];
    size_t inputlen = 0, templen = 0;
    
    do 
    {
        fgets(tempbuf, CHUNK, _readfrom);
        templen = strlen(tempbuf);
        input = (char *) realloc(input, inputlen+templen+1);
        strcpy(input+inputlen, tempbuf);
        inputlen += templen;
    } 
    while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');
    return input;
}

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
            fprintf(file, "%s", str.get_cstring());
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
            str = __readinput(this->f);
        }
        void operator()(data::string &str)
        {
            str = __readinput(this->f);
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