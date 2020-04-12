/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"
#include "dbLib.h"
#include "dsaLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}

void Finalization() {
    // Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
    // TODO: Implement this function for processing a request
    // NOTE: You can add other functions to support this main process.
    //       pData is a pointer to a data structure that manages the dataset
    //       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
    //       N is the size of output, must be a non-negative number
	TDataset*p = (TDataset*)pData;
	if (strcmp(pRequest, "CL") == 0) {
		int li = p->sizeOfLine();
		pOutput = new int;
		*((int*)pOutput) = li;
		N = 1;
	}

	else if ((pRequest[0] == 'C' && pRequest[1] == 'L') && strlen(pRequest) > 2) {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		int li = p->getNum(str);
		pOutput = new int;
		*((int*)pOutput) = li;
		N = 1;
		
	}

	else if ((pRequest[0] == 'F' && pRequest[1] == 'C') && strlen(pRequest) > 2) {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		int li = p->findCity(str);
		pOutput = new int;
		*((int*)pOutput) = li;
		N = 1;
	}

	else if ((pRequest[0] == 'F' && pRequest[1] == 'S') && strlen(pRequest) > 2) {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		int li = p->findStation(str);
		pOutput = new int;
		*((int*)pOutput) = li;
		N = 1;
	}

	else if (pRequest[0] == 'R' && pRequest[1] == 'S' && pRequest[2]==' ') {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		int deleteStation = atoi(str.c_str());
		int li = p->removeStation(deleteStation);
		pOutput = new int;
		*((int*)pOutput) = li;
		N = 1;
	}

	else if (pRequest[0] == 'L' && pRequest[1] == 'S' && pRequest[2] == 'C') {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		N = p->countStation(str);
		pOutput = new int[N];
		int* li = p->findCityStation(str);
		for (int i = 0; i < N; i++) {
			((int*)pOutput)[i] = li[i];
		}
	}

	else if (pRequest[0] == 'L' && pRequest[1] == 'L' && pRequest[2] == 'C') {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		N = p->countLine(str);
		pOutput = new int[N];
		int* li = p->findCityLine(str);
		for (int i = 0; i < N; i++) {
			((int*)pOutput)[i] = li[i];
		}
	}

	else if (pRequest[0] == 'L' && pRequest[1] == 'S' && pRequest[2] == 'L') {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		int lineID = atoi(str.c_str());
		N = p->countStationLine(lineID);
		pOutput = new int[N];
		int* li = p->findLineStation(lineID);
		for (int i = 0; i < N; i++) {
			((int*)pOutput)[i] = li[i];
		}
	}

	else if (pRequest[0] == 'I' && pRequest[1] == 'S' && pRequest[2] == 'L') {
		string str, str1, str2;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			if (pRequest[i] != ' ') {
				str.push_back(pRequest[i]);
			}
			else {
				temp = i + 1;
				break;
			}
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			if (pRequest[i] != ' ') {
				str1.push_back(pRequest[i]);
			}
			else {
				temp = i + 1;
				break;
			}
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str2.push_back(pRequest[i]);
		}
		int stationID = atoi(str.c_str());
		int lineID = atoi(str1.c_str());
		int idx = atoi(str2.c_str());

		N = 1;
		int li = p->insertStation(idx, lineID, stationID);
		pOutput = new int;
		*((int*)pOutput) = li;
	}

	else if (pRequest[0] == 'R' && pRequest[1] == 'S' && pRequest[2] == 'L') {
		string str, str1;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			if (pRequest[i] != ' ') {
				str.push_back(pRequest[i]);
			}
			else {
				temp = i + 1;
				break;
			}
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str1.push_back(pRequest[i]);
		}
		int stationID = atoi(str.c_str());
		int lineID = atoi(str1.c_str());

		N = 1;
		int li = p->removeStationLine(lineID, stationID);
		pOutput = new int;
		*((int*)pOutput) = li;
	}

	else if (pRequest[0] == 'S' && pRequest[1] == 'L' && pRequest[2] == 'P') {
		string str, str1;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			if (pRequest[i] != ' ') {
				str.push_back(pRequest[i]);
			}
			else {
				temp = i + 1;
				break;
			}
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str1.push_back(pRequest[i]);
		}
		int stationID = atoi(str.c_str());
		int trackID = atoi(str1.c_str());
		N = 1;
		int li = p->findIndexStation(stationID, trackID);
		pOutput = new int;
		*((int*)pOutput) = li;
	}

	else if (pRequest[0] == 'I' && pRequest[1] == 'S' && pRequest[2] == ' ') {
		string str;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			str.push_back(pRequest[i]);
		}
		N = 1;
		int li = p->insertNewStation(str);
		pOutput = new int;
		*((int*)pOutput) = li;
	}
	
	else if (pRequest[0] == 'U' && pRequest[1] == 'S') {
		string str, str1;
		int temp = 0;
		for (int i = 0; i < strlen(pRequest); i++) {
			if (pRequest[i] == ' ') { temp = i + 1; break; }
		}
		for (int i = temp; i < strlen(pRequest); i++) {
			if (pRequest[i] != ' ') {
				str.push_back(pRequest[i]);
			}
			else {
				temp = i + 1;
				break;
			}
		}
		int stationID = atoi(str.c_str());
		for (int i = temp; i < strlen(pRequest); i++) {
			str1.push_back(pRequest[i]);
		}
		N = 1;
		int li = p->updateStation(str1, stationID);
		pOutput = new int;
		*((int*)pOutput) = li;
	}

	else pOutput = NULL;
}

