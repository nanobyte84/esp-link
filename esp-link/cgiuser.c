
#include <esp8266.h>
#include "cgi.h"
#include "espfs.h"
#include "config.h"
#include "serled.h"
#include "status.h"
#include "serbridge.h"
#include "user/user_main.h"

// Cgi to return choice of pin assignments
int ICACHE_FLASH_ATTR cgiUserGet(HttpdConnData *connData) {
  if (connData->conn==NULL) return HTTPD_CGI_DONE; // Connection aborted

  char buff[1024];
  int len;

  len = os_sprintf(buff,
      "{ \"user1\":2, \"user2\":3 }"
		  );

  jsonHeader(connData, 200);
  httpdSend(connData, buff, len);
  user_function1();
  return HTTPD_CGI_DONE;
}

// Cgi to change choice of pin assignments
int ICACHE_FLASH_ATTR cgiUserSet(HttpdConnData *connData) {
  if (connData->conn==NULL) {
    return HTTPD_CGI_DONE; // Connection aborted
  }

  int8_t ok = 0;
  int8_t user1, user2;
  ok |= getInt8Arg(connData, "userval1", &user1);
  ok |= getInt8Arg(connData, "userval1", &user2);
  if (ok < 0) return HTTPD_CGI_DONE;

  if (ok > 0) {

    os_printf("User config: user1=%d user2=%d\n",
	user1, user2);

    // apply the changes
    user_function2(user1, user2);

  }
  return HTTPD_CGI_DONE;

}

int ICACHE_FLASH_ATTR cgiUser(HttpdConnData *connData) {
  if (connData->conn==NULL) return HTTPD_CGI_DONE; // Connection aborted. Clean up.
  if (connData->requestType == HTTPD_METHOD_GET) {
    return cgiUserGet(connData);
  } else if (connData->requestType == HTTPD_METHOD_POST) {
    return cgiUserSet(connData);
  } else {
    jsonHeader(connData, 404);
    return HTTPD_CGI_DONE;
  }
}
