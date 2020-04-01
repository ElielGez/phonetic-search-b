
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
 function that check permutation of specific chars.
 * @param c_search - the char from the specific word in the text
 * @param c_find - the char from the word that we want to find
 * 
 * more details:
 * inside the function i'm holding array of strings that seperated by ','
 * this strings is the cases of chars that can be replace on my searcing.
 * for example "v,w" - so if I get char 'v' on c_search param and in the c_find param I get 'w' , this case is correct and can be replace !
 * 
 * so i'm iterating over the this cases in order to check if the char in c_find is existing in one of those strings
 * after that i'm holding the position of this char in the string (char array) , and then check:
 * if != -1 said that the char was found , and now I can check if c_search param is equal to the other char in this strings
 * if yes , set the flag true and break because there is a match , don't need to check the other chars..
 */
bool phonetic::checkPermutation(char c_search, char c_find)
{
    bool flag = false;
    string cases[] = {"v,w", "b,f,p", "g,j", "c,k,q", "s,z", "d,t", "o,u", "i,y"};
    for (string str : cases)
    {
        int pos = str.find(c_find);
        if (pos != -1)
        { // the char was found
            vector<string> tokens;
            split(str, tokens, ',');
            for (string ch : tokens)
            {
                //ch is string with one char , the char that I need after the split . so taking on pos 0
                // if the char that i'm searcing is equal to the other permutation in this specific case , return true
                if (ch[0] != c_find && ch[0] == c_search)
                {
                    flag = true;
                    break;
                }
            }
            // if flag is true break from the main loop , this if prevent from cases to be with same chars check.(not asked on the assignment)
            if (flag)
                break;
        }
    }
    return flag;
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
        //otherwise the sizes is equal so can compare those strings , char by char , and then calling checkPermutation function
        for (size_t i = 0; i < toSearch.size(); i++)
        {
            //if chars are equal continue to the next chars.
            if (toSearch[i] == toFind[i])
                continue;
            if (!checkPermutation(toSearch[i], toFind[i]))
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
