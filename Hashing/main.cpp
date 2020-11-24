#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include <map>
using namespace std;
using namespace std::chrono;

vector<pair<string, string>> loadCSV(string file);

int main()
{
  vector<pair<string, string>> data = loadCSV("data.csv");
  map<string, string> mymap;
  auto start = high_resolution_clock::now();
  for (auto par : data)
    mymap[par.first] = par.second;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time:" << duration.count() << endl;
  cout << "Size of map: " << mymap.size() << endl;  
}


void testHash()
{
  vector<pair<string, string>> data = loadCSV("data_small.csv");
  unordered_map<string, string> hash;
  auto start = high_resolution_clock::now();
  for (auto par : data)
    hash[par.first] = par.second;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Time:" << duration.count() << endl;
  cout << "Size of Hash Table: " << hash.bucket_count() << endl;
  for (unsigned i = 0; i < hash.bucket_count(); ++i)
  {
    cout << "bucket #" << i << " contains: ";
    for (auto it = hash.begin(i); it != hash.end(i); ++it)
      cout << "[" << it->first << ":" << it->second << "] ";
    cout << "\n";
  }
  cout << "Hash Code:" << hash.hash_function()("Heider") + 1 << endl;
}

vector<pair<string, string>> loadCSV(string file)
{
  vector<pair<string, string>> data;
  fstream fin;
  fin.open(file, ios::in);
  vector<string> row;
  string line, word, temp;
  int i = 0;
  while (!fin.eof())
  {
    row.clear();
    getline(fin, line);
    if (i++ == 0)
      continue;
    stringstream s(line);
    while (getline(s, word, ';'))
    {
      row.push_back(word);
    }
    if (row.size() == 2)
      data.push_back({row[0], row[1]});
  }
  return data;
}
