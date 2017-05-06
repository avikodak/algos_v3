/****************************************************************************************************************************************************
 *  File Name                   : dscommons.h
 *  File Location               : /algos_v3/src/libv3/ds/dscommons.h
 *  Created on                  : Apr 30, 2017 :: 11:44:08 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/
using namespace std;

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

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

/**
 * This represents a pair of integer values
 */
struct iPair {
    int firstValue;
    int secondValue;

    iPair() {
        this->firstValue = INT_MAX;
        this->secondValue = INT_MAX;
    }

    iPair(int firstValue, int secondValue) {
        this->firstValue = firstValue;
        this->secondValue = secondValue;
    }
};
