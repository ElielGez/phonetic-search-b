
#include "PhoneticFinder.hpp"

string phonetic::find(string text, string word)
{
    if (text.size() != 0 && word.size() != 0)
    {
        vector<string> tokens;
        split(text, tokens, ' ');
        for (string item : tokens)
        {
            string low_case = toLowerCase(item);
            if (isMatch(low_case, toLowerCase(word)))
                return item;
        }
    }
    throw exception();
}
bool phonetic::isMatch(string toSearch, string toFind)
{
    if (toSearch.size() != toFind.size())
        return false;
    else
    {
        for (size_t i = 0; i < toSearch.size(); i++)
        {
            if (toSearch[i] == toFind[i])
                continue;

            switch (toFind[i])
            {
            //v,w
            case 'v':
                if (toSearch[i] != 'w')
                    return false;
                break;
            case 'w':
                if (toSearch[i] != 'v')
                    return false;
                break;

            //b,f,p
            case 'b':
                if (toSearch[i] != 'f' && toSearch[i] != 'p')
                    return false;
                break;
            case 'f':
                if (toSearch[i] != 'b' && toSearch[i] != 'p')
                    return false;
                break;
            case 'p':
                if (toSearch[i] != 'f' && toSearch[i] != 'b')
                    return false;
                break;

            // g,j
            case 'g':
                if (toSearch[i] != 'j')
                    return false;
                break;
            case 'j':
                if (toSearch[i] != 'g')
                    return false;
                break;

            // c,k,q
            case 'c':
                if (toSearch[i] != 'k' && toSearch[i] != 'q')
                    return false;
                break;
            case 'k':
                if (toSearch[i] != 'c' && toSearch[i] != 'q')
                    return false;
                break;
            case 'q':
                if (toSearch[i] != 'c' && toSearch[i] != 'k')
                    return false;
                break;

            // s,z
            case 's':
                if (toSearch[i] != 'z')
                    return false;
                break;
            case 'z':
                if (toSearch[i] != 's')
                    return false;
                break;

            // d,t
            case 'd':
                if (toSearch[i] != 't')
                    return false;
                break;
            case 't':
                if (toSearch[i] != 'd')
                    return false;
                break;

            // o,u
            case 'o':
                if (toSearch[i] != 'u')
                    return false;
                break;
            case 'u':
                if (toSearch[i] != 'o')
                    return false;
                break;

            // i,y
            case 'i':
                if (toSearch[i] != 'y')
                    return false;
                break;
            case 'y':
                if (toSearch[i] != 'i')
                    return false;
                break;
            default:
                return false;
            }
        }
        return true;
    }
}
string toLowerCase(string word)
{
    string lower = word;
    for (size_t i = 0; i < word.size(); i++)
    {
        lower[i] = tolower(word[i]);
    }
    return lower;
}
size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}
