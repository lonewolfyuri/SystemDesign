#include "helpers.h"
#include "hw3_p1.h"
#include "hw3_p2.h"
#include "linkedList.h"

// helper definitions here

// sums the hw scores of a given student and returns that value.
int hwSum(void *student) {
	int result = 0, ndx;
	for (ndx = 0; ndx < 3; ndx++) {
		result += ((Student*) student)->hw_score[ndx];
	}
	return result;
}

// sums the midterm scores of a given student and returns that value.
int midSum(void *student) {
	int result = 0;
	result += ((Student*) student)->m_scores->m1_score;
	result += ((Student*) student)->m_scores->m2_score;
	return result;
}

// goes through each node in list and frees all malloc inside Student struct,
// then frees student struct, and then deletes list at the end.
void deleteListDeep(List_t *list) {
	node_t *cur = list->head;
	int ndx, len = list->length;
	for (ndx = 0; ndx < len; ndx++) {
		free(((Student*) cur->value)->m_scores);
		free(((Student*) cur->value)->name.firstName);
		free(((Student*) cur->value)->name.middleName);
		free(((Student*) cur->value)->name.lastName);
		free(cur->value);
		cur = cur->next;
	}	
	deleteList(list);
}


// calculates verified checksum and returns.
uint16_t verifiedChecksum(IPV4_header *header) {
	unsigned int tempcheck, checksum = 0, checker = 0xFF0000;
        uint16_t final, flipper = 0xFFFF, *cur = (uint16_t *)header;
        int ndx, len = 2*header->header_length;

        // sum checksum at each 16bit of packet
        for (ndx = 0; ndx < len; ndx++) {
                checksum += cur[ndx];
        }

        checker &= checksum;
        tempcheck = checksum & flipper;
        checker = checker >> 16;
        tempcheck += checker;
        checker = 0xF0000 & tempcheck;
        checker = checker >> 16;
        tempcheck += checker;
        final = tempcheck;
        return (~final);
}
