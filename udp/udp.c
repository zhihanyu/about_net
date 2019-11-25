
static struct sockaddr_in remote_addr;
static int udp_socket;
static unsigned int socklen;

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


void udp_recv_task(void)
{
	printf("udp rec task start.\n");
	/*send & receive first packet*/
	sockelen = sizeof(remote_addr);
	
	char *data_buff = malloc(512);
	memset(data_buff, 0, 512);

	while(1){
		
		memset(data_buff, 0, 512);
		
	}

}
void udp_conn(void *context)
{
	int socket_ret;

	while(1){
		printf("task  udp_conn start\n");
		printf("create up udp_server\n");
		socket_ret = create_udp_server();
		if(socket_ret == ESP_FAIL){
			printf("create udp socket err,stop.\n");
			vTaskDelete(NULL);
		}
		//start udp rev task
	}
}


void udp_task_int(void)
{
	xTaskCreate(&udp_conn,"udp_conn",UDP_SERVER_TASK_STACK_SZ,NULL,UDP_SERVER_TASK_PRIO,NULL);
}
		
