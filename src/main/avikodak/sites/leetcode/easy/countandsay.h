/****************************************************************************************************************************************************
 *  File Name                   : countandsay.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/countandsay.h
 *  Created on                  : Jul 21, 2017 :: 6:38:35 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://leetcode.com/problems/count-and-say/#/description
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_COUNTANDSAY_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_COUNTANDSAY_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
string countAndSay(int noOfTerms) {
    if (noOfTerms == 0) {
        return "1";
    }
    string result = "1";
    for (int counter = 1; counter < noOfTerms; counter++) {
        result = generateSequence(result);
        cout << result << endl;
    }
    return result;
}

string toString(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

string generateSequence(string userInput) {
    string result;
    if (userInput.size() == 0) {
        return result;
    }
    int rearCrawler = 0, frontCrawler = 0;
    int frequency = 0;
    while (rearCrawler < userInput.size()) {
        frequency = 0;
        while (frontCrawler < userInput.size() && userInput[rearCrawler] == userInput[frontCrawler]) {
            frontCrawler++;
            frequency++;
        }
        result.append(toString(frequency));
        result.push_back(userInput[rearCrawler]);
        rearCrawler = frontCrawler;
    }
    return result;
}

/****************************************************************************************************************************************************/
/*                                                          O(N*LOGN) Algorithm                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                           O(C^N) Algorithm                                                                       */
/****************************************************************************************************************************************************/

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_COUNTANDSAY_H_ */
