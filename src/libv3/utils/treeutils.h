/****************************************************************************************************************************************************
 *  File Name                   : treeutils.h
 *  File Location               : /algos_v3/src/libv3/utils/treeutils.h
 *  Created on                  : Apr 30, 2017 :: 11:48:04 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

#include <libv3/ds/treeds.h>

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

#ifndef LIBV3_UTILS_TREEUTILS_H_
#define LIBV3_UTILS_TREEUTILS_H_

class treeutil {
 private:
    itNode *getTree(vector<int> userInput, int index) {
        if (userInput.size() == 0 || index >= userInput.size()) {
            return null;
        }
        itNode *newNode = new itNode(userInput[index]);
        newNode->left = getTree(userInput, 2 * index + 1);
        newNode->right = getTree(userInput, 2 * index + 2);
        return newNode;
    }

    iptNode *getTreeWithParentPtr(vector<int> userInput, int index) {
        if (userInput.size() == 0 || index >= userInput.size()) {
            return null;
        }
        iptNode *newNode = new iptNode(userInput[index]);
        newNode->left = getTreeWithParentPtr(userInput, 2 * index + 1);
        newNode->right = getTreeWithParentPtr(userInput, 2 * index + 2);
        if (newNode->left != null) {
            newNode->left->parent = newNode;
        }
        if (newNode->right != null) {
            newNode->right->parent = newNode;
        }
        return newNode;
    }

    itNode *getTree(hash_map<unsigned int, int> userInput, int index) {
        if (userInput.size() == 0 || index >= userInput.size() || userInput.find(index) == userInput.end()) {
            return null;
        }
        itNode *newNode = new itNode(userInput[index]);
        newNode->left = getTree(userInput, 2 * index + 1);
        newNode->right = getTree(userInput, 2 * index + 2);
        return newNode;
    }
 public:
    itNode *getTree(vector<int> userInput) {
        return this->getTree(userInput, 0);
    }

    itNode *getTreeWithParentPtr(vector<int> userInput) {
        return getTreeWithParentPtr(userInput, 0);
    }

    itNode *getTree(hash_map<unsigned int, int> userInput) {
        return getTree(userInput, 0);
    }

    int getHeightOfTree(itNode *ptr) {
        if (ptr == null) {
            return 0;
        }
        return 1 + max(getHeightOfTree(ptr->left), getHeightOfTree(ptr->right));
    }

    int getSizeOfTree(itNode *ptr) {
        if (ptr == null) {
            return 0;
        }
        return 1 + getSizeOfTree(ptr->left) + getSizeOfTree(ptr->right);
    }
};

#endif /* LIBV3_UTILS_TREEUTILS_H_ */
