/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
struct TCity {
    // The structure to store city information
	int id;
	string name;
	string coords;
	int start_year;
	string url_name;
	string country;
	string country_state;
};

struct TLine {
    // The structure to store line information
	int id;
	int city_id;
	string name;
	string url_name;
	string color;
	int system_id;
	int transport_mode_id;
};

struct TTrack {
    // The structure to store track information
	int id;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int length;
	int city_id;
};

struct TStation {
	int id;
	string name;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int city_id;
};

struct TSystem {
	int id;
	int city_id;
	string name;
};

struct TStation_line {
	int id;
	int station_id;
	int line_id;
	int city_id;
	string created_at;
	string updated_at;
};

struct TTrack_line {
	int id;
	int section_id;
	int line_id;
	string created_at;
	string updated_at;
	int city_id;
};

class TDataset {
    // This class can be a container that help you manage your tables
	L1List<TCity> *city=new L1List<TCity>;
	L1List<TLine> *lines=new L1List<TLine>;
	L1List<TStation> *station=new L1List<TStation>;
	L1List<TSystem> *system = new L1List<TSystem>;
	L1List<TStation_line> *station_line=new L1List<TStation_line>;
	L1List<TTrack_line> *track_line=new L1List<TTrack_line>;
	L1List<TTrack> *track=new L1List<TTrack>;
public:
	TDataset() {};
	~TDataset() {};
	void ReadFileCities() {
		ifstream fileIn;
		fileIn.open("cities.csv");
		string line, _id, _start_year;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TCity>* pCity=new L1Item<TCity>;
		while (!fileIn.eof() && lineCount<335) {
			lineCount++;
			getline(fileIn, _id, ','); pCity->data.id = atoi(_id.c_str());
			getline(fileIn, pCity->data.name, ',');
			getline(fileIn, pCity->data.coords, ',');
			getline(fileIn, _start_year, ','); pCity->data.start_year = atoi(_start_year.c_str());
			getline(fileIn, pCity->data.url_name, ',');
			getline(fileIn, pCity->data.country, ',');
			getline(fileIn, pCity->data.country_state);
			if (pCity->data.country_state.length() > 0) pCity->data.country_state.pop_back();
			city->push_back(pCity->data);
		}
		fileIn.close();
	}

	void ReadFileLines() {
		ifstream fileIn;
		fileIn.open("lines.csv");
		string line, _id, _city_id, _system_id, _transport_mode_id;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TLine>* pLine=new L1Item<TLine>;
		while (!fileIn.eof() && lineCount<1344) {
			lineCount++;
			getline(fileIn, _id, ','); pLine->data.id = atoi(_id.c_str());
			getline(fileIn, _city_id, ','); pLine->data.city_id = atoi(_city_id.c_str());
			getline(fileIn, pLine->data.name, ',');
			getline(fileIn, pLine->data.url_name, ',');
			getline(fileIn, pLine->data.color, ',');
			getline(fileIn, _system_id, ','); pLine->data.system_id = atoi(_system_id.c_str());
			getline(fileIn, _transport_mode_id); pLine->data.transport_mode_id = atoi(_transport_mode_id.c_str());
			lines->push_back(pLine->data);
		}
		fileIn.close();
	}

	void ReadFileStations() {
		ifstream fileIn;
		fileIn.open("stations.csv");
		string line, _id, _buildstart, _opening, _closure, _city_id, removestr;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TStation>* pStation=new L1Item<TStation>;
		while (!fileIn.eof() && lineCount<15797) {
			lineCount++;
			getline(fileIn, _id, ','); pStation->data.id = atoi(_id.c_str());
			getline(fileIn, pStation->data.name, ',');
			getline(fileIn, removestr, '(');
			getline(fileIn, pStation->data.geometry, ','); pStation->data.geometry.pop_back();
			getline(fileIn, _buildstart, ','); pStation->data.buildstart = atoi(_buildstart.c_str());
			getline(fileIn, _opening, ','); pStation->data.opening = atoi(_opening.c_str());
			getline(fileIn, _closure, ','); pStation->data.closure = atoi(_closure.c_str());
			getline(fileIn, _city_id); pStation->data.city_id = atoi(_city_id.c_str());
			station->push_back(pStation->data);
		}
		fileIn.close();
	}

	void ReadFileStation_lines() {
		ifstream fileIn;
		fileIn.open("station_lines.csv");
		string line, _id, _station_id, _line_id, _city_id;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TStation_line>* pStation_line=new L1Item<TStation_line>;
		while (!fileIn.eof() && lineCount<16243) {
			lineCount++;
			getline(fileIn, _id, ','); pStation_line->data.id = atoi(_id.c_str());
			getline(fileIn, _station_id, ','); pStation_line->data.station_id = atoi(_station_id.c_str());
			getline(fileIn, _line_id, ','); pStation_line->data.line_id = atoi(_line_id.c_str());
			getline(fileIn, _city_id, ','); pStation_line->data.city_id = atoi(_city_id.c_str());
			getline(fileIn, pStation_line->data.created_at, ',');
			getline(fileIn, pStation_line->data.updated_at);
			station_line->push_back(pStation_line->data);
		}
		fileIn.close();
	}

	void ReadFileSystems() {
		ifstream fileIn;
		fileIn.open("systems.csv");
		string line, _id, _city_id;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TSystem>* pSystem=new L1Item<TSystem>;
		while (!fileIn.eof() && lineCount<489) {
			lineCount++;
			getline(fileIn, _id, ','); pSystem->data.id = atoi(_id.c_str());
			getline(fileIn, _city_id, ','); pSystem->data.city_id = atoi(_city_id.c_str());
			getline(fileIn, pSystem->data.name);
			system->push_back(pSystem->data);
		}
		fileIn.close();
	}

	void ReadFileTracks() {
		ifstream fileIn;
		fileIn.open("tracks.csv");
		string line, _id, _buildstart, _opening, _closure, _length, _city_id, removestr;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TTrack>* pTrack = new L1Item<TTrack>;
		while (!fileIn.eof() && lineCount<9272) {
			lineCount++;
			getline(fileIn, _id, '"');  pTrack->data.id = atoi(_id.c_str());
			getline(fileIn, removestr, '(');
			getline(fileIn, pTrack->data.geometry, '"'); pTrack->data.geometry.pop_back();
			getline(fileIn, _buildstart, ','); pTrack->data.buildstart = atoi(_buildstart.c_str());
			getline(fileIn, _opening, ','); pTrack->data.opening = atoi(_opening.c_str());
			getline(fileIn, _closure, ','); pTrack->data.closure = atoi(_closure.c_str());
			getline(fileIn, _length, ','); pTrack->data.length = atoi(_length.c_str());
			getline(fileIn, _city_id); pTrack->data.city_id = atoi(_city_id.c_str());
			track->push_back(pTrack->data);
		}
		fileIn.close();
	}

	void ReadFileTrack_lines() {
		ifstream fileIn;
		fileIn.open("track_lines.csv");
		string line, _id, _section_id, _line_id, _city_id;
		int lineCount = 1;
		getline(fileIn, line);
		L1Item<TTrack_line>* pTrack_line=new L1Item<TTrack_line>;
		while (!fileIn.eof() && lineCount<9758) {
			lineCount++;
			getline(fileIn, _id, ','); pTrack_line->data.id = atoi(_id.c_str());
			getline(fileIn, _section_id, ','); pTrack_line->data.section_id = atoi(_section_id.c_str());
			getline(fileIn, _line_id, ','); pTrack_line->data.line_id = atoi(_line_id.c_str());
			getline(fileIn, pTrack_line->data.created_at, ',');
			getline(fileIn, pTrack_line->data.updated_at, ',');
			getline(fileIn, _city_id); pTrack_line->data.city_id = atoi(_city_id.c_str());
			track_line->push_back(pTrack_line->data);
		}
		fileIn.close();
	}
	
	int sizeOfLine() {
		return lines->getSize();
	}

	int getNum(string str) {
		int cityID = 0;
		L1Item<TCity>* pNew= city->returnNode();
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else
			pNew = pNew->pNext;
		}
		int count = 0;
		L1Item<TLine>* pRun = lines->returnNode();
		while (pRun != NULL) {
			if (pRun->data.city_id == cityID) {
				count++;
			}
			pRun = pRun->pNext;
		}
		return count;
	}

	int findCity(string str) {
		int cityID = 0;
		L1Item<TCity>*pNew = city->returnNode();
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else pNew = pNew->pNext;
		}
		if (cityID != 0) return cityID;
		return -1;
	}

	int findStation(string str) {
		L1Item<TStation>*pNew = station->returnNode();
		while (pNew != NULL) {
			if (pNew->data.name == str) return pNew->data.id;
			else pNew = pNew->pNext;
		}
		return -1;
	}

	int removeStation(int str) {
		bool check = false;
		L1Item<TStation>*pNew = station->returnNode();
		int i = 0;
		while (pNew!=NULL) {
			if (pNew->data.id == str) {
				int idx = 0;
				int temp1 = 0;
				bool kt = false;

				L1Item<TTrack>* pCheck = track->returnNode();
				while (pCheck != NULL) {

					temp1 = pCheck->data.geometry.find(pNew->data.geometry); //pRun->data.geometry
					if (temp1 != -1) {
						for (int i = temp1; i < pCheck->data.geometry.length(); i++) {
							if (pCheck->data.geometry[i] == ',') {
								idx = i;
								kt = true;
								break;
							}
						}
					}
					if (kt) {
						pCheck->data.geometry.erase(temp1, idx - temp1 + 1);


						break;
					}
					else pCheck = pCheck->pNext;
				}
				station->remove(i);
				check = true;
				break;
			}
			else {
				pNew = pNew->pNext;
				i++;
			}
		}
		if (check) {
			L1Item<TStation_line>*pRun = station_line->returnNode();
			int j = 0;
			while (pRun != NULL) {
				if (pRun->data.station_id == str) {
					
					station_line->remove(j);
					return 0;
				}
				else {
					pRun = pRun->pNext;
					j++;
				}
			}

			
		}
		return -1;
	}

	int countStation(string str) {
		L1Item<TCity>*pNew = city->returnNode();
		int cityID = 0;
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else
				pNew = pNew->pNext;
		}

		L1Item<TStation>*pRun = station->returnNode();
		int count = 0;
		while (pRun != NULL) {
			if (pRun->data.city_id == cityID) count++;
			pRun = pRun->pNext;
		}
		return count;
	}

	int countLine(string str) {
		L1Item<TCity>*pNew = city->returnNode();
		int cityID = 0;
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else
				pNew = pNew->pNext;
		}

		L1Item<TLine>*pRun = lines->returnNode();
		int count = 0;
		while (pRun != NULL) {
			if (pRun->data.city_id == cityID) count++;
			pRun = pRun->pNext;
		}
		return count;
	}

	int* findCityLine(string str) {
		L1Item<TCity>*pNew = city->returnNode();
		int cityID = 0;
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else
				pNew = pNew->pNext;
		}

		int count = countStation(str);

		static int* a = new int[count];
		L1Item<TLine>*pTemp = lines->returnNode();
		int i = 0;
		while (pTemp != NULL) {
			if (pTemp->data.city_id == cityID) {
				a[i] = pTemp->data.id; i++;
			}
			pTemp = pTemp->pNext;
		}
		return a;
	}

	int* findCityStation(string str) {
		L1Item<TCity>*pNew = city->returnNode();
		int cityID = 0;
		while (pNew != NULL) {
			if (pNew->data.name == str) {
				cityID = pNew->data.id; break;
			}
			else
				pNew = pNew->pNext;
		}

		int count = countStation(str);

		static int* a = new int[count];
		L1Item<TStation>*pTemp = station->returnNode();
		int i = 0;
		while (pTemp != NULL) {
			if (pTemp->data.city_id == cityID) {
				a[i] = pTemp->data.id; i++;
			}
			pTemp = pTemp->pNext;
		}
		return a;
	}

	int countStationLine(int lineID) {
		L1Item<TStation_line>*pNew = station_line->returnNode();
		int count = 0;
		while (pNew != NULL) {
			if (pNew->data.line_id == lineID) count++;
			pNew = pNew->pNext;
		}
		return count;
	}

	int* findLineStation(int lineID) {
		L1Item<TStation_line>*pNew = station_line->returnNode();
		int count = countStationLine(lineID);
		int* a = new int[count];
		int i = 0;
		while (pNew != NULL) {
			if (pNew->data.line_id == lineID) {
				a[i] = pNew->data.station_id; i++;
			}
			pNew = pNew->pNext;
		}
		return a;
	}

	int insertStation(int idx, int lineID, int stationID) {
		int count = 0;
		L1Item<TStation_line>*pNew = new L1Item<TStation_line>;
		L1Item<TStation_line>*pRun = station_line->returnNode();
		while (pRun != NULL) {
			if (stationID == pRun->data.station_id && lineID == pRun->data.line_id) return -1;
			else pRun = pRun->pNext;
		}
		L1Item<TStation_line>*pCheck = station_line->returnNode();
		while (pCheck != NULL) {
			if (lineID == pCheck->data.line_id) {
				 break;
			}
			else { pCheck = pCheck->pNext; count++; }
		}
		pNew->data.station_id = stationID;
		pNew->data.line_id = lineID;
		station_line->insert(idx+count, pNew->data);
		L1Item<TStation>*pAdd = new L1Item<TStation>;
		pAdd->data.id = stationID;
		station->push_back(pAdd->data);
		return 0;
	}

	int removeStationLine(int lineID, int stationID) {
		L1Item<TStation_line>*pNew = station_line->returnNode();
		int i = 0;
		while (pNew != NULL) {
			if (pNew->data.line_id == lineID) {
				if (pNew->data.station_id == stationID) {
					station_line->remove(i); return 0;
				}
				else {
					pNew = pNew->pNext;
					i++;
				}
			}
			else {
				pNew = pNew->pNext;
				i++;
			}
		}
		return -1;
	}

	int findIndexStation(int stationID, int trackID) {
		L1Item<TTrack>*pRun = track->returnNode();
		int idx = 0;  //0
		while (pRun != NULL) {
			if (pRun->data.id == trackID) {
				L1Item<TStation>*pNew = station->returnNode();
				while (pNew != NULL) {
					if (pNew->data.id == stationID) {
						int temp = pRun->data.geometry.find(pNew->data.geometry);
						if (temp == 0 || temp == -1) return temp;
						for (int i = 0; i < pRun->data.geometry.length(); i++) {
							if (pRun->data.geometry[i] == ',') {
								if ((temp - i) == 1) return (idx + 1);
								else idx++;
							}
						}
					}
					else pNew = pNew->pNext;
				}
				return -1;
			}
			else pRun = pRun->pNext;
		}
		return -1;
	}

	int insertNewStation(string str) {
		int temp = 0;
		L1Item<TStation>*pNew = new L1Item<TStation>;
		string _name, _geometry, _buildstart, _opening, _closure, removestr;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ',') {
				_name.push_back(str[i]); 
			}
			else {
				temp = i + 1; break;
			}
		}
		pNew->data.name = _name;
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != '(') {
				removestr.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_geometry.push_back(str[i]); 
			}
			else {
				temp = i + 1; break;
			}
		}
		_geometry.pop_back();
		pNew->data.geometry = _geometry;
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_buildstart.push_back(str[i]); 
			}
			else {
				temp = i + 1; break;
			}
		}
		pNew->data.buildstart = atoi(_buildstart.c_str());
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_opening.push_back(str[i]); 
			}
			else {
				temp = i + 1; break;
			}
		}
		pNew->data.opening = atoi(_opening.c_str());
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_closure.push_back(str[i]); 
			}
			else {
				temp = i + 1; break;
			}
		}
		pNew->data.closure = atoi(_closure.c_str());
		L1Item<TStation>*pRun = station->returnNode();
		int id_max = pRun->data.id;
		while (pRun != NULL) {
			if (pRun->data.id > id_max) id_max = pRun->data.id;
			else pRun = pRun->pNext;
		}
		pNew->data.id = id_max + 1;
		station->push_back(pNew->data);
		return (id_max + 1);
	}

	int updateStation(string str, int stationID) {
		int temp = 0;
		bool check = false;
		L1Item<TStation>*pRun = station->returnNode();
		while (pRun != NULL) {
			if (pRun->data.id == stationID) {
				check = true; break;
			}
			else {
				pRun = pRun->pNext; check = false;
			}
		}
		if (!check) return -1;
		string _name, _geometry, _buildstart, _opening, _closure, removestr;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ',') {
				_name.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		pRun->data.name = _name;
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != '(') {
				removestr.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_geometry.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		_geometry.pop_back();
		int idx = 0;
		int temp1 = 0;
		bool kt = false;
		L1Item<TTrack>* pCheck = track->returnNode();
		while (pCheck != NULL) {
			
					temp1 = pCheck->data.geometry.find(pRun->data.geometry); //pRun->data.geometryUS 7697 NVT,234 123,0,0,0
					if (temp1 != -1) {
						for (int i = temp1; i < pCheck->data.geometry.length(); i++) {
							if (pCheck->data.geometry[i] == ',') {
								idx = i;
								kt = true;
								break;
							}
						}
					}
			if (kt) {
				pCheck->data.geometry.erase(temp1, idx - temp1);
				_geometry.push_back(',');
				pCheck->data.geometry.replace(temp1, 1, _geometry);
				break;
			}
			else pCheck = pCheck->pNext;
		}
		_geometry.pop_back();
		pRun->data.geometry = _geometry;
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_buildstart.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		pRun->data.buildstart = atoi(_buildstart.c_str());
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_opening.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		pRun->data.opening = atoi(_opening.c_str());
		for (int i = temp; i < str.length(); i++) {
			if (str[i] != ',') {
				_closure.push_back(str[i]);
			}
			else {
				temp = i + 1; break;
			}
		}
		pRun->data.closure = atoi(_closure.c_str());
		
		return 0;
	}
};

// Please add more or modify as needed

void LoadData(void* &);
void ReleaseData(void* &);

#endif //DSA191_A1_DBLIB_H
