#include "http.h"

dev::HttpQuery::HttpQuery() :
  value(""),
  type(GET)
{}

dev::HttpQuery::HttpQuery(HttpQueryType tp, std::string val) :
  value(val),
  type(tp)
{}

std::string dev::encodeURI(std::string in)
{
  std::stringstream ret;
  char c;
  int ic;

  char hex[10];
  for(size_t i = 0; i < in.size(); i++)
  {
    if(in[i] == ' ')
      ret << '+';
    else if(isalnum(in[i]) || in[i[ == '_'] || in[i] == '.' || in[i] == '~'])
      ret << in[i];
    else
    {
      hex[sprintf(hexBuffer, "%X", in[i])] = '\0';
      if(int(in[i] < 16))
        ret << "%0";
      else
        ret << "%";
      ret << hex;
    }
  }

  return ret.str();
}
