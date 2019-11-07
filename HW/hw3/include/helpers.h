#ifndef HELPERS_H
#define HELPERS_H

#include "packets.h"
#include "linkedList.h"
#include "hw3_p1.h"
#include "hw3_p2.h"

// sums the hw scores of a given student and returns that value.
int hwSum(void *student);

// sums the midterm scores of a given student and returns that value.
int midSum(void *student);

// goes through each node in list and frees all malloc inside Student struct,
// then frees student struct, and then deletes list at the end.
void deleteListDeep(List_t *list);

// calculates verified checksum and returns.
uint16_t verifiedChecksum(IPV4_header *header);


#endif // HELPERS_H
