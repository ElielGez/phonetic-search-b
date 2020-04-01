
#include "PhoneticFinder.hpp"

/**
 function that find word in text that have little spelling mistake with specific chars or upper/lower cases. 
 * @param text - the text to search on
 * @param word - the word to find
 */
string phonetic::find(string text, string word)
{
    if (text.size() != 0 && word.size() != 0) // only if text and word is not empty check if the word is in the text
    {
        vector<string> tokens;
        split(text, tokens, ' ');  // spliting by space char.
        for (string item : tokens) //loop over the splitted items
        {
            // in order to make things easy , change the string from the text and the word to be in lower case.
            string low_case = toLowerCase(item);
            if (isMatch(low_case, toLowerCase(word)))
                return item;
        }
    }
    //otherwise if the function doesn't find word on the text , throw exception.
    throw exception();
}
/**
 function that holds array of alphabetic a-z , every index represents the position on the alphabetic order
 every value of index holds different counter number , and if two of the chars can be replace by the definition of cases , they will have the same value
 so in order to check if char can be replace with other char , i'm comparing the weight(value) of them in the alphabetic order.
 if equal return true otherwise return false
 value of 0 say that the char isn't active and cannot be replace with any char.

* cases {"v,w", "b,f,p", "g,j", "c,k,q", "s,z", "d,t", "o,u", "i,y"};
 * @param c_search - the char from the specific word in the text
 * @param c_find - the char from the word that we want to find
 * 
 */
bool phonetic::checkByWeight(char c_search, char c_find)
{
    //          {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z}
    int arr[] = {0, 1, 2, 3, 0, 1, 4, 0, 5, 4, 2, 0, 0, 0, 6, 1, 2, 0, 7, 3, 6, 8, 8, 0, 5, 7};

    int index_search = c_search - 'a';
    int index_find = c_find - 'a';

    if (arr[index_search] == 0 || arr[index_find] == 0) // if some of them is 0 , return false (not active)
        return false;
    else if (arr[index_search] == arr[index_find])
        return true;
    else
        return false;
}

/**
 function that checking if the search word can be match to the find word
 * @param toSearch - the string to search on
 * @param toFind - the string to find
 */
bool phonetic::isMatch(string toSearch, string toFind)
{
    // if the sizes are different , return false
    if (toSearch.size() != toFind.size())
        return false;
    else
    {
        //otherwise the sizes is equal so can compare those strings , char by char , and then calling checkByWeight function
        for (size_t i = 0; i < toSearch.size(); i++)
        {
            //if chars are equal continue to the next chars.
            if (toSearch[i] == toFind[i])
                continue;
            if (!checkByWeight(toSearch[i], toFind[i]))
                return false;
        }
        return true;
    }
}
/**
 function that converting string to be in his lower case state
 * @param word - word to lowercase
 */
string toLowerCase(string word)
{
    string lower = word;
    for (size_t i = 0; i < word.size(); i++)
    {
        lower[i] = tolower(word[i]);
    }
    return lower;
}

/**
 function to split string by given char
 * @param &txt - the address of the string to split
 * @param &strs - the address of vector that will contains the strings after seperating them
 * @param ch - the seperator char
 */
size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // every iteration check if the seperator char was found on the text
    // and then taking his position and pushing to the strs the sub string of the word from the start to the seperator
    while (pos != string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // add the last one
    strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}
