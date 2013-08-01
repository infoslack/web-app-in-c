#include "raphters.h"

START_HANDLER (myapp, GET, "myapp", res, 0, matches) {
  response_add_header(res, "content-type", "text/html");
  response_write(res,
      "<h1>Hello World</h1>\n <a href=\"http://localhost\">back to home</a>"
  );
} END_HANDLER

START_HANDLER (default_handler, GET, "", res, 0, matches) {
  response_add_header(res, "content-type", "text/html");
  response_write(res,
      "Home\n <a href=\"http://localhost/myapp\">hello app</a>"
  );
} END_HANDLER

int main() {
  add_handler(myapp);
  add_handler(default_handler);
  serve_forever();
  return 0;
}
