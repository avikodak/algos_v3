/****************************************************************************************************************************************************
 *  File Name                   : strstr.h
 *  File Location               : /algos_v3/src/main/avikodak/sites/leetcode/easy/strstr.h
 *  Created on                  : Jul 22, 2017 :: 8:37:22 AM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
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

#ifndef MAIN_AVIKODAK_SITES_LEETCODE_EASY_STRSTR_H_
#define MAIN_AVIKODAK_SITES_LEETCODE_EASY_STRSTR_H_

/****************************************************************************************************************************************************/
/*                                                           O(LOGN) Algorithm                                                                      */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
vector<int> preComputeLongestCommonPrefixSuffix(string pattern) {
    vector<int> result;
    if (pattern.size() == 0) {
        return result;
    }
    result.assign(pattern.size(), 0);
    int length = 0;
    int index = 1;
    while (index < pattern.size()) {
        if (pattern[index] == pattern[length]) {
            result[index] = ++length;
            index++;
        } else {
            if (length == 0) {
                result[index] = 0;
                index++;
            } else {
                length = result[length - 1];
            }
        }
    }
    return result;
}

int strStr(string text, string pattern) {
    if (text.size() == 0) {
        return pattern.size() == 0 ? 0 : -1;
    }
    if (pattern.size() == 0) {
        return 0;
    }
    vector<int> lps = preComputeLongestCommonPrefixSuffix(pattern);
    int textCrawler = 0, patternCrawler = 0;
    while (textCrawler < text.size()) {
        if (text[textCrawler] == pattern[patternCrawler]) {
            textCrawler++;
            patternCrawler++;
            if (patternCrawler >= pattern.size()) {
                return textCrawler - patternCrawler;
            }
        } else {
            if (patternCrawler != 0) {
                patternCrawler = lps[patternCrawler - 1];
            } else {
                textCrawler = textCrawler + 1;
            }
        }
    }
    return -1;
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

#endif /* MAIN_AVIKODAK_SITES_LEETCODE_EASY_STRSTR_H_ */
