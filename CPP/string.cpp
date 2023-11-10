#include <iostream>
using namespace std;

void SplitFilename (const std::string& str)
{
  std::cout << "Splitting: " << str << '\n';
  std::size_t found = str.find_last_of("/\\");
  std::cout << " path: " << str.substr(0,found) << '\n';
  std::cout << " file: " << str.substr(found+1) << '\n';
}

int main(int argc, char* argv[]) {

    string str = " world hello world";

    // cout << "before: " << str << endl;
    // str.erase(str.begin()+5, str.end()-2);

    // cout << "after: " << str << endl;

    // find method in string class.
    // we always use the find() methond below. the input argment as a whole string are matched in the original string.
    size_t found = str.find("world");
    if (found != string::npos) {
        cout << "found = " << found << endl;
    }

    // actually, another overloaded find() method may be more practical, which includes three input arguments, 
    // the first argument in them is not a whole string found in original string, instead it can be an 
    // arbitrary string and the pos and the length can be able to specify according to actual situation.
    // obviously, the second find() method in class is more flexible than above
    found = str.find("world in a house", found+1, 5);
    if (found != string::npos) {
        cout << "found = " << found << endl;
    }

    // to match any character in the, we should use find_first_of() method. 


    std::string str1 ("/usr/bin/man");
    std::string str2 ("c:\\windows\\winhelp.exe");

    SplitFilename (str1);
    SplitFilename (str2);


    return 0;
}