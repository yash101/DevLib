#ifndef HTTP_H
#define HTTP_H
namespace dev
{
  enum HttpProtocol_t
  {
    HTTP_1_0,
    HTTP_1_1,
    PROTO_UNKNOWN
  };

  enum HttpQueryType
  {
    GET,
    POST
  };

  class HttpQuery
  {
  public:
    std::string value;
    HttpQueryType type;

    HttpQuery();
    HttpQuery(HttpQueryType tp, std::string value);
  };

  std::string encodeURI(std::string in);
  std::string decodeURI(std::string in);
  void iencodeURI(std::string& in);
  void idecodeURI(std::string& in);

  std::string httpStatus(int code);
  std::string generateTimestamp();

  extern std::string day[];
  extern std::string months[];
}
#endif
