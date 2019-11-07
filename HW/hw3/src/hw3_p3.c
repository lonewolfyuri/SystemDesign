#include "hw3_p3.h"
#include "helpers.h"
#include "linkedList.h"
#include "packets.h"

IPV4_validation validateIPV4List(List_t* packets) {
    	IPV4_validation valid;

	valid.packet = NULL;
	valid.errcode = NOERR;    

	node_t *cur = packets->head;
	int ndx, len = packets->length;
	int curOffset = 0;
	IPV4_node *prevIP;

	IPV4_node *nextIP, *curIP;
        IPV4_header *nextHead, *curHead;
        int total_len;
        int head_len;
	
	if (len > 0) {
		curIP = (IPV4_node *)cur->value;
        	curHead = (IPV4_header *)curIP->sop;
        	total_len = curHead->total_length;
        	head_len = curHead->header_length;
        	curIP->payload_len = total_len - head_len * 4;
        	curIP->payload =(char*) (curIP->sop + (head_len * 4));
        	curIP->fragment_offset = curHead->fragment_offset;
	}

	for (ndx = 0; ndx < len; ndx++) {
		// variables
		
		if (ndx < len - 1) {
			nextIP = (IPV4_node *)(cur->next->value);
			nextHead = (IPV4_header *)nextIP->sop;
			total_len = nextHead->total_length;
			head_len = nextHead->header_length;
			nextIP->payload_len = total_len - head_len * 4;
			nextIP->payload =(char*) (nextIP->sop + (head_len * 4));
			nextIP->fragment_offset = nextHead->fragment_offset;
		} 		

		uint16_t result = verifiedChecksum(curIP->sop);
		curOffset = curIP->fragment_offset + curIP->payload_len;
		
		// printf("Invalid Offset: %d | Next Offset: %d | Payload Len: %d\n", curIP->fragment_offset, nextIP->fragment_offset, curIP->payload_len);		

                if (result != 0x0000) {
			// printf("Invalid CSum: %d\n", result);
			valid.packet = curIP;
			valid.errcode = ERRSUM;
		} else if (ndx < len - 1) {
			if (curOffset != nextIP->fragment_offset) {
                        	valid.packet = curIP;
                        	valid.errcode = ERRHOLE;
                       		break;
			}

			curIP = nextIP;
			curHead = nextHead;
			cur = cur->next;
		}
	}
	
	return valid;
}
