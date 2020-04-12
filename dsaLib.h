/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
	~L1List() {
		this->clean();
	}

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

	
	L1Item<T>*    returnNode() {
		return this->_pHead;
	}

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // TODO: Your code goes here
	if (_size == 0) { insertHead(a); return 0; }
	if (this->_pHead == NULL) return -1;
	L1Item<T>* pNew = new L1Item<T>(a);
	if (pNew == NULL) return -1;
	L1Item<T>* pTemp = this->_pHead;
	L1Item<T>* pPrev = this->_pHead;
	while (pTemp!=NULL){
		pPrev = pTemp;
		pTemp = pTemp->pNext;
	}
	pNew->pNext = NULL;
	pPrev->pNext = pNew;
	this->_size++;
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
	L1Item<T>* pNew = new L1Item<T>(a);
	if (pNew == NULL) return -1;
	pNew->pNext = this->_pHead;
	this->_pHead = pNew;
	this->_size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
	if (this->_pHead == NULL) return -1;
	L1Item<T>* pLoc = this->_pHead;
	this->_pHead = pLoc->pNext;
	pLoc->pNext = NULL;
	delete pLoc;
	this->_size--;
    return 0;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
	if (this->_size == 1) { removeHead(); return 0; }
	if (this->_pHead == NULL) return -1;
	L1Item<T>* pTemp = this->_pHead;
	L1Item<T>* pTemp1 = this->_pHead;
	while (pTemp->pNext != NULL) {
		pTemp1 = pTemp;
		pTemp = pTemp->pNext;
	}
	pTemp1->pNext = NULL;
	delete pTemp;
	this->_size--;
    return 0;
}

template <class T>
bool L1List<T>::find(T& a, int& idx) {
	if (this->_pHead == NULL) return idx = -1;
	L1Item<T>* pRun = this->_pHead;
	int i = 0;
	while (pRun != NULL) {
		if (pRun->data == a) {
			idx = i; return true;
		}
		pRun = pRun->pNext;
		i++;
	}
	return idx = -1;
}

template <class T>
int L1List<T>::insert(int i, T& a) {
	if (i == 0) { insertHead(a); return 0; }
	if (i<0 || i>_size) return -1;
	L1Item<T>* pRun = this->_pHead;
	for (int j = 1; j < i; j++) {
		pRun = pRun->pNext;
	}
	L1Item<T>* pNew = new L1Item<T>(a);
	pNew->pNext = pRun->pNext;
	pRun->pNext = pNew;
	this->_size++;
	return 0;
}

template <class T>
int L1List<T>::remove(int i) {
	if (i == 0) { removeHead(); return 0; }
	if (this->_pHead == NULL) return -1;
	L1Item<T>* pRun = this->_pHead;
	L1Item<T>* pPrev = this->_pHead;
	for (int j = 0; j < i; j++) {
		pPrev = pRun;
		pRun = pRun->pNext;
	}
	pPrev->pNext = pRun->pNext;
	delete pRun;
	this->_size--;
	return 0;
}

template <class T>
void L1List<T>::reverse() {
	if (this->_pHead == NULL) return;
	L1Item<T>* pCurr = this->_pHead;
	L1Item<T>* pPrev = NULL;
	L1Item<T>* pRun = NULL;
	while (pCurr != NULL) {
		pRun = pCurr->pNext;
		pCurr->pNext = pPrev;
		pPrev = pCurr;
		pCurr = pRun;
	}
	this->_pHead = pPrev;
}

template <class T>
T& L1List<T>::at(int i) {
	L1Item<T>* pRun = this->_pHead;
	for (int j = 0; j < i; j++) {
		pRun = pRun->pNext;
	}
	return pRun->data;
}

template <class T>
T& L1List<T>::operator[](int i) {
	L1Item<T>* pRun = this->_pHead;
	for (int j = 0; j < i; j++) {
		pRun = pRun->pNext;
	}
	return pRun->data;
}

template <class T>
void L1List<T>::clean() {
	if (this->_pHead == NULL) return;
	L1Item<T>* pTemp;
	while (this->_pHead != NULL) {
		pTemp = this->_pHead;
		this->_pHead = this->_pHead->pNext;
		delete pTemp;
	}
	this->_size = 0;
}

#endif //DSA191_A1_DSALIB_H
