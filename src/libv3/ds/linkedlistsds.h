/****************************************************************************************************************************************************
 *  File Name                   : linkedlistsds.h
 *  File Location               : /algos_v3/src/libv3/ds/linkedlistsds.h
 *  Created on                  : Apr 30, 2017 :: 11:44:37 PM
 *  Author                      : avikodak
 *  Testing Status              : Data structures declarations
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <stdexcept>
#include <limits.h>
#include <stdint.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV3_DS_LINKEDLISTSDS_H_
#define LIBV3_DS_LINKEDLISTSDS_H_

/**
 * Represents a node in single
 * linked lists with integer values
 */
struct sillNode {
    int value;
    sillNode *next;

    sillNode() {
        this->value = 0;
        this->next = NULL;
    }

    sillNode(int value) {
        this->value = value;
        this->next = NULL;
    }
};

/**
 * Represents a node in double linked
 * lists with integer value
 */
struct dillNode {
    int value;
    dillNode *next;
    dillNode *prev;

    dillNode() {
        this->value = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    dillNode(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }

    dillNode(int value, dillNode *prev, dillNode *next) {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

#endif /* LIBV3_DS_LINKEDLISTSDS_H_ */
