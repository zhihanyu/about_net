
static int udp_socket;

esp_err_t creat_udp_server(void)
{
	int optval = 1;

	udp_socket = socket(AF_INET,SOCK_DGRAM,IPPROTO_IP);
	setsockopt(udp_socket,SOL_SOCKET,SO_BROADCAST,(void*)&optval,sizeof(optval));
	if(udp_socket < 0){
		return ESP_FAIL;
	}

	struct sockaddr_in server_addr;
	server_addr.sin_famliy = AF_INET;
	server_addr.sin_port = htons(48899);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(udp_socket, (struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
		pritf("create udp server failed\n");	
		close(udp_socket);
		return ESP_FAIL;
	}

	return ESP_OK;
}

void udp_conn_task(void *context)
{
	int socket_ret;

	while(1){
			
	}
}



