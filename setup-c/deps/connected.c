#include <stdlib.h>
#include <stdio.h>
#include "../lib/connected.h"

void connected() {
  if (system("ping google.com -c 1 >> /dev/null") != 0) {
    printf("connect to internet first (hint : use nmcli)\n");
    exit(1);
  }
}
