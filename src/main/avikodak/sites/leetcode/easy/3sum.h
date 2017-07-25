/****************************************************************************************************************************************************
 *  File Name                   : 3sum.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/3sum.h
 *  Created on                  : Jul 24, 2017 :: 9:30:40 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://leetcode.com/problems/3sum/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_3SUM_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_3SUM_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
struct triplet {
    int firstValue;
    int secondValue;
    int thirdValue;

    triplet(int firstValue, int secondValue, int thirdValue) {
        this->firstValue = min(min(firstValue, secondValue), thirdValue);
        this->thirdValue = max(max(firstValue, secondValue), thirdValue);
        this->secondValue = this->firstValue ^ firstValue ^ this->thirdValue ^ secondValue ^ thirdValue;
    }

    bool operator<(const triplet& rhs) const {
        if (this->firstValue == rhs.firstValue && this->secondValue == rhs.secondValue && this->thirdValue == rhs.thirdValue) {
            return false;
        } else if (this->firstValue == rhs.firstValue) {
            if (this->secondValue == rhs.secondValue) {
                return this->thirdValue < rhs.thirdValue;
            } else {
                return this->secondValue < rhs.secondValue;
            }
        } else {
            return this->firstValue < rhs.firstValue;
        }
    }
};

vector<vector<int> > threeSum(vector<int> userInput) {
    vector<vector<int> > result;
    if (userInput.size() < 3) {
        return result;
    }
    sort(userInput.begin(), userInput.end());
    set<triplet> uniqueTriplets;
    set<triplet>::iterator itToUniqueTriplets;
    int firstCrawler = 0, secondCrawler, thirdCrawler;
    while (firstCrawler < userInput.size() - 2) {
        secondCrawler = firstCrawler + 1;
        thirdCrawler = userInput.size() - 1;
        while (secondCrawler < thirdCrawler) {
            int sum = userInput[secondCrawler] + userInput[thirdCrawler] + userInput[firstCrawler];
            if (sum == 0) {
                triplet foundTriplet = triplet(userInput[firstCrawler], userInput[secondCrawler], userInput[thirdCrawler]);
                uniqueTriplets.insert(foundTriplet);
                secondCrawler++;
                thirdCrawler--;
            } else if (sum < 0) {
                secondCrawler++;
            } else {
                thirdCrawler--;
            }
        }
        firstCrawler++;
    }
    for (itToUniqueTriplets = uniqueTriplets.begin(); itToUniqueTriplets != uniqueTriplets.end(); itToUniqueTriplets++) {
        vector<int> outputTriplet;
        outputTriplet.push_back(itToUniqueTriplets->firstValue);
        outputTriplet.push_back(itToUniqueTriplets->secondValue);
        outputTriplet.push_back(itToUniqueTriplets->thirdValue);
        result.push_back(outputTriplet);
    }
    return result;
}

vector<vector<int> > threeSumWithoutSet(vector<int> userInput) {
    vector<vector<int> > result;
    if (userInput.size() < 3) {
        return result;
    }
    sort(userInput.begin(), userInput.end());
    int firstCrawler = 0;
    int currentSum;
    while (firstCrawler < userInput.size() - 2) {
        int secondCrawler = firstCrawler + 1;
        int thirdCrawler = userInput.size() - 1;
        while (secondCrawler < thirdCrawler) {
            currentSum = userInput[firstCrawler] + userInput[secondCrawler] + userInput[thirdCrawler];
            if (currentSum == 0) {
                vector<int> currentTriplet;
                currentTriplet.push_back(userInput[firstCrawler]);
                currentTriplet.push_back(userInput[secondCrawler]);
                currentTriplet.push_back(userInput[thirdCrawler]);
                result.push_back(currentTriplet);
                while (thirdCrawler - 1 >= 0 && userInput[thirdCrawler - 1] == userInput[thirdCrawler]) {
                    thirdCrawler--;
                }
                thirdCrawler--;
                while (secondCrawler + 1 < userInput.size() && userInput[secondCrawler] == userInput[secondCrawler + 1]) {
                    secondCrawler++;
                }
                secondCrawler++;
            } else if (currentSum < 0) {
                secondCrawler++;
            } else {
                thirdCrawler--;
            }
        }
        while (firstCrawler + 1 < userInput.size() && userInput[firstCrawler] == userInput[firstCrawler + 1]) {
            firstCrawler++;
        }
        firstCrawler++;
    }
    return result;
}

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_3SUM_H_ */
