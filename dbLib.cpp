/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
void LoadData(void* &a) {
	TDataset* p=new TDataset;
	a = (TDataset*)a;
	a = p;
	p->ReadFileCities();
	p->ReadFileLines();
	p->ReadFileStations();
	p->ReadFileStation_lines();
	p->ReadFileSystems();
	p->ReadFileTracks();
	p->ReadFileTrack_lines();
	
	
}

void ReleaseData(void* &a) {
	delete a;
}