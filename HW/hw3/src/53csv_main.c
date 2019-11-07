#include "hw3_p1.h"
#include "linkedList.h"
#include "helpers.h"

// 53csv implemenation 
int main(int argc, char* argv[]){
	List_t *list = malloc(sizeof(List_t));
	list->length = 0;
	int mode = atoi(argv[1]);
	
	// converts mode to comparator function
        switch(mode) {
                case 1:
                        // idComparator
                        list->comparator = idComparator;
                        break;
                case 2:
                        // nameComparator
                        list->comparator = nameComparator;
                        break;
                case 3:
                        // hwComparator
                        list->comparator = totalHWComparator;
                        break;
                case 4:
                        // midtermComparator
                        list->comparator = totalMidtermComparator;
                        break;
                case 5:
                        // totalComparator
                        list->comparator = totalPtsComparator;
                        break;
        }

	char cur = getchar();
	// loops through each line until EOF
	while (cur != EOF) {
		if (cur == '\n') {
			cur = getchar();
			continue;
		}
		
		// pushes first char of line back on stream
		ungetc(cur, stdin);

		int id = 0, hw_scores[3] = {0,0,0}, m_scores[2] = {0,0}, final = 0;
		char *firstName =(char*) malloc(100), *lastName =(char*) malloc(100), *middleName =(char*) malloc(100);
		// get id
		scanf("%d", &id);
		// comma
		getchar();
		// get name:
			// get firstName
			char curChar, *fnamePtr = firstName, *mnamePtr = middleName, *lnamePtr = lastName;
			while (curChar = getchar(), curChar != ',') {
				*(fnamePtr++) = curChar;
			} // comma
			*fnamePtr = '\0';
			
			// get lastName
			while (curChar = getchar(), curChar != ',') {
				*(lnamePtr++) = curChar;
			} // comma
			*lnamePtr = '\0';

			// get middleName
			while (curChar = getchar(), curChar != ',') {
				*(mnamePtr++) = curChar;
			} // comma
			*mnamePtr = '\0';
		// get hw_scores:
			// get hw_score[1]
		scanf("%d", &hw_scores[0]);
			// comma
		getchar();
			// get hw_score[2]
		scanf("%d", &hw_scores[1]);
			// comma
		getchar();
			// get hw_score[3]
		scanf("%d", &hw_scores[2]);
			// comma
		getchar();
		// get m_scores:
			// get m1_score
		scanf("%d", &m_scores[0]);
			// comma
		getchar();
			// get m2_score
		scanf("%d", &m_scores[1]);
			// comma
		getchar();
		// get final
		scanf("%d", &final);
		// newline or eof?
		cur = getchar();
		// error checking
		if (!id) {
			break;
		}
		// Make Midterms struct
		Midterms *mid =(Midterms*) malloc(sizeof(Midterms));
		mid->m1_score = m_scores[0];
		mid->m2_score = m_scores[1];
		// Make Student struct
		Student *newStu =(Student*) malloc(sizeof(Student));
		// Assigns all values into Student
		newStu->id = id;
		
		newStu->name.firstName = firstName;
		newStu->name.middleName = middleName;
		newStu->name.lastName = lastName;
		
		int ndx;
		for (ndx = 0; ndx < 3; ndx++) {
			newStu->hw_score[ndx] = hw_scores[ndx];
		}
		
		newStu->m_scores = mid;
		newStu->final = final;
		
		// based on mode, insertInOrder(List_t, Student);
		insertInOrder(list, newStu);
	}

	printCSVStudentList(list);
	deleteListDeep(list);
	return 0;
}

