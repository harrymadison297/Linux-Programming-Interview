receiver: local_receiver.c lib/err_exit.c lib/file_io.c lib/sock_com.c
	gcc local_receiver.c lib/err_exit.c lib/file_io.c lib/sock_com.c -pthread -o build/local_receiver;./build/local_receiver

mysender: sender.c lib/err_exit.c lib/file_io.c lib/sock_com.c
	gcc sender.c lib/err_exit.c lib/file_io.c lib/sock_com.c -pthread -lm -o build/sender

clean:
	rm -rf build/* tmp/*