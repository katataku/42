# Start up NGINX
service nginx start;
sleep infinity

# Please note that since "sleep infinity" is executed while running our container,
# the "docker run" flags "-it" (= terminal mode with a "pretty" format) are not going to do anything anymore.
# If you still want to run your container in terminal mode, you can remove the "sleep infinity" command
# or simply replace "sleep infinity" with "bash" command