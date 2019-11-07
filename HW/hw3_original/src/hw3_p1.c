#include "hw3_p1.h"

int intComparator(void* p, void* q) {
    return ((int)p - (int)q);
}

int strComparator(void* str1, void* str2) {
    char* s1 = (char*)str1, *s2 = (char*)str2;
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2){}
    if (*s1 < *s2){
        return -1;
    }
    else if (*s1 > *s2){
        return 1;
    }
    return 0;
}

int idComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}	

int nameComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}

int totalHWComparator(void *student1, void *student2){
	//Insert Code here
    return 2;
}

int totalMidtermComparator(void *student1, void *student2){
	//Insert Code Here
    return 2;
}

int totalPtsComparator(void *student1, void *student2){
	//Insert Code Here
    return 2;
}

void printCSVStudentList(List_t *list){
    //Insert Code Here
}

