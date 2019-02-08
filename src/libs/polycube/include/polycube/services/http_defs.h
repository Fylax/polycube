/* http_defs.h
   Mathieu Stefani, 01 September 2015

   Various http definitions
*/

/*
Sligtly modified from
   pistache/include/pistache/http_defs.h
*/

#pragma once
#include <ostream>
#include <stdexcept>
#include <string>

namespace polycube {
namespace service {

namespace Http {

#define HTTP_METHODS         \
  METHOD(Options, "OPTIONS") \
  METHOD(Get, "GET")         \
  METHOD(Post, "POST")       \
  METHOD(Head, "HEAD")       \
  METHOD(Put, "PUT")         \
  METHOD(Patch, "PATCH")     \
  METHOD(Delete, "DELETE")   \
  METHOD(Trace, "TRACE")     \
  METHOD(Connect, "CONNECT")

// 10. Status Code Definitions
// Added ifndef to avoid compiler warning
#ifndef STATUS_CODES
#define STATUS_CODES                                                        \
  CODE(100, Continue, "Continue")                                           \
  CODE(101, Switching_Protocols, "Switching Protocols")                     \
  CODE(200, Ok, "OK")                                                       \
  CODE(201, Created, "Created")                                             \
  CODE(202, Accepted, "Accepted")                                           \
  CODE(203, NonAuthoritative_Information, "Non-Authoritative Information")  \
  CODE(204, No_Content, "No Content")                                       \
  CODE(205, Reset_Content, "Reset Content")                                 \
  CODE(206, Partial_Content, "Partial Content")                             \
  CODE(300, Multiple_Choices, "Multiple Choices")                           \
  CODE(301, Moved_Permanently, "Moved Permanently")                         \
  CODE(302, Found, "Found")                                                 \
  CODE(303, See_Other, "See Other")                                         \
  CODE(304, Not_Modified, "Not Modified")                                   \
  CODE(305, Use_Proxy, "Use Proxy")                                         \
  CODE(307, Temporary_Redirect, "Temporary Redirect")                       \
  CODE(400, Bad_Request, "Bad Request")                                     \
  CODE(401, Unauthorized, "Unauthorized")                                   \
  CODE(402, Payment_Required, "Payment Required")                           \
  CODE(403, Forbidden, "Forbidden")                                         \
  CODE(404, Not_Found, "Not Found")                                         \
  CODE(405, Method_Not_Allowed, "Method Not Allowed")                       \
  CODE(406, Not_Acceptable, "Not Acceptable")                               \
  CODE(407, Proxy_Authentication_Required, "Proxy Authentication Required") \
  CODE(408, Request_Timeout, "Request Timeout")                             \
  CODE(409, Conflict, "Conflict")                                           \
  CODE(410, Gone, "Gone")                                                   \
  CODE(411, Length_Required, "Length Required")                             \
  CODE(412, Precondition_Failed, "Precondition Failed")                     \
  CODE(413, Request_Entity_Too_Large, "Request Entity Too Large")           \
  CODE(414, RequestURI_Too_Long, "Request-URI Too Long")                    \
  CODE(415, Unsupported_Media_Type, "Unsupported Media Type")               \
  CODE(416, Requested_Range_Not_Satisfiable,                                \
       "Requested Range Not Satisfiable")                                   \
  CODE(417, Expectation_Failed, "Expectation Failed")                       \
  CODE(500, Internal_Server_Error, "Internal Server Error")                 \
  CODE(501, Not_Implemented, "Not Implemented")                             \
  CODE(502, Bad_Gateway, "Bad Gateway")                                     \
  CODE(503, Service_Unavailable, "Service Unavailable")                     \
  CODE(504, Gateway_Timeout, "Gateway Timeout")
#endif  // STATUS_CODES

// 3.4. Character Sets
// See http://tools.ietf.org/html/rfc2978 and
// http://www.iana.org/assignments/character-sets/character-sets.xhtml
#define CHARSETS                          \
  CHARSET(UsAscii, "us-ascii")            \
  CHARSET(Iso - 8859 - 1, "iso-8859-1")   \
  CHARSET(Iso - 8859 - 2, "iso-8859-2")   \
  CHARSET(Iso - 8859 - 3, "iso-8859-3")   \
  CHARSET(Iso - 8859 - 4, "iso-8859-4")   \
  CHARSET(Iso - 8859 - 5, "iso-8859-5")   \
  CHARSET(Iso - 8859 - 6, "iso-8859-6")   \
  CHARSET(Iso - 8859 - 7, "iso-8859-7")   \
  CHARSET(Iso - 8859 - 8, "iso-8859-8")   \
  CHARSET(Iso - 8859 - 9, "iso-8859-9")   \
  CHARSET(Iso - 8859 - 10, "iso-8859-10") \
  CHARSET(Shift - JIS, "shift_jis")       \
  CHARSET(Utf7, "utf-7")                  \
  CHARSET(Utf8, "utf-8")                  \
  CHARSET(Utf16, "utf-16")                \
  CHARSET(Utf16 - BE, "utf-16be")         \
  CHARSET(Utf16 - LE, "utf-16le")         \
  CHARSET(Utf32, "utf-32")                \
  CHARSET(Utf32 - BE, "utf-32be")         \
  CHARSET(Utf32 - LE, "utf-32le")         \
  CHARSET(Unicode - 11, "unicode-1-1")

enum class Method {
#define METHOD(m, _) m,
  HTTP_METHODS
#undef METHOD
};

enum class Code {
#define CODE(value, name, _) name = value,
  STATUS_CODES
#undef CODE
};

enum class Version {
  Http10,  // HTTP/1.0
  Http11   // HTTP/1.1
};

enum class ConnectionControl { Close, KeepAlive, Ext };

enum class Expectation { Continue, Ext };

const char *methodString(Method method);
const char *codeString(Code code);
Method stringMethod(const std::string &method);

std::ostream &operator<<(std::ostream &os, Version version);
std::ostream &operator<<(std::ostream &os, Method method);
std::ostream &operator<<(std::ostream &os, Code code);

struct HttpError : public std::exception {
  HttpError(Code code, std::string reason);
  HttpError(int code, std::string reason);

  ~HttpError() noexcept {}

  const char *what() const noexcept {
    return reason_.c_str();
  }

  int code() const {
    return code_;
  }
  std::string reason() const {
    return reason_;
  }

 private:
  int code_;
  std::string reason_;
};

}  // namespace Http

}  // namespace service
}  // namespace polycube

namespace std {

template <>
struct hash<polycube::service::Http::Method> {
  size_t operator()(polycube::service::Http::Method method) const {
    return std::hash<int>()(static_cast<int>(method));
  }
};

}  // namespace std
