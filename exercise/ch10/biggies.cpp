#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    //排序

    //按长度排序
    stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
            {return a.size() < b.size();});

    //迭代器指向size() >= sz
    auto wc = find_if(words.begin(), words.end(),
            [sz](const string &a)
                {return a.size() >= sz;});

    //计数
    auto count = words.end() - wc;

    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz <<" or longer"  << endl;
    
    //print
    for_each(wc, words.end(),
            [](const string &s){cout << s <<" ";});
    
    cout << endl;
}

int main() {
  std::vector<std::string> words;
  for (std::string s; std::cin >> s; words.push_back(s)) {}
  biggies(words, 3);
  std::cout << std::endl;
  biggies(words, 5);

  return 0;
}