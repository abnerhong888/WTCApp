
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

int main(void){	
	wtc::UDPClient client;
	int cnt = 0;
	while(1){
		client.send(cnt);
		++cnt;
		au::sleep_ms(1000);
	}
	return 0;
}