/****************************************************************************************************************************************************
 *  File Name                   : bstutils.h
 *  File Location               : /algos_v3/src/libv3/utils/bstutils.h
 *  Created on                  : Apr 30, 2017 :: 11:46:57 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include "../ds/treeds.h"

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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV3_UTILS_BSTUTILS_H_
#define LIBV3_UTILS_BSTUTILS_H_

class bstutils {
 private:
    void insert(itNode **root, int value) {
        if (*root == null) {
            (*root) = new itNode(value);
            return;
        }
        itNode *crawler = *root;
        while (true) {
            if (crawler->value == value) {
                return;
            } else if (crawler->value > value) {
                if (crawler->left == null) {
                    crawler->left = new itNode(value);
                    return;
                } else {
                    crawler = crawler->left;
                }
            } else {
                if (crawler->right == null) {
                    crawler->right = new itNode(value);
                    return;
                } else {
                    crawler = crawler->right;
                }
            }
        }
    }

    void insert(iftNode **root, int value) {
        if (*root == null) {
            (*root) = new iftNode(value);
            return;
        }
        iftNode *crawler = *root;
        while (true) {
            if (crawler->value == value) {
                crawler->frequency++;
                return;
            } else if (crawler->value > value) {
                if (crawler->left == null) {
                    crawler->left = new iftNode(value);
                    return;
                } else {
                    crawler = crawler->left;
                }
            } else {
                if (crawler->right == null) {
                    crawler->right = new iftNode(value);
                    return;
                } else {
                    crawler = crawler->right;
                }
            }
        }
    }
 public:
    itNode *getBst(vector<int> userInput) {
        if (userInput.size() == 0) {
            return null;
        }
        itNode *root = null;
        for (unsigned int counter = 0; counter < userInput.size(); counter++) {
            this->insert(&root, userInput[counter]);
        }
        return root;
    }

    iftNode *getFreqBst(vector<int> userInput) {
        if (userInput.size() == 0) {
            return null;
        }
        iftNode *root = null;
        for (unsigned int counter = 0; counter < userInput.size(); counter++) {
            this->insert(&root, userInput[counter]);
        }
        return root;
    }
};

#endif /* LIBV3_UTILS_BSTUTILS_H_ */
