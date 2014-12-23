#ifndef STRING_HPP
#define STRING_HPP
#include <string>
#include <cstring>
#include <sstream>

namespace dev
{
    template<typename C> inline std::string toString(C toStr)
    {
        std::stringstream str;
        str << toStr;
        return str.str();
    }

    inline bool equals(std::string a, std::string b) { return !strcmp(a.c_str(), b.c_str()); }

    inline int charPos(std::string in, char f)
    {
        for(unsigned int i = 0; i < in.size(); i++)
        {
            if(in[i] == f)
            {
                return i;
            }
        }
        return -1;
    }

    template<typename Type> void fromString(Type& x, std::string source)
    { std::stringstream str(source); str >> x; return; }
}

inline bool operator==(std::string a, std::string b) { return !strcmp(a.c_str(), b.c_str()); }
inline bool operator!=(std::string a, std::string b) { return strcmp(a.c_str(), b.c_str()); }
#endif // STRING_HPP
