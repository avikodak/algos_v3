/****************************************************************************************************************************************************
 *  File Name                   : treeds.h
 *  File Location               : /algos_v3/src/libv3/ds/treeds.h
 *  Created on                  : Apr 30, 2017 :: 11:30:53 PM
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

#ifndef LIBV3_DS_TREEDS_H_
#define LIBV3_DS_TREEDS_H_

/**
 * Represents integer binary tree node
 */
struct itNode {
    int value;
    itNode *left;
    itNode *right;
};

/**
 * Represents character binary tree node
 */
struct ctNode {
    char ch;
    ctNode *left;
    ctNode *right;
};

/**
 * Represents string binary tree node
 */
struct stNode {
    string value;
    stNode *left;
    stNode *right;
};

/**
 * Represents integer binary tree node
 * with parent pointer
 */
struct iptNode {
    int value;
    iptNode *left;
    iptNode *right;
    iptNode *parent;
};

/**
 * Represents character binary tree node
 * with parent pointer
 */
struct cptNode {
    char ch;
    cptNode *left;
    cptNode *right;
    cptNode *parent;
};

#endif /* LIBV3_DS_TREEDS_H_ */
