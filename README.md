#Web application in C

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

Execute cgi:

      cgi-fcgi -start  -connect localhost:9000 ./myapp

or

      spawn-fcgi -a127.0.0.1 -p9000 -n ./myapp
