/****************************************************************************************************************************************************
 *  File Name                   : majorityelement.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/geeksforgeeks/arrays/page21/majorityelement.h
 *  Created on                  : May 9, 2017 :: 12:19:10 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <libv2/constants/constants.h>

#include "../../../../../../libv3/ds/treeds.h"
#include "../../../../../../libv3/utils/bstutils.h"

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
#include <libv3/constants/constants.h>
#include <libv3/ds/dscommons.h>
#include <libv3/ds/graphds.h>
#include <libv3/ds/linkedlistsds.h>
#include <libv3/ds/treeds.h>
#include <libv3/utils/abtreeutils.h>
#include <libv3/utils/arrayutils.h>
#include <libv3/utils/avltreeutils.h>
#include <libv3/utils/binarytreeutils.h>
#include <libv3/utils/bplustreeutils.h>
#include <libv3/utils/bstutils.h>
#include <libv3/utils/btreeutils.h>
#include <libv3/utils/commonutil.h>
#include <libv3/utils/dllutils.h>
#include <libv3/utils/graphutils.h>
#include <libv3/utils/ioutils.h>
#include <libv3/utils/mathutils.h>
#include <libv3/utils/redblacktreeutils.h>
#include <libv3/utils/treeutils.h>
#include <libv3/utils/trieutils.h>
#include <libv3/utils/twofourtreeutils.h>
#include <libv3/utils/sillutils.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_MAJORITYELEMENT_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_MAJORITYELEMENT_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
int getMajorityElementMooreVotingAlgo(vector<int> userInput) {
    if (userInput.size() == 0) {
        return INT_MIN;
    }
    int prospectMajorityElement = userInput[0];
    int frequency = 1;
    for (unsigned int counter = 1; counter < userInput.size(); counter++) {
        if (prospectMajorityElement == userInput[counter]) {
            frequency++;
        } else if (frequency == 1) {
            prospectMajorityElement = userInput[counter];
        } else {
            frequency--;
        }
    }
    frequency = 0;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        if (prospectMajorityElement == userInput[counter]) {
            frequency++;
        }
    }
    return frequency >= userInput.size() / 2 ? prospectMajorityElement : INT_MIN;
}

int getMajorityElementONHashMap(vector<int> userInput) {
    if (userInput.size() == 0) {
        return INT_MIN;
    }
    hash_map<int, unsigned int> frequencyMap;
    hash_map<int, unsigned int>::iterator itToFrequencyMap;
    for (unsigned int counter = 0; counter < userInput.size(); counter++) {
        if ((itToFrequencyMap = frequencyMap.find(userInput[counter])) != frequencyMap.end()) {
            frequencyMap[userInput[counter]]++;
        } else {
            frequencyMap[userInput[counter]] = 0;
        }
    }
    for (itToFrequencyMap = frequencyMap.begin(); itToFrequencyMap != frequencyMap.end(); itToFrequencyMap++) {
        if (itToFrequencyMap->second >= userInput.size() / 2) {
            return itToFrequencyMap->first;
        }
    }
    return INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/
int getMajorityElementONLogN(vector<int> userInput) {
    sort(userInput.begin(), userInput.end());
    int outerCrawler = 0;
    int innerCrawler, frequency;
    while (outerCrawler < userInput.size()) {
        innerCrawler = outerCrawler;
        frequency = 0;
        while (innerCrawler < userInput.size() && userInput[innerCrawler] == userInput[outerCrawler]) {
            innerCrawler++;
            frequency++;
        }
        if (frequency > userInput.size() / 2) {
            return userInput[outerCrawler];
        }
        outerCrawler = innerCrawler;
    }
    return INT_MIN;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
int getMajorityElementON2BST(vector<int> userInput) {
    if (userInput.size() == 0) {
        return INT_MIN;
    }
    bstutils *util = new bstutils();
    iftNode *root = util->getFreqBst(userInput);
    stack<iftNode *> auxSpace;
    auxSpace.push(root);
    iftNode *currentNode;
    while (!auxSpace.empty()) {
        currentNode = auxSpace.top();
        auxSpace.pop();
        if (currentNode->frequency >= userInput.size() / 2) {
            return currentNode->value;
        }
        if (currentNode->right != null) {
            auxSpace.push(currentNode->right);
        }
        if (currentNode->left != null) {
            auxSpace.push(currentNode->left);
        }
    }
    return INT_MIN;
}

int getMajorityElementON2(vector<int> userInput) {
    int frequency = 0;
    for (unsigned int outerCrawler = 0; outerCrawler < userInput.size(); outerCrawler++) {
        frequency = 0;
        for (unsigned int innerCrawler = outerCrawler; innerCrawler < userInput.size(); innerCrawler++) {
            if (userInput[outerCrawler] == userInput[innerCrawler]) {
                frequency++;
            }
        }
        if (frequency >= userInput.size() / 2) {
            return userInput[outerCrawler];
        }
    }
    return INT_MIN;
}
/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_ARRAYS_PAGE21_MAJORITYELEMENT_H_ */
