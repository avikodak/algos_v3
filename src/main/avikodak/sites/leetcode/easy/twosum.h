/****************************************************************************************************************************************************
 *  File Name                   : twosum.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/twosum.h
 *  Created on                  : Jul 16, 2017 :: 5:47:44 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/two-sum/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_TWOSUM_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_TWOSUM_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
vector<int> twoSumON(vector<int> &userInput, int target) {
    vector<int> result;
    map<int, int> auxSpace;
    map<int, int>::iterator itToAuxSpace;
    for (int crawler = 0; crawler < userInput.size(); crawler++) {
        if ((itToAuxSpace = auxSpace.find(target - userInput[crawler])) != auxSpace.end()) {
            result.push_back(min(crawler, itToAuxSpace->second));
            result.push_back(max(crawler, itToAuxSpace->second));
            return result;
        }
        auxSpace.insert(pair<int, int>(userInput[crawler], crawler));
    }
    return result;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
vector<int> twoSum(vector<int> &userInput, int target) {
    vector<int> result;
    if (userInput.size() < 2) {
        return result;
    }
    for (unsigned int outerCrawler = 0; outerCrawler < userInput.size() - 1; outerCrawler++) {
        for (unsigned int innerCrawler = outerCrawler + 1; innerCrawler < userInput.size(); innerCrawler++) {
            if (userInput[outerCrawler] + userInput[innerCrawler] == target) {
                result.push_back(outerCrawler);
                result.push_back(innerCrawler);
                return result;
            }
        }
    }
    return result;
}
/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_TWOSUM_H_ */
