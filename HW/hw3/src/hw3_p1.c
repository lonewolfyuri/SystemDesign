#include "hw3_p1.h"
#include "helpers.h"

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
	if (((Student*) student1)->id < ((Student*) student2)->id) {
		return -1;
	} else if (((Student*) student1)->id > ((Student*) student2)->id) {
		return 1;
	} else {
		return 0;
	}
	return 2;
}	

int nameComparator(void *student1, void *student2){
	int lname = strComparator(((Student*) student1)->name.lastName, ((Student*) student2)->name.lastName);
	if (lname < 0) {
		return -1;
	} else if (lname > 0) {
		return 1;
	} else {
		int fname = strComparator(((Student*) student1)->name.firstName, ((Student*) student2)->name.firstName);
		if (fname < 0) {
			return -1;
		} else if (fname > 0) {
			return 1;
		} else {
			int mname = strComparator(((Student*) student1)->name.middleName, ((Student*) student2)->name.middleName);
			if (mname < 0) {
				return -1;
			} else if (mname > 0) {
				return 1;
			} else {
				return idComparator(student1, student2);
			}
		}
	}
    	return 2;
}

int totalHWComparator(void *student1, void *student2){
    	int hwSum1 = hwSum(student1), hwSum2 = hwSum(student2);
	
	if (hwSum1 < hwSum2) {
		return -1;
	} else if (hwSum1 > hwSum2) {
		return 1;
	} else {
		return idComparator(student1, student2);
	}
	return 2;
}

int totalMidtermComparator(void *student1, void *student2){
	int midSum1 = midSum(student1), midSum2 = midSum(student2);

	if (midSum1 < midSum2) {
		return -1;
	} else if (midSum1 > midSum2) {
		return 1;
	} else {
		return idComparator(student1, student2);
	}

    	return 2;
}

int totalPtsComparator(void *student1, void *student2){
	int totalSum1 = 0, totalSum2 = 0, ndx;
	
	totalSum1 += hwSum(student1);
	totalSum1 += midSum(student1);
	totalSum1 += ((Student*) student1)->final;	

	totalSum2 += hwSum(student2);
	totalSum2 += midSum(student2);
	totalSum2 += ((Student*) student2)->final;

	if (totalSum1 < totalSum2) {
		return -1;
	} else if (totalSum1 > totalSum2) {
		return 1;
	} else {
		return idComparator(student1, student2);
	}

    	return 2;
}

void printCSVStudentList(List_t *list){
    	int ndx;
	node_t *curNode = list->head;
	for (ndx = list->length; ndx > 0; ndx--) {
		Student *cur = ((Student*) curNode->value);
		printf("%d,%s,%s,%s,%d,%d,%d,%d,%d,%d\n", cur->id, cur->name.firstName, cur->name.lastName, cur->name.middleName, cur->hw_score[0], cur->hw_score[1], cur->hw_score[2], cur->m_scores->m1_score, cur->m_scores->m2_score, cur->final);
		curNode = curNode->next;
	}
}

