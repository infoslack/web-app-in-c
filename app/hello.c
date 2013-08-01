#include "raphters.h"

START_HANDLER (hello, GET, "hello", res, 0 matches) {
  response_add_header(res, "content-type", "text/html");
  response_write(res, "<h1>Hello World</h1>");
} END_HANDLER

START_HANDLER (default_handler, GET, "", res, 0, matches) {
  reponse_add_header(res, "conent-type", "tex/html");
  response_write(res, "Home");
} END_HANDLER

int main() {
  add_handler(hello);
  add_handler(default_handler);
  server_forever();
  return 0;
}
