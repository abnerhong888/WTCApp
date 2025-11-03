
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

#include "wtc/wtcApp.h"

int main(int argc, char **argv){	
    
    WTCApp app("abner.wtc");
    if(app.init() != 0){
        return -1;
    }
    return app.run(argc, argv);

    // 	wtc::UDPClient client;
// 	int cnt = 0;
// 	while(1){
// 		client.send(cnt);
// 		++cnt;
// 		au::sleep_ms(1000);
// 	}
// 	return 0;
}
