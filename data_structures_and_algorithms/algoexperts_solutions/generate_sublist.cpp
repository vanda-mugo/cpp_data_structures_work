#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// Function to generate all combinations of a certain length
/*the generateCombinations - function generates all possible combinations of a certain length ('n') from the given elements
It uses a recursive approach to build each combination*/
void generateCombinations(const vector<int>& elements, int n, int start, vector<int>& combination, vector<vector<int>>& result) 
{
    if (combination.size() == n) {
        result.push_back(combination);
        return;
    }
    for (int i = start; i < elements.size(); ++i) {
        combination.push_back(elements[i]);
        generateCombinations(elements, n, i + 1, combination, result);
        combination.pop_back();
    }
}

// Function to generate all sublists from a combination of 3 elements
/*
the generateSublists function generates all possible sublists with lenghts ranging from 'minlength' to  'maxlength' (1 to 10 in this case)
from a given combination of 3 elements  */
void generateSublists(const vector<int>& combination, int minLength, int maxLength, vector<vector<int>>& sublists) {
    for (int length = minLength; length <= maxLength; ++length) {
        vector<int> sublist;
        generateCombinations(combination, length, 0, sublist, sublists);
    }
}

int main() {

    /* the unordered_set of unique elements from which to create the sublist */
    unordered_set<int> unorderedSet = {1, 2, 3, 4, 5, 6, 7};
    /*
    Use the range constructor of the vector to initialize it with the elements of the 
    unordered_set. This is done by passing the beginning and end iterators of the 
    unordered_set to the vector constructor: std::vector<int> vec(unorderedSet.begin()
    , unorderedSet.end());.*/

    vector<int> elements(unorderedSet.begin(), unorderedSet.end());
    std::cout << "elements[] ";
    for(int i= 0; i < elements.size(); i++)
    {
        std::cout << elements[i]; 
    }
    std::cout << "\nsize" <<elements.size() << std::endl;
    
    vector<vector<int>> combinations;
    vector<int> combination;
    
    // Generate all combinations of 3 unique elements
    generateCombinations(elements, 3, 0, combination, combinations);
    
    vector<vector<int>> allSublists;
    
    // Generate all sublists for each combination
    for (const auto& comb : combinations) {
        generateSublists(comb, 1, 10, allSublists);
    }
    
    // Output the results
    for (const auto& sublist : allSublists) {
        for (int num : sublist) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}




// todo


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to generate all combinations of a certain length
void generateCombinations(const vector<int>& elements, int n, int start, vector<int>& combination, vector<vector<int>>& result) {
    if (combination.size() == n) {
        result.push_back(combination);
        return;
    }
    for (int i = start; i < elements.size(); ++i) {
        combination.push_back(elements[i]);
        generateCombinations(elements, n, i + 1, combination, result);
        combination.pop_back();
    }
}

// Function to generate all sublists from a combination of 3 elements
void generateSublistsWithRepetitions(const vector<int>& combination, int minLength, int maxLength, vector<vector<int>>& sublists) {
    for (int length = minLength; length <= maxLength; ++length) {
        int total = pow(combination.size(), length);
        for (int i = 0; i < total; ++i) {
            vector<int> sublist;
            int num = i;
            for (int j = 0; j < length; ++j) {
                sublist.push_back(combination[num % combination.size()]);
                num /= combination.size();
            }
            sublists.push_back(sublist);
        }
    }
}

int main() {
    unordered_set<int> unorderedSet = {1, 2, 3, 4, 5, 6, 7};
    vector<int> elements(unorderedSet.begin(), unorderedSet.end());
    
    vector<vector<int>> combinations;
    vector<int> combination;
    
    // Generate all combinations of 3 unique elements
    generateCombinations(elements, 3, 0, combination, combinations);
    
    vector<vector<int>> allSublists;
    
    // Generate all sublists for each combination with repetitions
    for (const auto& comb : combinations) {
        generateSublistsWithRepetitions(comb, 1, 10, allSublists);
    }
    
    // Output the results
    for (const auto& sublist : allSublists) {
        for (int num : sublist) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
