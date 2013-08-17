#Web application in C

[![endorse](https://api.coderwall.com/infoslack/endorsecount.png)](https://coderwall.com/infoslack)

### Example using [Raphters](https://github.com/DanielWaterworth/Raphters) framework

##### Instructions

      $ mkdir build
      $ cd build
      $ cmake ../
      $ make

Config Nginx to FastCGI:

      server {
        listen 80;
        server_name localhost;

        location / {
          root /var/www;
          index index.html;
          fastcgi_pass 127.0.0.1:9000;

          include /etc/nginx/fastcgi_params;
          fastcgi_param SCRIPT_NAME "";
          fastcgi_param PATH_INFO $uri;
        }
      }

Run cgi:

      cgi-fcgi -start  -connect localhost:9000 ./myapp

or

      spawn-fcgi -a127.0.0.1 -p9000 -n ./myapp

Look:
[spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)

In case of problems to end fastcgi find PID:

      netstat -tpan |grep "LISTEN" |grep :9000
