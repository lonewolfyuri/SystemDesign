#include "hw3_p2.h"
#include "hw3_p1.h"
#include "helpers.h"

uint16_t verifyIPV4Checksum(IPV4_header* header) {
        return (verifiedChecksum(header));
}
