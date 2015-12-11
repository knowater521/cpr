#ifndef CPR_ERROR_H
#define CPR_ERROR_H

#include <string>

#include "cprtypes.h"
#include "defines.h"

namespace cpr {

enum class ErrorCode {
    OK = 0,
    CONNECTION_FAILURE,
    EMPTY_RESPONSE,
    HOST_RESOLUTION_FAILURE,
    INTERNAL_ERROR,
    INVALID_URL_FORMAT,
    NETWORK_RECEIVE_ERROR,
    NETWORK_SEND_FAILURE,
    OPERATION_TIMEDOUT,
    PROXY_RESOLUTION_FAILURE,
    SSL_CONNECT_ERROR,
    SSL_LOCAL_CERTIFICATE_ERROR,
    SSL_REMOTE_CERTIFICATE_ERROR,
    SSL_CACERT_ERROR,
    GENERIC_SSL_ERROR,
    UNSUPPORTED_PROTOCOL,
    UNKNOWN_ERROR = 1000,
};

class Error {
  public:
    Error() : code{ErrorCode::OK} {}

    template <typename TextType>
    Error(const ErrorCode& p_error_code, TextType&& p_error_message)
            : code{p_error_code}, message{CPR_FWD(p_error_message)} {}

    explicit operator bool() const {
        return code != ErrorCode::OK;
    }

    ErrorCode code;
    std::string message;

    static ErrorCode getErrorCodeForCurlError(int curl_code);
};

} // namespace cpr

#endif
